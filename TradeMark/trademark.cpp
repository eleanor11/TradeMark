#include "trademark.h"

#if _MSC_VER >= 1600  
#pragma execution_character_set("utf-8")  
#endif  

TradeMark::TradeMark(QWidget *parent)
	: QMainWindow(parent)
{
	//ui.setupUi(this);
	this->setFixedSize(QSize(800, 600));

	type = 0; 
	num = 0;

	label = new QLabel(this);
	label->setGeometry(QRect(QPoint(10, 10), QSize(380, 550)));
	
	loadImages();

	m_buttonLeft = new QPushButton("<", this);
	m_buttonRight = new QPushButton(">", this);
	m_buttonReWater = new QPushButton("Remove WaterMark", this);
	m_buttonCut = new QPushButton("Cut Trade Marker", this);
	m_buttonGetInfo = new QPushButton("Get Infomation", this);

	m_buttonReWater->setGeometry(QRect(QPoint(410, 30), QSize(120, 50)));
	connect(m_buttonReWater, SIGNAL(pressed()), this, SLOT(handleButtonReWater()));
	m_buttonCut->setGeometry(QRect(QPoint(540, 30), QSize(120, 50)));
	connect(m_buttonCut, SIGNAL(pressed()), this, SLOT(handleButtonCut()));
	m_buttonGetInfo->setGeometry(QRect(QPoint(670, 30), QSize(120, 50)));
	connect(m_buttonGetInfo, SIGNAL(pressed()), this, SLOT(handleButtonGetInfo()));

	m_buttonLeft->setGeometry(QRect(QPoint(15, 560), QSize(150, 30)));
	connect(m_buttonLeft, SIGNAL(pressed()), this, SLOT(handleButtonLeft()));
	m_buttonRight->setGeometry(QRect(QPoint(225, 560), QSize(150, 30)));
	connect(m_buttonRight, SIGNAL(pressed()), this, SLOT(handleButtonRight()));

	l_number = new QLabel(this);
	e_number = new QTextEdit(this);
	l_date = new QLabel(this);
	e_date = new QTextEdit(this);
	l_logo = new QLabel(this);
	l_logoImage = new QLabel(this);
	l_content = new QLabel(this);
	l_class = new QLabel(this);
	e_class = new QTextEdit(this);
	l_applicant = new QLabel(this);
	e_applicant = new QTextEdit(this);
	l_address = new QLabel(this);
	e_address = new QTextEdit(this);
	l_agency = new QLabel(this);
	e_agency = new QTextEdit(this);
	l_priority = new QLabel(this);
	e_priority = new QTextEdit(this);

	l_number->setGeometry(QRect(QPoint(410, 110), QSize(60, 30)));
	l_number->setText(QString("编号"));
	e_number->setGeometry(QRect(QPoint(480, 110), QSize(100, 30)));
	e_number->setTextInteractionFlags(Qt::TextSelectableByMouse | Qt::TextSelectableByKeyboard);

	l_date->setGeometry(QRect(QPoint(600, 110), QSize(60, 30)));
	l_date->setText(QString("申请日期"));
	e_date->setGeometry(QRect(QPoint(670, 110), QSize(100, 30)));
	e_date->setTextInteractionFlags(Qt::TextSelectableByMouse | Qt::TextSelectableByKeyboard);

	l_logo->setGeometry(QRect(QPoint(410, 150), QSize(60, 30)));
	l_logo->setText(QString("商标"));
	l_logoImage->setGeometry(QRect(QPoint(480, 150), QSize(200, 200)));

	l_content->setGeometry(QRect(QPoint(410, 350), QSize(150, 30)));
	l_content->setText(QString("核定使用商品/服务项目"));

	l_class->setGeometry(QRect(QPoint(410, 380), QSize(60, 30)));
	l_class->setText(QString("类别"));
	e_class->setGeometry(QRect(QPoint(480, 380), QSize(100, 30)));
	e_class->setTextInteractionFlags(Qt::TextSelectableByMouse | Qt::TextSelectableByKeyboard);

	l_applicant->setGeometry(QRect(QPoint(410, 420), QSize(60, 30)));
	l_applicant->setText(QString("申请人"));
	e_applicant->setGeometry(QRect(QPoint(480, 420), QSize(100, 30)));
	e_applicant->setTextInteractionFlags(Qt::TextSelectableByMouse | Qt::TextSelectableByKeyboard);

	l_address->setGeometry(QRect(QPoint(410, 460), QSize(60, 30)));
	l_address->setText(QString("地址"));
	e_address->setGeometry(QRect(QPoint(480, 460), QSize(100, 30)));
	e_address->setTextInteractionFlags(Qt::TextSelectableByMouse | Qt::TextSelectableByKeyboard);

	l_agency->setGeometry(QRect(QPoint(410, 500), QSize(60, 30)));
	l_agency->setText(QString("代理机构"));
	e_agency->setGeometry(QRect(QPoint(480, 500), QSize(100, 30)));
	e_agency->setTextInteractionFlags(Qt::TextSelectableByMouse | Qt::TextSelectableByKeyboard);

	l_priority->setGeometry(QRect(QPoint(410, 540), QSize(60, 30)));
	l_priority->setText(QString("优先权日期"));
	e_priority->setGeometry(QRect(QPoint(480, 540), QSize(100, 30)));
	e_priority->setTextInteractionFlags(Qt::TextSelectableByMouse | Qt::TextSelectableByKeyboard);

}

TradeMark::~TradeMark()
{

}


void TradeMark::loadImages() {

	hi.loadImages();
	type = 0;
	num = 0;

	showImg(0);
}

void TradeMark::handleButtonLeft() {
	num--;
	if (num < 0 && type < boundary) {
		num = hi.getImgNum() - 1;
	}
	if (num < 0 && type >= boundary) {
		num = hi.getMarkerNum() - 1;
	}
	showImg(6);
	showMessage();
}

void TradeMark::handleButtonRight() {
	num++;
	if (type < boundary && num >= hi.getImgNum()) {
		num = 0;
	}
	if (type >= boundary && num >= hi.getMarkerNum()) {
		num = 0;
	}
	showImg(6);
	showMessage();
}


void TradeMark::handleButtonReWater() {

	hi.removeWaterMark();
	type = 1;
	//num = 0;

	showImg(1);

}

void TradeMark::handleButtonCut() {
	//string str = hi.getInfo("marker_12.png");
	//QImage *image = new QImage(QString(str.c_str()));
	//*image = image->scaled(380, 580);
	//label->setPixmap(QPixmap::fromImage(*image));
	//label->show();

	hi.cutMarkers();
	type = 6;

	showImg(6);
}

void TradeMark::handleButtonGetInfo() {

//	hi.getInfo("marker_0_1.png");

	hi.getInfo();
	type = 8;

	showMessage();
}

String TradeMark::imageName(int type) {
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
	else if (type == 8) {
		std::stringstream ss;
		ss << num;
		return "categories/marker_" + ss.str() + "_2.png";
	}
}

void TradeMark::showImg(int type) {
	String str = imageName(type);
	QImage *image = new QImage(QString(str.c_str()));
	int w = image->width();
	int h = image->height();
	if (380.0 / w * h > 560) {
		w = int(560.0 / h * w);
		h = 560;
	}
	else {
		h = int(380.0 / w * h);
		w = 380;
	}
	*image = image->scaled(w, h);
	label->setPixmap(QPixmap::fromImage(*image));
	label->show();
}


void TradeMark::showMessage() {

	String str = imageName(8);
	QImage *image = new QImage(QString(str.c_str()));
	int w = image->width();
	int h = image->height();
	if (200.0 / w * h > 200) {
		w = int(200.0 / h * w);
		h = 200;
	}
	else {
		h = int(200.0 / w * h);
		w = 200;
	}
	*image = image->scaled(w, h);
	l_logoImage->setPixmap(QPixmap::fromImage(*image));
	l_logoImage->show();
}
