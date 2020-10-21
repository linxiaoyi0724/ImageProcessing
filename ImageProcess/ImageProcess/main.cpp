#include "MainWindow.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	ImageProcess w;
	w.setWindowIcon(QIcon("./Resources/ImageProcessIcon.ico"));
	w.show();
	return a.exec();
}
