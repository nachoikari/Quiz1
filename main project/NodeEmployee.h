#ifndef NODEEMPLOYEE_H
#define NODEEMPLOYEE_H
#include <string>
#include "ListSales.h"
class NodeEmployee{
private:
    std::string employeeName; 
    int totalSales;            
    NodeEmployee* nextEmployee; 
    ListSales salesList;        
public:
    NodeEmployee(const std::string& name);

    void setEmployeeName(const std::string& name);
    void setTotalSales(int sales);
    void setNextEmployee(NodeEmployee* next);

    std::string getEmployeeName() const;
    int getTotalSales() const;
    NodeEmployee* getNextEmployee() const;
    ListSales& getSalesList();

    void addSale(int amount);

    ~NodeEmployee();
};
#endif