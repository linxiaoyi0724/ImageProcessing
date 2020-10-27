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

	QPushButton *button_full = new QPushButton(tr("��������"));
	QPushButton *button_auto = new QPushButton(tr("����Ӧ����"));
	//button_full->setStyleSheet("background-color:blue;");

	connect(button_full, SIGNAL(clicked()), this, SLOT(FullSize()));
	connect(button_auto, SIGNAL(clicked()), this, SLOT(AutoSize()));

	ui.mainToolBar->addWidget(button_full);
	ui.mainToolBar->addWidget(button_auto);

	QPushButton *button_about = new QPushButton(tr("����"));
	connect(button_about, SIGNAL(clicked()), this, SLOT(showWin()));
	ui.mainToolBar->addWidget(button_about);

	colorBtn = new QPushButton(tr("������ɫ"));
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
	QPushButton *button = new QPushButton(tr("��ť"), dock_Geom);
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
	textEdit->append("��һ��");
	textEdit->append("�ڶ���");
	textEdit->append("�ڶ���");
	textEdit->append("�ڶ���");
	textEdit->append("�ڶ���");
	textEdit->append("�ڶ���");

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
	combo->addItem(tr("��һ��ѡ��"));
	combo->addItem(tr("�ڶ���ѡ��"));
	combo->move(130, 130);
	connect(combo, SIGNAL(currentIndexChanged(int)), this, SLOT(slot_combo()));


	QRadioButton *radio1 = new QRadioButton(tr("ѡ��1"), dock_Color);
	QRadioButton *radio2 = new QRadioButton(tr("ѡ��2"), dock_Color);

	radio1->setChecked(true);

	connect(radio1, SIGNAL(clicked()), this, SLOT(slot_radio1()));
	connect(radio2, SIGNAL(clicked()), this, SLOT(slot_radio2()));

	QButtonGroup *radioGroup = new QButtonGroup();
	radioGroup->setExclusive(true);
	radioGroup->addButton(radio1);
	radioGroup->addButton(radio2);

	radio1->move(50, 350);
	radio2->move(150, 350);



	QPushButton *button_H1 = new QPushButton(tr("QHBoxLayout��һ����ť"));
	QPushButton *button_H2 = new QPushButton(tr("QHBoxLayout�ڶ�����ť")); 
	QPushButton *button_H3 = new QPushButton(tr("QHBoxLayout��������ť"));

	QHBoxLayout *hlayout = new QHBoxLayout();
	hlayout->addWidget(button_H1);
	hlayout->addWidget(button_H2);
	hlayout->addWidget(button_H3);

	QPushButton *button_V1 = new QPushButton(tr("QVBoxLayout��һ����ť"));
	QPushButton *button_V2 = new QPushButton(tr("QVBoxLayout�ڶ�����ť"));
	QPushButton *button_V3 = new QPushButton(tr("QVBoxLayout��������ť"));

	QVBoxLayout *vlayout = new QVBoxLayout();
	vlayout->addWidget(button_V1);
	vlayout->addWidget(button_V2);
	vlayout->addWidget(button_V3);

	QPushButton *button_G1 = new QPushButton(tr("QGridLayout��һ����ť"));
	QPushButton *button_G2 = new QPushButton(tr("QGridLayout�ڶ�����ť"));
	QPushButton *button_G3 = new QPushButton(tr("QGridLayout��������ť"));
	QPushButton *button_G4 = new QPushButton(tr("QGridLayout���ĸ���ť"));

	QGridLayout *glayout = new QGridLayout();
	glayout->addWidget(button_G1, 0, 0);
	glayout->addWidget(button_G2, 1, 1);
	glayout->addWidget(button_G3, 2, 0);
	glayout->addWidget(button_G4, 2, 1);

	QLineEdit *line_F1 = new QLineEdit(tr("��һ��"));
	QLineEdit *line_F2 = new QLineEdit(tr("�ڶ���"));
	QLineEdit *line_F3 = new QLineEdit(tr("������"));
	QLineEdit *line_F4 = new QLineEdit(tr("������"));

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
	label_about->setText(tr("ͼ��������Ա�1.0"));

	QLabel *label_right = new QLabel(helpWin);
	label_right->setText(tr("Copyright(C) 2020 �Ϻ� xiaoyi"));

	QLabel *label_author = new QLabel(helpWin);
	label_author->setText(tr("���ߣ�С�� https://blog.csdn.net/Lin_xiaoyi/article/details/78214874"));

	QPushButton *button_ok = new QPushButton(helpWin);
	button_ok->setText(tr("ȷ��"));
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
	button_pen->setToolTip(tr("�ֱ�"));
	button_pen->setObjectName("customButton");

	QPushButton *button_line = new QPushButton(QIcon("../Imgae/icon/ImageProcess.png"), tr(""), this);
	button_line->setFixedSize(35, 35);
	button_line->setToolTip(tr("����"));
	button_line->setObjectName("customButton");

	QPushButton *button_circle = new QPushButton(QIcon("../Imgae/icon/ImageProcess.png"), tr(""), this);
	button_circle->setFixedSize(35, 35);
	button_circle->setToolTip(tr("Բ��"));
	button_circle->setObjectName("customButton");

	QPushButton *button_ellipse = new QPushButton(QIcon("../Imgae/icon/ImageProcess.png"), tr(""), this);
	button_ellipse->setFixedSize(35, 35);
	button_ellipse->setToolTip(tr("��Բ"));
	button_ellipse->setObjectName("customButton");

	QPushButton *button_triangle = new QPushButton(QIcon("../Imgae/icon/ImageProcess.png"), tr(""), this);
	button_triangle->setFixedSize(35, 35);
	button_triangle->setToolTip(tr("������"));
	button_triangle->setObjectName("customButton");

	QPushButton *button_rhombus = new QPushButton(QIcon("../Imgae/icon/ImageProcess.png"), tr(""), this);
	button_rhombus->setFixedSize(35, 35);
	button_rhombus->setToolTip(tr("����"));
	button_rhombus->setObjectName("customButton");

	QPushButton *button_rect = new QPushButton(QIcon("../Imgae/icon/ImageProcess.png"), tr(""), this);
	button_rect->setFixedSize(35, 35);
	button_rect->setToolTip(tr("������"));
	button_rect->setObjectName("customButton");

	QPushButton *button_square = new QPushButton(QIcon("../Imgae/icon/ImageProcess.png"), tr(""), this);
	button_square->setFixedSize(35, 35);
	button_square->setToolTip(tr("������"));
	button_square->setObjectName("customButton");

	QPushButton *button_hexagon = new QPushButton(QIcon("../Imgae/icon/ImageProcess.png"), tr(""), this);
	button_hexagon->setFixedSize(35, 35);
	button_hexagon->setToolTip(tr("������"));
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
	QString path = QFileDialog::getOpenFileName(this, tr("ѡ��ͼ��"), ".", tr("Images(*.jpg *.png *.bmp)"));

	
	//Old read image
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
	


	//New read Image
	//if (!path.isEmpty())
	//{
	//	srcImg = imread(path.toStdString());
	//	if (srcImg.empty())
	//	{
	//		QMessageBox::information(this, tr("����"), tr("��ͼ��ʧ��"));
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
		//QMessageBox::information(this, tr("����"), tr("�˳�����ģʽ"));
		imgLabel->setShape(PaintWidget::Null);
		break;
	
	case 1:
		//QMessageBox::information(this, tr("����"), tr("�ֱ�"));
		imgLabel->setShape(PaintWidget::Pen);
		break;
	case 2:
		//QMessageBox::information(this, tr("����"), tr("����"));
		imgLabel->setShape(PaintWidget::Line);
		break;
	case 3:
		//QMessageBox::information(this, tr("����"), tr("��Բ�Σ�")); 
		imgLabel->setShape(PaintWidget::Ellipse);
		break;
	case 4:
		//QMessageBox::information(this, tr("����"), tr("Բ�Σ�")); 
		imgLabel->setShape(PaintWidget::Circle);
		break;
	case 5:
		//QMessageBox::information(this, tr("����"), tr("�����Σ�"));  
		imgLabel->setShape(PaintWidget::Triangle);
		break;
	case 6:
		//QMessageBox::information(this, tr("����"), tr("���Σ�")); 
		imgLabel->setShape(PaintWidget::Rhombus);
		break;
	case 7:
		//imgLabel->setShape(PaintWidget::Rect);
		QMessageBox::information(this, tr("����"), tr("�����Σ�")); 
		break;
	case 8:
		//QMessageBox::information(this, tr("����"), tr("�����Σ�"));
		imgLabel->setShape(PaintWidget::Square);
		break;
	case 9:
		//QMessageBox::information(this, tr("����"), tr("�����Σ�")); 
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