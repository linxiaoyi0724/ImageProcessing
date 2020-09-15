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


	//setWindowTitle("图像处理自编软件 by小轶");

	//setWindowIcon(QIcon("../Imgae/icon/ImageProcess.png"));

	//resize(QApplication::desktop()->width()*0.9, QApplication::desktop()->height()*0.9);
	//move(QApplication::desktop()->width()*0.05, QApplication::desktop()->height()*0.01);


	//QMenu *menu1 = menuBar()->addMenu(tr("菜单栏1"));
	//QAction* act1 = new QAction(QIcon("../Imgae/icon/ImageProcess.png"), tr("子菜单"), this);
	////如果想自定义快捷键，可以设置为act->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_N));
	//act1->setShortcuts(QKeySequence::New);
	//connect(act1, SIGNAL(triggered()), this, SLOT(pSlot1()));
	//menu1->addAction(act1);


	//QMenu *menu2 = menuBar()->addMenu(tr("菜单栏2"));
	//QAction *act2 = new QAction(QIcon("../Imgae/icon/ImageProcess.png"), tr("一级菜单"), this);

	//QMenu *submenu = new QMenu();
	//QAction *subact = new QAction(QIcon("../Imgae/icon/ImageProcess.png"), tr("二级菜单"), this);
	//submenu->addAction(subact);
	//connect(subact, SIGNAL(triggered()), this, SLOT(subSlot()));

	//act2->setMenu(submenu);
	//menu2->addAction(act2);

	//ui.mainToolBar->addAction(act1);

	//QToolBar *toolBar = new QToolBar();
	//toolBar->setMovable(false);
	//addToolBar(toolBar);

	//QPushButton *button = new QPushButton();
	//button->setText("控件");

	//toolBar->addAction(subact);
	//toolBar->addWidget(button);

	//act1->setStatusTip(tr("子菜单"));
	//act2->setStatusTip(tr("一级菜单"));
	//subact->setStatusTip(tr("二级菜单"));

	////connect(this, SIGNAL(ISignal(int, float)), this, SLOT(ISlot()));
	////emit ISignal(1000,0.3);

	////HelloWorld();
}

ImageProcess::~ImageProcess()
{

}

void ImageProcess::Menu_File()
{
	QMenu *file = menuBar()->addMenu(tr("文件"));

	QAction *act_file_new = new QAction(QIcon("../Imgae/icon/ImageProcess.png"), tr("新建"), this);
	act_file_new->setShortcut(QKeySequence::New);
	connect(act_file_new, SIGNAL(triggered()), this, SLOT(File_new()));

	QAction *act_file_open = new QAction(QIcon("../Imgae/icon/ImageProcess.png"), tr("打开"), this);
	act_file_open->setShortcut(QKeySequence::Open);
	connect(act_file_open, SIGNAL(triggered()), this, SLOT(File_open()));

	QAction *act_file_save = new QAction(QIcon("../Imgae/icon/ImageProcess.png"), tr("保存"),this);
	act_file_save->setShortcut(QKeySequence::Save);
	connect(act_file_save, SIGNAL(triggered()), this, SLOT(File_save()));

	QAction *act_file_saveas = new QAction(QIcon("../Imgae/icon/ImageProcess.png"), tr("另存为"), this);
	act_file_saveas->setShortcut(QKeySequence::SaveAs);
	connect(act_file_saveas, SIGNAL(triggered()), this, SLOT(File_saveas()));

	QAction *act_file_close = new QAction(QIcon("../Imgae/icon/ImageProcess.png"), tr("关闭"), this);
	act_file_close->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_F4));
	connect(act_file_close, SIGNAL(triggered()), this, SLOT(close()));

	//菜单栏
	file->addAction(act_file_new);
	file->addAction(act_file_open);
	file->addAction(act_file_save);
	file->addAction(act_file_saveas);
	file->addSeparator(); //添加分割线
	file->addAction(act_file_close);

	//工具栏
	ui.mainToolBar->addAction(act_file_new);
	ui.mainToolBar->addAction(act_file_open);
	ui.mainToolBar->addAction(act_file_save);


	//任务栏
	act_file_new->setStatusTip(tr("新建图像"));
	act_file_open->setStatusTip(tr("打开图像"));
	act_file_save->setStatusTip(tr("保存图像"));
	act_file_saveas->setStatusTip(tr("图像另存为"));
	act_file_close->setStatusTip(tr("关闭软件"));
}

void ImageProcess::InitImage()
{
	//QWidget* p = takeCentralWidget();
	//if (p)
	//	delete p;
	//setDockNestingEnabled(true);

	//dock_Image = new QDockWidget(tr("图像"), this);
	QDockWidget* dock_Image = new QDockWidget(tr("图像"), this);
	dock_Image->setFeatures(QDockWidget::DockWidgetMovable | QDockWidget::DockWidgetFloatable);
	dock_Image->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
	dock_Image->setMinimumSize(600, 600);

	dock_Tool = new QDockWidget(tr("工具箱"), this);
	dock_Geom = new QDockWidget(tr("几何变换"), this);
	dock_Gray = new QDockWidget(tr("灰度变换"), this);
	dock_Enhance = new QDockWidget(tr("图像增强"), this);
	dock_Morp = new QDockWidget(tr("形态学处理"), this);
	dock_Color = new QDockWidget(tr("颜色模型"), this);
	dock_Prop = new QDockWidget(tr("属性"), this);
	dock_Output = new QDockWidget(tr("输出"), this);

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
	QString path = QFileDialog::getOpenFileName(this, tr("选择图像"), ".", tr("Images(*.jpg *.png *.bmp)"));
	if (!path.isEmpty())
	{
		QImage *img = new QImage();
		if (!(img->load(path)))
		{
			QMessageBox::information(this, tr("错误"), tr("打开图像失败"));
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
		QString path = QFileDialog::getSaveFileName(this, tr("保存图像"), ".", tr("Images(*.jpg *.png *.bmp)"));
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
	QString path = QFileDialog::getSaveFileName(this, tr("图像另存为"), ".", tr("Images(*.jpg *.png *.bmp)"));
	if (!path.isEmpty())
	{
		QImage img = imgLabel->pixmap()->toImage();
		img.save(path);
		currentPath = path;
	}
}