#include "mainwindow.h"
#include "ui_mainwindow.h"

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

void MainWindow::on_pushButton_setBorderColor_clicked()
{
    QColor color = QColorDialog::getColor();
    ui->lineEdit_borderColor->setStyleSheet("background-color:" + color.name());
}

void MainWindow::on_pushButton_aiModel_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(
                this,
                "打开AI模型",
                QDir::currentPath(),
                "*.*");
    ui->lineEdit_aiModel->setText(fileName);
}

void MainWindow::on_pushButton_reset_clicked()
{
    ui->lineEdit_worldSize->setText("10");
    ui->lineEdit_zoningSize->setText("6");
    ui->lineEdit_AiNumber->setText("7");
    ui->comboBox_resSetting->setCurrentIndex(1);
    ui->lineEdit_playerName->setText("玩家帝国");
    ui->lineEdit_borderColor->setStyleSheet("background-color:rgb(0, 170, 255)");
    borderColor = QColor(0, 170, 255);
    ui->checkBox_fog->setChecked(true);
    ui->checkBox_aiMode->setChecked(false);
    ui->lineEdit_aiModel->setText("");
}

