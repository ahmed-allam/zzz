#ifndef HEADER_VIEW_CUSTOM_H
#define HEADER_VIEW_CUSTOM_H

#include <QWidget>
#include <QHeaderView>

class header_view_custom : public QHeaderView {
	Q_OBJECT

public:

	header_view_custom(Qt::Orientation orientation, QWidget* parent = nullptr);
	QSize sizeHint() const;
	QSize minimumsizeHint() const;

};

#endif // HEADER_VIEW_CUSTOM_H
