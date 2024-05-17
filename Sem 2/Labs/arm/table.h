#ifndef TABLE_H
#define TABLE_H

#include <QDialog>
#include <QSqlTableModel>

namespace Ui {
class table;
}

class table : public QDialog
{
    Q_OBJECT

public:
    explicit table(QString code, QString login, QSqlDatabase *db,QWidget *parent = nullptr);
    ~table();

private slots:
    void on_localSave_clicked();

    void on_posBtn_clicked();

    void on_limitBtn_clicked();

    void on_tableBox_currentIndexChanged(int index);

    void on_reportTG_clicked();

private:
    Ui::table *ui;
    QSqlTableModel *model;
    QSqlDatabase *db;
    QString code;
    QString login;
};

#endif // TABLE_H
