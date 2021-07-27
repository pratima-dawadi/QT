#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QPixmap>
#include<QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QSqlDatabase myfile;
    myfile=QSqlDatabase::addDatabase("QSQLITE");
    myfile.setDatabaseName("C:/Users/dawad/OneDrive/Desktop/database/genre_action.db");
    if(!myfile.open())
    {
        qDebug()<<("Failed to open the database");


    }
    else
    {
        qDebug()<<("Connected");

    }
}

MainWindow::~MainWindow()
{

    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QSqlQueryModel *modal=new QSqlQueryModel;
    QSqlQuery qry;
    qry.prepare("SELECT * FROM action");
    if (qry.exec())
    {
        modal->setQuery(qry);
        ui->tableView->setModel(modal);
    }
}

