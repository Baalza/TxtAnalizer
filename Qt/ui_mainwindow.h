/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QWidget *centralwidget;
    QPushButton *Analizza;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QTextEdit *Testo;
    QVBoxLayout *verticalLayout;
    QTableWidget *tabellaRisultati;
    QHBoxLayout *horizontalLayout;
    QFrame *frame;
    QMenuBar *menubar;
    QMenu *menuFile;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(961, 581);
        MainWindow->setMinimumSize(QSize(961, 581));
        MainWindow->setMaximumSize(QSize(961, 581));
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setEnabled(true);
        centralwidget->setMaximumSize(QSize(988, 538));
        Analizza = new QPushButton(centralwidget);
        Analizza->setObjectName(QString::fromUtf8("Analizza"));
        Analizza->setGeometry(QRect(150, 500, 111, 31));
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(19, 19, 931, 471));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        Testo = new QTextEdit(horizontalLayoutWidget);
        Testo->setObjectName(QString::fromUtf8("Testo"));

        horizontalLayout_2->addWidget(Testo);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tabellaRisultati = new QTableWidget(horizontalLayoutWidget);
        if (tabellaRisultati->columnCount() < 1)
            tabellaRisultati->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tabellaRisultati->setHorizontalHeaderItem(0, __qtablewidgetitem);
        if (tabellaRisultati->rowCount() < 5)
            tabellaRisultati->setRowCount(5);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tabellaRisultati->setVerticalHeaderItem(0, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tabellaRisultati->setVerticalHeaderItem(1, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tabellaRisultati->setVerticalHeaderItem(2, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tabellaRisultati->setVerticalHeaderItem(3, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tabellaRisultati->setVerticalHeaderItem(4, __qtablewidgetitem5);
        tabellaRisultati->setObjectName(QString::fromUtf8("tabellaRisultati"));
        tabellaRisultati->setMaximumSize(QSize(16777215, 300));
        tabellaRisultati->setEditTriggers(QAbstractItemView::NoEditTriggers);

        verticalLayout->addWidget(tabellaRisultati);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        frame = new QFrame(horizontalLayoutWidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);

        horizontalLayout->addWidget(frame);


        verticalLayout->addLayout(horizontalLayout);


        horizontalLayout_2->addLayout(verticalLayout);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 961, 21));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menuFile->addAction(actionOpen);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionOpen->setText(QCoreApplication::translate("MainWindow", "Open", nullptr));
        Analizza->setText(QCoreApplication::translate("MainWindow", "Analizza", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tabellaRisultati->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "Risultati", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tabellaRisultati->verticalHeaderItem(0);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Caratteri", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tabellaRisultati->verticalHeaderItem(1);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Caratteri (senza spazi)", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tabellaRisultati->verticalHeaderItem(2);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "Parole", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tabellaRisultati->verticalHeaderItem(3);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "Frasi", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tabellaRisultati->verticalHeaderItem(4);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "Paragrafi", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
