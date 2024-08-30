#include "NodeSales.h"

NodeSales::NodeSales(int pAmount){
	this->amount = pAmount;
	this->nextNode = nullptr;
}

// Setters
void NodeSales::setAmount(int pAmount) {
    this->amount = pAmount;
}

void NodeSales::setNextNode(NodeSales* pNextNode) {
    this->nextNode = pNextNode;
}

// Getters
int NodeSales::getAmount() const {
    return this->amount;
}

NodeSales* NodeSales::getNextNode() const {
    return this->nextNode;
}