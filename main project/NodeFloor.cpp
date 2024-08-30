#include "NodeFloor.h"

NodeFloor::NodeFloor(int numberFloor){
	this->numberFloor = numberFloor;
	this->prevFloor = nullptr;
	this->nextFloor = nullptr;
	this->salesPerFloor = 0;
}

void NodeFloor::setNextFloor(NodeFloor* nextFloor) {
    this->nextFloor = nextFloor;
}

void NodeFloor::setPrevFloor(NodeFloor* prevFloor) {
    this->prevFloor = prevFloor;
}

void NodeFloor::setNumberFloor(int numberFloor) {
    this->numberFloor = numberFloor;
}

void NodeFloor::setSalesPerFloor(int salesPerFloor) {
    this->salesPerFloor = salesPerFloor;
}

NodeFloor* NodeFloor::getNextFloor() const {
    return this->nextFloor;
}


NodeFloor* NodeFloor::getPrevFloor() const {
    return this->prevFloor;
}

ListEmployee& NodeFloor::getList(){
    return this->list;
}

int NodeFloor::getNumberFloor() const {
    return this->numberFloor;
}

int NodeFloor::getSalesPerFloor() const {
    return this->salesPerFloor;
}

void NodeFloor::updateSalesPerFloor() {
    salesPerFloor = 0;
    NodeEmployee* currentEmployee = this->list.getHead();
    while (currentEmployee) {
        salesPerFloor += currentEmployee->getTotalSales();
        currentEmployee = currentEmployee->getNextEmployee();
    }
}

NodeFloor::~NodeFloor() {
   
}
