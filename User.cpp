
#include "User.h"

User::User(int id, const std::string& uname, Role r)
    : userId(id), username(uname), role(r) {}

bool User::canPerform(const std::string& action) {
    if (role == Role::Admin) return true;
    if (role == Role::WarehouseStaff && action == "manage_inventory") return true;
    if (role == Role::Pharmacist && action == "place_order") return true;
    if (role == Role::ComplianceOfficer && action == "generate_report") return true;
    return false;
}
