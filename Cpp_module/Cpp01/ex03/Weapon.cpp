#include "Weapon.hpp"

Weapon::Weapon(std::string type) {
    this->type = type;
}

Weapon::~Weapon() {}

const std::string &Weapon::getType() {
    const std::string &typeRef = this->type;
    return (typeRef);
}

void Weapon::setType(std::string type) {
    this->type = type;
}