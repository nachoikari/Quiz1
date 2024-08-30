#ifndef NODEFLOOR_H
#define NODEFLOOR_H
#include "ListEmployee.h"
class NodeFloor{
private:
	NodeFloor* nextFloor;
	NodeFloor* prevFloor;
	ListEmployee list;
	int numberFloor;
	int salesPerFloor;
public:
    NodeFloor(int numberFloor);

    NodeFloor* getNextFloor() const;
    NodeFloor* getPrevFloor() const;
    ListEmployee& getList();
    int getNumberFloor() const;
    int getSalesPerFloor() const;

    void setNextFloor(NodeFloor* nextFloor);
    void setPrevFloor(NodeFloor* prevFloor);
    void setNumberFloor(int numberFloor);
    void setSalesPerFloor(int salesPerFloor);

    void updateSalesPerFloor();

    ~NodeFloor();
};
#endif