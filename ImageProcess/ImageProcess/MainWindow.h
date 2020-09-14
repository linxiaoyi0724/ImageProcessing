#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_ImageProcess.h"

class ImageProcess : public QMainWindow
{
	Q_OBJECT

public:
	ImageProcess(QWidget *parent = Q_NULLPTR);
	~ImageProcess();


private:
	Ui::ImageProcessClass ui;

	QDockWidget *dock_Image;
	QString currentPath;
	QLabel *imageLabel;
	void InitImage();
	void Menu_File();

private slots:
	void File_new();
	void File_open();
	void File_save();
	void File_saveas();
};
