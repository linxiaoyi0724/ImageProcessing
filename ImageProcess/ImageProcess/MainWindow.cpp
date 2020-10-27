#include <qmainwindow.h>
#include <QtGui>
#include <QtWidgets>
#include "MainWindow.h"
#include "header/CustomWindow.h"
#pragma execution_character_set("utf-8")

ImageProcess::ImageProcess(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	Menu_File();
	InitImage();

	ToolWin();




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

	QPushButton *button_full = new QPushButton(tr("铺满窗口"));
	QPushButton *button_auto = new QPushButton(tr("自适应窗口"));
	//button_full->setStyleSheet("background-color:blue;");

	connect(button_full, SIGNAL(clicked()), this, SLOT(FullSize()));
	connect(button_auto, SIGNAL(clicked()), this, SLOT(AutoSize()));

	ui.mainToolBar->addWidget(button_full);
	ui.mainToolBar->addWidget(button_auto);

	QPushButton *button_about = new QPushButton(tr("关于"));
	connect(button_about, SIGNAL(clicked()), this, SLOT(showWin()));
	ui.mainToolBar->addWidget(button_about);

	colorBtn = new QPushButton(tr("画笔颜色"));
	connect(colorBtn, SIGNAL(clicked()), this, SLOT(setColor()));


	//colorFram = new QFrame(ui.mainToolBar);
	//colorFram->setFrameShape(QFrame::Box);
	//colorFram->setPalette(QPalette(Qt::black));
	//colorFram->setAutoFillBackground(true);
	//colorFram->setFixedSize(25, 25);
	ui.mainToolBar->addWidget(colorBtn);
	
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


	imgLabel = new PaintWidget(dock_Image);
	imgLabel->setScaledContents(true);

	QImage image = QImage(500, 500, QImage::Format_RGB32);
	image.fill(qRgb(255, 255, 255));
	imgLabel->setPixmap(QPixmap::fromImage(image));
	imgLabel->setImage(image);
	imgLabel->resize(image.width(), image.height());


	//QScrollArea* scrollArea = new QScrollArea(this);
	scrollArea->setBackgroundRole(QPalette::Dark);
	scrollArea->setAlignment(Qt::AlignCenter);
	scrollArea->setWidget(imgLabel);
	dock_Image->setWidget(scrollArea);


	QLabel *label = new QLabel(tr("label"), dock_Geom);
	QPushButton *button = new QPushButton(tr("按钮"), dock_Geom);
	//button->setFlat(true);
	connect(button, SIGNAL(clicked()), this, SLOT(slot_button));

	QLabel *labelMove = new QLabel(tr("labelMove"),dock_Geom);
	QMovie *pMovie = new QMovie("../Imgae/aaa.gif");
	labelMove->setMovie(pMovie);
	labelMove->setFixedSize(135, 200);
	labelMove->setScaledContents(true);
	pMovie->start();

	QLineEdit *lineEdit = new QLineEdit(tr("Line"), dock_Geom);
	lineEdit->setReadOnly(true);
	//lineEdit->selectAll();

	QTextEdit *textEdit = new QTextEdit(tr("Text"), dock_Geom);
	textEdit->textCursor().movePosition(QTextCursor::End);
	textEdit->setWordWrapMode(QTextOption::NoWrap);
	textEdit->setReadOnly(true);
	textEdit->append("第一行");
	textEdit->append("第二行");
	textEdit->append("第二行");
	textEdit->append("第二行");
	textEdit->append("第二行");
	textEdit->append("第二行");

	labelMove->move(5, 5);
	label->move(50, 50);
	button->move(200, 50);
	lineEdit->move(50, 100);
	textEdit->move(50, 150);
	textEdit->resize(200, 100);



	QSlider *slider = new QSlider(Qt::Horizontal, dock_Gray);
	slider->setRange(0, 100);
	slider->setValue(1);
	slider->move(60, 60);

	QSpinBox *spinBox = new QSpinBox(dock_Enhance);
	spinBox->setRange(0, 100);
	spinBox->setValue(1);
	spinBox->move(70, 70);

	connect(spinBox, SIGNAL(valueChanged(int)), slider, SLOT(setValue(int)));
	connect(slider, SIGNAL(valueChanged(int)), spinBox, SLOT(setValue(int)));
	connect(spinBox, SIGNAL(valueChanged(int)), this, SLOT(slot_spinbox()));


	QComboBox *combo = new QComboBox(dock_Enhance);
	combo->addItem(tr("第一个选项"));
	combo->addItem(tr("第二个选项"));
	combo->move(130, 130);
	connect(combo, SIGNAL(currentIndexChanged(int)), this, SLOT(slot_combo()));


	QRadioButton *radio1 = new QRadioButton(tr("选项1"), dock_Color);
	QRadioButton *radio2 = new QRadioButton(tr("选项2"), dock_Color);

	radio1->setChecked(true);

	connect(radio1, SIGNAL(clicked()), this, SLOT(slot_radio1()));
	connect(radio2, SIGNAL(clicked()), this, SLOT(slot_radio2()));

	QButtonGroup *radioGroup = new QButtonGroup();
	radioGroup->setExclusive(true);
	radioGroup->addButton(radio1);
	radioGroup->addButton(radio2);

	radio1->move(50, 350);
	radio2->move(150, 350);



	QPushButton *button_H1 = new QPushButton(tr("QHBoxLayout第一个按钮"));
	QPushButton *button_H2 = new QPushButton(tr("QHBoxLayout第二个按钮")); 
	QPushButton *button_H3 = new QPushButton(tr("QHBoxLayout第三个按钮"));

	QHBoxLayout *hlayout = new QHBoxLayout();
	hlayout->addWidget(button_H1);
	hlayout->addWidget(button_H2);
	hlayout->addWidget(button_H3);

	QPushButton *button_V1 = new QPushButton(tr("QVBoxLayout第一个按钮"));
	QPushButton *button_V2 = new QPushButton(tr("QVBoxLayout第二个按钮"));
	QPushButton *button_V3 = new QPushButton(tr("QVBoxLayout第三个按钮"));

	QVBoxLayout *vlayout = new QVBoxLayout();
	vlayout->addWidget(button_V1);
	vlayout->addWidget(button_V2);
	vlayout->addWidget(button_V3);

	QPushButton *button_G1 = new QPushButton(tr("QGridLayout第一个按钮"));
	QPushButton *button_G2 = new QPushButton(tr("QGridLayout第二个按钮"));
	QPushButton *button_G3 = new QPushButton(tr("QGridLayout第三个按钮"));
	QPushButton *button_G4 = new QPushButton(tr("QGridLayout第四个按钮"));

	QGridLayout *glayout = new QGridLayout();
	glayout->addWidget(button_G1, 0, 0);
	glayout->addWidget(button_G2, 1, 1);
	glayout->addWidget(button_G3, 2, 0);
	glayout->addWidget(button_G4, 2, 1);

	QLineEdit *line_F1 = new QLineEdit(tr("第一项"));
	QLineEdit *line_F2 = new QLineEdit(tr("第二项"));
	QLineEdit *line_F3 = new QLineEdit(tr("第三项"));
	QLineEdit *line_F4 = new QLineEdit(tr("第四项"));

	QFormLayout *flayout = new QFormLayout();
	flayout->addRow(tr("1"), line_F1);
	flayout->addRow(tr("2"), line_F2);
	flayout->addRow(tr("3"), line_F3);
	flayout->addRow(tr("4"), line_F4);
	flayout->setSpacing(20);
	flayout->setMargin(20);

	QVBoxLayout *playout = new QVBoxLayout();
	playout->addLayout(hlayout);
	playout->addLayout(vlayout);
	playout->addStretch();
	playout->addLayout(glayout);
	playout->addLayout(flayout);

	QWidget *pWidget = new QWidget(dock_Morp);
	pWidget->setLayout(playout);
	dock_Morp->setWidget(pWidget);

}

void ImageProcess::showWin()
{
	CustomWindow *helpWin = new CustomWindow();
	helpWin->resize(600, 400);

	QLabel *label_about = new QLabel(helpWin);
	label_about->setText(tr("图像处理软件自编1.0"));

	QLabel *label_right = new QLabel(helpWin);
	label_right->setText(tr("Copyright(C) 2020 上海 xiaoyi"));

	QLabel *label_author = new QLabel(helpWin);
	label_author->setText(tr("作者：小轶 https://blog.csdn.net/Lin_xiaoyi/article/details/78214874"));

	QPushButton *button_ok = new QPushButton(helpWin);
	button_ok->setText(tr("确定"));
	connect(button_ok, SIGNAL(clicked()), helpWin, SLOT(close()));

	label_about->move(100, 100);
	label_right->move(100, 180);
	label_author->move(100, 260);
	button_ok->move(400, 180);
	
	helpWin->exec();


}

void ImageProcess::ToolWin()
{
	dock_Tool->setFeatures(QDockWidget::DockWidgetClosable);

	QPushButton *button_pen = new QPushButton(QIcon("../Imgae/icon/ImageProcess.png"), tr(""), this);
	button_pen->setFixedSize(35, 35);
	button_pen->setToolTip(tr("钢笔"));
	button_pen->setObjectName("customButton");

	QPushButton *button_line = new QPushButton(QIcon("../Imgae/icon/ImageProcess.png"), tr(""), this);
	button_line->setFixedSize(35, 35);
	button_line->setToolTip(tr("线条"));
	button_line->setObjectName("customButton");

	QPushButton *button_circle = new QPushButton(QIcon("../Imgae/icon/ImageProcess.png"), tr(""), this);
	button_circle->setFixedSize(35, 35);
	button_circle->setToolTip(tr("圆形"));
	button_circle->setObjectName("customButton");

	QPushButton *button_ellipse = new QPushButton(QIcon("../Imgae/icon/ImageProcess.png"), tr(""), this);
	button_ellipse->setFixedSize(35, 35);
	button_ellipse->setToolTip(tr("椭圆"));
	button_ellipse->setObjectName("customButton");

	QPushButton *button_triangle = new QPushButton(QIcon("../Imgae/icon/ImageProcess.png"), tr(""), this);
	button_triangle->setFixedSize(35, 35);
	button_triangle->setToolTip(tr("三角形"));
	button_triangle->setObjectName("customButton");

	QPushButton *button_rhombus = new QPushButton(QIcon("../Imgae/icon/ImageProcess.png"), tr(""), this);
	button_rhombus->setFixedSize(35, 35);
	button_rhombus->setToolTip(tr("菱形"));
	button_rhombus->setObjectName("customButton");

	QPushButton *button_rect = new QPushButton(QIcon("../Imgae/icon/ImageProcess.png"), tr(""), this);
	button_rect->setFixedSize(35, 35);
	button_rect->setToolTip(tr("长方形"));
	button_rect->setObjectName("customButton");

	QPushButton *button_square = new QPushButton(QIcon("../Imgae/icon/ImageProcess.png"), tr(""), this);
	button_square->setFixedSize(35, 35);
	button_square->setToolTip(tr("正方形"));
	button_square->setObjectName("customButton");

	QPushButton *button_hexagon = new QPushButton(QIcon("../Imgae/icon/ImageProcess.png"), tr(""), this);
	button_hexagon->setFixedSize(35, 35);
	button_hexagon->setToolTip(tr("六边形"));
	button_hexagon->setObjectName("customButton");

	QGridLayout *toolLayout = new QGridLayout();
	toolLayout->setAlignment(Qt::AlignTop);
	toolLayout->addWidget(button_pen, 0, 0);
	toolLayout->addWidget(button_line, 0, 1);
	toolLayout->addWidget(button_ellipse, 1, 0);
	toolLayout->addWidget(button_circle, 1, 1);
	toolLayout->addWidget(button_triangle, 2, 0);
	toolLayout->addWidget(button_rhombus, 2, 1);
	toolLayout->addWidget(button_rect, 3, 0);
	toolLayout->addWidget(button_square, 3, 1);
	toolLayout->addWidget(button_hexagon, 4, 0);

	QWidget *toolWidget = new QWidget(dock_Tool);
	toolWidget->setLayout(toolLayout);
	dock_Tool->setWidget(toolWidget);

	toolButtonGroup = new QButtonGroup();
	toolButtonGroup->addButton(button_pen, 1);
	toolButtonGroup->addButton(button_line, 2);
	toolButtonGroup->addButton(button_ellipse, 3);
	toolButtonGroup->addButton(button_circle, 4);
	toolButtonGroup->addButton(button_triangle, 5);
	toolButtonGroup->addButton(button_rhombus, 6);
	toolButtonGroup->addButton(button_rect, 7);
	toolButtonGroup->addButton(button_square,8);
	toolButtonGroup->addButton(button_hexagon, 9);
	connect(toolButtonGroup, SIGNAL(buttonClicked(int)), this, SLOT(toolButtonClicked(int)));

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

	
	//Old read image
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
	


	//New read Image
	//if (!path.isEmpty())
	//{
	//	srcImg = imread(path.toStdString());
	//	if (srcImg.empty())
	//	{
	//		QMessageBox::information(this, tr("错误"), tr("打开图像失败"));
	//		return;
	//	}

	//	cvtColor(srcImg, grayImg, cv::COLOR_BGR2GRAY);

	//	Mat temp;
	//	QImage Qtemp;
	//	if (!isGray)
	//	{
	//		cvtColor(srcImg, temp, cv::COLOR_BGR2RGB);
	//		Qtemp = QImage((const unsigned char*)(temp.data), temp.cols, temp.rows, temp.step, QImage::Format_RGB888);
	//	}
	//	else
	//	{
	//		cvtColor(grayImg, temp, cv::COLOR_GRAY2RGB);
	//		Qtemp = QImage((const unsigned char*)(temp.data), temp.cols, temp.rows, temp.step, QImage::Format_RGB888);
	//	}
	//	imgLabel->setPixmap(QPixmap::fromImage(Qtemp));
	//	imgLabel->resize(Qtemp.size());
	//	currentPath = path;
	//}
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

void ImageProcess::FullSize()
{
	QImage img = imgLabel->pixmap()->toImage().scaled(scrollArea->width() - 2, scrollArea->height() - 2, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
	imgLabel->setPixmap(QPixmap::fromImage(img));
	imgLabel->resize(img.width(), img.height());
}

void ImageProcess::AutoSize()
{
	QImage img;
	double imgRatio = 1.0 * imgLabel->pixmap()->toImage().width() / imgLabel->pixmap()->toImage().height();
	double winRatio = 1.0 * (scrollArea->width() - 2) / (scrollArea->height() - 2);
	if (imgRatio > winRatio)
	{
		img = imgLabel->pixmap()->toImage().scaled((scrollArea->width() - 2), (scrollArea->width() - 2) / imgRatio, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
	}
	else
	{
		img = imgLabel->pixmap()->toImage().scaled((scrollArea->height() - 2)*imgRatio, (scrollArea->height() - 2), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
	}
	imgLabel->setPixmap(QPixmap::fromImage(img));
	imgLabel->resize(img.width(), img.height());
}

void ImageProcess::toolButtonClicked(int id)
{
	QList<QAbstractButton*> buttons = toolButtonGroup->buttons();
	foreach(QAbstractButton *button, buttons)
	{
		if (toolButtonGroup->button(id) != button)
			button->setChecked(false);
		else if (drawType == id)
		{
			drawType = 0;
		}
		else
		{
			drawType = id;
		}
	}

	switch (drawType)
	{
	case 0:
		//QMessageBox::information(this, tr("绘制"), tr("退出绘制模式"));
		imgLabel->setShape(PaintWidget::Null);
		break;
	
	case 1:
		//QMessageBox::information(this, tr("绘制"), tr("钢笔"));
		imgLabel->setShape(PaintWidget::Pen);
		break;
	case 2:
		//QMessageBox::information(this, tr("绘制"), tr("线条"));
		imgLabel->setShape(PaintWidget::Line);
		break;
	case 3:
		//QMessageBox::information(this, tr("绘制"), tr("椭圆形！")); 
		imgLabel->setShape(PaintWidget::Ellipse);
		break;
	case 4:
		//QMessageBox::information(this, tr("绘制"), tr("圆形！")); 
		imgLabel->setShape(PaintWidget::Circle);
		break;
	case 5:
		//QMessageBox::information(this, tr("绘制"), tr("三角形！"));  
		imgLabel->setShape(PaintWidget::Triangle);
		break;
	case 6:
		//QMessageBox::information(this, tr("绘制"), tr("菱形！")); 
		imgLabel->setShape(PaintWidget::Rhombus);
		break;
	case 7:
		//imgLabel->setShape(PaintWidget::Rect);
		QMessageBox::information(this, tr("绘制"), tr("长方形！")); 
		break;
	case 8:
		//QMessageBox::information(this, tr("绘制"), tr("正方形！"));
		imgLabel->setShape(PaintWidget::Square);
		break;
	case 9:
		//QMessageBox::information(this, tr("绘制"), tr("六边形！")); 
		imgLabel->setShape(PaintWidget::Hexagon);
		break;
	default:
		break;
	}
}

void ImageProcess::setColor()
{
	QColor c = QColorDialog::getColor(Qt::blue);
	if (c.isValid())
	{
		colorFram->setPalette(QPalette(c));
	}
}