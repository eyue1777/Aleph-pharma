
#ifndef INVENTORYITEM_H
#define INVENTORYITEM_H

#include <string>
#include <ctime>

class InventoryItem {
private:
    int itemId;
    std::string name;
    int stockQuantity;
    std::tm expiryDate;
    int reorderLevel;
    int supplierId;

public:
    InventoryItem(int id, const std::string& name, int qty, std::tm expiry, int reorder, int supplierId);
    void updateStock(int quantity);
    bool checkExpiry();
    void triggerReorder();

    // Getters
    int getItemId() const;
    std::string getName() const;
    int getStockQuantity() const;
    std::tm getExpiryDate() const;
    int getReorderLevel() const;
    int getSupplierId() const;
};

#endif
