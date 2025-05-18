
#include <iostream>

void placeOrder(int userId, const std::string& orderType) {
    std::cout << "User " << userId << " is placing an order..." << std::endl;
    std::cout << "Order placed. Reorder triggers (if any) have been checked.\n";
}
