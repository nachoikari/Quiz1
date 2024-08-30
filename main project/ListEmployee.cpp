#include "ListEmployee.h"

ListEmployee::ListEmployee(){
	this->head = nullptr;
}

std::string ListEmployee::toUpperCase(std::string str) const {
    for (int i = 0; i < str.length(); i++) {
        str[i] = std::toupper(str[i]);
    }
    return str;
}

void ListEmployee::addEmployee(const std::string& employeeName) {
    std::string upperName = toUpperCase(employeeName);
    NodeEmployee* newEmployee = new NodeEmployee(upperName);

    if (!this->head || this->head->getEmployeeName() > upperName) {
        newEmployee->setNextEmployee(this->head);
        this->head = newEmployee;
    }
    else {
        NodeEmployee* current = this->head;
        while (current->getNextEmployee() && current->getNextEmployee()->getEmployeeName() < upperName) {
            current = current->getNextEmployee();
        }
        newEmployee->setNextEmployee(current->getNextEmployee());
        current->setNextEmployee(newEmployee);
    }
}

void ListEmployee::addSaleToEmployee(const std::string& employeeName, int amount) {
    std::string upperName = toUpperCase(employeeName);
    NodeEmployee* current = this->head;
    while (current) {
        if (current->getEmployeeName() == upperName) {
            current->addSale(amount);
            return;
        }
        current = current->getNextEmployee();
    }

    addEmployee(upperName);
    this->head->addSale(amount);
}

void ListEmployee::printEmployees() const {
    NodeEmployee* current = this->head;
    while (current) {
        std::cout << "Employee: " << current->getEmployeeName() << ", Total sales: " << current->getTotalSales() << std::endl;
        current->getSalesList().printSales(); 
        current = current->getNextEmployee();
    }
}

NodeEmployee* ListEmployee::getHead() const {
    return this->head;
}

ListEmployee::~ListEmployee() {
    this->head->getSalesList().~ListSales();
    while (this->head) {
        NodeEmployee* temp = this->head;
        this->head = this->head->getNextEmployee();
        delete temp;
    }
}