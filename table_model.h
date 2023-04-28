#ifndef TABLE_MODEL_H
#define TABLE_MODEL_H

#include <QAbstractTableModel>
#include "./csv_to_monowave/csv_min_time_with_price_difference.h"

//class csv_to_monowave_bin;
class MatrixModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    MatrixModel(csv_min_time_with_price_difference* ,QObject* parent = nullptr);
    MatrixModel(QObject* parent = nullptr);

    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    int columnCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index, int role ) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;

private:
    //int m_numRows=84;
    int m_numRows = 89;

    int m_numColumns;
    double* m_data;
public:
    csv_min_time_with_price_difference* current_monowave_class_ptr = nullptr;
    //csv_to_monowave_bin* csv_to_monowave_ptr;
};


#endif //TABLE_MODEL_H