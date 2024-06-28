#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QString>
#include <QtSql>

class DatabaseManager {
public:
    DatabaseManager(const QString& dbName);

    bool open();
    bool createTable();
    QSqlQuery executeSqlQuery(const QString& sqlCommand);

private:
    QString m_dbName;
    QSqlDatabase m_db;
};

#endif // DATABASEMANAGER_H
