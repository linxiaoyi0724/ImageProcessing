#include <qmainwindow.h>
#include <QtGui>
#include <QtWidgets>
#include "MainWindow.h"
#pragma execution_character_set("utf-8")

ImageProcess::ImageProcess(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	Menu_File();
	InitImage();




	//this->resize(400, 400);


	//setWindowTitle("ͼ�����Ա���� byС��");

	//setWindowIcon(QIcon("../Imgae/icon/ImageProcess.png"));

	//resize(QApplication::desktop()->width()*0.9, QApplication::desktop()->height()*0.9);
	//move(QApplication::desktop()->width()*0.05, QApplication::desktop()->height()*0.01);


	//QMenu *menu1 = menuBar()->addMenu(tr("�˵���1"));
	//QAction* act1 = new QAction(QIcon("../Imgae/icon/ImageProcess.png"), tr("�Ӳ˵�"), this);
	////������Զ����ݼ�����������Ϊact->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_N));
	//act1->setShortcuts(QKeySequence::New);
	//connect(act1, SIGNAL(triggered()), this, SLOT(pSlot1()));
	//menu1->addAction(act1);


	//QMenu *menu2 = menuBar()->addMenu(tr("�˵���2"));
	//QAction *act2 = new QAction(QIcon("../Imgae/icon/ImageProcess.png"), tr("һ���˵�"), this);

	//QMenu *submenu = new QMenu();
	//QAction *subact = new QAction(QIcon("../Imgae/icon/ImageProcess.png"), tr("�����˵�"), this);
	//submenu->addAction(subact);
	//connect(subact, SIGNAL(triggered()), this, SLOT(subSlot()));

	//act2->setMenu(submenu);
	//menu2->addAction(act2);

	//ui.mainToolBar->addAction(act1);

	//QToolBar *toolBar = new QToolBar();
	//toolBar->setMovable(false);
	//addToolBar(toolBar);

	//QPushButton *button = new QPushButton();
	//button->setText("�ؼ�");

	//toolBar->addAction(subact);
	//toolBar->addWidget(button);

	//act1->setStatusTip(tr("�Ӳ˵�"));
	//act2->setStatusTip(tr("һ���˵�"));
	//subact->setStatusTip(tr("�����˵�"));

	////connect(this, SIGNAL(ISignal(int, float)), this, SLOT(ISlot()));
	////emit ISignal(1000,0.3);

	////HelloWorld();
}

ImageProcess::~ImageProcess()
{

}

void ImageProcess::Menu_File()
{
	QMenu *file = menuBar()->addMenu(tr("�ļ�"));

	QAction *act_file_new = new QAction(QIcon("../Imgae/icon/ImageProcess.png"), tr("�½�"), this);
	act_file_new->setShortcut(QKeySequence::New);
	connect(act_file_new, SIGNAL(triggered()), this, SLOT(File_new()));

	QAction *act_file_open = new QAction(QIcon("../Imgae/icon/ImageProcess.png"), tr("��"), this);
	act_file_open->setShortcut(QKeySequence::Open);
	connect(act_file_open, SIGNAL(triggered()), this, SLOT(File_open()));

	QAction *act_file_save = new QAction(QIcon("../Imgae/icon/ImageProcess.png"), tr("����"),this);
	act_file_save->setShortcut(QKeySequence::Save);
	connect(act_file_save, SIGNAL(triggered()), this, SLOT(File_save()));



}
