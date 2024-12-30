#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "silnik.h"
#include "silnik.h"
#include <QPixmap>
#include <QMainWindow>
#include <QPushButton>
#include <QString>
#include <QMessageBox>
#include <QApplication>
#include <QTimer>
vector<Szachownica> history;
Szachownica game;
int MV1=0, MV2=0, MV3=0, MV4=0;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    game.init();
    ui->setupUi(this);
    for (int i = 1; i <= 8; ++i) {
        for (int j = 1; j <= 8; ++j) {
            QString buttonName = QString("pole%1%2").arg(i).arg(j);
            QPushButton *button = findChild<QPushButton*>(buttonName);
            if (button) {
                connect(button, &QPushButton::clicked, this, &MainWindow::handleBoardClick);
            }
        }
    }
}
void wait(int milliseconds=50) {
    QEventLoop loop;
    QTimer::singleShot(milliseconds, &loop, &QEventLoop::quit);
    loop.exec();
}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::blok(bool var){
    ui->arrow->setEnabled(var);
    for(int i = 1; i <= 8; ++i) {
        for(int j = 1; j <= 8; ++j) {
            QString buttonName = QString("pole%1%2").arg(i).arg(j);
            QPushButton *button = findChild<QPushButton*>(buttonName);
            button->setEnabled(var);
        }
    }
}
void MainWindow::on_actionAutor_2_triggered()
{
    QMessageBox::about(this, "Autor", "Wiktor Lewicki, viksolve@gmail.com");
}
void MainWindow::koniec(int win){
    refresh();
    if(win==0) QMessageBox::about(this, "Koniec ", "Wygrałeś!");
    else if(win==1) QMessageBox::about(this, "Koniec ", "Przegrałeś!");
    else QMessageBox::about(this, "Koniec ", "Remis!");
    QApplication::quit();
}
int MainWindow::zapytanie(){
    QMessageBox msgBox;
    msgBox.setWindowTitle("Wybór");
    msgBox.setText("Na kogo chcesz zamienić piona?");

    QPushButton *option1 = msgBox.addButton("Wieża", QMessageBox::ActionRole);
    QPushButton *option2 = msgBox.addButton("Skoczek", QMessageBox::ActionRole);
    QPushButton *option3 = msgBox.addButton("Goniec", QMessageBox::ActionRole);
    QPushButton *option4 = msgBox.addButton("Dama", QMessageBox::ActionRole);

    msgBox.exec();
    if (msgBox.clickedButton() == option1) return 1;
    else if (msgBox.clickedButton() == option2) return 2;
    else if (msgBox.clickedButton() == option3) return 3;
    else if (msgBox.clickedButton() == option4) return 4;
    return 4;
}
void MainWindow::MOVE(){
    history.push_back(game);
    int info=game.ruch_gracza(MV1, MV2, MV3, MV4, 1);
    if(info==-1) koniec(0);
    if(game.kto()==1){
        if(info==2) game.nadaj_moc(MV3, MV4, zapytanie());
        if(game.pat()) koniec(2);
        refresh();
        ui->label->setText("Tura bota");
        blok(0);
        QApplication::processEvents();
        wait();
        ans rb=bot(game);
        if(game.ruch_gracza(rb.a, rb.b, rb.c, rb.d, 0)==-1) koniec(1);
        refresh();
        if(game.pat()) koniec(2);
        ui->label->setText("Twoja tura");
        blok(1);
    }
    else{
        history.pop_back();
        QMessageBox::about(this, "BŁĄD", "Zły ruch!");
    }
    MV1=MV2=MV3=MV4=0;
}
QString nazwa(int a, int b){
    QString file_name;
    if((a+b)&1){
        if(game.msc(a, b)==0) file_name=":/img/c.png";
        else if(game.msc(a, b)==1) file_name=":/img/pole_c/1/pion.png";
        else if(game.msc(a, b)==2) file_name=":/img/pole_c/1/wieza.png";
        else if(game.msc(a, b)==3) file_name=":/img/pole_c/1/skoczek.png";
        else if(game.msc(a, b)==4) file_name=":/img/pole_c/1/goniec.png";
        else if(game.msc(a, b)==5) file_name=":/img/pole_c/1/hetman.png";
        else if(game.msc(a, b)==6) file_name=":/img/pole_c/1/krol.png";
        else if(game.msc(a, b)==7) file_name=":/img/pole_c/2/pion.png";
        else if(game.msc(a, b)==8) file_name=":/img/pole_c/2/wieza.png";
        else if(game.msc(a, b)==9) file_name=":/img/pole_c/2/skoczek.png";
        else if(game.msc(a, b)==10) file_name=":/img/pole_c/2/goniec.png";
        else if(game.msc(a, b)==11) file_name=":/img/pole_c/2/hetman.png";
        else if(game.msc(a, b)==12) file_name=":/img/pole_c/2/krol.png";
    }
    else{
        if(game.msc(a, b)==0) file_name=":/img/b.png";
        else if(game.msc(a, b)==1) file_name=":/img/pole_b/1/pion.png";
        else if(game.msc(a, b)==2) file_name=":/img/pole_b/1/wieza.png";
        else if(game.msc(a, b)==3) file_name=":/img/pole_b/1/skoczek.png";
        else if(game.msc(a, b)==4) file_name=":/img/pole_b/1/goniec.png";
        else if(game.msc(a, b)==5) file_name=":/img/pole_b/1/hetman.png";
        else if(game.msc(a, b)==6) file_name=":/img/pole_b/1/krol.png";
        else if(game.msc(a, b)==7) file_name=":/img/pole_b/2/pion.png";
        else if(game.msc(a, b)==8) file_name=":/img/pole_b/2/wieza.png";
        else if(game.msc(a, b)==9) file_name=":/img/pole_b/2/skoczek.png";
        else if(game.msc(a, b)==10) file_name=":/img/pole_b/2/goniec.png";
        else if(game.msc(a, b)==11) file_name=":/img/pole_b/2/hetman.png";
        else if(game.msc(a, b)==12) file_name=":/img/pole_b/2/krol.png";
    }
    return file_name;
}
void MainWindow::refresh(){
    for(int i = 1; i <= 8; ++i) {
        for(int j = 1; j <= 8; ++j) {
            QString buttonName = QString("pole%1%2").arg(i).arg(j);
            QPushButton *button = findChild<QPushButton*>(buttonName);
            button->setIcon(QIcon(nazwa(i, j)));
            button->setIconSize(QSize(80, 80));
        }
    }
}


void MainWindow::handleBoardClick()
{
    QPushButton *clickedButton = qobject_cast<QPushButton*>(sender());
    if (!clickedButton) return;
    QString buttonName = clickedButton->objectName();
    if (buttonName.startsWith("pole")) {
        int x = buttonName.mid(4, 1).toInt();
        int y = buttonName.mid(5, 1).toInt();
        if (MV1 == 0 && MV2 == 0) {
            MV1 = x;
            MV2 = y;
        } else {
            MV3 = x;
            MV4 = y;
            MOVE();
        }
    }
}

void MainWindow::on_arrow_clicked()
{
    if((int)history.size()<1) return;
    game=history.back();
    history.pop_back();
    refresh();
}

