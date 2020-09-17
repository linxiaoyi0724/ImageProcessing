#include <QtGui>
#include <QtWidgets>
#include <qmainwindow.h>
#include "../header/PaintWidget.h"

PaintWidget::PaintWidget(QWidget *parent) :QLabel(parent)
{
	isDrawing = false;
}

void PaintWidget::setImage(QImage& img)
{
	image = img;
	tempImage = image;
}

QImage PaintWidget::getImage()
{
	if (image.isNull() != true)
	{
		return image;
	}
}

void PaintWidget::setShape(PaintWidget::shape t)
{
	type = t;
}

void PaintWidget::setPenwidth(int w)
{
	penWidth = w;
}

void PaintWidget::setPenColor(QColor c)
{
	penColor = c;
}

void PaintWidget::paintEvent(QPaintEvent*)
{
	QPainter painter(this);
	if (isDrawing == true)
	{
		painter.drawImage(0, 0, tempImage);
	}
	else
	{
		painter.drawImage(0, 0, image);
	}
}

void PaintWidget::mousePressEvent(QMouseEvent *event)
{
	if (event->button() == Qt::LeftButton)
	{
		lastPoint = event->pos();
		isDrawing = true;
	}
}

void PaintWidget::mouseMoveEvent(QMouseEvent *event)
{
	if (event->buttons() & Qt::LeftButton)
	{
		endPoint = event->pos();
		tempImage = image;
		if (type == Pen)
		{
			paint(image);
		}
		else
		{
			paint(tempImage);
		}
	}
}

void PaintWidget::mouseReleaseEvent(QMouseEvent *event)
{
	isDrawing = false;
	if (type != Pen)
	{
		paint(image);
	}
}

void PaintWidget::paint(QImage &theImage)
{
	QPainter p(&theImage);
	QPen apen;
	apen.setWidth(4);
	apen.setColor(penColor);

	p.setPen(apen);
	p.setRenderHint(QPainter::Antialiasing, true);

	int x1, y1, x2, y2;
	x1 = lastPoint.x();
	y1 = lastPoint.y();
	x2 = endPoint.x();
	y2 = endPoint.y();

	switch (type)
	{
	case PaintWidget::Pen:
	{
		p.drawLine(lastPoint, endPoint);
		lastPoint = endPoint;
		break;
	}
	case PaintWidget::Line:
	{
		p.drawLine(lastPoint, endPoint);
		break;
	}
	case PaintWidget::Ellipse:
	{
		p.drawEllipse(x1, y1, x2 - x1, y2 - y1);
		break;
	}
	case PaintWidget::Circle:
	{
		double length = (x2 - x1) > (y2 - y1) ? (x2 - x1) : (y2 - y1);
		p.drawEllipse(x1, y1, length, length);
		break;
	}
	case PaintWidget::Triangle:
	{
		int top, buttom, left, right;
		top = (y1 < y2) ? y1 : y2;
		buttom = (y1 > y2) ? y1 : y2;
		left = (x1 < x2) ? x1 : x2;
		right = (x1 > x2) ? x1 : x2;

		if (y1 < y2)
		{
			QPoint points[3] = { QPoint(left, buttom), QPoint(right, buttom), QPoint((right + left) / 2, top) };
			p.drawPolygon(points, 3);
		}
		else
		{
			QPoint points[3] = { QPoint(left, top),QPoint(right, top), QPoint((left + right) / 2,buttom) };
			p.drawPolygon(points, 3);
		}
		break;
	}
	case PaintWidget::Rhombus:
	{
		int top, buttom, left, right;
		top = (y1 < y2) ? y1 : y2;
		buttom = (y1 > y2) ? y1 : y2;
		left = (x1 < x2) ? x1 : x2;
		right = (x1 > x2) ? x1 : x2;

		QPoint points[4] = { QPoint(left, (top + buttom) / 2), QPoint((left + right) / 2, buttom), QPoint(right,(top + buttom) / 2),QPoint((left + right) / 2,top) };
		p.drawPolygon(points, 4);
		break;
	}
	case PaintWidget::Rect:
	{
		p.drawRect(x1, y1, x2 - x1, y2 - y1);
		break;
	}
	case PaintWidget::Square:
	{
		double length = (x2 - x1) > (y2 - y1) ? (x2 - x1) : (y2 - y1);
		p.drawRect(x1, y1, length, length);
		break;
	}
	case PaintWidget::Hexagon:
	{
		QPoint points[6] = { QPoint(x1, y1), QPoint(x2,y1), QPoint((3 * x2 - x1) / 2,(y1 + y2) / 2), QPoint(x2,y2),QPoint(x1,y2), QPoint((3 * x1 - x2) / 2,(y1 + y2) / 2) };
		p.drawPolygon(points, 6);
		break;
	}
	case PaintWidget::Null:
	{
		;
	}
	default:
		break;
	}
	update();
}