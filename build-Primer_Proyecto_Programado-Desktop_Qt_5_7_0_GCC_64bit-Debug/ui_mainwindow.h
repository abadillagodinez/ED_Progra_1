/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGraphicsView *graphicsView;
    QRadioButton *rbtnPausar;
    QPushButton *btnRandom;
    QPushButton *btnQuick;
    QComboBox *cbxEstructura;
    QComboBox *cbxDato;
    QLabel *lblEstructura;
    QLabel *lblDato;
    QLabel *lblCantidadDatos;
    QSpinBox *sbxCantidad;
    QSpinBox *sbxRango1;
    QLabel *lblRango;
    QSpinBox *sbxRango2;
    QRadioButton *rbtnAdelante;
    QRadioButton *rbtnAtras;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1126, 516);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(60, 200, 931, 231));
        rbtnPausar = new QRadioButton(centralWidget);
        rbtnPausar->setObjectName(QStringLiteral("rbtnPausar"));
        rbtnPausar->setGeometry(QRect(710, 40, 82, 17));
        btnRandom = new QPushButton(centralWidget);
        btnRandom->setObjectName(QStringLiteral("btnRandom"));
        btnRandom->setGeometry(QRect(310, 10, 111, 23));
        btnQuick = new QPushButton(centralWidget);
        btnQuick->setObjectName(QStringLiteral("btnQuick"));
        btnQuick->setGeometry(QRect(590, 10, 75, 23));
        cbxEstructura = new QComboBox(centralWidget);
        cbxEstructura->setObjectName(QStringLiteral("cbxEstructura"));
        cbxEstructura->setGeometry(QRect(110, 10, 151, 23));
        cbxDato = new QComboBox(centralWidget);
        cbxDato->setObjectName(QStringLiteral("cbxDato"));
        cbxDato->setGeometry(QRect(110, 50, 151, 23));
        lblEstructura = new QLabel(centralWidget);
        lblEstructura->setObjectName(QStringLiteral("lblEstructura"));
        lblEstructura->setGeometry(QRect(30, 10, 71, 21));
        lblDato = new QLabel(centralWidget);
        lblDato->setObjectName(QStringLiteral("lblDato"));
        lblDato->setGeometry(QRect(30, 50, 61, 21));
        lblCantidadDatos = new QLabel(centralWidget);
        lblCantidadDatos->setObjectName(QStringLiteral("lblCantidadDatos"));
        lblCantidadDatos->setGeometry(QRect(30, 130, 61, 21));
        sbxCantidad = new QSpinBox(centralWidget);
        sbxCantidad->setObjectName(QStringLiteral("sbxCantidad"));
        sbxCantidad->setEnabled(true);
        sbxCantidad->setGeometry(QRect(110, 130, 151, 24));
        sbxCantidad->setMinimum(10);
        sbxCantidad->setMaximum(100);
        sbxRango1 = new QSpinBox(centralWidget);
        sbxRango1->setObjectName(QStringLiteral("sbxRango1"));
        sbxRango1->setEnabled(true);
        sbxRango1->setGeometry(QRect(110, 90, 71, 24));
        sbxRango1->setMinimum(10);
        sbxRango1->setMaximum(100);
        lblRango = new QLabel(centralWidget);
        lblRango->setObjectName(QStringLiteral("lblRango"));
        lblRango->setGeometry(QRect(30, 90, 61, 21));
        sbxRango2 = new QSpinBox(centralWidget);
        sbxRango2->setObjectName(QStringLiteral("sbxRango2"));
        sbxRango2->setEnabled(true);
        sbxRango2->setGeometry(QRect(190, 90, 71, 24));
        sbxRango2->setMinimum(10);
        sbxRango2->setMaximum(100);
        rbtnAdelante = new QRadioButton(centralWidget);
        rbtnAdelante->setObjectName(QStringLiteral("rbtnAdelante"));
        rbtnAdelante->setGeometry(QRect(710, 10, 100, 21));
        rbtnAtras = new QRadioButton(centralWidget);
        rbtnAtras->setObjectName(QStringLiteral("rbtnAtras"));
        rbtnAtras->setGeometry(QRect(710, 70, 100, 21));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1126, 20));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        cbxEstructura->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        rbtnPausar->setText(QApplication::translate("MainWindow", "Pausar", 0));
        btnRandom->setText(QApplication::translate("MainWindow", "Random", 0));
        btnQuick->setText(QApplication::translate("MainWindow", "QuickSort", 0));
        cbxEstructura->clear();
        cbxEstructura->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Lista Simple", 0)
         << QApplication::translate("MainWindow", "Lista Doble", 0)
         << QApplication::translate("MainWindow", "Lista Doble Circular", 0)
         << QApplication::translate("MainWindow", "Pila", 0)
         << QApplication::translate("MainWindow", "Cola", 0)
        );
        cbxEstructura->setCurrentText(QApplication::translate("MainWindow", "Lista Simple", 0));
        cbxDato->clear();
        cbxDato->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Enteros", 0)
         << QApplication::translate("MainWindow", "Letras", 0)
         << QApplication::translate("MainWindow", "Palabras", 0)
         << QApplication::translate("MainWindow", "Otros", 0)
        );
        lblEstructura->setText(QApplication::translate("MainWindow", "Estructura:", 0));
        lblDato->setText(QApplication::translate("MainWindow", "Dato:", 0));
        lblCantidadDatos->setText(QApplication::translate("MainWindow", "Cantidad:", 0));
        lblRango->setText(QApplication::translate("MainWindow", "Rango:", 0));
        rbtnAdelante->setText(QApplication::translate("MainWindow", "Adelante", 0));
        rbtnAtras->setText(QApplication::translate("MainWindow", "Atr\303\241s", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
