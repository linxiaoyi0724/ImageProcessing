#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_ImageProcess.h"

class ImageProcess : public QMainWindow
{
	Q_OBJECT

public:
	ImageProcess(QWidget *parent = Q_NULLPTR);
	~ImageProcess();

	void HelloWorld();

private:
	Ui::ImageProcessClass ui;


signals:
	void ISignal(int a, float b);

private slots:
	void ISlot();
};
