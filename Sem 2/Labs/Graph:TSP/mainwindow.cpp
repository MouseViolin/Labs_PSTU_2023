#include "mainwindow.h"

#include "./ui_mainwindow.h"
#include "addnode.h"
#include "addedge.h"
#include <QString>
#include <QPoint>
#include <qDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    Создание, установка сцены. Отключение ползунков. Задание размеров
    Scene = new QGraphicsScene(this);
    ui->grView->setScene(Scene);
    ui->grView->setRenderHint(QPainter::Antialiasing);
    ui->grView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->grView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    Scene->setSceneRect(0,0,800,490);


    Scene->update();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_addNode_clicked()
{
//    Задание инстументов для покраски
    QBrush whBrush(Qt::white);
    QPen blackPen(Qt::black);
    blackPen.setWidth(1);
    
//    Вызов соответствующего метода класса и отрисовка объектов на сцене
    gr->addNode();
    QGraphicsEllipseItem *ell = Scene->addEllipse(0,0,30,30, blackPen, whBrush);
    QGraphicsTextItem *text = Scene->addText(QString::number(gr->arrGr.size()+1), QFont("Arial"));
    text->setPos(ell->boundingRect().center().rx()- ell->boundingRect().width()/4,
                 ell->boundingRect().center().ry() - ell->boundingRect().height()/3);
    text->setDefaultTextColor(QColor("balck"));
    QList<QGraphicsItem*> items;
    items << ell << text;
    QGraphicsItemGroup *group = Scene->createItemGroup(items);
    group->setFlag(QGraphicsItem::ItemIsMovable, true);
    gr->arrGr.push_back(group);
    updateLine();
    Scene->update();
}


void MainWindow::on_delNode_clicked()
{
//    Вызов нового окна для ввода значения, которые будут приняты с помощью сигнала из нового окна
    addNode *window = new addNode(this);
    connect(window, &addNode::dataReady, this, &MainWindow::receiveData);
    window->setModal(true);

    window->exec();
    updateLine();
    delete window;
    Scene->update();

}
void MainWindow::receiveData(const QString& data) {     // Обработка полученных данных
    gr->delNode(data.toInt());

    delete gr->arrGr[data.toInt()-1];
    for (int i(data.toInt()); i < gr->arrGr.size();i++){
        gr->arrGr[i-1] = gr->arrGr[i];
    }
    gr->arrGr.pop_back();

    QGraphicsItemGroup** groups = new QGraphicsItemGroup* [gr->arrGr.size()];

    for (int i(0); i < gr->arrGr.size();i++){
        groups[i] = gr->arrGr[i];
    }


    for (int i(data.toInt()-1); i < gr->arrGr.size(); i++)
    {
        foreach (QGraphicsItem *item, groups[i]->childItems())
        {
            QGraphicsTextItem *textItem = qgraphicsitem_cast<QGraphicsTextItem*>(item);
            if (textItem)
            {
                textItem->setPlainText(QString::number(i+1));
            }
        }
    }
    groups = 0;
    delete[] groups;
    updateLine();
    Scene->update();
}



void MainWindow::on_addEdge_clicked()
{
//    Вызов нового окна для ввода значения, которые будут приняты с помощью сигнала из нового окна
    addEdge *wi = new addEdge(this);
    connect(wi, &addEdge::dataR, this, &MainWindow::recEdge);
    wi->setModal(true);
    wi->exec();
    updateLine();
    delete wi;
    Scene->update();
}

void MainWindow::recEdge(const QString&first,const QString&second,const QString&weidht){ // обработка полученных данных

    gr->setMat(first.toInt(),second.toInt(),weidht.toInt());
    gr->show();
    updateLine();
    Scene->update();

}
// Метод перестройки линий связи на сцене
void MainWindow::updateLine(){
    QPen whPen(Qt::white);
//    Очищение векторов от указателей на объекты сцены, тем самым удаляя их со сцены
    int s = gr->l.size();
    for (int i(0); i<s; i++){
        delete gr->l.back();
        gr->l.pop_back();

    }
    s = gr->t.size();
    for (int i(0); i<s; i++){

        delete gr->t.back();
        gr->t.pop_back();

    }
    Scene->update();
//    Новая отрисовка линий связи, считывая значения новых координат каждого необходимого объекта со сцены
    for (int i(0); i<gr->getSize();i++){
        for (int j(i+1); j < gr->getSize();j++){
            if (gr->checkMat(i,j)){
                QGraphicsLineItem *lin = new QGraphicsLineItem;
                QGraphicsTextItem *text = new QGraphicsTextItem;
                text = Scene->addText(QString::number(gr->weidgt(i,j)), QFont("Arial"));

                QPointF center1 = gr->arrGr[i]->mapToScene(gr->arrGr[i]->boundingRect().center());
                QPointF center2 = gr->arrGr[j]->mapToScene(gr->arrGr[j]->boundingRect().center());
                qreal angle = qAtan2(center2.y() - center1.y(), center2.x() - center1.x());
                text->setPos((center1.x()+center2.x())/2,(center1.y()+center2.y())/2);
                lin = Scene->addLine(center1.x() + 10 *qCos(angle),center1.y()+ 10 *qSin(angle),center2.x()- 10 *qCos(angle),center2.y()- 10 *qSin(angle), whPen);
                text->setDefaultTextColor(QColor("yellow"));
                // gr->lines[i][j] = lin;
                // gr->lines[j][i] = lin;
                gr->l.push_back(lin);
                gr->t.push_back(text);
            }
        }
    }

    for (int i(0); i<gr->getSize();i++){
        for (int j(i+1); j < gr->getSize();j++){
            if (gr->checkMat(j,i)){
                QGraphicsLineItem *lin = new QGraphicsLineItem;
                QGraphicsTextItem *text = new QGraphicsTextItem;
                text = Scene->addText('(' + QString::number(gr->weidgt(j,i)) + ')', QFont("Arial"));

                QPointF center1 = gr->arrGr[i]->mapToScene(gr->arrGr[i]->boundingRect().center());
                QPointF center2 = gr->arrGr[j]->mapToScene(gr->arrGr[j]->boundingRect().center());
                qreal angle = qAtan2(center2.y() - center1.y(), center2.x() - center1.x());
                text->setPos((center1.x()+center2.x())/2-4,(center1.y()+center2.y())/2+12);
                lin = Scene->addLine(center1.x() + 10 *qCos(angle),center1.y()+ 10 *qSin(angle),center2.x()- 10 *qCos(angle),center2.y()- 10 *qSin(angle), whPen);
                text->setDefaultTextColor(QColor("red"));

                gr->l.push_back(lin);
                gr->t.push_back(text);
            }
        }
    }

    Scene->update();
}

void MainWindow::on_upd_clicked()
{
    updateLine();
    Scene->update();
}


void MainWindow::on_dijkstra_clicked()
{
    gr->dijkstra(1);

    ui->statusbar->showMessage("Кратчайший путь: "+ gr->showw());

}


void MainWindow::on_searchWidth_clicked()
{
    ui->statusbar->showMessage("Обход в ширину: "+ gr->searchInWidth(1));

}


void MainWindow::on_searchInDepth_clicked()
{
    ui->statusbar->showMessage("Обход в глубину: "+ gr->searchInDepth(1));
}



void MainWindow::on_tsp_clicked()
{

//    qDebug() << gr->getSize();
    gr->generateMatrix(); // Генерация матрицы для TSP


    Node first = Node({}, 0, 0, gr); // первая вершина
    Container cont = Container(0); // создаем контейнер
    cont.addSome(first.getNextNodes()); // делим первое множество и добавляем в контейнер
    int v = 0; // количество проверенных множеств


    while (true)
    {
        list<Node>::iterator itr = cont.nodes.begin();
        list<Node> newNodes;
        int i = 0;
        while (itr != cont.nodes.end()) // перебираем текущие вершины
        {
            // если нижняя оценка хуже рекорда, то удаляем вершину
            if (itr->H > cont.r && cont.nodes.size() != 1)
            {
                itr = cont.del(itr);
                ++v;
            }
            // иначе получаем список следующих вершин
            else
            {
                list<Node> nodes = itr->getNextNodes();
                newNodes.insert(newNodes.end(), nodes.begin(), nodes.end());
                ++itr;
            }
            ++i;
        }
        // если осталась 1 вершина и новых нет, то выходим из цикла
        if(cont.quantity == 1 && newNodes.size() == 0)
            break;
        cont.changeNodes(newNodes);

    }

    cout << endl;
    cout << "Ответ:" << endl; // печатаем ответ
    QString dat = cont.nodes.front().print();
    ui->statusbar->showMessage(dat);
    cout << endl;
    cout << "Всего проверено вариантов: " << v << endl;

}


