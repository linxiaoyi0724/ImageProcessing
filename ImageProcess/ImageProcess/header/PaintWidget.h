#pragma once

#include <QtGui>
#include <QtWidgets>
#include <qmainwindow.h>

class PaintWidget : public QLabel
{
	Q_OBJECT
public:
	explicit PaintWidget(QWidget* parent = 0);
	enum shape
	{
		Pen = 1, Line, Ellipse, Circle, Triangle, Rhombus, Rect, Square, Hexagon, Null
	};

	void paint(QImage &theImage);
	void setImage(QImage &img);
	QImage getImage();

	void setShape(PaintWidget::shape);
	void setPenwidth(int w);
	void setPenColor(QColor c);


protected:
	void paintEvent(QPaintEvent*);
	void mousePressEvent(QMouseEvent*);
	void mouseMoveEvent(QMouseEvent*);
	void mouseReleaseEvent(QMouseEvent*);

private:
	PaintWidget::shape type;
	int penWidth;
	QColor penColor;
	QImage image;
	QImage tempImage;
	QPoint lastPoint;
	QPoint endPoint;
	bool isDrawing;
};