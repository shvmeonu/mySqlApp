#include <QCoreApplication>
#include <QDebug>
#include <iostream>
#include <windows.h>
#include "DatabaseManager.h"
#include "SqlExecutor.h"

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);
    SetConsoleOutputCP(1251);
    qDebug() << "Введите название базы данных: ";
    std::string dbNameStd;
    std::getline(std::cin, dbNameStd);
    QString dbName = QString::fromStdString(dbNameStd);

    DatabaseManager dbManager(dbName);
    if (!dbManager.open() || !dbManager.createTable()) {
        return -1;
    }

    SqlExecutor sqlExecutor(dbManager);
    sqlExecutor.executeSqlCommands();

    return a.exec();
}
