/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAutor_2;
    QWidget *centralwidget;
    QPushButton *pole11;
    QPushButton *pole12;
    QPushButton *pole14;
    QPushButton *pole13;
    QPushButton *pole18;
    QPushButton *pole17;
    QPushButton *pole16;
    QPushButton *pole15;
    QPushButton *pole23;
    QPushButton *pole24;
    QPushButton *pole28;
    QPushButton *pole21;
    QPushButton *pole26;
    QPushButton *pole22;
    QPushButton *pole25;
    QPushButton *pole27;
    QPushButton *pole35;
    QPushButton *pole38;
    QPushButton *pole34;
    QPushButton *pole32;
    QPushButton *pole36;
    QPushButton *pole31;
    QPushButton *pole37;
    QPushButton *pole33;
    QPushButton *pole43;
    QPushButton *pole42;
    QPushButton *pole45;
    QPushButton *pole41;
    QPushButton *pole47;
    QPushButton *pole46;
    QPushButton *pole44;
    QPushButton *pole48;
    QPushButton *pole53;
    QPushButton *pole52;
    QPushButton *pole55;
    QPushButton *pole65;
    QPushButton *pole51;
    QPushButton *pole61;
    QPushButton *pole62;
    QPushButton *pole64;
    QPushButton *pole66;
    QPushButton *pole57;
    QPushButton *pole68;
    QPushButton *pole56;
    QPushButton *pole67;
    QPushButton *pole54;
    QPushButton *pole63;
    QPushButton *pole58;
    QPushButton *pole88;
    QPushButton *pole85;
    QPushButton *pole84;
    QPushButton *pole77;
    QPushButton *pole71;
    QPushButton *pole86;
    QPushButton *pole82;
    QPushButton *pole74;
    QPushButton *pole83;
    QPushButton *pole78;
    QPushButton *pole75;
    QPushButton *pole73;
    QPushButton *pole76;
    QPushButton *pole81;
    QPushButton *pole87;
    QPushButton *pole72;
    QLabel *label;
    QMenuBar *menubar;
    QMenu *menuO_programie;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->setEnabled(true);
        MainWindow->resize(900, 800);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(900, 800));
        MainWindow->setMaximumSize(QSize(900, 800));
        MainWindow->setBaseSize(QSize(900, 800));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/pole_b/1/Chess.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setWindowOpacity(2.000000000000000);
        MainWindow->setAutoFillBackground(false);
        actionAutor_2 = new QAction(MainWindow);
        actionAutor_2->setObjectName("actionAutor_2");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        pole11 = new QPushButton(centralwidget);
        pole11->setObjectName("pole11");
        pole11->setGeometry(QRect(50, 60, 80, 80));
        pole11->setCursor(QCursor(Qt::OpenHandCursor));
        pole11->setStyleSheet(QString::fromUtf8("#pole11{\n"
"border-image: url(:/img/pole_b/2/wieza.png)\n"
"}"));
        pole12 = new QPushButton(centralwidget);
        pole12->setObjectName("pole12");
        pole12->setGeometry(QRect(130, 60, 80, 80));
        pole12->setCursor(QCursor(Qt::OpenHandCursor));
        pole12->setStyleSheet(QString::fromUtf8("#pole12{\n"
"border-image: url(:/img/pole_c/2/skoczek.png)\n"
"}"));
        pole14 = new QPushButton(centralwidget);
        pole14->setObjectName("pole14");
        pole14->setGeometry(QRect(290, 60, 80, 80));
        pole14->setCursor(QCursor(Qt::OpenHandCursor));
        pole14->setStyleSheet(QString::fromUtf8("#pole14{\n"
"border-image: url(:/img/pole_c/2/hetman.png)\n"
"}"));
        pole13 = new QPushButton(centralwidget);
        pole13->setObjectName("pole13");
        pole13->setGeometry(QRect(210, 60, 80, 80));
        pole13->setCursor(QCursor(Qt::OpenHandCursor));
        pole13->setStyleSheet(QString::fromUtf8("#pole13{\n"
"border-image: url(:/img/pole_b/2/goniec.png)\n"
"}"));
        pole18 = new QPushButton(centralwidget);
        pole18->setObjectName("pole18");
        pole18->setGeometry(QRect(610, 60, 80, 80));
        pole18->setCursor(QCursor(Qt::OpenHandCursor));
        pole18->setStyleSheet(QString::fromUtf8("#pole18{\n"
"border-image: url(:/img/pole_c/2/wieza.png)\n"
"}"));
        pole17 = new QPushButton(centralwidget);
        pole17->setObjectName("pole17");
        pole17->setGeometry(QRect(530, 60, 80, 80));
        pole17->setCursor(QCursor(Qt::OpenHandCursor));
        pole17->setStyleSheet(QString::fromUtf8("#pole17{\n"
"border-image: url(:/img/pole_b/2/skoczek.png)\n"
"}"));
        pole16 = new QPushButton(centralwidget);
        pole16->setObjectName("pole16");
        pole16->setGeometry(QRect(450, 60, 80, 80));
        pole16->setCursor(QCursor(Qt::OpenHandCursor));
        pole16->setStyleSheet(QString::fromUtf8("#pole16{\n"
"border-image: url(:/img/pole_c/2/goniec.png)\n"
"}"));
        pole15 = new QPushButton(centralwidget);
        pole15->setObjectName("pole15");
        pole15->setGeometry(QRect(370, 60, 80, 80));
        pole15->setCursor(QCursor(Qt::OpenHandCursor));
        pole15->setStyleSheet(QString::fromUtf8("#pole15{\n"
"border-image: url(:/img/pole_b/2/krol.png)\n"
"}"));
        pole23 = new QPushButton(centralwidget);
        pole23->setObjectName("pole23");
        pole23->setGeometry(QRect(210, 140, 80, 80));
        pole23->setCursor(QCursor(Qt::OpenHandCursor));
        pole23->setStyleSheet(QString::fromUtf8("#pole23{\n"
"border-image: url(:/img/pole_c/2/pion.png)\n"
"}"));
        pole24 = new QPushButton(centralwidget);
        pole24->setObjectName("pole24");
        pole24->setGeometry(QRect(290, 140, 80, 80));
        pole24->setCursor(QCursor(Qt::OpenHandCursor));
        pole24->setStyleSheet(QString::fromUtf8("#pole24{\n"
"border-image: url(:/img/pole_b/2/pion.png)\n"
"}"));
        pole28 = new QPushButton(centralwidget);
        pole28->setObjectName("pole28");
        pole28->setGeometry(QRect(610, 140, 80, 80));
        pole28->setCursor(QCursor(Qt::OpenHandCursor));
        pole28->setStyleSheet(QString::fromUtf8("#pole28{\n"
"border-image: url(:/img/pole_b/2/pion.png)\n"
"}"));
        pole21 = new QPushButton(centralwidget);
        pole21->setObjectName("pole21");
        pole21->setGeometry(QRect(50, 140, 80, 80));
        pole21->setCursor(QCursor(Qt::OpenHandCursor));
        pole21->setStyleSheet(QString::fromUtf8("#pole21{\n"
"border-image: url(:/img/pole_c/2/pion.png)\n"
"}"));
        pole26 = new QPushButton(centralwidget);
        pole26->setObjectName("pole26");
        pole26->setGeometry(QRect(450, 140, 80, 80));
        pole26->setCursor(QCursor(Qt::OpenHandCursor));
        pole26->setStyleSheet(QString::fromUtf8("#pole26{\n"
"border-image: url(:/img/pole_b/2/pion.png)\n"
"}"));
        pole22 = new QPushButton(centralwidget);
        pole22->setObjectName("pole22");
        pole22->setGeometry(QRect(130, 140, 80, 80));
        pole22->setCursor(QCursor(Qt::OpenHandCursor));
        pole22->setStyleSheet(QString::fromUtf8("#pole22{\n"
"border-image: url(:/img/pole_b/2/pion.png)\n"
"}"));
        pole25 = new QPushButton(centralwidget);
        pole25->setObjectName("pole25");
        pole25->setGeometry(QRect(370, 140, 80, 80));
        pole25->setCursor(QCursor(Qt::OpenHandCursor));
        pole25->setStyleSheet(QString::fromUtf8("#pole25{\n"
"border-image: url(:/img/pole_c/2/pion.png)\n"
"}"));
        pole27 = new QPushButton(centralwidget);
        pole27->setObjectName("pole27");
        pole27->setGeometry(QRect(530, 140, 80, 80));
        pole27->setCursor(QCursor(Qt::OpenHandCursor));
        pole27->setStyleSheet(QString::fromUtf8("#pole27{\n"
"border-image: url(:/img/pole_c/2/pion.png)\n"
"}"));
        pole35 = new QPushButton(centralwidget);
        pole35->setObjectName("pole35");
        pole35->setGeometry(QRect(370, 220, 80, 80));
        pole35->setCursor(QCursor(Qt::OpenHandCursor));
        pole35->setStyleSheet(QString::fromUtf8("#pole35{\n"
"border-image: url(:/img/b.png)\n"
"}"));
        pole38 = new QPushButton(centralwidget);
        pole38->setObjectName("pole38");
        pole38->setGeometry(QRect(610, 220, 80, 80));
        pole38->setCursor(QCursor(Qt::OpenHandCursor));
        pole38->setStyleSheet(QString::fromUtf8("#pole38{\n"
"border-image: url(:/img/c.png)\n"
"}"));
        pole34 = new QPushButton(centralwidget);
        pole34->setObjectName("pole34");
        pole34->setGeometry(QRect(290, 220, 80, 80));
        pole34->setCursor(QCursor(Qt::OpenHandCursor));
        pole34->setStyleSheet(QString::fromUtf8("#pole34{\n"
"border-image: url(:/img/c.png)\n"
"}"));
        pole32 = new QPushButton(centralwidget);
        pole32->setObjectName("pole32");
        pole32->setGeometry(QRect(130, 220, 80, 80));
        pole32->setCursor(QCursor(Qt::OpenHandCursor));
        pole32->setStyleSheet(QString::fromUtf8("#pole32{\n"
"border-image: url(:/img/c.png)\n"
"}"));
        pole36 = new QPushButton(centralwidget);
        pole36->setObjectName("pole36");
        pole36->setGeometry(QRect(450, 220, 80, 80));
        pole36->setCursor(QCursor(Qt::OpenHandCursor));
        pole36->setStyleSheet(QString::fromUtf8("#pole36{\n"
"border-image: url(:/img/c.png)\n"
"}"));
        pole31 = new QPushButton(centralwidget);
        pole31->setObjectName("pole31");
        pole31->setGeometry(QRect(50, 220, 80, 80));
        pole31->setCursor(QCursor(Qt::OpenHandCursor));
        pole31->setStyleSheet(QString::fromUtf8("#pole31{\n"
"border-image: url(:/img/b.png)\n"
"}"));
        pole37 = new QPushButton(centralwidget);
        pole37->setObjectName("pole37");
        pole37->setGeometry(QRect(530, 220, 80, 80));
        pole37->setCursor(QCursor(Qt::OpenHandCursor));
        pole37->setStyleSheet(QString::fromUtf8("#pole37{\n"
"border-image: url(:/img/b.png)\n"
"}"));
        pole33 = new QPushButton(centralwidget);
        pole33->setObjectName("pole33");
        pole33->setGeometry(QRect(210, 220, 80, 80));
        pole33->setCursor(QCursor(Qt::OpenHandCursor));
        pole33->setStyleSheet(QString::fromUtf8("#pole33{\n"
"border-image: url(:/img/b.png)\n"
"}"));
        pole43 = new QPushButton(centralwidget);
        pole43->setObjectName("pole43");
        pole43->setGeometry(QRect(210, 300, 80, 80));
        pole43->setCursor(QCursor(Qt::OpenHandCursor));
        pole43->setStyleSheet(QString::fromUtf8("#pole43{\n"
"border-image: url(:/img/c.png)\n"
"}"));
        pole42 = new QPushButton(centralwidget);
        pole42->setObjectName("pole42");
        pole42->setGeometry(QRect(130, 300, 80, 80));
        pole42->setCursor(QCursor(Qt::OpenHandCursor));
        pole42->setStyleSheet(QString::fromUtf8("#pole42{\n"
"border-image: url(:/img/b.png)\n"
"}"));
        pole45 = new QPushButton(centralwidget);
        pole45->setObjectName("pole45");
        pole45->setGeometry(QRect(370, 300, 80, 80));
        pole45->setCursor(QCursor(Qt::OpenHandCursor));
        pole45->setStyleSheet(QString::fromUtf8("#pole45{\n"
"border-image: url(:/img/c.png)\n"
"}"));
        pole41 = new QPushButton(centralwidget);
        pole41->setObjectName("pole41");
        pole41->setGeometry(QRect(50, 300, 80, 80));
        pole41->setCursor(QCursor(Qt::OpenHandCursor));
        pole41->setStyleSheet(QString::fromUtf8("#pole41{\n"
"border-image: url(:/img/c.png)\n"
"}"));
        pole47 = new QPushButton(centralwidget);
        pole47->setObjectName("pole47");
        pole47->setGeometry(QRect(530, 300, 80, 80));
        pole47->setCursor(QCursor(Qt::OpenHandCursor));
        pole47->setStyleSheet(QString::fromUtf8("#pole47{\n"
"border-image: url(:/img/c.png)\n"
"}"));
        pole46 = new QPushButton(centralwidget);
        pole46->setObjectName("pole46");
        pole46->setGeometry(QRect(450, 300, 80, 80));
        pole46->setCursor(QCursor(Qt::OpenHandCursor));
        pole46->setStyleSheet(QString::fromUtf8("#pole46{\n"
"border-image: url(:/img/b.png)\n"
"}"));
        pole44 = new QPushButton(centralwidget);
        pole44->setObjectName("pole44");
        pole44->setGeometry(QRect(290, 300, 80, 80));
        pole44->setCursor(QCursor(Qt::OpenHandCursor));
        pole44->setStyleSheet(QString::fromUtf8("#pole44{\n"
"border-image: url(:/img/b.png)\n"
"}"));
        pole48 = new QPushButton(centralwidget);
        pole48->setObjectName("pole48");
        pole48->setGeometry(QRect(610, 300, 80, 80));
        pole48->setCursor(QCursor(Qt::OpenHandCursor));
        pole48->setStyleSheet(QString::fromUtf8("#pole48{\n"
"border-image: url(:/img/b.png)\n"
"}"));
        pole53 = new QPushButton(centralwidget);
        pole53->setObjectName("pole53");
        pole53->setGeometry(QRect(210, 380, 80, 80));
        pole53->setCursor(QCursor(Qt::OpenHandCursor));
        pole53->setStyleSheet(QString::fromUtf8("#pole53{\n"
"border-image: url(:/img/b.png)\n"
"}"));
        pole52 = new QPushButton(centralwidget);
        pole52->setObjectName("pole52");
        pole52->setGeometry(QRect(130, 380, 80, 80));
        pole52->setCursor(QCursor(Qt::OpenHandCursor));
        pole52->setStyleSheet(QString::fromUtf8("#pole52{\n"
"border-image: url(:/img/c.png)\n"
"}"));
        pole55 = new QPushButton(centralwidget);
        pole55->setObjectName("pole55");
        pole55->setGeometry(QRect(370, 380, 80, 80));
        pole55->setCursor(QCursor(Qt::OpenHandCursor));
        pole55->setStyleSheet(QString::fromUtf8("#pole55{\n"
"border-image: url(:/img/b.png)\n"
"}"));
        pole65 = new QPushButton(centralwidget);
        pole65->setObjectName("pole65");
        pole65->setGeometry(QRect(370, 460, 80, 80));
        pole65->setCursor(QCursor(Qt::OpenHandCursor));
        pole65->setStyleSheet(QString::fromUtf8("#pole65{\n"
"border-image: url(:/img/c.png)\n"
"}"));
        pole51 = new QPushButton(centralwidget);
        pole51->setObjectName("pole51");
        pole51->setGeometry(QRect(50, 380, 80, 80));
        pole51->setCursor(QCursor(Qt::OpenHandCursor));
        pole51->setStyleSheet(QString::fromUtf8("#pole51{\n"
"border-image: url(:/img/b.png)\n"
"}"));
        pole61 = new QPushButton(centralwidget);
        pole61->setObjectName("pole61");
        pole61->setGeometry(QRect(50, 460, 80, 80));
        pole61->setCursor(QCursor(Qt::OpenHandCursor));
        pole61->setStyleSheet(QString::fromUtf8("#pole61{\n"
"border-image: url(:/img/c.png)\n"
"}"));
        pole62 = new QPushButton(centralwidget);
        pole62->setObjectName("pole62");
        pole62->setGeometry(QRect(130, 460, 80, 80));
        pole62->setCursor(QCursor(Qt::OpenHandCursor));
        pole62->setStyleSheet(QString::fromUtf8("#pole62{\n"
"border-image: url(:/img/b.png)\n"
"}"));
        pole64 = new QPushButton(centralwidget);
        pole64->setObjectName("pole64");
        pole64->setGeometry(QRect(290, 460, 80, 80));
        pole64->setCursor(QCursor(Qt::OpenHandCursor));
        pole64->setStyleSheet(QString::fromUtf8("#pole64{\n"
"border-image: url(:/img/b.png)\n"
"}"));
        pole66 = new QPushButton(centralwidget);
        pole66->setObjectName("pole66");
        pole66->setGeometry(QRect(450, 460, 80, 80));
        pole66->setCursor(QCursor(Qt::OpenHandCursor));
        pole66->setStyleSheet(QString::fromUtf8("#pole66{\n"
"border-image: url(:/img/b.png)\n"
"}"));
        pole57 = new QPushButton(centralwidget);
        pole57->setObjectName("pole57");
        pole57->setGeometry(QRect(530, 380, 80, 80));
        pole57->setCursor(QCursor(Qt::OpenHandCursor));
        pole57->setStyleSheet(QString::fromUtf8("#pole57{\n"
"border-image: url(:/img/b.png)\n"
"}"));
        pole68 = new QPushButton(centralwidget);
        pole68->setObjectName("pole68");
        pole68->setGeometry(QRect(610, 460, 80, 80));
        pole68->setCursor(QCursor(Qt::OpenHandCursor));
        pole68->setStyleSheet(QString::fromUtf8("#pole68{\n"
"border-image: url(:/img/b.png)\n"
"}"));
        pole56 = new QPushButton(centralwidget);
        pole56->setObjectName("pole56");
        pole56->setGeometry(QRect(450, 380, 80, 80));
        pole56->setCursor(QCursor(Qt::OpenHandCursor));
        pole56->setStyleSheet(QString::fromUtf8("#pole56{\n"
"border-image: url(:/img/c.png)\n"
"}"));
        pole67 = new QPushButton(centralwidget);
        pole67->setObjectName("pole67");
        pole67->setGeometry(QRect(530, 460, 80, 80));
        pole67->setCursor(QCursor(Qt::OpenHandCursor));
        pole67->setStyleSheet(QString::fromUtf8("#pole67{\n"
"border-image: url(:/img/c.png)\n"
"}"));
        pole54 = new QPushButton(centralwidget);
        pole54->setObjectName("pole54");
        pole54->setGeometry(QRect(290, 380, 80, 80));
        pole54->setCursor(QCursor(Qt::OpenHandCursor));
        pole54->setStyleSheet(QString::fromUtf8("#pole54{\n"
"border-image: url(:/img/c.png)\n"
"}"));
        pole63 = new QPushButton(centralwidget);
        pole63->setObjectName("pole63");
        pole63->setGeometry(QRect(210, 460, 80, 80));
        pole63->setCursor(QCursor(Qt::OpenHandCursor));
        pole63->setStyleSheet(QString::fromUtf8("#pole63{\n"
"border-image: url(:/img/c.png)\n"
"}"));
        pole58 = new QPushButton(centralwidget);
        pole58->setObjectName("pole58");
        pole58->setGeometry(QRect(610, 380, 80, 80));
        pole58->setCursor(QCursor(Qt::OpenHandCursor));
        pole58->setStyleSheet(QString::fromUtf8("#pole58{\n"
"border-image: url(:/img/c.png)\n"
"}"));
        pole88 = new QPushButton(centralwidget);
        pole88->setObjectName("pole88");
        pole88->setGeometry(QRect(610, 620, 80, 80));
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pole88->sizePolicy().hasHeightForWidth());
        pole88->setSizePolicy(sizePolicy1);
        pole88->setCursor(QCursor(Qt::OpenHandCursor));
        pole88->setStyleSheet(QString::fromUtf8("#pole88{\n"
"border-image: url(:/img/pole_b/1/wieza.png)\n"
"}"));
        pole85 = new QPushButton(centralwidget);
        pole85->setObjectName("pole85");
        pole85->setGeometry(QRect(370, 620, 80, 80));
        pole85->setCursor(QCursor(Qt::OpenHandCursor));
        pole85->setStyleSheet(QString::fromUtf8("#pole85{\n"
"border-image: url(:/img/pole_c/1/krol.png)\n"
"}"));
        pole84 = new QPushButton(centralwidget);
        pole84->setObjectName("pole84");
        pole84->setGeometry(QRect(290, 620, 80, 80));
        pole84->setCursor(QCursor(Qt::OpenHandCursor));
        pole84->setStyleSheet(QString::fromUtf8("#pole84{\n"
"border-image: url(:/img/pole_b/1/hetman.png)\n"
"}"));
        pole77 = new QPushButton(centralwidget);
        pole77->setObjectName("pole77");
        pole77->setGeometry(QRect(530, 540, 80, 80));
        pole77->setCursor(QCursor(Qt::OpenHandCursor));
        pole77->setStyleSheet(QString::fromUtf8("#pole77{\n"
"border-image: url(:/img/pole_b/1/pion.png)\n"
"}"));
        pole71 = new QPushButton(centralwidget);
        pole71->setObjectName("pole71");
        pole71->setGeometry(QRect(50, 540, 80, 80));
        pole71->setCursor(QCursor(Qt::OpenHandCursor));
        pole71->setStyleSheet(QString::fromUtf8("#pole71{\n"
"border-image: url(:/img/pole_b/1/pion.png)\n"
"}"));
        pole86 = new QPushButton(centralwidget);
        pole86->setObjectName("pole86");
        pole86->setGeometry(QRect(450, 620, 80, 80));
        pole86->setCursor(QCursor(Qt::OpenHandCursor));
        pole86->setStyleSheet(QString::fromUtf8("#pole86{\n"
"border-image: url(:/img/pole_b/1/goniec.png)\n"
"}"));
        pole82 = new QPushButton(centralwidget);
        pole82->setObjectName("pole82");
        pole82->setGeometry(QRect(130, 620, 80, 80));
        pole82->setCursor(QCursor(Qt::OpenHandCursor));
        pole82->setStyleSheet(QString::fromUtf8("#pole82{\n"
"border-image: url(:/img/pole_b/1/skoczek.png)\n"
"}"));
        pole74 = new QPushButton(centralwidget);
        pole74->setObjectName("pole74");
        pole74->setGeometry(QRect(290, 540, 80, 80));
        pole74->setCursor(QCursor(Qt::OpenHandCursor));
        pole74->setStyleSheet(QString::fromUtf8("#pole74{\n"
"border-image: url(:/img/pole_c/1/pion.png)\n"
"}"));
        pole83 = new QPushButton(centralwidget);
        pole83->setObjectName("pole83");
        pole83->setGeometry(QRect(210, 620, 80, 80));
        pole83->setCursor(QCursor(Qt::OpenHandCursor));
        pole83->setStyleSheet(QString::fromUtf8("#pole83{\n"
"border-image: url(:/img/pole_c/1/goniec.png)\n"
"}"));
        pole78 = new QPushButton(centralwidget);
        pole78->setObjectName("pole78");
        pole78->setGeometry(QRect(610, 540, 80, 80));
        pole78->setCursor(QCursor(Qt::OpenHandCursor));
        pole78->setStyleSheet(QString::fromUtf8("#pole78{\n"
"border-image: url(:/img/pole_c/1/pion.png)\n"
"}"));
        pole75 = new QPushButton(centralwidget);
        pole75->setObjectName("pole75");
        pole75->setGeometry(QRect(370, 540, 80, 80));
        pole75->setCursor(QCursor(Qt::OpenHandCursor));
        pole75->setStyleSheet(QString::fromUtf8("#pole75{\n"
"border-image: url(:/img/pole_b/1/pion.png)\n"
"}"));
        pole73 = new QPushButton(centralwidget);
        pole73->setObjectName("pole73");
        pole73->setGeometry(QRect(210, 540, 80, 80));
        pole73->setCursor(QCursor(Qt::OpenHandCursor));
        pole73->setStyleSheet(QString::fromUtf8("#pole73{\n"
"border-image: url(:/img/pole_b/1/pion.png)\n"
"}"));
        pole76 = new QPushButton(centralwidget);
        pole76->setObjectName("pole76");
        pole76->setGeometry(QRect(450, 540, 80, 80));
        pole76->setCursor(QCursor(Qt::OpenHandCursor));
        pole76->setStyleSheet(QString::fromUtf8("#pole76{\n"
"border-image: url(:/img/pole_c/1/pion.png)\n"
"}"));
        pole81 = new QPushButton(centralwidget);
        pole81->setObjectName("pole81");
        pole81->setGeometry(QRect(50, 620, 80, 80));
        pole81->setCursor(QCursor(Qt::OpenHandCursor));
        pole81->setStyleSheet(QString::fromUtf8("#pole81{\n"
"border-image: url(:/img/pole_c/1/wieza.png)\n"
"}"));
        pole87 = new QPushButton(centralwidget);
        pole87->setObjectName("pole87");
        pole87->setGeometry(QRect(530, 620, 80, 80));
        pole87->setCursor(QCursor(Qt::OpenHandCursor));
        pole87->setStyleSheet(QString::fromUtf8("#pole87{\n"
"border-image: url(:/img/pole_c/1/skoczek.png)\n"
"}"));
        pole72 = new QPushButton(centralwidget);
        pole72->setObjectName("pole72");
        pole72->setGeometry(QRect(130, 540, 80, 80));
        pole72->setCursor(QCursor(Qt::OpenHandCursor));
        pole72->setStyleSheet(QString::fromUtf8("#pole72{\n"
"border-image: url(:/img/pole_c/1/pion.png)\n"
"}"));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(710, 360, 181, 51));
        QFont font;
        font.setPointSize(22);
        label->setFont(font);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 900, 25));
        menuO_programie = new QMenu(menubar);
        menuO_programie->setObjectName("menuO_programie");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuO_programie->menuAction());
        menuO_programie->addAction(actionAutor_2);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Szachy by Wiktor Lewicki", nullptr));
        actionAutor_2->setText(QCoreApplication::translate("MainWindow", "Autor", nullptr));
        pole11->setText(QString());
        pole12->setText(QString());
        pole14->setText(QString());
        pole13->setText(QString());
        pole18->setText(QString());
        pole17->setText(QString());
        pole16->setText(QString());
        pole15->setText(QString());
        pole23->setText(QString());
        pole24->setText(QString());
        pole28->setText(QString());
        pole21->setText(QString());
        pole26->setText(QString());
        pole22->setText(QString());
        pole25->setText(QString());
        pole27->setText(QString());
        pole35->setText(QString());
        pole38->setText(QString());
        pole34->setText(QString());
        pole32->setText(QString());
        pole36->setText(QString());
        pole31->setText(QString());
        pole37->setText(QString());
        pole33->setText(QString());
        pole43->setText(QString());
        pole42->setText(QString());
        pole45->setText(QString());
        pole41->setText(QString());
        pole47->setText(QString());
        pole46->setText(QString());
        pole44->setText(QString());
        pole48->setText(QString());
        pole53->setText(QString());
        pole52->setText(QString());
        pole55->setText(QString());
        pole65->setText(QString());
        pole51->setText(QString());
        pole61->setText(QString());
        pole62->setText(QString());
        pole64->setText(QString());
        pole66->setText(QString());
        pole57->setText(QString());
        pole68->setText(QString());
        pole56->setText(QString());
        pole67->setText(QString());
        pole54->setText(QString());
        pole63->setText(QString());
        pole58->setText(QString());
        pole88->setText(QString());
        pole85->setText(QString());
        pole84->setText(QString());
        pole77->setText(QString());
        pole71->setText(QString());
        pole86->setText(QString());
        pole82->setText(QString());
        pole74->setText(QString());
        pole83->setText(QString());
        pole78->setText(QString());
        pole75->setText(QString());
        pole73->setText(QString());
        pole76->setText(QString());
        pole81->setText(QString());
        pole87->setText(QString());
        pole72->setText(QString());
        label->setText(QCoreApplication::translate("MainWindow", "Twoja Tura", nullptr));
        menuO_programie->setTitle(QCoreApplication::translate("MainWindow", "O programie", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
