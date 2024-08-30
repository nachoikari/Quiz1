#include "ListFloor.h"
void menu();
int main() {
    menu();
    return 0;
}
void menu() {
    ListFloor ini;
    int option;

    do {
        std::cout << "===== Menu =====" << std::endl;
        std::cout << "1. Insert floor" << std::endl;
        std::cout << "2. Insert employee in a floor" << std::endl;
        std::cout << "3. Insert sale for an employee" << std::endl;
        std::cout << "4. Delete floor" << std::endl;
        std::cout << "5. Display floor information" << std::endl;
        std::cout << "6. Exit" << std::endl;
        std::cout << "Choose an option: ";
        std::cin >> option;

        switch (option) {
        case 1: {
            int floorNumber;
            std::cout << "Enter the floor number: ";
            std::cin >> floorNumber;
            ini.insertFloor(floorNumber);
            std::cout << "Floor " << floorNumber << " inserted." << std::endl;
            break;
        }
        case 2: {
            int floorNumber;
            std::string employeeName;
            std::cout << "Enter the floor number: ";
            std::cin >> floorNumber;
            std::cout << "Enter the employee's name: ";
            std::cin >> employeeName;
            ini.insertEmployee(floorNumber, employeeName);
            std::cout << "Employee " << employeeName << " inserted into floor " << floorNumber << "." << std::endl;
            break;
        }
        case 3: {
            int floorNumber, amount;
            std::string employeeName;
            std::cout << "Enter the floor number: ";
            std::cin >> floorNumber;
            std::cout << "Enter the employee's name: ";
            std::cin >> employeeName;
            std::cout << "Enter the sale amount: ";
            std::cin >> amount;
            ini.insertSale(floorNumber, employeeName, amount);
            std::cout << "Sale of " << amount << " added for " << employeeName << " in floor " << floorNumber << "." << std::endl;
            break;
        }
        case 4: {
            int floorNumber;
            std::cout << "Enter the floor number to delete: ";
            std::cin >> floorNumber;
            ini.deleteFloor(floorNumber);
            std::cout << "Floor " << floorNumber << " deleted." << std::endl;
            break;
        }
        case 5: {
            int floorNumber;
            std::cout << "Enter the floor number to display: ";
            std::cin >> floorNumber;
            ini.printFloor(floorNumber);
            break;
        }
        case 6:
            std::cout << "Exiting the program..." << std::endl;
            break;
        default:
            std::cout << "Invalid option, please try again." << std::endl;
        }
        std::cout << std::endl;
    } while (option != 6);
}