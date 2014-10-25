#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <fstream>
#include <QFile>
#include <QTextStream>
#include "extApi.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);   

    // setup "coords.txt" for writing
}

MainWindow::~MainWindow()
{
    delete ui;

    // remove all coordinates from output text file "coords.txt"
    // TODO: NEED TO ADD FUNCTIONALITY
}

void MainWindow::on_pushButton_clicked()
{
    // takes in coordinates from the GUI
    QString x_coord = ui->x_coord->text();
    QString y_coord = ui->y_coord->text();
    QString z_coord = ui->z_coord->text();
    QString output = "X:"+x_coord+" Y:"+y_coord+" Z:"+z_coord+"\n";
    std::string outputText = output.toUtf8().constData();

    // writes coordinates to an external text file "coords.txt"
    // TODO: NEED TO ADD FUNCTIONALITY

    // writes list of coordinates to the GUI
    ui->listOfCoords->insertPlainText(output);
}
