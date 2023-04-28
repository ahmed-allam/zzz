//#include "stdafx.h"

/*
Copyright 2013 Michael O'Keeffe (a.k.a. ninety47).

This file is part of ninety47 Dukascopy toolbox.

The "ninety47 Dukascopy toolbox" is free software: you can redistribute it
and/or modify it under the terms of the GNU General Public License as
published by the Free Software Foundation, either version 3 of the License,
or any later version.

"ninety47 Dukascopy toolbox" is distributed in the hope that it will be
useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General
Public License for more details.

You should have received a copy of the GNU General Public License along with
"ninety47 Dukascopy toolbox".  If not, see <http://www.gnu.org/licenses/>.
*/

#include "ninety47/dukascopy.h"
#include <boost/date_time/posix_time/posix_time.hpp>
#include <algorithm>
#include <vector>
#include "ninety47/dukascopy/defs.h"
#include "ninety47/dukascopy/io.hpp"
#include "ninety47/dukascopy/lzma.h"



namespace n47 {

namespace pt = boost::posix_time;


tick *tickFromBuffer(
        unsigned char *buffer, pt::ptime epoch, float digits, size_t offset) {
    bytesTo<unsigned int, n47::BigEndian> bytesTo_unsigned;
    bytesTo<float, n47::BigEndian> bytesTo_float;

    unsigned int ts = bytesTo_unsigned(buffer + offset);
    pt::time_duration ms = pt::millisec(ts);
    unsigned int ofs = offset + sizeof(ts);
    float ask = bytesTo_unsigned(buffer + ofs) * digits;
    ofs += sizeof(ts);
    float bid = bytesTo_unsigned(buffer + ofs) * digits;
    ofs += sizeof(ts);
    //28-9-2020 convert volume to million
    float askv = bytesTo_float(buffer + ofs) *1000000;
    ofs += sizeof(ts);
    float bidv = bytesTo_float(buffer + ofs) *1000000;

    return new tick(epoch, ms, ask, bid, askv, bidv);
}


tick_data* read_bin(
        unsigned char *buffer, size_t buffer_size, pt::ptime epoch, float point_value) {
    std::vector<tick*> *data = new std::vector<tick*>();
    std::vector<tick*>::iterator iter;

    std::size_t offset = 0;

    while ( offset < buffer_size ) {
        data->push_back(tickFromBuffer(buffer, epoch, point_value, offset));
        offset += ROW_SIZE;
    }

    return data;
}

//6-12-2020 add epoch to binary file
tick_epoch *tickFromBuffer_epoch(
        unsigned char *buffer, pt::ptime epoch, float digits, size_t offset) {
    bytesTo<unsigned int, n47::BigEndian> bytesTo_unsigned;
    bytesTo<float, n47::BigEndian> bytesTo_float;
    boost::posix_time::ptime const time_epoch(boost::gregorian::date(1970, 1, 1));
    unsigned int epoch_to_tick=(epoch-time_epoch).total_seconds();
    unsigned int ts = bytesTo_unsigned(buffer + offset);
    //pt::time_duration ms = pt::millisec(ts);
    unsigned int ofs = offset + sizeof(ts);
    unsigned int ask = bytesTo_unsigned(buffer + ofs) ;
    ofs += sizeof(ts);
    unsigned int bid = bytesTo_unsigned(buffer + ofs) ;
    ofs += sizeof(ts);
    //28-9-2020 convert volume to million
    unsigned int askv = bytesTo_float(buffer + ofs)*1000000 ;
    ofs += sizeof(ts);
    unsigned int bidv = bytesTo_float(buffer + ofs)*1000000 ;

    return new tick_epoch(epoch_to_tick, ts, ask, bid, askv, bidv);
}
tick_data_epoch* read_bin_with_epoch(
        unsigned char *buffer, size_t buffer_size, pt::ptime epoch, float point_value) {
    std::vector<tick_epoch*> *data = new std::vector<tick_epoch*>();
    //std::vector<tick_epoch*>::iterator iter;

    std::size_t offset = 0;

    while ( offset < buffer_size ) {
        data->push_back(tickFromBuffer_epoch(buffer, epoch, point_value, offset));
        offset += ROW_SIZE;
    }

    return data;
}



tick_data* read_bi5(
        unsigned char *lzma_buffer, size_t lzma_buffer_size, pt::ptime epoch,
        float point_value, size_t *bytes_read) {
    tick_data *result = 0;

    // decompress
    int status;
    unsigned char *buffer = n47::lzma::decompress(lzma_buffer,
            lzma_buffer_size, &status, bytes_read);

	//5-11-2020 here i will save binary file


    if (status != N47_E_OK) {
        bytes_read = 0;
    } else {
        // convert to tick data (with read_bin).
        result = read_bin(buffer, *bytes_read, epoch, point_value);
        delete [] buffer;
    }

    return result;
}

//5-11-2020
tick_data* read_bi5_to_bin(
	unsigned char *lzma_buffer, size_t lzma_buffer_size, pt::ptime epoch,
	float point_value, size_t *bytes_read, unsigned char** buffer_decompressed) {
	tick_data *result = 0;

	// decompress
	int status;
	*buffer_decompressed = n47::lzma::decompress(lzma_buffer,
		lzma_buffer_size, &status, bytes_read);

	if (status != N47_E_OK) 
	{
		bytes_read = 0;
	}
	else {
		// convert to tick data (with read_bin).
		result = read_bin(*buffer_decompressed, *bytes_read, epoch, point_value);
		//delete[] buffer_decompressed;
	}

	return result;
}


tick_data* read(
        const char *filename, pt::ptime epoch, float point_value, size_t *bytes_read) {
    tick_data *result = 0;
    size_t buffer_size = 0;
    unsigned char *buffer = n47::io::loadToBuffer<unsigned char>(filename, &buffer_size);

    if ( buffer != 0 ) {
        if ( n47::lzma::bufferIsLZMA(buffer, buffer_size) ) {
            result = read_bi5(buffer, buffer_size, epoch, point_value, bytes_read);
            // Reading in as bi5 failed lets double check its not binary
            // data in the buffer.
            if (result == 0) {
                result = read_bin(buffer, buffer_size, epoch, point_value);
            }
        } else {
            result = read_bin(buffer, buffer_size, epoch, point_value);
            *bytes_read = buffer_size;
        }
        delete [] buffer;

        if (result != 0 && result->size() != (*bytes_read / n47::ROW_SIZE)) {
            delete result;
            result = 0;
        }
    }
    return result;
}

}  // namespace n47
