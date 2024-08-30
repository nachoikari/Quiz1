#ifndef LISTSALES_H
#define LISTSALES_H
#include "NodeSales.h"
#include <iostream>
class ListSales{
private:
	NodeSales* head;
public:
	ListSales();

    void addSale(int amount);
    void printSales() const;

    NodeSales* getHead() const;

    ~ListSales();
};
#endif