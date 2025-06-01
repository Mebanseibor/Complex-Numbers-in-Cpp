#include <iostream>
#include "headers/Company.h"


using namespace com;
int main(){
    std::cout << "\t--- Start of Program ---\n\n\n";

    std::cout << "Employee:\n";
    Employee employee = Employee(0, "Emily");
    employee.printDetails();


    std::cout << "\nManager:\n";
    Manager manager = Manager(1, "Medon");
    manager.printDetails();
    
    std::cout << "\nDeveloper:\n";
    Developer developer = Developer(2, "Daphi", 3);
    developer.printDetails();
    
    std::cout << "\nSales Person:\n";
    SalesPerson salesPerson = SalesPerson(3, "Simon", 2);
    salesPerson.printDetails();
    
    std::cout << "\nTech Lead:\n";
    TechLead techLead = TechLead(4, "Timothy", 5);
    techLead.printDetails();

    std::cout << "\n\n\t--- End of Program ---\n\n\n";

    return 0;
}
