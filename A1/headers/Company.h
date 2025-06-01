#ifndef Company
    #include <iostream>
    const double bonusManagersPercentage = 20;
    const double bonusDeveloperValue = 1000;
    const double bonusSalesPersonValue = 500;
    
    namespace com{
        class Employee{
            public:
            int id = 0;
            std::string name = "default name";
            double salaryBase = 10000;

            void calculateSalary(){ }

            Employee(){ }

            Employee(int id, std::string name){
                this->id = id;
                this->name = name;
                calculateSalary();
            }

            void printDetails(){
                std::cout << "ID:\t" << id << "\n";
                std::cout << "Name:\t" << name << "\n";
                std::cout << "Salary Base:\t" << salaryBase << "\n";
            }

            virtual ~Employee(){ std::cout << "Base object with name " << name << " has been destroyed\n"; }
        };

        class Manager : Employee{
            double salary = 0;

            void calculateSalary(){ salary = salaryBase * (1 + bonusManagersPercentage/100); }

            public:
            Manager(int id, std::string name){
                this->id = id;
                this->name = name;
                calculateSalary();
            }

            void printDetails(){
                Employee::printDetails();
                std::cout << "Bonus Percentage over base salary:\t" << bonusManagersPercentage << "\n";
                std::cout << "Salary:\t" << salary << "\n";
            }

            ~Manager(){ std::cout << "Destroying Manager:\t" << name << "\n"; }
        };

        class Developer : Employee{
            int countProjects = 0;
            double salary = 0;
            
            void calculateSalary(){ salary = salaryBase + (bonusDeveloperValue*countProjects); }

            public:
            Developer(int id, std::string name, int projects){
                this->id = id;
                this->name = name;
                countProjects = projects;
                calculateSalary();
            }

            void printDetails(){
                Employee::printDetails();
                std::cout << "Projects Done:\t" << countProjects << "\n";
                std::cout << "Bonus per project:\t" << bonusDeveloperValue << "\n";
                std::cout << "Salary:\t" << salary << "\n";
            }

            ~Developer(){ std::cout << "Destroying Developer:\t" << name << "\n"; }
        };

        class SalesPerson : Employee{
            int monthlySales = 0;
            double salary = 0;
            
            void calculateSalary(){ salary = salaryBase + (bonusSalesPersonValue*monthlySales); }

            public:
            SalesPerson(int id, std::string name, int monthlySales){
                this->id = id;
                this->name = name;
                this->monthlySales = monthlySales;
                calculateSalary();
            }

            void printDetails(){
                Employee::printDetails();
                std::cout << "Monthly Sales:\t" << monthlySales<< "\n";
                std::cout << "Bonus per Monthly Sales:\t" << bonusSalesPersonValue << "\n";
                std::cout << "Salary:\t" << salary << "\n";
            }

            ~SalesPerson(){ std::cout << "Destroying Sales Person:\t" << name << "\n"; }
        };

        class TechLead : Employee{
            int countProjects = 0;
            int salary = 0;

            void calculateSalary(){
                double bonusManager = salaryBase * (bonusManagersPercentage/100); 
                double bonusDeveloper = bonusDeveloperValue*countProjects; 
                salary = salaryBase + bonusManager + bonusDeveloper;
            }

            public:
            TechLead(int id, std::string name, int projects){
                this->id = id;
                this->name = name;
                countProjects = projects;
                calculateSalary();
            }

            void printDetails(){
                Employee::printDetails();
                std::cout << "Projects Done:\t" << countProjects << "\n";
                std::cout << "Bonus per project:\t" << bonusDeveloperValue << "\n";
                std::cout << "Bonus Percentage over base salary:\t" << bonusManagersPercentage << "\n";
                std::cout << "Salary:\t" << salary << "\n";
            }

            ~TechLead(){ std::cout << "Destroying Tech Lead:\t" << name << "\n"; }
        };
    }
#endif
