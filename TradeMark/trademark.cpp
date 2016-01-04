#include "trademark.h"
#include "handleImg.h"


TradeMark::TradeMark(QWidget *parent)
	: QMainWindow(parent)
{
	//ui.setupUi(this);
	this->setFixedSize(QSize(800, 600));

	label = new QLabel(this);
	label->setGeometry(QRect(QPoint(10, 0), QSize(380, 580)));
	QImage *image = new QImage("1456_1_168EB22AA16A501EE053640B503A501E.png");
	*image = image->scaled(380, 580);
	label->setPixmap(QPixmap::fromImage(*image));
	label->show();

	m_button0 = new QPushButton("Remove WaterMark", this);
	m_button0->setGeometry(QRect(QPoint(500, 50), QSize(200, 50)));
	connect(m_button0, SIGNAL(pressed()), this, SLOT(handleButton0()));
}

TradeMark::~TradeMark()
{

}

void TradeMark::handleButton0() {

	string str = removeWaterMark("1456_1_168EB22AA16A501EE053640B503A501E.png");
	QImage *image = new QImage(QString(str.c_str()));
	*image = image->scaled(380, 580);
	label->setPixmap(QPixmap::fromImage(*image));
	label->show();

}