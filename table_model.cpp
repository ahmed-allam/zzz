#include "table_model.h"

MatrixModel::MatrixModel( QObject* parent)
    :
    QAbstractTableModel(parent)
{
};
MatrixModel::MatrixModel(csv_min_time_with_price_difference* current_monowave_class_ptr_arg, QObject* parent)
    :
    QAbstractTableModel(parent)
{
	current_monowave_class_ptr = current_monowave_class_ptr_arg;
	m_numColumns = current_monowave_class_ptr->bidPrice.size();
};
int MatrixModel::rowCount(const QModelIndex&) const
{

    return m_numRows;
};

int MatrixModel::columnCount(const QModelIndex&) const
{
    //if (current_monowave_class_ptr->askPrice.empty() )
    if (current_monowave_class_ptr==nullptr)
        return 0;
    return (int)current_monowave_class_ptr->askPrice.size();
};

QVariant MatrixModel::data(const QModelIndex& index, int role = Qt::DisplayRole) const
{
	if (!index.isValid() || role != Qt::DisplayRole)
		return QVariant();

	// Return the data to which index points.
	//return m_data[index.row() * m_numColumns + index.column()];
	//return  current_monowave_class_ptr->bidPrice[index.column()];
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//\r\n\tcase 3:\r\n\t\treturn current_monowave_class_ptr->D_ND_degree_vec[10].$1[index.column()];\r\n\t\tbreak;
	if ((current_monowave_class_ptr->plot_flag == 1) || (current_monowave_class_ptr->plot_flag == 2) || (current_monowave_class_ptr->plot_flag == 3))
	{
		switch (index.row()) {

		case 0:

			return current_monowave_class_ptr->askPrice[index.column()];
			break;
		case 1:

			return current_monowave_class_ptr->askVolume[index.column()];
			break;
		case 2:

			return current_monowave_class_ptr->bidPrice[index.column()];
			break;


		case 3:

			return current_monowave_class_ptr->bidVolume[index.column()];
			break;

		case 4:

			return current_monowave_class_ptr->tickpartTime[index.column()];
			break;
		case 5:

			return current_monowave_class_ptr->epochpartTime[index.column()];
			break;
		default:
			return 0;
		}
	}
	else if (current_monowave_class_ptr->plot_flag == 4)
	{
		switch (index.row())
		{

		case 0:

			return current_monowave_class_ptr->askPrice[index.column()];
			break;
		case 1:

			return current_monowave_class_ptr->askVolume[index.column()];
			break;
		case 2:

			return current_monowave_class_ptr->bidPrice[index.column()];
			break;


		case 3:

			return current_monowave_class_ptr->bidVolume[index.column()];
			break;

		case 4:

			return current_monowave_class_ptr->tickpartTime[index.column()];
			break;
		case 5:

			return current_monowave_class_ptr->epochpartTime[index.column()];
			break;
		case 6:

			return current_monowave_class_ptr->D_ND_degree_vec[10].bidPrice_difference_move_start_MS_number_of_moves[index.column()];
			break;
		case 7:


			return current_monowave_class_ptr->D_ND_degree_vec[10].bidPrice_difference_move_start_MS[index.column()];
			break;
		case 8:


			return current_monowave_class_ptr->D_ND_degree_vec[10].bidPrice_difference_multi_segment_same_direction[index.column()];
			break;


		case 9:


			return current_monowave_class_ptr->D_ND_degree_vec[10].bidPrice_difference_Directional_D_up_main[index.column()];
			break;

		case 10:


			return current_monowave_class_ptr->D_ND_degree_vec[10].bidPrice_difference_Directional_D_number_moves_up_main[index.column()];
			break;

		case 11:


			return current_monowave_class_ptr->D_ND_degree_vec[10].bidPrice_difference_Directional_D_up_main_start[index.column()];
			break;

		case 12:


			return current_monowave_class_ptr->D_ND_degree_vec[10].bidPrice_difference_Directional_D_up_main_continuation[index.column()];
			break;

		case 13:


			return current_monowave_class_ptr->D_ND_degree_vec[10].bidPrice_difference_Directional_D_up_main_end[index.column()];
			break;

		case 14:


			return current_monowave_class_ptr->D_ND_degree_vec[10].bidPrice_difference_Directional_D_up_main_confirmation[index.column()];
			break;

		case 15:


			return current_monowave_class_ptr->D_ND_degree_vec[10].bidPrice_difference_Directional_D_up_main_new_price_action[index.column()];
			break;

		case 16:


			return current_monowave_class_ptr->D_ND_degree_vec[10].bidPrice_difference_Directional_D_up_main_segment_time[index.column()];
			break;

		case 17:


			return current_monowave_class_ptr->D_ND_degree_vec[10].bidPrice_difference_Directional_D_up_main_top[index.column()];
			break;

		case 18:


			return current_monowave_class_ptr->D_ND_degree_vec[10].bidPrice_difference_Directional_D_up_main_bottom[index.column()];
			break;


		case 19:


			return current_monowave_class_ptr->D_ND_degree_vec[10].bidPrice_difference_Directional_D_up_counter[index.column()];
			break;

		case 20:


			return current_monowave_class_ptr->D_ND_degree_vec[10].bidPrice_difference_Directional_D_number_moves_up_counter[index.column()];
			break;

		case 21:


			return current_monowave_class_ptr->D_ND_degree_vec[10].bidPrice_difference_Directional_D_up_counter_start[index.column()];
			break;

		case 22:


			return current_monowave_class_ptr->D_ND_degree_vec[10].bidPrice_difference_Directional_D_up_counter_continuation[index.column()];
			break;

		case 23:


			return current_monowave_class_ptr->D_ND_degree_vec[10].bidPrice_difference_Directional_D_up_counter_end[index.column()];
			break;

		case 24:


			return current_monowave_class_ptr->D_ND_degree_vec[10].bidPrice_difference_Directional_D_up_counter_confirmation[index.column()];
			break;


		case 25:


			return current_monowave_class_ptr->D_ND_degree_vec[10].bidPrice_difference_Directional_D_up_counter_new_price_action[index.column()];
			break;

		case 26:


			return current_monowave_class_ptr->D_ND_degree_vec[10].bidPrice_difference_Directional_D_up_counter_segment_time[index.column()];
			break;

		case 27:


			return current_monowave_class_ptr->D_ND_degree_vec[10].bidPrice_difference_Directional_D_up_counter_top[index.column()];
			break;

		case 28:


			return current_monowave_class_ptr->D_ND_degree_vec[10].bidPrice_difference_Directional_D_up_counter_bottom[index.column()];
			break;



		case 29:


			return current_monowave_class_ptr->D_ND_degree_vec[10].bidPrice_difference_Directional_D_down_main[index.column()];
			break;

		case 30:


			return current_monowave_class_ptr->D_ND_degree_vec[10].bidPrice_difference_Directional_D_number_moves_down_main[index.column()];
			break;

		case 31:


			return current_monowave_class_ptr->D_ND_degree_vec[10].bidPrice_difference_Directional_D_down_main_start[index.column()];
			break;

		case 32:


			return current_monowave_class_ptr->D_ND_degree_vec[10].bidPrice_difference_Directional_D_down_main_continuation[index.column()];
			break;

		case 33:


			return current_monowave_class_ptr->D_ND_degree_vec[10].bidPrice_difference_Directional_D_down_main_end[index.column()];
			break;

		case 34:


			return current_monowave_class_ptr->D_ND_degree_vec[10].bidPrice_difference_Directional_D_down_main_confirmation[index.column()];
			break;


		case 35:


			return current_monowave_class_ptr->D_ND_degree_vec[10].bidPrice_difference_Directional_D_down_main_new_price_action[index.column()];
			break;

		case 36:


			return current_monowave_class_ptr->D_ND_degree_vec[10].bidPrice_difference_Directional_D_down_main_segment_time[index.column()];
			break;

		case 37:


			return current_monowave_class_ptr->D_ND_degree_vec[10].bidPrice_difference_Directional_D_down_main_top[index.column()];
			break;

		case 38:


			return current_monowave_class_ptr->D_ND_degree_vec[10].bidPrice_difference_Directional_D_down_main_bottom[index.column()];
			break;



		case 39:


			return current_monowave_class_ptr->D_ND_degree_vec[10].bidPrice_difference_Directional_D_down_counter[index.column()];
			break;

		case 40:


			return current_monowave_class_ptr->D_ND_degree_vec[10].bidPrice_difference_Directional_D_number_moves_down_counter[index.column()];
			break;

		case 41:


			return current_monowave_class_ptr->D_ND_degree_vec[10].bidPrice_difference_Directional_D_down_counter_start[index.column()];
			break;

		case 42:


			return current_monowave_class_ptr->D_ND_degree_vec[10].bidPrice_difference_Directional_D_down_counter_continuation[index.column()];
			break;

		case 43:


			return current_monowave_class_ptr->D_ND_degree_vec[10].bidPrice_difference_Directional_D_down_counter_end[index.column()];
			break;

		case 44:


			return current_monowave_class_ptr->D_ND_degree_vec[10].bidPrice_difference_Directional_D_down_counter_confirmation[index.column()];
			break;


		case 45:


			return current_monowave_class_ptr->D_ND_degree_vec[10].bidPrice_difference_Directional_D_down_counter_new_price_action[index.column()];
			break;

		case 46:


			return current_monowave_class_ptr->D_ND_degree_vec[10].bidPrice_difference_Directional_D_down_counter_segment_time[index.column()];
			break;

		case 47:


			return current_monowave_class_ptr->D_ND_degree_vec[10].bidPrice_difference_Directional_D_down_counter_top[index.column()];
			break;

		case 48:


			return current_monowave_class_ptr->D_ND_degree_vec[10].bidPrice_difference_Directional_D_down_counter_bottom[index.column()];
			break;



		case 49:


			return current_monowave_class_ptr->D_ND_degree_vec[10].bidPrice_difference_NonDirectional_ND_up_main[index.column()];
			break;

		case 50:


			return current_monowave_class_ptr->D_ND_degree_vec[10].bidPrice_difference_NonDirectional_ND_number_moves_up_main[index.column()];
			break;

		case 51:


			return current_monowave_class_ptr->D_ND_degree_vec[10].bidPrice_difference_NonDirectional_ND_up_main_start[index.column()];
			break;

		case 52:


			return current_monowave_class_ptr->D_ND_degree_vec[10].bidPrice_difference_NonDirectional_ND_up_main_continuation[index.column()];
			break;

		case 53:


			return current_monowave_class_ptr->D_ND_degree_vec[10].bidPrice_difference_NonDirectional_ND_up_main_end[index.column()];
			break;

		case 54:


			return current_monowave_class_ptr->D_ND_degree_vec[10].bidPrice_difference_NonDirectional_ND_up_main_confirmation[index.column()];
			break;


		case 55:


			return current_monowave_class_ptr->D_ND_degree_vec[10].bidPrice_difference_Directional_ND_up_main_segment_time[index.column()];
			break;

		case 56:


			return current_monowave_class_ptr->D_ND_degree_vec[10].bidPrice_difference_Directional_ND_up_main_top[index.column()];
			break;

		case 57:


			return current_monowave_class_ptr->D_ND_degree_vec[10].bidPrice_difference_Directional_ND_up_main_bottom[index.column()];
			break;

		case 58:


			return current_monowave_class_ptr->D_ND_degree_vec[10].bidPrice_difference_Directional_ND_up_main_span[index.column()];
			break;


		case 59:


			return current_monowave_class_ptr->D_ND_degree_vec[10].bidPrice_difference_NonDirectional_ND_up_counter[index.column()];
			break;

		case 60:


			return current_monowave_class_ptr->D_ND_degree_vec[10].bidPrice_difference_NonDirectional_ND_number_moves_up_counter[index.column()];
			break;

		case 61:


			return current_monowave_class_ptr->D_ND_degree_vec[10].bidPrice_difference_NonDirectional_ND_up_counter_start[index.column()];
			break;

		case 62:


			return current_monowave_class_ptr->D_ND_degree_vec[10].bidPrice_difference_NonDirectional_ND_up_counter_continuation[index.column()];
			break;

		case 63:


			return current_monowave_class_ptr->D_ND_degree_vec[10].bidPrice_difference_NonDirectional_ND_up_counter_end[index.column()];
			break;

		case 64:


			return current_monowave_class_ptr->D_ND_degree_vec[10].bidPrice_difference_NonDirectional_ND_up_counter_confirmation[index.column()];
			break;


		case 65:


			return current_monowave_class_ptr->D_ND_degree_vec[10].bidPrice_difference_Directional_ND_up_counter_segment_time[index.column()];
			break;

		case 66:


			return current_monowave_class_ptr->D_ND_degree_vec[10].bidPrice_difference_Directional_ND_up_counter_top[index.column()];
			break;

		case 67:


			return current_monowave_class_ptr->D_ND_degree_vec[10].bidPrice_difference_Directional_ND_up_counter_bottom[index.column()];
			break;

		case 68:


			return current_monowave_class_ptr->D_ND_degree_vec[10].bidPrice_difference_Directional_ND_up_counter_span[index.column()];
			break;




		case 69:


			return current_monowave_class_ptr->D_ND_degree_vec[10].bidPrice_difference_NonDirectional_ND_down_main[index.column()];
			break;

		case 70:


			return current_monowave_class_ptr->D_ND_degree_vec[10].bidPrice_difference_NonDirectional_ND_number_moves_down_main[index.column()];
			break;

		case 71:


			return current_monowave_class_ptr->D_ND_degree_vec[10].bidPrice_difference_NonDirectional_ND_down_main_start[index.column()];
			break;

		case 72:


			return current_monowave_class_ptr->D_ND_degree_vec[10].bidPrice_difference_NonDirectional_ND_down_main_continuation[index.column()];
			break;

		case 73:


			return current_monowave_class_ptr->D_ND_degree_vec[10].bidPrice_difference_NonDirectional_ND_down_main_end[index.column()];
			break;

		case 74:


			return current_monowave_class_ptr->D_ND_degree_vec[10].bidPrice_difference_NonDirectional_ND_down_main_confirmation[index.column()];
			break;


		case 75:


			return current_monowave_class_ptr->D_ND_degree_vec[10].bidPrice_difference_Directional_ND_down_main_segment_time[index.column()];
			break;

		case 76:


			return current_monowave_class_ptr->D_ND_degree_vec[10].bidPrice_difference_Directional_ND_down_main_top[index.column()];
			break;

		case 77:


			return current_monowave_class_ptr->D_ND_degree_vec[10].bidPrice_difference_Directional_ND_down_main_bottom[index.column()];
			break;

		case 78:


			return current_monowave_class_ptr->D_ND_degree_vec[10].bidPrice_difference_Directional_ND_down_main_span[index.column()];
			break;



		case 79:


			return current_monowave_class_ptr->D_ND_degree_vec[10].bidPrice_difference_NonDirectional_ND_down_counter[index.column()];
			break;

		case 80:


			return current_monowave_class_ptr->D_ND_degree_vec[10].bidPrice_difference_NonDirectional_ND_number_moves_down_counter[index.column()];
			break;

		case 81:


			return current_monowave_class_ptr->D_ND_degree_vec[10].bidPrice_difference_NonDirectional_ND_down_counter_start[index.column()];
			break;

		case 82:


			return current_monowave_class_ptr->D_ND_degree_vec[10].bidPrice_difference_NonDirectional_ND_down_counter_continuation[index.column()];
			break;

		case 83:


			return current_monowave_class_ptr->D_ND_degree_vec[10].bidPrice_difference_NonDirectional_ND_down_counter_end[index.column()];
			break;

		case 84:


			return current_monowave_class_ptr->D_ND_degree_vec[10].bidPrice_difference_NonDirectional_ND_down_counter_confirmation[index.column()];
			break;


		case 85:


			return current_monowave_class_ptr->D_ND_degree_vec[10].bidPrice_difference_Directional_ND_down_counter_segment_time[index.column()];
			break;

		case 86:


			return current_monowave_class_ptr->D_ND_degree_vec[10].bidPrice_difference_Directional_ND_down_counter_top[index.column()];
			break;

		case 87:


			return current_monowave_class_ptr->D_ND_degree_vec[10].bidPrice_difference_Directional_ND_down_counter_bottom[index.column()];
			break;

		case 88:


			return current_monowave_class_ptr->D_ND_degree_vec[10].bidPrice_difference_Directional_ND_down_counter_span[index.column()];
			break;

			//2/5/2021

		case 89:


			return current_monowave_class_ptr->D_ND_degree_vec[10].bidPrice_difference_undetermined_degree[index.column()];
			break;

		case 90:
			return current_monowave_class_ptr->D_ND_degree_vec[10].bidPrice_difference_undetermined_price_difference_move[index.column()];
			break;

		}
		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


	}
};

QVariant MatrixModel::headerData(int section, Qt::Orientation orientation, int role) const
{
	if (role == Qt::DisplayRole && orientation == Qt::Vertical) 
	{
		switch (section)
			{
			case 0:
				return QString("askPrice");
			case 1:
				return QString("askVolume");
			case 2:
				return QString("bidPrice");
				//case(?([^\r\n])\s)([a-zA-Z0-9_:].*)\r\n(?([^\r\n])\s).*return QString\("([a-zA-Z0-9_].*)"\);
				//\r\n\t\tcase $1\r\n\t\treturn QString("$2");

				//\r\n\tcase 3:\r\n\t\treturn current_monowave_class_ptr->D_ND_degree_vec[10].$1[index.column()];\r\n\t\tbreak;
				//case(?([^\r\n])\s)([a-zA-Z0-9_:].*)\r\n\t\t\treturn current_monowave_class_ptr->D_ND_degree_vec[10].([a-zA-Z0-9_:].*)[index.column()];\r\n\t\t\tbreak;

				//case(?([^\r\n])\s)([a-zA-Z0-9_:].*)\r\n\t\t\treturn current_monowave_class_ptr->D_ND_degree_vec\[10\]\.([a-zA-Z0-9_:].*)\[index\.column\(\)\];\r\n\t\t\tbreak;

			case 3:
				return QString("bidVolume");


			case 4:
				return QString("tickpartTime");


			case 5:
				return QString("epochpartTime");

			

		
		/*
		case 0:
			return QString("move_start_MS");
		case 1:
			return QString("move_start_MS_number_of_moves");
		case 2:
			return QString("Directional_D_up");
		case 3:
			return QString("Directional_D_number_moves_up");
		case 4:
			return QString("Directional_D_down");
		case 5:
			return QString("Directional_D_number_moves_down");
		case 6:
			return QString("NonDirectional_ND_up");
		case 7:
			return QString("NonDirectional_ND_number_moves_up");
		case 8:
			return QString("NonDirectional_ND_down");
		case 9:
			return QString("NonDirectional_ND_number_moves_down");
		case 10:
			return QString("bidPrice_difference_many_differences_var");
		case 11:
			return QString("bidPrice_difference_to_previous_movement_percentage_many_percentages_var");
		*/
			case 6:
				return QString("bidPrice_difference_move_start_MS_number_of_moves");
			case 7:
				return QString("bidPrice_difference_move_start_MS");
			case 8:
				return QString("bidPrice_difference_multi_segment_same_direction");
				//case(?([^\r\n])\s)([a-zA-Z0-9_:].*)\r\n(?([^\r\n])\s).*return QString\("([a-zA-Z0-9_].*)"\);
				//\r\n\t\tcase $1\r\n\t\treturn QString("$2");

				//\r\n\tcase 3:\r\n\t\treturn current_monowave_class_ptr->D_ND_degree_vec[10].$1[index.column()];\r\n\t\tbreak;
				//case(?([^\r\n])\s)([a-zA-Z0-9_:].*)\r\n\t\t\treturn current_monowave_class_ptr->D_ND_degree_vec[10].([a-zA-Z0-9_:].*)[index.column()];\r\n\t\t\tbreak;

				//case(?([^\r\n])\s)([a-zA-Z0-9_:].*)\r\n\t\t\treturn current_monowave_class_ptr->D_ND_degree_vec\[10\]\.([a-zA-Z0-9_:].*)\[index\.column\(\)\];\r\n\t\t\tbreak;

			case 9:
				return QString("bidPrice_difference_Directional_D_up_main");


			case 10:
				return QString("bidPrice_difference_Directional_D_number_moves_up_main");


			case 11:
				return QString("bidPrice_difference_Directional_D_up_main_start");


			case 12:
				return QString("bidPrice_difference_Directional_D_up_main_continuation");


			case 13:
				return QString("bidPrice_difference_Directional_D_up_main_end");


			case 14:
				return QString("bidPrice_difference_Directional_D_up_main_confirmation");


			case 15:
				return QString("bidPrice_difference_Directional_D_up_main_new_price_action");


			case 16:
				return QString("bidPrice_difference_Directional_D_up_main_segment_time");


			case 17:
				return QString("bidPrice_difference_Directional_D_up_main_top");


			case 18:
				return QString("bidPrice_difference_Directional_D_up_main_bottom");



			case 19:
				return QString("bidPrice_difference_Directional_D_up_counter");


			case 20:
				return QString("bidPrice_difference_Directional_D_number_moves_up_counter");


			case 21:
				return QString("bidPrice_difference_Directional_D_up_counter_start");


			case 22:
				return QString("bidPrice_difference_Directional_D_up_counter_continuation");


			case 23:
				return QString("bidPrice_difference_Directional_D_up_counter_end");


			case 24:
				return QString("bidPrice_difference_Directional_D_up_counter_confirmation");



			case 25:
				return QString("bidPrice_difference_Directional_D_up_counter_new_price_action");


			case 26:
				return QString("bidPrice_difference_Directional_D_up_counter_segment_time");


			case 27:
				return QString("bidPrice_difference_Directional_D_up_counter_top");


			case 28:
				return QString("bidPrice_difference_Directional_D_up_counter_bottom");




			case 29:
				return QString("bidPrice_difference_Directional_D_down_main");


			case 30:
				return QString("bidPrice_difference_Directional_D_number_moves_down_main");


			case 31:
				return QString("bidPrice_difference_Directional_D_down_main_start");


			case 32:
				return QString("bidPrice_difference_Directional_D_down_main_continuation");


			case 33:
				return QString("bidPrice_difference_Directional_D_down_main_end");


			case 34:
				return QString("bidPrice_difference_Directional_D_down_main_confirmation");



			case 35:
				return QString("bidPrice_difference_Directional_D_down_main_new_price_action");


			case 36:
				return QString("bidPrice_difference_Directional_D_down_main_segment_time");


			case 37:
				return QString("bidPrice_difference_Directional_D_down_main_top");


			case 38:
				return QString("bidPrice_difference_Directional_D_down_main_bottom");




			case 39:
				return QString("bidPrice_difference_Directional_D_down_counter");


			case 40:
				return QString("bidPrice_difference_Directional_D_number_moves_down_counter");


			case 41:
				return QString("bidPrice_difference_Directional_D_down_counter_start");


			case 42:
				return QString("bidPrice_difference_Directional_D_down_counter_continuation");


			case 43:
				return QString("bidPrice_difference_Directional_D_down_counter_end");


			case 44:
				return QString("bidPrice_difference_Directional_D_down_counter_confirmation");



			case 45:
				return QString("bidPrice_difference_Directional_D_down_counter_new_price_action");


			case 46:
				return QString("bidPrice_difference_Directional_D_down_counter_segment_time");


			case 47:
				return QString("bidPrice_difference_Directional_D_down_counter_top");


			case 48:
				return QString("bidPrice_difference_Directional_D_down_counter_bottom");




			case 49:
				return QString("bidPrice_difference_NonDirectional_ND_up_main");


			case 50:
				return QString("bidPrice_difference_NonDirectional_ND_number_moves_up_main");


			case 51:
				return QString("bidPrice_difference_NonDirectional_ND_up_main_start");


			case 52:
				return QString("bidPrice_difference_NonDirectional_ND_up_main_continuation");


			case 53:
				return QString("bidPrice_difference_NonDirectional_ND_up_main_end");


			case 54:
				return QString("bidPrice_difference_NonDirectional_ND_up_main_confirmation");



			case 55:
				return QString("bidPrice_difference_Directional_ND_up_main_segment_time");


			case 56:
				return QString("bidPrice_difference_Directional_ND_up_main_top");


			case 57:
				return QString("bidPrice_difference_Directional_ND_up_main_bottom");


			case 58:
				return QString("bidPrice_difference_Directional_ND_up_main_span");



			case 59:
				return QString("bidPrice_difference_NonDirectional_ND_up_counter");


			case 60:
				return QString("bidPrice_difference_NonDirectional_ND_number_moves_up_counter");


			case 61:
				return QString("bidPrice_difference_NonDirectional_ND_up_counter_start");


			case 62:
				return QString("bidPrice_difference_NonDirectional_ND_up_counter_continuation");


			case 63:
				return QString("bidPrice_difference_NonDirectional_ND_up_counter_end");


			case 64:
				return QString("bidPrice_difference_NonDirectional_ND_up_counter_confirmation");



			case 65:
				return QString("bidPrice_difference_Directional_ND_up_counter_segment_time");


			case 66:
				return QString("bidPrice_difference_Directional_ND_up_counter_top");


			case 67:
				return QString("bidPrice_difference_Directional_ND_up_counter_bottom");


			case 68:
				return QString("bidPrice_difference_Directional_ND_up_counter_span");





			case 69:
				return QString("bidPrice_difference_NonDirectional_ND_down_main");


			case 70:
				return QString("bidPrice_difference_NonDirectional_ND_number_moves_down_main");


			case 71:
				return QString("bidPrice_difference_NonDirectional_ND_down_main_start");


			case 72:
				return QString("bidPrice_difference_NonDirectional_ND_down_main_continuation");


			case 73:
				return QString("bidPrice_difference_NonDirectional_ND_down_main_end");


			case 74:
				return QString("bidPrice_difference_NonDirectional_ND_down_main_confirmation");



			case 75:
				return QString("bidPrice_difference_Directional_ND_down_main_segment_time");


			case 76:
				return QString("bidPrice_difference_Directional_ND_down_main_top");


			case 77:
				return QString("bidPrice_difference_Directional_ND_down_main_bottom");


			case 78:
				return QString("bidPrice_difference_Directional_ND_down_main_span");




			case 79:
				return QString("bidPrice_difference_NonDirectional_ND_down_counter");


			case 80:
				return QString("bidPrice_difference_NonDirectional_ND_number_moves_down_counter");


			case 81:
				return QString("bidPrice_difference_NonDirectional_ND_down_counter_start");


			case 82:
				return QString("bidPrice_difference_NonDirectional_ND_down_counter_continuation");


			case 83:
				return QString("bidPrice_difference_NonDirectional_ND_down_counter_end");


			case 84:
				return QString("bidPrice_difference_NonDirectional_ND_down_counter_confirmation");



			case 85:
				return QString("bidPrice_difference_Directional_ND_down_counter_segment_time");


			case 86:
				return QString("bidPrice_difference_Directional_ND_down_counter_top");


			case 87:
				return QString("bidPrice_difference_Directional_ND_down_counter_bottom");


			case 88:
				return QString("bidPrice_difference_Directional_ND_down_counter_span");

				//2/5/2021


			case 89:
				return QString("bidPrice_difference_undetermined_degree");

			

			}
		}
		return QVariant();
	
};


/*
#include <QtGui>

class MatrixModel : public QAbstractTableModel
{
public:
    MatrixModel(int numRows, int numColumns, double* data)
        : m_numRows(numRows),
          m_numColumns(numColumns),
          m_data(data)
    {
    }

    int rowCount(const QModelIndex& parent = QModelIndex()) const
    {
        return m_numRows;
    }

    int columnCount(const QModelIndex& parent = QModelIndex()) const
    {
        return m_numColumns;
    }

    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const
    {
        if (!index.isValid() || role != Qt::DisplayRole)
            return QVariant();

        // Return the data to which index points.
        return m_data[index.row() * m_numColumns + index.column()];
    }

private:
    int m_numRows;
    int m_numColumns;
    double* m_data;
};


*/

