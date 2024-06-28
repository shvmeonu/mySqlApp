#include "SqlExecutor.h"
#include <QDebug>
#include <iostream>

SqlExecutor::SqlExecutor(DatabaseManager& dbManager) : m_dbManager(dbManager) {}

void SqlExecutor::executeSqlCommands() {
    while (true) {
        qDebug() << "Введите SQL-команду (или 'close'/'exit' для выхода): ";
        std::string sqlCommandStd;
        std::getline(std::cin, sqlCommandStd);
        QString sqlCommand = QString::fromStdString(sqlCommandStd);

        if (sqlCommand.toLower() == "close" || sqlCommand.toLower() == "exit") {
            qDebug() << "Выход из программы.";
            break;
        }

        QSqlQuery query = m_dbManager.executeSqlQuery(sqlCommand);

        qDebug() << "Результат выполнения SQL-команды:";

        // Выводим названия столбцов в строку
        QSqlRecord rec = query.record();
        QString columnNames;
        for (int i = 0; i < rec.count(); ++i) {
            columnNames += rec.fieldName(i) + "\t";
        }
        qDebug().noquote() << columnNames;

        // Выводим данные
        while (query.next()) {
            QString row;
            for (int i = 0; i < rec.count(); ++i) {
                row += query.value(i).toString() + "\t";
            }
            qDebug().noquote() << row;
        }
    }
}
