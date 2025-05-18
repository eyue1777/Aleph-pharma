#ifndef DBCONNECTOR_H
#define DBCONNECTOR_H

#include <vector>
#include <string>

struct InventoryInfo {
    std::string name;
    int stock_quantity;
    std::string expiry_date;
};

std::vector<InventoryInfo> fetchInventory();

#endif