#include "DatabaseManager.h"
#include <QDebug>

DatabaseManager::DatabaseManager(const QString& dbName) : m_dbName(dbName) {}

bool DatabaseManager::open() {
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName(m_dbName);
    if (!m_db.open()) {
        qWarning() << "Не удалось открыть бд.:" << m_db.lastError();
        return false;
    }
    return true;
}

bool DatabaseManager::createTable() {
    QSqlQuery query;
    qDebug() << "Создаются таблицы `person` и `address` и заполняются данными";
    return query.exec("CREATE TABLE IF NOT EXISTS person (id INTEGER PRIMARY KEY, name TEXT)") &&
           query.exec("CREATE TABLE IF NOT EXISTS address (id INTEGER PRIMARY KEY, person_id INTEGER, location TEXT)") &&
           query.exec("INSERT INTO person (name) VALUES ('John')") &&
           query.exec("INSERT INTO person (name) VALUES ('Jane')") &&
           query.exec("INSERT INTO address (person_id, location) VALUES (1, 'Test Address for Person 1')") &&
           query.exec("INSERT INTO address (person_id, location) VALUES (2, 'Test Address for Person 2')");
}

QSqlQuery DatabaseManager::executeSqlQuery(const QString& sqlCommand) {
    QSqlQuery query;
    if (!query.exec(sqlCommand)) {
        qWarning() << "Ошибка выполнения SQL-команды:" << query.lastError().text();
    }
    return query;
}
