#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "solver.h"
#include "corrector.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    //--------------------calculation--------------------------------------------------//

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


    connect(ui->refRange, &QLineEdit::textChanged, this, &MainWindow::recalculate);
    connect(ui->refRange_2, &QLineEdit::textChanged, this, &MainWindow::recalculate);
    connect(ui->refRange_2, &QLineEdit::textChanged, this, &MainWindow::recalculate);

    connect(ui->corrAngle, &QLineEdit::textChanged, this, &MainWindow::recalculate);
    connect(ui->corrAngle_2, &QLineEdit::textChanged, this, &MainWindow::recalculate);
    connect(ui->corrAngle_3, &QLineEdit::textChanged, this, &MainWindow::recalculate);

    connect(ui->corrDist, &QLineEdit::textChanged, this, &MainWindow::recalculate);
    connect(ui->corrDist_2, &QLineEdit::textChanged, this, &MainWindow::recalculate);
    connect(ui->corrDist_3, &QLineEdit::textChanged, this, &MainWindow::recalculate);


    //-------------------------keyboard---------------------------------------------------//



}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::recalculate()
{
    solver solver;

    QInputMethod *keyboard = QGuiApplication::inputMethod();
    keyboard->show();

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
    ui->ResultDTT->setText(QString::number(solver.getDTT()));
    ui->ResultRTT->setText(QString::number(solver.getRTT()));
    ui->ResultLVL->setText(QString::number(solver.getLVL()));
    ui->ResultKy->setText(QString::number(solver.getKy()));

    ui->ResultPS->setText(QString::number(solver.getPS()));
    ui->ResultShy->setText(QString::number(solver.getShy()));


    corrector corrector;
    corrector.setrefD1(ui->refRange->text().toInt());
    corrector.setrefD2(ui->refRange_2->text().toInt());
    corrector.setrefD3(ui->refRange_3->text().toInt());

    corrector.setdD1(ui->corrDist->text().toInt());
    corrector.setdD2(ui->corrDist_2->text().toInt());
    corrector.setdD3(ui->corrDist_3->text().toInt());


    corrector.setdd1(ui->corrAngle->text().toInt());
    corrector.setdd2(ui->corrAngle_2->text().toInt());
    corrector.setdd3(ui->corrAngle_3->text().toInt());


    corrector.setdtt(solver.getDTT());
    corrector.setrtt(solver.getRTT());

    corrector.calculate();


    ui->ResultDD->setText(QString::number(corrector.getResultdD()));
    ui->ResultDTR->setText(QString::number(corrector.getResultDTR()));

    ui->ResultDR->setText(QString::number(corrector.getResultdd()));
    ui->ResultRTR->setText(QString::number(corrector.getResultRTR()));



}
