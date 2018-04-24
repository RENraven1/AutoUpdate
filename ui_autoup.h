/********************************************************************************
** Form generated from reading UI file 'autoup.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUTOUP_H
#define UI_AUTOUP_H

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

class Ui_autoup
{
public:
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *autoup)
    {
        if (autoup->objectName().isEmpty())
            autoup->setObjectName(QStringLiteral("autoup"));
        autoup->resize(751, 360);
        centralWidget = new QWidget(autoup);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        autoup->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(autoup);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 751, 21));
        autoup->setMenuBar(menuBar);
        mainToolBar = new QToolBar(autoup);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        autoup->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(autoup);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        autoup->setStatusBar(statusBar);

        retranslateUi(autoup);

        QMetaObject::connectSlotsByName(autoup);
    } // setupUi

    void retranslateUi(QMainWindow *autoup)
    {
        autoup->setWindowTitle(QApplication::translate("autoup", "autoup", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class autoup: public Ui_autoup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUTOUP_H
