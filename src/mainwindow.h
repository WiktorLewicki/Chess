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
    void handleBoardClick();


    void on_arrow_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
