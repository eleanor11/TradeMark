#ifndef TRADEMARK_H
#define TRADEMARK_H

#include <QtWidgets/QMainWindow>
#include <QtWidgets/qpushbutton.h>
#include <QtWidgets/qtextedit.h>
#include <QTextCodec>
#include <qlabel.h>
#include <qpixmap.h>
#include "ui_trademark.h"
#include "handleImg.h"

class TradeMark : public QMainWindow
{
	Q_OBJECT

public:
	TradeMark(QWidget *parent = 0);
	~TradeMark();

private slots:
	void handleButtonLeft();
	void handleButtonRight();
	void handleButtonReWater();
	void handleButtonCut();
	void handleButtonGetInfo();


private:

	Ui::TradeMarkClass ui;
	QPushButton *m_buttonLeft;
	QPushButton *m_buttonRight;
	QPushButton *m_buttonReWater;
	QPushButton *m_buttonCut;
	QPushButton *m_buttonGetInfo;
	QLabel *label;

	QLabel *l_number;
	QTextEdit *e_number;
	QLabel *l_date;
	QTextEdit *e_date;
	QLabel *l_logo;
	QLabel *l_logoImage;
	QLabel *l_content;
	QLabel *l_class;
	QTextEdit *e_class; 
	QLabel *l_applicant;
	QTextEdit *e_applicant;
	QLabel *l_address;
	QTextEdit *e_address;
	QLabel *l_agency;
	QTextEdit *e_agency;
	QLabel *l_priority;
	QTextEdit *e_priority;


	HandleImg hi;

	int type;	//0:origin, 1:remove water mark, 
	int num;

	void loadImages();
	String imageName(int type);
	void showImg(int type);
	void showMessage();

};

#endif // TRADEMARK_H
