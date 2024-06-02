#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "bot.cpp"
#include <QMessageBox>
#include <QPixmap>
Szachownica game;
int MV1=0, MV2=0, MV3=0, MV4=0;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    game.init();
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::blok(bool var){
    //ui->centralwidget->setEnabled(var);
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
    else return 4;
}
void MainWindow::MOVE(){
    int info=game.ruch_gracza(MV1, MV2, MV3, MV4, 1);
    if(info==-1) koniec(0);
    if(game.kto()==1){
        if(info==2) game.nadaj_moc(MV3, MV4, zapytanie());
        if(game.pat()) koniec(2);
        refresh();
        ui->label->setText("Tura bota");
        blok(0);
        QApplication::processEvents();
        _sleep(1);
        ans rb=bot(game);
        if(game.ruch_gracza(rb.a, rb.b, rb.c, rb.d, 0)==-1) koniec(1);
        refresh();
        if(game.pat()) koniec(2);
        ui->label->setText("Twoja tura");
        blok(1);
    }
    else QMessageBox::about(this, "BŁĄD", "Zły ruch!");
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

void MainWindow::on_pole11_clicked()
{
    if(MV1==0&&MV2==0) MV1=1, MV2=1;
    else{
        MV3=1, MV4=1;
        MOVE();
    }
}


void MainWindow::on_pole12_clicked()
{
    if(MV1==0&&MV2==0) MV1=1, MV2=2;
    else{
        MV3=1, MV4=2;
        MOVE();
    }
}


void MainWindow::on_pole13_clicked()
{
    if(MV1==0&&MV2==0) MV1=1, MV2=3;
    else{
        MV3=1, MV4=3;
        MOVE();
    }
}


void MainWindow::on_pole14_clicked()
{
    if(MV1==0&&MV2==0) MV1=1, MV2=4;
    else{
        MV3=1, MV4=4;
        MOVE();
    }
}


void MainWindow::on_pole15_clicked()
{
    if(MV1==0&&MV2==0) MV1=1, MV2=5;
    else{
        MV3=1, MV4=5;
        MOVE();
    }
}


void MainWindow::on_pole16_clicked()
{
    if(MV1==0&&MV2==0) MV1=1, MV2=6;
    else{
        MV3=1, MV4=6;
        MOVE();
    }
}


void MainWindow::on_pole17_clicked()
{
    if(MV1==0&&MV2==0) MV1=1, MV2=7;
    else{
        MV3=1, MV4=7;
        MOVE();
    }
}


void MainWindow::on_pole18_clicked()
{
    if(MV1==0&&MV2==0) MV1=1, MV2=8;
    else{
        MV3=1, MV4=8;
        MOVE();
    }
}


void MainWindow::on_pole21_clicked()
{
    if(MV1==0&&MV2==0) MV1=2, MV2=1;
    else{
        MV3=2, MV4=1;
        MOVE();
    }
}


void MainWindow::on_pole22_clicked()
{
    if(MV1==0&&MV2==0) MV1=2, MV2=2;
    else{
        MV3=2, MV4=2;
        MOVE();
    }
}


void MainWindow::on_pole23_clicked()
{
    if(MV1==0&&MV2==0) MV1=2, MV2=3;
    else{
        MV3=2, MV4=3;
        MOVE();
    }
}


void MainWindow::on_pole24_clicked()
{
    if(MV1==0&&MV2==0) MV1=2, MV2=4;
    else{
        MV3=2, MV4=4;
        MOVE();
    }
}


void MainWindow::on_pole25_clicked()
{
    if(MV1==0&&MV2==0) MV1=2, MV2=5;
    else{
        MV3=2, MV4=5;
        MOVE();
    }
}


void MainWindow::on_pole26_clicked()
{
    if(MV1==0&&MV2==0) MV1=2, MV2=6;
    else{
        MV3=2, MV4=6;
        MOVE();
    }
}


void MainWindow::on_pole27_clicked()
{
    if(MV1==0&&MV2==0) MV1=2, MV2=7;
    else{
        MV3=2, MV4=7;
        MOVE();
    }
}


void MainWindow::on_pole28_clicked()
{
    if(MV1==0&&MV2==0) MV1=2, MV2=8;
    else{
        MV3=2, MV4=8;
        MOVE();
    }
}


void MainWindow::on_pole31_clicked()
{
    if(MV1==0&&MV2==0) MV1=3, MV2=1;
    else{
        MV3=3, MV4=1;
        MOVE();
    }
}


void MainWindow::on_pole32_clicked()
{
    if(MV1==0&&MV2==0) MV1=3, MV2=2;
    else{
        MV3=3, MV4=2;
        MOVE();
    }
}


void MainWindow::on_pole33_clicked()
{
    if(MV1==0&&MV2==0) MV1=3, MV2=3;
    else{
        MV3=3, MV4=3;
        MOVE();
    }
}


void MainWindow::on_pole34_clicked()
{
    if(MV1==0&&MV2==0) MV1=3, MV2=4;
    else{
        MV3=3, MV4=4;
        MOVE();
    }
}


void MainWindow::on_pole35_clicked()
{
    if(MV1==0&&MV2==0) MV1=3, MV2=5;
    else{
        MV3=3, MV4=5;
        MOVE();
    }
}


void MainWindow::on_pole36_clicked()
{
    if(MV1==0&&MV2==0) MV1=3, MV2=6;
    else{
        MV3=3, MV4=6;
        MOVE();
    }
}


void MainWindow::on_pole37_clicked()
{
    if(MV1==0&&MV2==0) MV1=3, MV2=7;
    else{
        MV3=3, MV4=7;
        MOVE();
    }
}


void MainWindow::on_pole38_clicked()
{
    if(MV1==0&&MV2==0) MV1=3, MV2=8;
    else{
        MV3=3, MV4=8;
        MOVE();
    }
}


void MainWindow::on_pole41_clicked()
{
    if(MV1==0&&MV2==0) MV1=4, MV2=1;
    else{
        MV3=4, MV4=1;
        MOVE();
    }
}


void MainWindow::on_pole42_clicked()
{
    if(MV1==0&&MV2==0) MV1=4, MV2=2;
    else{
        MV3=4, MV4=2;
        MOVE();
    }
}


void MainWindow::on_pole43_clicked()
{
    if(MV1==0&&MV2==0) MV1=4, MV2=3;
    else{
        MV3=4, MV4=3;
        MOVE();
    }
}


void MainWindow::on_pole44_clicked()
{
    if(MV1==0&&MV2==0) MV1=4, MV2=4;
    else{
        MV3=4, MV4=4;
        MOVE();
    }
}


void MainWindow::on_pole45_clicked()
{
    if(MV1==0&&MV2==0) MV1=4, MV2=5;
    else{
        MV3=4, MV4=5;
        MOVE();
    }
}


void MainWindow::on_pole46_clicked()
{
    if(MV1==0&&MV2==0) MV1=4, MV2=6;
    else{
        MV3=4, MV4=6;
        MOVE();
    }
}


void MainWindow::on_pole47_clicked()
{
    if(MV1==0&&MV2==0) MV1=4, MV2=7;
    else{
        MV3=4, MV4=7;
        MOVE();
    }
}


void MainWindow::on_pole48_clicked()
{
    if(MV1==0&&MV2==0) MV1=4, MV2=8;
    else{
        MV3=4, MV4=8;
        MOVE();
    }
}


void MainWindow::on_pole51_clicked()
{
    if(MV1==0&&MV2==0) MV1=5, MV2=1;
    else{
        MV3=5, MV4=1;
        MOVE();
    }
}


void MainWindow::on_pole52_clicked()
{
    if(MV1==0&&MV2==0) MV1=5, MV2=2;
    else{
        MV3=5, MV4=2;
        MOVE();
    }
}


void MainWindow::on_pole53_clicked()
{
    if(MV1==0&&MV2==0) MV1=5, MV2=3;
    else{
        MV3=5, MV4=3;
        MOVE();
    }
}


void MainWindow::on_pole54_clicked()
{
    if(MV1==0&&MV2==0) MV1=5, MV2=4;
    else{
        MV3=5, MV4=4;
        MOVE();
    }
}


void MainWindow::on_pole55_clicked()
{
    if(MV1==0&&MV2==0) MV1=5, MV2=5;
    else{
        MV3=5, MV4=5;
        MOVE();
    }
}


void MainWindow::on_pole56_clicked()
{
    if(MV1==0&&MV2==0) MV1=5, MV2=6;
    else{
        MV3=5, MV4=6;
        MOVE();
    }
}


void MainWindow::on_pole57_clicked()
{
    if(MV1==0&&MV2==0) MV1=5, MV2=7;
    else{
        MV3=5, MV4=7;
        MOVE();
    }
}


void MainWindow::on_pole58_clicked()
{
    if(MV1==0&&MV2==0) MV1=5, MV2=8;
    else{
        MV3=5, MV4=8;
        MOVE();
    }
}


void MainWindow::on_pole61_clicked()
{
    if(MV1==0&&MV2==0) MV1=6, MV2=1;
    else{
        MV3=6, MV4=1;
        MOVE();
    }
}


void MainWindow::on_pole62_clicked()
{
    if(MV1==0&&MV2==0) MV1=6, MV2=2;
    else{
        MV3=6, MV4=2;
        MOVE();
    }
}


void MainWindow::on_pole63_clicked()
{
    if(MV1==0&&MV2==0) MV1=6, MV2=3;
    else{
        MV3=6, MV4=3;
        MOVE();
    }
}


void MainWindow::on_pole64_clicked()
{
    if(MV1==0&&MV2==0) MV1=6, MV2=4;
    else{
        MV3=6, MV4=4;
        MOVE();
    }
}


void MainWindow::on_pole65_clicked()
{
    if(MV1==0&&MV2==0) MV1=6, MV2=5;
    else{
        MV3=6, MV4=5;
        MOVE();
    }
}


void MainWindow::on_pole66_clicked()
{
    if(MV1==0&&MV2==0) MV1=6, MV2=6;
    else{
        MV3=6, MV4=6;
        MOVE();
    }
}


void MainWindow::on_pole67_clicked()
{
    if(MV1==0&&MV2==0) MV1=6, MV2=7;
    else{
        MV3=6, MV4=7;
        MOVE();
    }
}


void MainWindow::on_pole68_clicked()
{
    if(MV1==0&&MV2==0) MV1=6, MV2=8;
    else{
        MV3=6, MV4=8;
        MOVE();
    }
}


void MainWindow::on_pole71_clicked()
{
    if(MV1==0&&MV2==0) MV1=7, MV2=1;
    else{
        MV3=7, MV4=1;
        MOVE();
    }
}


void MainWindow::on_pole72_clicked()
{
    if(MV1==0&&MV2==0) MV1=7, MV2=2;
    else{
        MV3=7, MV4=2;
        MOVE();
    }
}


void MainWindow::on_pole73_clicked()
{
    if(MV1==0&&MV2==0) MV1=7, MV2=3;
    else{
        MV3=7, MV4=3;
        MOVE();
    }
}


void MainWindow::on_pole74_clicked()
{
    if(MV1==0&&MV2==0) MV1=7, MV2=4;
    else{
        MV3=7, MV4=4;
        MOVE();
    }
}


void MainWindow::on_pole75_clicked()
{
    if(MV1==0&&MV2==0) MV1=7, MV2=5;
    else{
        MV3=7, MV4=5;
        MOVE();
    }
}


void MainWindow::on_pole76_clicked()
{
    if(MV1==0&&MV2==0) MV1=7, MV2=6;
    else{
        MV3=7, MV4=6;
        MOVE();
    }
}


void MainWindow::on_pole77_clicked()
{
    if(MV1==0&&MV2==0) MV1=7, MV2=7;
    else{
        MV3=7, MV4=7;
        MOVE();
    }
}


void MainWindow::on_pole78_clicked()
{
    if(MV1==0&&MV2==0) MV1=7, MV2=8;
    else{
        MV3=7, MV4=8;
        MOVE();
    }
}


void MainWindow::on_pole81_clicked()
{
    if(MV1==0&&MV2==0) MV1=8, MV2=1;
    else{
        MV3=8, MV4=1;
        MOVE();
    }
}


void MainWindow::on_pole82_clicked()
{
    if(MV1==0&&MV2==0) MV1=8, MV2=2;
    else{
        MV3=8, MV4=2;
        MOVE();
    }
}


void MainWindow::on_pole83_clicked()
{
    if(MV1==0&&MV2==0) MV1=8, MV2=3;
    else{
        MV3=8, MV4=3;
        MOVE();
    }
}


void MainWindow::on_pole84_clicked()
{
    if(MV1==0&&MV2==0) MV1=8, MV2=4;
    else{
        MV3=8, MV4=4;
        MOVE();
    }
}


void MainWindow::on_pole85_clicked()
{
    if(MV1==0&&MV2==0) MV1=8, MV2=5;
    else{
        MV3=8, MV4=5;
        MOVE();
    }
}


void MainWindow::on_pole86_clicked()
{
    if(MV1==0&&MV2==0) MV1=8, MV2=6;
    else{
        MV3=8, MV4=6;
        MOVE();
    }
}


void MainWindow::on_pole87_clicked()
{
    if(MV1==0&&MV2==0) MV1=8, MV2=7;
    else{
        MV3=8, MV4=7;
        MOVE();
    }
}


void MainWindow::on_pole88_clicked()
{
    if(MV1==0&&MV2==0) MV1=8, MV2=8;
    else{
        MV3=8, MV4=8;
        MOVE();
    }
}

