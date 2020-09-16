#pragma once

#include <QtWidgets/QMainWindow>
#include <QtGui>
#include <QtWidgets>
#include <qmainwindow.h>
#include "ui_ImageProcess.h"

class ImageProcess : public QMainWindow
{
	Q_OBJECT

public:
	ImageProcess(QWidget *parent = Q_NULLPTR);
	~ImageProcess();


private:
	Ui::ImageProcessClass ui;

	QScrollArea* scrollArea = new QScrollArea(this);

	QDockWidget *dock_Image;
	QDockWidget *dock_Tool;
	QDockWidget *dock_Geom;
	QDockWidget *dock_Gray;
	QDockWidget *dock_Enhance;
	QDockWidget *dock_Morp;
	QDockWidget *dock_Color;
	QDockWidget *dock_Prop;
	QDockWidget* dock_Output;

	QString currentPath;
	QLabel *imgLabel;
	void InitImage();
	void Menu_File();
	

private slots:
	void File_new();
	void File_open();
	void File_save();
	void File_saveas();

	void showWin();
	void FullSize();
	void AutoSize();
};
