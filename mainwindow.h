#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QMessageBox>
#include "ZorkUL.h"
#include "qtextbrowser.h"
#include "qprogressbar.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    //void on_click();

    void on_teleport_clicked();

    void on_north_clicked();

    void on_east_clicked();

    void on_south_clicked();

    void on_west_clicked();

    void on_play_clicked();

    void on_collect_clicked();

private:
    Ui::MainWindow *ui;
     QPushButton *btn;
     QPushButton *play;
     QTextBrowser *mainlines;
     ZorkUL *zorkul;
     QProgressBar *progressbar;
public:
     void makezork();

};

#endif // MAINWINDOW_H
