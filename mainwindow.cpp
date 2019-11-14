#include "mainwindow.h"
#include "ui_mainwindow.h"
#define north 1
#define east 2
#define south 3
#define west 4

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->mainlines=ui->textBrowser;
    this->progressbar=ui->status;
    progressbar->setMaximum(300);
    progressbar->setMinimum(0);
    makezork();
    /*
    btn=new QPushButton("TEXT", this);
    btn->setGeometry(
                QRect(
                    QPoint(100,100),
                    QSize(100,100)
                    )
                );

    mainlines= new QTextBrowser(this);
    mainlines->setGeometry(
                QRect(
                    QPoint(50,50),
                    QSize(100,100)
                    )
                );

    connect( mainlines, SIGNAL( sourceChanged(const QString& ) ),
                 this, SLOT( sourceChanged( const QString&) ) );
    //connect(btn, SIGNAL(released()), this, SLOT(on_click()));
    */
 }

MainWindow::~MainWindow()
{
    delete ui;
}


/*
void MainWindow::on_click()
{
    QMessageBox messageBox(this);
    messageBox.about(this, "Teleport", "It happens now");
    zorkul.teleport();
}
*/



void MainWindow::on_teleport_clicked()
{
        zorkul->teleport();
}


void MainWindow::on_north_clicked()
{
        zorkul->changeroom(north);
}


void MainWindow::on_east_clicked()
{
        zorkul->changeroom(east);
}

void MainWindow::on_south_clicked()
{
        zorkul->changeroom(south);
}

void MainWindow::on_west_clicked()
{
        zorkul->changeroom(west);
}

void MainWindow::on_play_clicked()
{
    zorkul->play();
}

void MainWindow::on_collect_clicked()
{
    zorkul->collect();
}

void MainWindow::makezork(){
    zorkul=new ZorkUL(mainlines, progressbar);
    zorkul->play();
}

