#include "trademark.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	TradeMark w;
	w.show();
	return a.exec();
}
