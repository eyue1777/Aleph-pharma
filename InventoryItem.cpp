
#include "InventoryItem.h"
#include <iostream>
#include <ctime>

InventoryItem::InventoryItem(int id, const std::string& name, int qty, std::tm expiry, int reorder, int suppId)
    : itemId(id), name(name), stockQuantity(qty), expiryDate(expiry), reorderLevel(reorder), supplierId(suppId) {}

void InventoryItem::updateStock(int quantity) {
    if (quantity >= 0) {
        stockQuantity = quantity;
        std::cout << "Stock updated to: " << stockQuantity << std::endl;
    }
}

bool InventoryItem::checkExpiry() {
    std::time_t now = std::time(nullptr);
    std::tm* current = std::localtime(&now);
    return std::mktime(&expiryDate) < std::mktime(current);
}

void InventoryItem::triggerReorder() {
    if (stockQuantity <= reorderLevel) {
        std::cout << "[REORDER ALERT] Item: " << name << " needs reordering from Supplier ID: " << supplierId << std::endl;
    }
}

int InventoryItem::getItemId() const { return itemId; }
std::string InventoryItem::getName() const { return name; }
int InventoryItem::getStockQuantity() const { return stockQuantity; }
std::tm InventoryItem::getExpiryDate() const { return expiryDate; }
int InventoryItem::getReorderLevel() const { return reorderLevel; }
int InventoryItem::getSupplierId() const { return supplierId; }
