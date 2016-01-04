#ifndef TRADEMARK_H
#define TRADEMARK_H

#include <QtWidgets/QMainWindow>
#include <QtWidgets/qpushbutton.h>
#include <qlabel.h>
#include <qpixmap.h>
#include "ui_trademark.h"

class TradeMark : public QMainWindow
{
	Q_OBJECT

public:
	TradeMark(QWidget *parent = 0);
	~TradeMark();

private slots:
	void handleButton0();


private:

	Ui::TradeMarkClass ui;
	QPushButton *m_button0;
	QLabel *label;

};

#endif // TRADEMARK_H
