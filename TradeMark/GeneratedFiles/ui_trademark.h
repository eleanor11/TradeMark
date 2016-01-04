/********************************************************************************
** Form generated from reading UI file 'trademark.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRADEMARK_H
#define UI_TRADEMARK_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TradeMarkClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *TradeMarkClass)
    {
        if (TradeMarkClass->objectName().isEmpty())
            TradeMarkClass->setObjectName(QStringLiteral("TradeMarkClass"));
        TradeMarkClass->resize(600, 400);
        menuBar = new QMenuBar(TradeMarkClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        TradeMarkClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(TradeMarkClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        TradeMarkClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(TradeMarkClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        TradeMarkClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(TradeMarkClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        TradeMarkClass->setStatusBar(statusBar);

        retranslateUi(TradeMarkClass);

        QMetaObject::connectSlotsByName(TradeMarkClass);
    } // setupUi

    void retranslateUi(QMainWindow *TradeMarkClass)
    {
        TradeMarkClass->setWindowTitle(QApplication::translate("TradeMarkClass", "TradeMark", 0));
    } // retranslateUi

};

namespace Ui {
    class TradeMarkClass: public Ui_TradeMarkClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRADEMARK_H
