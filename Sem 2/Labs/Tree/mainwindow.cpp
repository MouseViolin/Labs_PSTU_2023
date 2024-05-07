#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QString>
#include <QPainter>


Tree *tree = new Tree;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    ui->initNode->click();
    Scene = new QGraphicsScene(this);
    ui->grView->setScene(Scene);
    ui->grView->setRenderHint(QPainter::Antialiasing);
    ui->grView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->grView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    Scene->setSceneRect(0,0,741,341);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QString dat = ui->userData->text();

    if (ui->arr->isChecked())
        tree->arrNodes(dat,tree->root);

    if (ui->initNode->isChecked()){
        ui->statusbar->showMessage(dat);
        tree->deletNodes(tree->root);
        delete tree;
        tree = new Tree;
        tree->init(dat.toInt());
        ui->addNode->click();
        ui->userData->clear();
        return;
    }

    if (ui->addNode->isChecked()){
        ui->statusbar->showMessage(dat);
        tree->addNode(dat.toInt(),tree->root,356,0,200);
    }
    if (ui->delNode->isChecked()){
        ui->statusbar->showMessage(dat);
        if (tree->count == 0) {delete tree; tree->root = NULL;}
        else tree->delNodes(dat.toInt(),tree->root);
    }
    ui->userData->clear();
}

void MainWindow::showTre(Node *tree, int x, int y) {
    QBrush whBrush(Qt::white);
    QPen blackPen(Qt::black);
    QPen whPen(Qt::white);
    blackPen.setWidth(1);



    if (tree != NULL) {
        showTre(tree->left, tree->x, tree->y);

        ell = Scene->addEllipse(tree->x,tree->y,30,30, blackPen, whBrush);
        text = Scene->addText(QString::number(tree->data),QFont("Arial"));
        text->setDefaultTextColor(QColor("balck"));
        text->setPos(tree->x+4,tree->y+3);
        line = Scene->addLine(x+30-10,y+30-5,tree->x+10,tree->y+5, whPen);
        //ell->setFlag(QGraphicsEllipseItem::ItemIsMovable);
        showTre(tree->right, tree->x, tree->y);
    }
}

void MainWindow::on_showBtn_clicked()
{
    Scene->clear();
    showTre(tree->root, 356, 0);
    ui->statusbar->showMessage(QString::number(tree->arithMean()));
}






