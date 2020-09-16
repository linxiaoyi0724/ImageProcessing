#include <QtGui>
#include <QtWidgets>
#include <qmenubar.h>
#include <qmainwindow.h>
#include "../header/CustomWindow.h"

CustomWindow::CustomWindow(QWidget* parent)
{
	mMoveing = false;
	setWindowFlags(Qt::FramelessWindowHint | Qt::WindowMinimizeButtonHint | Qt::WindowStaysOnTopHint);
}

CustomWindow::~CustomWindow()
{

}

void CustomWindow::mousePressEvent(QMouseEvent *event)
{
	mMoveing = true;
	mMovePosition = event->globalPos() - pos();
	return QDialog::mousePressEvent(event);
}

void CustomWindow::mouseMoveEvent(QMouseEvent *event)
{
	if (mMoveing && (event->buttons() && Qt::LeftButton) && (event->globalPos() - mMovePosition).manhattanLength() > QApplication::startDragDistance())
	{
		move(event->globalPos() - mMovePosition);
		mMovePosition = event->globalPos() - pos();
	}
	return QDialog::mouseMoveEvent(event);
}

void CustomWindow::mouseReleaseEvent(QMouseEvent *event)
{
	mMoveing = false;
}