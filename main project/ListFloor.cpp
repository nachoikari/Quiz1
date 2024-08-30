#include "ListFloor.h"

ListFloor::ListFloor(){
	this->head = nullptr;
}

void ListFloor::insertFloor(int pFloor){
    NodeFloor* newNode = new NodeFloor(pFloor);
    if (this->head == nullptr) {
        newNode->setNextFloor(nullptr);
        newNode->setPrevFloor(nullptr);
        this->head = newNode;
        return;
    }
    NodeFloor* temp = this->head;
    if (pFloor < temp->getNumberFloor()) {
        newNode->setNextFloor(this->head);
        newNode->setPrevFloor(nullptr);
        this->head->setPrevFloor(newNode);
        this->head = newNode;
        return;
    }
    while (temp->getNextFloor() != nullptr && temp->getNextFloor()->getNumberFloor() < pFloor) {
        temp = temp->getNextFloor();
    }
    if (temp->getNextFloor() == nullptr) {
        temp->setNextFloor(newNode);
        newNode->setPrevFloor(temp);
        newNode->setNextFloor(nullptr);
        return;
    }
    newNode->setNextFloor(temp->getNextFloor());
    newNode->setPrevFloor(temp);
    temp->getNextFloor()->setPrevFloor(newNode);
    temp->setNextFloor(newNode);
}

void ListFloor::insertEmployee(int pFloor, std::string pName){
	NodeFloor* temp = this->head;
	while (temp != nullptr) {
		if (temp->getNumberFloor() == pFloor) {
            temp->getList().addEmployee(pName);
            return;
		}
        temp = temp->getNextFloor();
	}
    std::cout << "Floor doesnt exist" << std::endl;
}

void ListFloor::insertSale(int pFloor, std::string pName, int pAmount){
    NodeFloor* temp = this->head;
    while (temp != nullptr) {
        if (temp->getNumberFloor() == pFloor) {
            temp->getList().addSaleToEmployee(pName, pAmount);
            temp->updateSalesPerFloor();
            return;
        }
        temp = temp->getNextFloor();
    }
    std::cout << "Floor doesnt exist" << std::endl;
}

void ListFloor::printFloor(int pFloor){
    NodeFloor* temp = this->head;
    while (temp != nullptr) {
        if (temp->getNumberFloor() == pFloor) {
            std::cout << "************\nFloor: " << temp->getNumberFloor() << std::endl;
            std::cout << "Floor sales: " << temp->getSalesPerFloor() << std::endl;
            std::cout << "Employee and their sales: " << std::endl;
            temp->getList().printEmployees();
            return;
        }
        temp = temp->getNextFloor();
    }
    std::cout << "Floor " << pFloor << " doesnt exist." << std::endl;
}

void ListFloor::deleteFloor(int pFloor){
    if (this->head == nullptr) {
        return;
    }

    NodeFloor* temp = this->head;

    while (temp != nullptr && temp->getNumberFloor() != pFloor) {
        temp = temp->getNextFloor();
    }

    if (temp == nullptr) {
        return;
    }

    NodeFloor* prevFloor = temp->getPrevFloor();
    NodeFloor* nextFloor = temp->getNextFloor();

    // Mover empleados al piso anterior si existe
    if (prevFloor != nullptr) {
        NodeEmployee* employee = temp->getList().getHead();
        copyEmployee(employee, prevFloor);
    }

    // Actualizar los punteros de los pisos vecinos
    if (prevFloor != nullptr) {
        prevFloor->setNextFloor(nextFloor);
    }
    else {
        this->head = nextFloor;
    }
    if (nextFloor != nullptr) {
        nextFloor->setPrevFloor(prevFloor);
    }
    delete temp;
}
void ListFloor::copyEmployee(NodeEmployee* aux, NodeFloor* floorToMove) {
    while (aux != nullptr) {
        floorToMove->getList().addEmployee(aux->getEmployeeName());
        if (aux->getSalesList().getHead() != nullptr) {
            copySales(aux->getSalesList().getHead(), aux->getEmployeeName(), floorToMove);
        }
        aux = aux->getNextEmployee();
    }
}

void ListFloor::copySales(NodeSales* aux, std::string pName, NodeFloor* floorToMove){
    while (aux != nullptr) {
        floorToMove->getList().addSaleToEmployee(pName, aux->getAmount());
        aux = aux->getNextNode();
        floorToMove->updateSalesPerFloor();
    }
}

ListFloor::~ListFloor(){
    this->head->getList().~ListEmployee();
    while (this->head != nullptr) {
        NodeFloor* aux = this->head;
        this->head = head->getNextFloor();
        delete aux;
    }
}
