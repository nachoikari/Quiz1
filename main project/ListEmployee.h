#ifndef LISTEMPLOYEE_H
#define LISTEMPLOYEE_H
#include "NodeEmployee.h"
class ListEmployee{
private:
	NodeEmployee* head;
public:
	ListEmployee();

    void addEmployee(const std::string& employeeName);
    void addSaleToEmployee(const std::string& employeeName, int amount);
    void printEmployees() const;
    std::string toUpperCase(std::string str) const;
    NodeEmployee* getHead() const;

    ~ListEmployee();
};
#endif