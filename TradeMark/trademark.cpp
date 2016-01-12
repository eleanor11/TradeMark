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
	redo = true;

	label = new QLabel(this);
	label->setGeometry(QRect(QPoint(10, 10), QSize(380, 550)));
	
	loadImages();

	l_select = new QLabel(this);
	m_buttonSelect = new QPushButton("no", this);

	m_buttonLeft = new QPushButton("<", this);
	m_buttonRight = new QPushButton(">", this);
	m_buttonReWater = new QPushButton("Remove WaterMark", this);
	m_buttonCut = new QPushButton("Cut Trade Marker", this);
	m_buttonGetInfo = new QPushButton("Get Infomation", this);

	l_select->setGeometry(QRect(QPoint(410, 10), QSize(60, 30)));
	l_select->setText("redo");
	m_buttonSelect->setGeometry(QRect(QPoint(480, 10), QSize(120, 30)));
	connect(m_buttonSelect, SIGNAL(pressed()), this, SLOT(handleButtonSelect()));

	m_buttonReWater->setGeometry(QRect(QPoint(410, 50), QSize(120, 30)));
	connect(m_buttonReWater, SIGNAL(pressed()), this, SLOT(handleButtonReWater()));
	m_buttonCut->setGeometry(QRect(QPoint(540, 50), QSize(120, 30)));
	connect(m_buttonCut, SIGNAL(pressed()), this, SLOT(handleButtonCut()));
	m_buttonGetInfo->setGeometry(QRect(QPoint(670, 50), QSize(120, 30)));
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
	e_classNum = new QTextEdit(this);
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
	l_logoImage->setGeometry(QRect(QPoint(480, 150), QSize(150, 150)));

	l_content->setGeometry(QRect(QPoint(410, 300), QSize(150, 30)));
	l_content->setText(QString("核定使用商品/服务项目"));

	l_class->setGeometry(QRect(QPoint(410, 330), QSize(60, 30)));
	l_class->setText(QString("第      类"));
	e_classNum->setGeometry(QRect(QPoint(425, 330), QSize(30, 30)));
	e_classNum->setTextInteractionFlags(Qt::TextSelectableByMouse | Qt::TextSelectableByKeyboard);
	e_class->setGeometry(QRect(QPoint(480, 330), QSize(290, 40)));
	e_class->setTextInteractionFlags(Qt::TextSelectableByMouse | Qt::TextSelectableByKeyboard);

	l_applicant->setGeometry(QRect(QPoint(410, 380), QSize(60, 30)));
	l_applicant->setText(QString("申请人"));
	e_applicant->setGeometry(QRect(QPoint(480, 380), QSize(290, 40)));
	e_applicant->setTextInteractionFlags(Qt::TextSelectableByMouse | Qt::TextSelectableByKeyboard);

	l_address->setGeometry(QRect(QPoint(410, 430), QSize(60, 30)));
	l_address->setText(QString("地址"));
	e_address->setGeometry(QRect(QPoint(480, 430), QSize(290, 40)));
	e_address->setTextInteractionFlags(Qt::TextSelectableByMouse | Qt::TextSelectableByKeyboard);

	l_agency->setGeometry(QRect(QPoint(410, 480), QSize(60, 30)));
	l_agency->setText(QString("代理机构"));
	e_agency->setGeometry(QRect(QPoint(480, 480), QSize(290, 40)));
	e_agency->setTextInteractionFlags(Qt::TextSelectableByMouse | Qt::TextSelectableByKeyboard);

	l_priority->setGeometry(QRect(QPoint(410, 530), QSize(60, 30)));
	l_priority->setText(QString("优先权日期"));
	e_priority->setGeometry(QRect(QPoint(480, 530), QSize(290, 40)));
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

	if (type == 8) {
		showImg(6);
		showMessage();
	}
	else {
		showImg(type);
	}
}

void TradeMark::handleButtonRight() {
	num++;
	if (type < boundary && num >= hi.getImgNum()) {
		num = 0;
	}
	if (type >= boundary && num >= hi.getMarkerNum()) {
		num = 0;
	}

	if (type == 8) {
		showImg(6);
		showMessage();
	}
	else {
		showImg(type);
	}
}

void TradeMark::handleButtonSelect() {
	redo = !redo;
	if (redo) {
		m_buttonSelect->setText("no");
	}
	else {
		m_buttonSelect->setText("yes");
	}
}

void TradeMark::handleButtonReWater() {

	if (redo) {
		hi.removeWaterMark();
	}
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

	if (redo) {
		hi.cutMarkers();
	}
	type = 6;

	showImg(6);
}

void TradeMark::handleButtonGetInfo() {

//	hi.getInfo("marker_0_1.png");
	type = 8;

	if (redo) {
		hi.getInfoByLine();
	}
	showImg(6);
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
String TradeMark::imageNameC(int c) {
	std::stringstream ss;
	ss << num << "_" << c;
	return "categories/marker_" + ss.str() + ".png";

}
String TradeMark::fileName() {

	std::stringstream ss;
	ss << num;
	return "doc/marker_" + ss.str() + ".txt";
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

//	if (!redo) {
		showMessageFile();
		return;
//	}

	//string str = fileName();
	//ofstream out;
	//out.open(str.c_str(), ios::out);

	//{	//number
	//	string str = imageNameC(0);
	//	string content = cleanString(img2chi(str));
	//	e_number->setText(QString(content.c_str()));
	//	out << content << endl;
	//}

	//{	//date
	//	string str = imageNameC(1);
	//	hi.cutDate(str);
	//	string content = toDate();
	//	e_date->setText(QString(content.c_str()));
	//	out << content << endl;
	//}

	//{	//logo
	//	String str = imageName(8);
	//	QImage *image = new QImage(QString(str.c_str()));
	//	int w = image->width();
	//	int h = image->height();
	//	if (150.0 / w * h > 150) {
	//		w = int(150.0 / h * w);
	//		h = 150;
	//	}
	//	else {
	//		h = int(150.0 / w * h);
	//		w = 150;
	//	}
	//	*image = image->scaled(w, h);
	//	l_logoImage->setPixmap(QPixmap::fromImage(*image));
	//	l_logoImage->show();
	//}
	//{	//class
	//	string str = imageNameC(4);
	//	string str0 = imageNameC(40);
	//	string content = cleanString(img2chi(str0));
	//	e_classNum->setText(QString(content.c_str()));
	//	out << content << endl;

	//	content = cleanString(img2chi(str));
	//	e_class->setText(QString(content.c_str()));
	//	out << content << endl;
	//}
	//{	//applicant
	//	string str = imageNameC(5);
	//	string content = cleanString(img2chi(str));
	//	e_applicant->setText(QString(content.c_str()));
	//	out << content << endl;
	//}
	//{	//address
	//	string str = imageNameC(6);
	//	string content = cleanString(img2chi(str));
	//	e_address->setText(QString(content.c_str()));
	//	out << content << endl;
	//}
	//{	//agency
	//	string str = imageNameC(7);
	//	string content = cleanString(img2chi(str));
	//	e_agency->setText(QString(content.c_str()));
	//	out << content << endl;
	//}
	//{	//priority
	//	string str = imageNameC(8);
	//	if (hi.cutDate(str)) {
	//		string content = toDate();
	//		e_priority->setText(QString(content.c_str()));
	//		out << content << endl;
	//	}
	//}

	//out.close();

}
void TradeMark::showMessageFile() {

	string str = fileName();
	ifstream in;
	in.open(str.c_str(), ios::in);



	{	//number
		string content;
		if (getline(in, content)){
			e_number->setText(QString(content.c_str()));
		}
	}

	{	//date
		string content;
		if (getline(in, content)){
			e_date->setText(QString(content.c_str()));
		}
	}

	{	//logo
		String str = imageName(8);
		QImage *image = new QImage(QString(str.c_str()));
		int w = image->width();
		int h = image->height();
		if (150.0 / w * h > 150) {
			w = int(150.0 / h * w);
			h = 150;
		}
		else {
			h = int(150.0 / w * h);
			w = 150;
		}
		*image = image->scaled(w, h);
		l_logoImage->setPixmap(QPixmap::fromImage(*image));
		l_logoImage->show();
	}
	{	//class
		string content;
		if (getline(in, content)){
			e_classNum->setText(QString(content.c_str()));
		}

		content;
		if (getline(in, content)){
			e_class->setText(QString(content.c_str()));
		}
	}
	{	//applicant
		string content;
		if (getline(in, content)){
			e_applicant->setText(QString(content.c_str()));
		}
	}
	{	//address
		string content;
		if (getline(in, content)){
			e_address->setText(QString(content.c_str()));
		}
	}
	{	//agency
		string content;
		if (getline(in, content)){
			e_agency->setText(QString(content.c_str()));
		}
	}
	{	//priority
		string content;
		if (getline(in, content)){
			e_priority->setText(QString(content.c_str()));
		}
	}

	in.close();

}
