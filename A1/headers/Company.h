#ifndef Company
    #include <iostream>
    
    namespace com{
        class Employee{
            public:
            int id = 0;
            std::string name = "default name";
            double salaryBase = 10000;

            double calculateSalary(){ return salaryBase; }

            void printDetails(){
                std::cout << "ID:\t" << id << "\n";
                std::cout << "Name:\t" << name << "\n";
                std::cout << "Salary Base:\t" << salaryBase << "\n";
            }
        };

        class Manager : Employee{
            double percentage = 20;
            double salary = 0;

            void calculateSalary(){ salary = salaryBase * (1 + percentage/100); }

            public:
            Manager(){ calculateSalary(); }

            void printDetails(){
                Employee::printDetails();
                std::cout << "Salary:\t" << salary << "\n";
            }
        };
    }
#endif
