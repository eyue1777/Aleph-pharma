#include "crow.h"
#include "DBConnector.h"
#include <cppconn/driver.h>
#include <memory>

int main() {
    crow::SimpleApp app;

    // Route to fetch inventory
    CROW_ROUTE(app, "/inventory")([](){
        try {
            std::vector<InventoryInfo> inventory = fetchInventory();
            crow::json::wvalue jsonResponse;
            for (size_t i = 0; i < inventory.size(); ++i) {
                jsonResponse[i]["name"] = inventory[i].name;
                jsonResponse[i]["stock_quantity"] = inventory[i].stock_quantity;
                jsonResponse[i]["expiry_date"] = inventory[i].expiry_date;
            }
            return crow::response{jsonResponse};
        } catch (const std::exception& e) {
            return crow::response(500, "Server Error: " + std::string(e.what()));
        }
    });

    // Route for placing orders (example)
    CROW_ROUTE(app, "/order/<int>/<string>")
    ([](int userId, const std::string& orderType) {
        placeOrder(userId, orderType);
        return crow::response(200, "Order placed successfully");
    });

    app.port(8080).multithreaded().run();
    return 0;
}