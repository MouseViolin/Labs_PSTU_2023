#include "table.h"
#include "ui_table.h"
#include <QFile>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QDate>
#include <QFileDialog>
#include <cstdlib>


table::table(QString code, QString login,QSqlDatabase *db,QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::table)
{
    // проносим с собой указатель на базу данных, код организации и логин
    this->db = db;
    ui->setupUi(this);
    QSqlQuery query(*db);
    // создание "шаблона" для дальнейшего отображения в виджете
    model = new QSqlTableModel(this, *db);
    this->code = code;
    this->login = login;
    model->setTable( code + "TableFirst");
    model->select();
    // установка "шаблона" в виджет
    ui->tableView->setModel(model);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->horizontalHeader()->setStretchLastSection(true);

    // заполнение comboBoxs исходя из данных таблицы
    query.exec("SELECT name FROM "+ code +"TableFirst");
    while(query.next()){
        QString value = query.value(0).toString();
        if (value != ""){
            ui->nameBox->addItem(value);
            ui->nameLimitBox->addItem(value);
        }
    }
    ui->nameBox->setStyleSheet("color: white;" "font: 14px");
    ui->nameLimitBox->setStyleSheet("color: white;" "font: 14px");

    query.exec("SELECT category FROM " + code + "TableFirst");
    while(query.next()){
        QString value = query.value(0).toString();
        if (value != "" && ui->categoryBox->findText(value)==-1){
            ui->categoryBox->addItem(value);
        }
    }
    ui->categoryBox->setStyleSheet("color: white;" "font: 14px");
}

table::~table()
{
    delete ui;
}
void sendMess(QString message){

    // Генерация уникального имени файла на основе текущей даты и времени
    QString currentDateTime = QDateTime::currentDateTime().toString("yyyyMMdd_HHmmss");
    QString filename = QString("/Users/user/Documents/Qt/arm/mes/message_%1.txt").arg(currentDateTime); // Путь к файлу сообщения

    // Создание и запись в файл
    QFile file(filename);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);
        out << message;
        file.close();

        qDebug() << "Сообщение сохранено в файле:" << filename;

        // Запуск скрипта Python с передачей пути к файлу
        QString command = QString("/usr/local/bin/python3 /Users/user/Documents/Qt/arm/bot.py \"%1\"").arg(filename);
        system(command.toStdString().c_str());
    } else {
        qDebug() << "Не удалось открыть файл для записи:" << filename;
    }

}

// Запись файла CSV локально
void table::on_localSave_clicked()
{
    // формирование названия и запись файла
    QString tableName = code + ui->tableBox->currentText();
    QString filename = QFileDialog::getSaveFileName(nullptr, "Save CSV File", "", "CSV Files (*.csv)");
    if (filename.isEmpty())
    {
        qDebug() << "File save cancelled.";
        return;
    }

    QFile file(filename);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qDebug() << "Failed to open file for writing:" << file.errorString();
        return;
    }

    QTextStream out(&file);

    QSqlQuery query;
    query.exec("SELECT * FROM " + tableName);
    QSqlRecord rec = query.record();

    // Write header
    QStringList headers;
    for (int i = 0; i < rec.count(); ++i)
    {
        headers << rec.fieldName(i);
    }
    out << headers.join(",") << "\n";

    // Write data
    while (query.next())
    {
        QStringList rowData;
        for (int i = 0; i < rec.count(); ++i)
        {
            rowData << query.value(i).toString();
        }
        out << rowData.join(",") << "\n";
    }

    file.close();
    qDebug() << "CSV file saved as:" << filename;
}

// Кнопка, отвечающая  за 3 возможных действия : Новая поизиция, Увеличение/Уменьшение значение у определенной таблицы
void table::on_posBtn_clicked()
{
    // Сбор необходимых данных для формирования запроса к базе данных
    QSqlQuery query;
    QString id = ui->id->text();
    QString newName = ui->newName->text();
    QString nameBox = ui->nameBox->currentText();
    int cnt = ui->cntSpin->value();
    QString category = ui->categoryBox->currentText();

    // Сбор информации о дате/времени для отчетности
    QTime currentTime = QTime::currentTime();
    QString timeString = currentTime.toString("hh:mm:ss");
    QDate currentDate = QDate::currentDate();
    QString dateString = currentDate.toString("yyyy-MM-dd"); // Вывод: "2023-05-31"

    // Сверяем включенные RadioBTN, относительно этого выбираем последующие действия
    if (ui->newPosRBtn->isChecked()){
        // Добавление новой позиции
        if (id != "" && (newName != "" || nameBox != "") && cnt != NULL && category != ""){
            if (newName != ""){
                // формирование зароса к базе данных для создания новой позиции
                query.prepare("INSERT INTO "+ code+ ui->tableBox->currentText()+" (id,name,count,category) VALUES (:id, :name, :cnt, :cat)");
                query.bindValue(":id", id);
                query.bindValue(":name", newName);
                query.bindValue(":cnt", cnt);
                query.bindValue(":cat", category);
                query.exec();

                // формирование запроса к таблице отвечающей за учет транзакций
                query.prepare("INSERT INTO "+ code+ "TableTransactions (id,login,date,time) VALUES (:id, :login, :date, :time)");
                query.bindValue(":id", newName);
                query.bindValue(":login", login);
                query.bindValue(":date", dateString);
                query.bindValue(":time", timeString);

                query.exec();
            }
        }

    }
    // Уменьшение значения определенной позиции
    if (ui->lowerRBtn->isChecked()){
        // Поиск необходимой строки
        query.prepare("SELECT * FROM "+ code+ ui->tableBox->currentText()+" WHERE name = :name");
        query.bindValue(":name", nameBox);
        query.exec();
        query.next();
        int value = query.value(2).toInt();
        int up = query.value(5).toInt();
        int low = query.value(4).toInt();


        //Обновление значения
        query.prepare(QString("UPDATE "+ code+ ui->tableBox->currentText()+" SET count = :newValue WHERE name = :name"));
        if (value - cnt < 0) {
            query.bindValue(":newValue", 0);
            query.bindValue(":name", nameBox);

        } else {
            query.bindValue(":newValue", value-cnt);
            query.bindValue(":name", nameBox);
        }
        // При достижении лимитов отправка сообщений в бота
        if (value - cnt < up && value - cnt > low){
            sendMess("Милорд! Количество " + nameBox + " достигло верхней границы");
        }
        else if (value - cnt <= low) {sendMess("Милорд! Количество " + nameBox + " достигло нижней границы");}
        query.exec();

        // обновление последней даты изменения
        query.prepare("UPDATE " + code+ ui->tableBox->currentText()+ " SET lastDate = :lastDate WHERE name = :name");
        query.bindValue(":name", nameBox);
        query.bindValue(":lastDate", dateString);
        query.exec();
// формирование запроса к таблице отвечающей за учет транзакций
        query.prepare("INSERT INTO "+ code+ "TableTransactions (id,login,date,time) VALUES (:id, :login, :date, :time)");
        query.bindValue(":id", nameBox);
        query.bindValue(":login", login);
        query.bindValue(":date", dateString);
        query.bindValue(":time", timeString);

        query.exec();

    }
    // Увелличение значения определенной позиции
    if (ui->upperRBtn->isChecked()){
        // Поиск необходимой строки
        query.prepare("SELECT * FROM "+ code+ ui->tableBox->currentText()+" WHERE name = :name");
        query.bindValue(":name", nameBox);
        query.exec();
        query.next();
        int value = query.value(2).toInt();
        //Обновление значения
        query.prepare(QString("UPDATE "+ code+ ui->tableBox->currentText()+" SET count = :newValue WHERE name = :name"));
        query.bindValue(":newValue", value+cnt);
        query.bindValue(":name", nameBox);
        query.exec();
        // обновление последней даты изменения
        query.prepare("UPDATE "+ code+ ui->tableBox->currentText()+" SET lastDate = :lastDate WHERE name = :name");
        query.bindValue(":name", nameBox);
        query.bindValue(":lastDate", dateString);
        query.exec();
        // формирование запроса к таблице отвечающей за учет транзакций
        query.prepare("INSERT INTO "+ code+ "TableTransactions (id,login,date,time) VALUES (:id, :login, :date, :time)");
        query.bindValue(":id", nameBox);
        query.bindValue(":login", login);
        query.bindValue(":date", dateString);
        query.bindValue(":time", timeString);

        query.exec();

    }
    ui->newName->clear();
    ui->id->clear();
    ui->limitSpin->clear();
    ui->cntSpin->clear();
    model->select();
}

// установка Верхнего и Нижнего лимита для позиции
void table::on_limitBtn_clicked()
{
    QSqlQuery query;
    int limitSpin = ui->limitSpin->value();
    QString nameLimitBox = ui->nameLimitBox->currentText();

    if (ui->lowerLimitRBtn->isChecked()){
        // поиск нужной строки
        query.prepare("SELECT * FROM "+ code+ ui->tableBox->currentText()+" WHERE name = :name");
        query.bindValue(":name", nameLimitBox);
        query.exec();
        query.next();
        // Изменение значения
        query.prepare(QString("UPDATE "+ code+ ui->tableBox->currentText()+" SET lowerLimit = :newValue WHERE name = :name"));
        query.bindValue(":newValue", limitSpin);
        query.bindValue(":name", nameLimitBox);
        query.exec();
    }
    if (ui->upperLimitRBtn->isChecked()){
        // поиск нужной строки
        query.prepare("SELECT * FROM "+ code+ ui->tableBox->currentText()+" WHERE name = :name");
        query.bindValue(":name", nameLimitBox);
        query.exec();
        query.next();
        // Изменение значения
        query.prepare(QString("UPDATE "+ code+ ui->tableBox->currentText()+" SET upperLimit = :newValue WHERE name = :name"));
        query.bindValue(":newValue", limitSpin);
        query.bindValue(":name", nameLimitBox);
        query.exec();
    }
    model->select();
}

// Переключение между доступными таблицами
void table::on_tableBox_currentIndexChanged(int index)
{

    switch (index) {
    case 0:{
        model->setTable(code+"TableFirst");
        model->select();
        ui->tableView->setModel(model);
        break;}
    case 1:{
        model->setTable(code + "TableTwo");
        model->select();
        ui->tableView->setModel(model);
        break;
    }
    case 2:{
        model->setTable(code + "TableTransactions");
        model->select();
        ui->tableView->setModel(model);
    }
    default:
        break;
    }


}

// Отправка файла для отправки в TG
void table::on_reportTG_clicked()
{
    QString tableName = code + ui->tableBox->currentText();
    QString defaultPath = "/Users/user/Documents/Qt/arm/reports";
    // Генерируем имя файла на основе текущей даты и времени
    QString currentDateTime = QDateTime::currentDateTime().toString("yyyyMMdd_HHmmss");
    QString suggestedFileName = QString("data_%1.csv").arg(currentDateTime);

    // Полный путь к файлу
    QString filename = defaultPath + "/" + suggestedFileName;

    QFile file(filename);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qDebug() << "Failed to open file for writing:" << file.errorString();
        return;
    }

    QTextStream out(&file);

    QSqlQuery query;
    query.exec("SELECT * FROM " + tableName);
    QSqlRecord rec = query.record();

    // Записываем заголовок
    QStringList headers;
    for (int i = 0; i < rec.count(); ++i)
    {
        headers << rec.fieldName(i);
    }
    out << headers.join(",") << "\n";

    // Записываем данные
    while (query.next())
    {
        QStringList rowData;
        for (int i = 0; i < rec.count(); ++i)
        {
            rowData << query.value(i).toString();
        }
        out << rowData.join(",") << "\n";
    }

    file.close();
    qDebug() << "CSV file saved as:" << filename;
    // Вызываем скрипт на Python для отправки файла в бота
    system("/usr/local/bin/python3 /Users/user/Documents/Qt/arm/bot.py");

}



