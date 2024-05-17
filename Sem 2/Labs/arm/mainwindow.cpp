#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QSqlQuery>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // установка скрытого режима поля ввода
    ui->password->setEchoMode(QLineEdit::Password);
    // установка связей с базой данных
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/Users/user/Documents/Qt/arm/DB.db");
    // проверка на удачное открытие
    if (db.open())
    {
        ui->statusbar->showMessage("Successful connection to the database: " + db.databaseName());
    }
    else
    {
        ui->statusbar->showMessage("An error occurred while connecting to the database: " + db.lastError().databaseText());
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_push_clicked()
{
    // Считывание значений из полей ввода:
    // КОд организации, логин, пароль
    QString code = ui->codeOrg->text();
    QString login = ui->login->text();
    QString password = ui->password->text();
    // Установка связей с опредленной базой данных для формирования запросов
    QSqlQuery query(db);
    // формирование запроса, который состоит из трех считанных полей, тем самым мы разделяем доступ к разным "учетным записям" и если все данные введенные пользователем совпадают, то будет получен доступ к таблицам
    query.prepare("SELECT * FROM " + code + " WHERE login = :value");
    query.bindValue(":value", login);
    query.exec();
    query.next();
    QString description = query.value(1).toString();
    if (description == password) {
        table *wi = new table(code, login,&db);
        close();
        wi->show();

    }else ui->statusbar->showMessage("Ошибка");

    qDebug() << "Error executing query:" << query.lastError().text();




}




