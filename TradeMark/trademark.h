#ifndef TRADEMARK_H
#define TRADEMARK_H

#include <QtWidgets/QMainWindow>
#include <QtWidgets/qpushbutton.h>
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

	void loadImages();
	String imageName();
	void showImg();

private:

	Ui::TradeMarkClass ui;
	QPushButton *m_buttonLeft;
	QPushButton *m_buttonRight;
	QPushButton *m_buttonReWater;
	QPushButton *m_buttonCut;
	QPushButton *m_buttonGetInfo;
	QLabel *label;

	HandleImg hi;

	int type;	//0:origin, 1:remove water mark, 
	int num;

};

#endif // TRADEMARK_H
