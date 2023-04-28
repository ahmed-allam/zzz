#ifndef TABDIALOG_H
#define TABDIALOG_H
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QWidget>
#include "tableView_custom.h"

//allam 16-9-2022
//#include "tab_dialog0.h"
#include <QDialog>
#include "./csv_to_monowave/csv_min_time_with_price_difference.h"
#include "table_model.h"
#include "global.h"
#include "plot.h"

//allam 16-9-2022
//#include "tab_dialog0.h"
/*
QT_BEGIN_NAMESPACE
class QDialogButtonBox;
class QFileInfo;
class QTabWidget;
QT_END_NAMESPACE

//! [0]
class GeneralTab : public QWidget
{
    Q_OBJECT

public:
    explicit GeneralTab(const QFileInfo& fileInfo, QWidget* parent = nullptr);
};
//! [0]


//! [1]
class PermissionsTab : public QWidget
{
    Q_OBJECT

public:
    explicit PermissionsTab(const QFileInfo& fileInfo, QWidget* parent = nullptr);
};
//! [1]


//! [2]
class ApplicationsTab : public QWidget
{
    Q_OBJECT

public:
    explicit ApplicationsTab(const QFileInfo& fileInfo, QWidget* parent = nullptr);
};
//! [2]
*/

//! [3]

class qtTab;
class tabWidget : public QTabWidget
{
    Q_OBJECT

public:
    //explicit TabDialog(const QString& fileName, QWidget* parent = nullptr);
    explicit tabWidget(int width, int height, QWidget* parent = nullptr);
public slots:
    //void showRowHeaderName(QString Input) const;
    void plottingGraph(csv_min_time_with_price_difference* current_monowave_class_ptr, int degree);
    void updatingTable(csv_min_time_with_price_difference* current_monowave_class_ptr, int degree);

    //void pushButtonClicked();
private:
    //QTabWidget* tabWidget;
    //QDialogButtonBox* buttonBox;
    int screen_width, screen_height;
    int Degree_minus10, Degree_minus9, Degree_minus8, Degree_minus7, Degree_minus6, Degree_minus5, Degree_minus4, Degree_minus3, Degree_minus2, Degree_minus1, Degree0, Degree1, Degree2, Degree3, Degree4, Degree5, Degree6, Degree7, Degree8, Degree9, Degree10;
    std::vector<qtTab*> tab_ptr_vector;
    csv_min_time_with_price_difference* csv_to_monowave_vectors_pointer_m;

};
//! [3]


//allam 16-9-2022
//! [2]
class qtTab : public QWidget
{
    Q_OBJECT

public:
    explicit qtTab(int width, int height, QWidget* parent = nullptr);

public slots:
    void showRowHeaderName(QString Input) const;
    void updatingTable(csv_min_time_with_price_difference* current_monowave_class_ptr);
    void plottingGraph(csv_min_time_with_price_difference* current_monowave_class_ptr);

    void pushButtonClicked();
public:
    QVBoxLayout* layout_;
    QGridLayout* layout_H_label;
    QVBoxLayout* layout_V_table;
    QVBoxLayout* layout_V_plot;
    QSplitter* splitter;
    QLabel* label_;
    TableView* tableView_;
    QPushButton* pushButton;
    //QWidget* TransformPlot_;
    Plot* Plot_;
    MatrixModel* model_;
    int screen_width, screen_height;

    csv_min_time_with_price_difference* csv_to_monowave_vectors_pointer_m;
    int Size = 0;
    const double* xData;
    const double* yData;
    const unsigned int* yData_unsigned_int;
    std::vector<double> yData_vec;
    std::vector<double> x;
    QwtPlotCurve* curve;


};
//! [2]
#endif