
#ifndef USER_H
#define USER_H

#include <string>

enum class Role { Admin, WarehouseStaff, Pharmacist, ComplianceOfficer };

class User {
private:
    int userId;
    std::string username;
    Role role;

public:
    User(int id, const std::string& uname, Role r);
    bool canPerform(const std::string& action);
};

#endif
