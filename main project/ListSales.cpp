#include "ListSales.h"

ListSales::ListSales(){
	this->head = nullptr;
}

void ListSales::addSale(int amount) {
    NodeSales* newNode = new NodeSales(amount);

    if (!this->head || this->head->getAmount() < amount) {
        newNode->setNextNode(this->head);
        head = newNode;
    }
    else {
        NodeSales* current = this->head;
        while (current->getNextNode() && current->getNextNode()->getAmount() > amount) {
            current = current->getNextNode();
        }
        newNode->setNextNode(current->getNextNode());
        current->setNextNode(newNode);
    }
}

void ListSales::printSales() const {
    NodeSales* current = this->head;
    while (current) {
        std::cout << "Sale: " << current->getAmount() << std::endl;
        current = current->getNextNode();
    }
}


NodeSales* ListSales::getHead() const {
    return this->head;
}

ListSales::~ListSales() {
    while (this->head) {
        NodeSales* temp = this->head;
        this->head = this->head->getNextNode();
        delete temp;
    }
}