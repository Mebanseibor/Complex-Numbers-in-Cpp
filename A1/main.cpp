#include <iostream>
#include "headers/Company.h"


using namespace com;
int main(){
    std::cout << "Employee:\n";
    Employee employee = Employee();
    employee.printDetails();


    std::cout << "\nManager:\n";
    Manager manager = Manager();
    manager.printDetails();
    
    return 0;
}
