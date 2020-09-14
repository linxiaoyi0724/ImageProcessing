#include <qmainwindow.h>
#include <QtGui>
#include <QtWidgets>
#include "MainWindow.h"
#pragma execution_character_set("utf-8")

ImageProcess::ImageProcess(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	this->resize(400, 400);


	setWindowTitle("图像处理自编软件 by小轶");

	setWindowIcon(QIcon("../Imgae/icon/ImageProcess.png"));

	resize(QApplication::desktop()->width()*0.9, QApplication::desktop()->height()*0.9);
	move(QApplication::desktop()->width()*0.05, QApplication::desktop()->height()*0.01);


	QMenu *menu1 = menuBar()->addMenu(tr("菜单栏1"));
	QAction* act1 = new QAction(QIcon("../Imgae/icon/ImageProcess.png"), tr("子菜单"), this);
	//如果想自定义快捷键，可以设置为act->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_N));
	act1->setShortcuts(QKeySequence::New);
	connect(act1, SIGNAL(triggered()), this, SLOT(pSlot1()));
	menu1->addAction(act1);


	QMenu *menu2 = menuBar()->addMenu(tr("菜单栏2"));
	QAction *act2 = new QAction(QIcon("../Imgae/icon/ImageProcess.png"), tr("一级菜单"), this);

	QMenu *submenu = new QMenu();
	QAction *subact = new QAction(QIcon("../Imgae/icon/ImageProcess.png"), tr("二级菜单"), this);
	submenu->addAction(subact);
	connect(subact, SIGNAL(triggered()), this, SLOT(subSlot()));

	act2->setMenu(submenu);
	menu2->addAction(act2);


	ui.mainToolBar->addAction(act1);

	QToolBar *toolBar = new QToolBar();
	toolBar->setMovable(false);
	addToolBar(toolBar);

	QPushButton *button = new QPushButton();
	button->setText("控件");

	toolBar->addAction(subact);
	toolBar->addWidget(button);

	act1->setStatusTip(tr("子菜单"));
	act2->setStatusTip(tr("一级菜单"));
	subact->setStatusTip(tr("二级菜单"));

	//connect(this, SIGNAL(ISignal(int, float)), this, SLOT(ISlot()));
	//emit ISignal(1000,0.3);

	//HelloWorld();
}

ImageProcess::~ImageProcess()
{

}

void ImageProcess::HelloWorld()
{
	QPushButton *button = new QPushButton(this);
	button->setText(tr("你好，QT！"));
	button->move(100, 100);
	connect(button, SIGNAL(clicked()), this, SLOT(ISlot()));
}

void ImageProcess::ISlot()
{
	/*QMessageBox::information(this, tr("hello"), tr("Hello World!"));*/

	QString qString = "Qt test (signal & slots)";
	qDebug() << qString;
	//qDebug() << qString.number(b);
}
