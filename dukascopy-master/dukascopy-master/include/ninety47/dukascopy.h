#ifndef INCLUDE_NINETY47_DUKASCOPY_H_
#define INCLUDE_NINETY47_DUKASCOPY_H_

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

#include <boost/date_time/posix_time/posix_time.hpp>

#include <ctime>
#include <cstdio>
#include <vector>
#include <string>
#include <sstream>

namespace n47 {

namespace pt = boost::posix_time;


#define PV_YEN_PAIR 0.001
#define PV_DOLLAR_PAIR 0.00001
//22-9-2020 point value for oil and other instruments
//#define PV_xx.xxxx_PAIR 0.0001
//#define PV_xxxxx.x_PAIR 0.1

struct tick;

typedef std::vector<tick*> tick_data;

typedef std::vector<tick*>::iterator tick_data_iterator;

struct tick {
    tick()
    : td(pt::millisec(0)), ask(0.0), bid(0.0), askv(0.0), bidv(0.0)
    {}

    tick(pt::ptime epoch_, pt::time_duration ms, float a, float b, float av, float bv)
    : epoch(epoch_), td(ms), ask(a), bid(b), askv(av), bidv(bv)
    {}

    tick(const tick& rhs) {
        epoch = rhs.epoch;
        td = rhs.td;
        ask =  rhs.ask;
        bid = rhs.bid;
        askv = rhs.askv;
        bidv = rhs.bidv;
    }

    std::string str() const {
        std::stringstream strm;
        strm << epoch << ", " << td.total_milliseconds()
             << ask << ", " << askv << ", "
             << bid << ", " << bidv;
        return strm.str();
    }

    pt::ptime epoch;
    pt::time_duration td;
    float ask;
    float bid;
    float askv;
    float bidv;
};

//6-12-2020
struct tick_epoch;

typedef std::vector<tick_epoch*> tick_data_epoch;

typedef std::vector<tick_epoch*>::iterator tick_data_epoch_iterator;

struct tick_epoch {
    tick_epoch()
    :epoch(), td(), ask(0), bid(0), askv(0), bidv(0)
    {}

    tick_epoch(unsigned int epoch_, unsigned int ms, unsigned int a, unsigned int b, unsigned int av, unsigned int bv)
    : epoch(epoch_), td(ms), ask(a), bid(b), askv(av), bidv(bv)
    {}

    tick_epoch(const tick_epoch& rhs) {
        epoch = rhs.epoch;
        td = rhs.td;
        ask =  rhs.ask;
        bid = rhs.bid;
        askv = rhs.askv;
        bidv = rhs.bidv;
    }

    std::string str() const {
        std::stringstream strm;
        strm << epoch << ", " << td
             << ask << ", " << askv << ", "
             << bid << ", " << bidv;
        return strm.str();
    }

    unsigned int epoch;
    unsigned int td;
    unsigned int ask;
    unsigned int bid;
    unsigned int askv;
    unsigned int bidv;
};

struct BigEndian {};
struct LittleEndian {};

template <typename T, class endian>
struct bytesTo {
    T operator()(const unsigned char *buffer);
};

template <typename T>
struct bytesTo<T, BigEndian> {
    T operator()(const unsigned char *buffer) {
        T value;
        size_t index;
        for (index = sizeof(T); index > 0; index--) {
            ((unsigned char*) &value)[sizeof(T) - index]  =  *(buffer + index - 1);
        }
        return value;
    }
};

template <typename U>
struct bytesTo<U, LittleEndian> {
    U operator()(const unsigned char *buffer) {
        U value;
        size_t index;
        for (index = 0; index < sizeof(U); index++) {
            ((unsigned char*) &value)[ index ] = *(buffer + index);
        }
        return value;
    }
};


tick* tickFromBuffer(
        unsigned char *buffer, pt::ptime epoch, float digits, size_t offset = 0);


tick_data* read_bin(
        unsigned char *buffer, size_t buffer_size, pt::ptime epoch, float point_value);

//6-12-2020
tick_epoch* tickFromBuffer_epoch(
        unsigned char *buffer, pt::ptime epoch, float digits, size_t offset = 0);


tick_data_epoch* read_bin_with_epoch(
        unsigned char *buffer, size_t buffer_size, pt::ptime epoch, float point_value);


tick_data* read_bi5(
        unsigned char *lzma_buffer, size_t lzma_buffer_size, pt::ptime epoch,
        float point_value, size_t *bytes_read);

//5-11-2020
tick_data* read_bi5_to_bin(
	unsigned char *lzma_buffer, size_t lzma_buffer_size, pt::ptime epoch,
	float point_value, size_t *bytes_read,unsigned char** buffer_decompressed);


tick_data* read(
        const char *filename, pt::ptime epoch, float point_value, size_t *bytes_read);

}  // namespace n47

#endif  // INCLUDE_NINETY47_DUKASCOPY_H_
