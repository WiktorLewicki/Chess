#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionAutor_2_triggered();
    void blok(bool var);
    void refresh();
    void MOVE();
    void koniec(int win);
    int zapytanie();


    void on_pole11_clicked();

    void on_pole12_clicked();

    void on_pole13_clicked();

    void on_pole14_clicked();

    void on_pole15_clicked();

    void on_pole16_clicked();

    void on_pole17_clicked();

    void on_pole18_clicked();

    void on_pole21_clicked();

    void on_pole22_clicked();

    void on_pole23_clicked();

    void on_pole24_clicked();

    void on_pole25_clicked();

    void on_pole26_clicked();

    void on_pole27_clicked();

    void on_pole28_clicked();

    void on_pole31_clicked();

    void on_pole32_clicked();

    void on_pole33_clicked();

    void on_pole34_clicked();

    void on_pole35_clicked();

    void on_pole36_clicked();

    void on_pole37_clicked();

    void on_pole38_clicked();

    void on_pole41_clicked();

    void on_pole42_clicked();

    void on_pole43_clicked();

    void on_pole44_clicked();

    void on_pole45_clicked();

    void on_pole46_clicked();

    void on_pole47_clicked();

    void on_pole48_clicked();

    void on_pole51_clicked();

    void on_pole52_clicked();

    void on_pole53_clicked();

    void on_pole54_clicked();

    void on_pole55_clicked();

    void on_pole56_clicked();

    void on_pole57_clicked();

    void on_pole58_clicked();

    void on_pole61_clicked();

    void on_pole62_clicked();

    void on_pole63_clicked();

    void on_pole64_clicked();

    void on_pole65_clicked();

    void on_pole66_clicked();

    void on_pole67_clicked();

    void on_pole68_clicked();

    void on_pole71_clicked();

    void on_pole72_clicked();

    void on_pole73_clicked();

    void on_pole74_clicked();

    void on_pole75_clicked();

    void on_pole76_clicked();

    void on_pole77_clicked();

    void on_pole78_clicked();

    void on_pole81_clicked();

    void on_pole82_clicked();

    void on_pole83_clicked();

    void on_pole84_clicked();

    void on_pole85_clicked();

    void on_pole86_clicked();

    void on_pole87_clicked();

    void on_pole88_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
