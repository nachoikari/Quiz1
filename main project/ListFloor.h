#ifndef LISTFLOOR_H
#define LISTFLOOR_H
#include "NodeFloor.h"
class ListFloor{
private:
	NodeFloor* head;
public:
	ListFloor();
	void insertFloor(int pFloor);
	void insertEmployee(int pFloor, std::string pName);
	void insertSale(int pFloor, std::string pName, int pAmount);
	void printFloor(int pFloor);
	
	void deleteFloor(int pFloor);
	void copyEmployee(NodeEmployee* aux, NodeFloor* floorToMove);
	void copySales(NodeSales* aux, std::string pName, NodeFloor* floorToMove);
	~ListFloor();
};
#endif