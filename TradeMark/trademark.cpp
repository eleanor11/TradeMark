#include "trademark.h"


TradeMark::TradeMark(QWidget *parent)
	: QMainWindow(parent)
{
	//ui.setupUi(this);
	this->setFixedSize(QSize(800, 600));

	type = 0; 
	num = 0;

	label = new QLabel(this);
	label->setGeometry(QRect(QPoint(10, 10), QSize(380, 580)));
	
	loadImages();

	QPushButton *m_buttonLeft = new QPushButton("<", this);
	QPushButton *m_buttonRight = new QPushButton(">", this);
	QPushButton *m_buttonReWater = new QPushButton("Remove WaterMark", this);
	QPushButton *m_buttonCut = new QPushButton("Cut Trade Marker", this);
	QPushButton *m_buttonGetInfo = new QPushButton("Get Infomation", this);

	m_buttonReWater->setGeometry(QRect(QPoint(410, 30), QSize(120, 50)));
	connect(m_buttonReWater, SIGNAL(pressed()), this, SLOT(handleButtonReWater()));
	m_buttonCut->setGeometry(QRect(QPoint(540, 30), QSize(120, 50)));
	connect(m_buttonCut, SIGNAL(pressed()), this, SLOT(handleButtonCut()));
	m_buttonGetInfo->setGeometry(QRect(QPoint(670, 30), QSize(120, 50)));
	connect(m_buttonGetInfo, SIGNAL(pressed()), this, SLOT(handleButtonGetInfo()));


	m_buttonLeft->setGeometry(QRect(QPoint(410, 100), QSize(150, 30)));
	connect(m_buttonLeft, SIGNAL(pressed()), this, SLOT(handleButtonLeft()));
	m_buttonRight->setGeometry(QRect(QPoint(640, 100), QSize(150, 30)));
	connect(m_buttonRight, SIGNAL(pressed()), this, SLOT(handleButtonRight()));
}

TradeMark::~TradeMark()
{

}


void TradeMark::loadImages() {

	hi.loadImages();
	type = 0;
	num = 0;

	showImg();
}

void TradeMark::handleButtonLeft() {
	num--;
	if (num < 0 && type < boundary) {
		num = hi.getImgNum() - 1;
	}
	if (num < 0 && type >= boundary) {
		num = hi.getMarkerNum() - 1;
	}
	showImg();
}

void TradeMark::handleButtonRight() {
	num++;
	if (type < boundary && num >= hi.getImgNum()) {
		num = 0;
	}
	if (type >= boundary && num >= hi.getMarkerNum()) {
		num = 0;
	}
	showImg();
}


void TradeMark::handleButtonReWater() {

	hi.removeWaterMark();
	type = 1;
	//num = 0;

	showImg();

}

void TradeMark::handleButtonCut() {
	//string str = hi.getInfo("marker_12.png");
	//QImage *image = new QImage(QString(str.c_str()));
	//*image = image->scaled(380, 580);
	//label->setPixmap(QPixmap::fromImage(*image));
	//label->show();

	hi.cutMarkers();
	type = 6;

	showImg();
}

void TradeMark::handleButtonGetInfo() {

}

String TradeMark::imageName() {
	if (type < 4) {
		return strs[num] + addition[type];
	}
	else if (type == 4) {
		int a = num / 2;
		int b = num % 2 + 4;
		return strs[a] + addition[b];
	}
	else if (type == 5) {
		int a = num / 2;
		int b = num % 2 + 6;
		return strs[a] + addition[b];
	}
	else if (type == 6) {
		std::stringstream ss;
		ss << num;
		return "markers/marker_" + ss.str() + ".png";
	}
}

void TradeMark::showImg() {
	String str = imageName();
	QImage *image = new QImage(QString(str.c_str()));
	int w = image->width();
	int h = image->height();
	if (380.0 / w * h > 580) {
		w = int(580.0 / h * w);
		h = 580;
	}
	else {
		h = int(380.0 / w * h);
		w = 380;
	}
	*image = image->scaled(w, h);
	label->setPixmap(QPixmap::fromImage(*image));
	label->show();
}

