#ifndef SQLEXECUTOR_H
#define SQLEXECUTOR_H

#include "DatabaseManager.h"

class SqlExecutor {
public:
    SqlExecutor(DatabaseManager& dbManager);

    void executeSqlCommands();

private:
    DatabaseManager& m_dbManager;
};

#endif // SQLEXECUTOR_H
