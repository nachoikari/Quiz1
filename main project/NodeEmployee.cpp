#include "NodeEmployee.h"

NodeEmployee::NodeEmployee(const std::string& name) {
    this->employeeName = name;
    this->nextEmployee = nullptr;
    this->totalSales = 0;
}
void NodeEmployee::setEmployeeName(const std::string& name) {
    this->employeeName = name;
}

void NodeEmployee::setTotalSales(int sales) {
    this->totalSales = sales;
}

void NodeEmployee::setNextEmployee(NodeEmployee* next) {
    this->nextEmployee = next;
}

std::string NodeEmployee::getEmployeeName() const {
    return this->employeeName;
}

int NodeEmployee::getTotalSales() const {
    return this->totalSales;
}

NodeEmployee* NodeEmployee::getNextEmployee() const {
    return this->nextEmployee;
}

ListSales& NodeEmployee::getSalesList() {
    return this->salesList;
}

void NodeEmployee::addSale(int amount) {
    this->salesList.addSale(amount);
    this->totalSales += amount;
}

NodeEmployee::~NodeEmployee() {

}