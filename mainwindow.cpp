#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "arithmeticoperation.h"

bool add = false;
bool subtract = false;
bool divide = false;
bool multiply = false;

double leftHandValue = 0.0;
double rightHandValue = 0.0;

const QColor GREEN = QColor(Qt::green);
const QString STR_BGCOLOR_GREEN = QString("background-color: %1").arg(GREEN.name());

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateLeftHandText(QString text)
{
        ui->leftHandText->setText(ui->leftHandText->text().append(text));
}

void MainWindow::updateRightHandText(QString text)
{
    ui->rightHandText->setText(ui->rightHandText->text().append(text));
}

void MainWindow::updateText(QString text)
{
    if (add || subtract || divide || multiply) {
        updateRightHandText(text);
    } else {
        updateLeftHandText(text);
    }
}

void MainWindow::on_btnZero_clicked()
{
    updateText(ui->btnZero->text());
}

void MainWindow::on_btnOne_clicked()
{
    updateText(ui->btnOne->text());
}

void MainWindow::on_btnTwo_clicked()
{
    updateText(ui->btnTwo->text());
}

void MainWindow::on_btnThree_clicked()
{
    updateText(ui->btnThree->text());
}

void MainWindow::on_btnFour_clicked()
{
    updateText(ui->btnFour->text());
}

void MainWindow::on_btnFive_clicked()
{
    updateText(ui->btnFive->text());
}

void MainWindow::on_btnSix_clicked()
{
    updateText(ui->btnSix->text());
}

void MainWindow::on_btnSeven_clicked()
{
    updateText(ui->btnSeven->text());
}

void MainWindow::on_btnEight_clicked()
{
    updateText(ui->btnEight->text());
}

void MainWindow::on_btnNine_clicked()
{
    updateText(ui->btnNine->text());
}

void MainWindow::on_btnSeparator_clicked()
{
    updateText(ui->btnSeparator->text());
}

void MainWindow::on_btnAdd_clicked()
{
    leftHandValue = ui->leftHandText->text().toDouble();

    ui->btnAdd->setStyleSheet(STR_BGCOLOR_GREEN);

    add = true;
}

void MainWindow::on_btnSubtract_clicked()
{
    leftHandValue = ui->leftHandText->text().toDouble();

    ui->btnSubtract->setStyleSheet(STR_BGCOLOR_GREEN);

    subtract = true;
}

void MainWindow::on_btnDivide_clicked()
{
    leftHandValue = ui->leftHandText->text().toDouble();

    ui->btnDivide->setStyleSheet(STR_BGCOLOR_GREEN);

    divide = true;
}

void MainWindow::on_btnMultiply_clicked()
{
    leftHandValue = ui->leftHandText->text().toDouble();

    ui->btnMultiply->setStyleSheet(STR_BGCOLOR_GREEN);

    multiply = true;
}

void MainWindow::on_btnCE_clicked()
{
    leftHandValue = 0.0;
    rightHandValue = 0.0;

    ui->resultText->clear();
    ui->leftHandText->clear();
    ui->rightHandText->clear();
}

void MainWindow::on_btnResult_clicked()
{
    rightHandValue = ui->rightHandText->text().toDouble();
    QColor color = ui->btnResult->palette().color(QWidget::backgroundRole());

    if (add)
        ui->resultText->setText(QString::number(ArithmeticOperation::Add(leftHandValue, rightHandValue)));

    if (subtract)
        ui->resultText->setText(QString::number(ArithmeticOperation::Subtract(leftHandValue, rightHandValue)));

    if (divide)
        ui->resultText->setText(QString::number(ArithmeticOperation::Divide(leftHandValue, rightHandValue)));

    if (multiply)
        ui->resultText->setText(QString::number(ArithmeticOperation::Multiply(leftHandValue, rightHandValue)));

    if (color.isValid()) {
        QString strColor = QString("background-color: %1").arg(color.name());
        ui->btnAdd->setStyleSheet(strColor);
        ui->btnDivide->setStyleSheet(strColor);
        ui->btnSubtract->setStyleSheet(strColor);
        ui->btnMultiply->setStyleSheet(strColor);
    }

    /* reset state */
    add = false;
    subtract = false;
    divide = false;
    multiply = false;
}
