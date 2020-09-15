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

	QAction *act_file_saveas = new QAction(QIcon("../Imgae/icon/ImageProcess.png"), tr("���Ϊ"), this);
	act_file_saveas->setShortcut(QKeySequence::SaveAs);
	connect(act_file_saveas, SIGNAL(triggered()), this, SLOT(File_saveas()));

	QAction *act_file_close = new QAction(QIcon("../Imgae/icon/ImageProcess.png"), tr("�ر�"), this);
	act_file_close->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_F4));
	connect(act_file_close, SIGNAL(triggered()), this, SLOT(close()));

	//�˵���
	file->addAction(act_file_new);
	file->addAction(act_file_open);
	file->addAction(act_file_save);
	file->addAction(act_file_saveas);
	file->addSeparator(); //��ӷָ���
	file->addAction(act_file_close);

	//������
	ui.mainToolBar->addAction(act_file_new);
	ui.mainToolBar->addAction(act_file_open);
	ui.mainToolBar->addAction(act_file_save);


	//������
	act_file_new->setStatusTip(tr("�½�ͼ��"));
	act_file_open->setStatusTip(tr("��ͼ��"));
	act_file_save->setStatusTip(tr("����ͼ��"));
	act_file_saveas->setStatusTip(tr("ͼ�����Ϊ"));
	act_file_close->setStatusTip(tr("�ر����"));
}

void ImageProcess::InitImage()
{
	//QWidget* p = takeCentralWidget();
	//if (p)
	//	delete p;
	//setDockNestingEnabled(true);

	//dock_Image = new QDockWidget(tr("ͼ��"), this);
	QDockWidget* dock_Image = new QDockWidget(tr("ͼ��"), this);
	dock_Image->setFeatures(QDockWidget::DockWidgetMovable | QDockWidget::DockWidgetFloatable);
	dock_Image->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
	dock_Image->setMinimumSize(600, 600);

	dock_Tool = new QDockWidget(tr("������"), this);
	dock_Geom = new QDockWidget(tr("���α任"), this);
	dock_Gray = new QDockWidget(tr("�Ҷȱ任"), this);
	dock_Enhance = new QDockWidget(tr("ͼ����ǿ"), this);
	dock_Morp = new QDockWidget(tr("��̬ѧ����"), this);
	dock_Color = new QDockWidget(tr("��ɫģ��"), this);
	dock_Prop = new QDockWidget(tr("����"), this);
	dock_Output = new QDockWidget(tr("���"), this);

	setCentralWidget(dock_Image);
	addDockWidget(Qt::LeftDockWidgetArea, dock_Tool);
	addDockWidget(Qt::BottomDockWidgetArea, dock_Output);
	addDockWidget(Qt::RightDockWidgetArea, dock_Geom);
	addDockWidget(Qt::RightDockWidgetArea, dock_Gray);
	addDockWidget(Qt::RightDockWidgetArea, dock_Enhance);
	addDockWidget(Qt::RightDockWidgetArea, dock_Morp);
	addDockWidget(Qt::RightDockWidgetArea, dock_Color);
	addDockWidget(Qt::RightDockWidgetArea, dock_Prop);


	splitDockWidget(dock_Tool, dock_Image, Qt::Horizontal);
	splitDockWidget(dock_Geom, dock_Output, Qt::Vertical);

	tabifyDockWidget(dock_Geom, dock_Gray);
	tabifyDockWidget(dock_Gray, dock_Enhance);
	tabifyDockWidget(dock_Enhance, dock_Morp);
	tabifyDockWidget(dock_Morp, dock_Color);
	tabifyDockWidget(dock_Output, dock_Prop);

	dock_Geom->raise();


	imgLabel = new QLabel(dock_Image);
	imgLabel->setScaledContents(true);

	QImage image = QImage(500, 500, QImage::Format_RGB32);
	image.fill(qRgb(255, 255, 255));
	imgLabel->setPixmap(QPixmap::fromImage(image));
	imgLabel->resize(image.width(), image.height());


	QScrollArea* scrollArea = new QScrollArea(this);
	scrollArea->setBackgroundRole(QPalette::Dark);
	scrollArea->setAlignment(Qt::AlignCenter);
	scrollArea->setWidget(imgLabel);
	dock_Image->setWidget(scrollArea);
}

void ImageProcess::File_new()
{
	QImage image = QImage(500, 500, QImage::Format_RGB32);
	image.fill(qRgb(255, 255, 255));
	imgLabel->setPixmap(QPixmap::fromImage(image));
	imgLabel->resize(image.width(), image.height());
	currentPath = "";
}

void ImageProcess::File_open()
{
	QString path = QFileDialog::getOpenFileName(this, tr("ѡ��ͼ��"), ".", tr("Images(*.jpg *.png *.bmp)"));
	if (!path.isEmpty())
	{
		QImage *img = new QImage();
		if (!(img->load(path)))
		{
			QMessageBox::information(this, tr("����"), tr("��ͼ��ʧ��"));
			delete img;
			return;
		}
		imgLabel->setPixmap(QPixmap::fromImage(*img));
		imgLabel->resize(img->width(), img->height());
		currentPath = path;
	}
}

void ImageProcess::File_save()
{
	if (currentPath.isEmpty())
	{
		QString path = QFileDialog::getSaveFileName(this, tr("����ͼ��"), ".", tr("Images(*.jpg *.png *.bmp)"));
		{
			if (!path.isEmpty())
				currentPath = path;
		}
	}
	QImage img = imgLabel->pixmap()->toImage();
	img.save(currentPath);
}

void ImageProcess::File_saveas()
{
	QString path = QFileDialog::getSaveFileName(this, tr("ͼ�����Ϊ"), ".", tr("Images(*.jpg *.png *.bmp)"));
	if (!path.isEmpty())
	{
		QImage img = imgLabel->pixmap()->toImage();
		img.save(path);
		currentPath = path;
	}
}