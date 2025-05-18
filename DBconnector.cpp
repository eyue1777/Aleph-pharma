#include <cppconn/driver.h>
#include <cppconn/prepared_statement.h>
#include <cppconn/resultset.h>
#include <iostream>
#include "DBConnector.h"

std::vector<InventoryInfo> fetchInventory() {
    sql::mysql::MySQL_Driver *driver;
    sql::Connection *con = nullptr;
    sql::PreparedStatement *pstmt = nullptr;
    sql::ResultSet *res = nullptr;
    std::vector<InventoryInfo> items;

    try {
        driver = sql::mysql::get_mysql_driver_instance();
        con = driver->connect("tcp://127.0.0.1:3306", "root", "password");
        con->setSchema("aleph_pharma");

        pstmt = con->prepareStatement("SELECT name, stock_quantity, expiry_date FROM InventoryItems");
        res = pstmt->executeQuery();

        while (res->next()) {
            InventoryInfo item;
            item.name = res->getString("name");
            item.stock_quantity = res->getInt("stock_quantity");
            item.expiry_date = res->getString("expiry_date");
            items.push_back(item);
        }

        delete res;
        delete pstmt;
        delete con;
    } catch (sql::SQLException &e) {
        std::cerr << "Database Error: " << e.what() << std::endl;
        if (res) delete res;
        if (pstmt) delete pstmt;
        if (con) delete con;
        throw;
    }

    return items;
}