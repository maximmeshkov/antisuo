#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <solver.h>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->xKNPin, &QLineEdit::textChanged, this, &MainWindow::recalculate);
    connect(ui->yKNPin, &QLineEdit::textChanged, this, &MainWindow::recalculate);

    connect(ui->xOPin, &QLineEdit::textChanged, this, &MainWindow::recalculate);
    connect(ui->yOPin, &QLineEdit::textChanged, this, &MainWindow::recalculate);

    connect(ui->alphaOH, &QLineEdit::textChanged, this, &MainWindow::recalculate);
    connect(ui->alphaTarget, &QLineEdit::textChanged, this, &MainWindow::recalculate);
    connect(ui->distCmdr, &QLineEdit::textChanged, this, &MainWindow::recalculate);

    connect(ui->hKNPin, &QLineEdit::textChanged, this, &MainWindow::recalculate);
    connect(ui->epsTarget, &QLineEdit::textChanged, this, &MainWindow::recalculate);
    connect(ui->hOPin, &QLineEdit::textChanged, this, &MainWindow::recalculate);


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::recalculate()
{
    solver solver;
    solver.setxKNP(ui->xKNPin->text().toInt());
    solver.setyKNP(ui->yKNPin->text().toInt());

    solver.setxOP(ui->xOPin->text().toInt());
    solver.setyOP(ui->yOPin->text().toInt());

    solver.setalphaOH(ui->alphaOH->text().toInt());
    solver.setaalphaTarget(ui->alphaTarget->text().toInt());
    solver.setdistCmdr(ui->distCmdr->text().toInt());

    solver.sethKNP(ui->hKNPin->text().toInt());
    solver.setepsTarget(ui->epsTarget->text().toInt());
    solver.sethOP(ui->hOPin->text().toInt());



    solver.solve();
    //solver.solve_degree();
    ui->ResultDTT->setText(QString::number(solver.getDTT()));
    ui->ResultRTT->setText(QString::number(solver.getRTT()));
}



