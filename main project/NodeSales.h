#ifndef NODESALES_H
#define NODESALES_H
class NodeSales{
private:
	NodeSales* nextNode;
	int amount;
public:
	NodeSales(int pAmount);
    // Setters
    void setAmount(int pAmount);
    void setNextNode(NodeSales* pNextNode);

    // Getters
    int getAmount() const;
    NodeSales* getNextNode() const;
};
#endif