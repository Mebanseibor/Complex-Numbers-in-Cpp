#include <iostream>
#include <cmath>

class Complex{
    private:
    double real;
    double imag;

    public:
    Complex(double r = 0.0, double i = 0.0){
        real = r;
        imag = i;
    }

    Complex operator + (const Complex& other) const{
        return Complex(this->real+other.real , this->imag + other.imag);
    }

    Complex operator - (const Complex& other) const{
        return Complex(this->real-other.real , this->imag - other.imag);
    }

    Complex operator * (const Complex& other) const{
        double realPart = this->real * other.real - this->imag * other.imag;
        double imagPart = this->real * other.imag + this->imag * other.real;
        return Complex(realPart, imagPart);
    }

    bool operator == (const Complex& other) const {
        const double EPS = 1e-6;
        bool boolReal = std::abs(this->real - other.real) <= EPS;
        bool boolImag = std::abs(this->imag - other.imag) <= EPS;
        return boolReal && boolImag;
    }

    Complex& operator ++(){ // prefix
        real++;
        return *this;
    }

    Complex operator ++(int){   // postfix
        Complex result = *this;
        real++;
        return result;
    }

    // helper functions
    void display(){
        char symbol = '\0';
        if (imag>=0) symbol = '+';
        std::cout << real << symbol << imag << "i\n";
    }

    double getReal() const {return real;}
    double getImag() const {return imag;}
    double& getReal() {return real;}
    double& getImag() {return imag;}
    void setReal(double real){this->real = real;}
    void setImag(double imag){this->imag = imag;}
};

std::ostream& operator << (std::ostream& os, const Complex& c) {
    os << c.getReal();

    if (c.getImag() >= 0) os << "+" << c.getImag() << "i";
    else os << c.getImag() << "i";

    return os;
}

std::istream& operator >> (std::istream& is, Complex& c) {
    is >> c.getReal() >> c.getImag();
    return is;
}

Complex input(){
    double r, i;
    std::cout << "Enter the real part: ";
    std::cin >> r;
    std::cout << "Enter the imaginary part: ";
    std::cin >> i;
    return Complex(r, i);
}

void displayInputs(Complex c1, Complex c2){
    std::cout << "Complex Number 1:\n";
    c1.display();

    std::cout << "\nComplex Number 2:\n";
    c2.display();
}

int main(){
    std::cout << "--- Start of program ---\n";

    // take inputs
    std::cout << "Input 2 complex numbers\n";
    
    std::cout << "Enter the first complex number:\n";
    Complex c1 = input();
    std::cout << "\n";

    std::cout << "Enter the second complex number:\n";
    Complex c2 = input();
    std::cout << "\n";

    displayInputs(c1, c2);



    // compute sum, difference and product
    Complex cSum = c1+c2;
    Complex cDiff = c1-c2;
    Complex cProduct = c1*c2;

    std::cout << "\n\nResults of their Sum, Difference and Products\n";

    std::cout << "Sum:\n";
    cSum.display();

    std::cout << "\nDiff:\n";
    cDiff.display();

    std::cout << "\nProduct:\n";
    cProduct.display();




    // prefix and postfix
    std::cout << "\n\nPrefix and Postfix\n";
    std::cout << "Before prefix:\t" << c1.getReal() << "\n";
    std::cout << "After prefix:\t" << ++c1.getReal();

    std::cout << "\nBefore postfix:\t" << c1.getReal() << "\n";
    std::cout << "After postfix:\t" << c1++.getReal();
    

    // equality
    std::cout << "\n\nEquality Check\n";
    std::string equality = c1==c2?"true":"false";
    std::cout << "Equality:\t" << equality << "\n";



    // demonstrating << operator overloadding
    std::cout << "\n\nResults:\n";
    std::cout << "First complex number:\t" << c1 << "\n";
    std::cout << "Second complex number:\t" << c2 << "\n";
    std::cout << "Sum:\t" << cSum<< "\n";
    std::cout << "Difference:\t" << cDiff<< "\n";
    std::cout << "Product:\t" << cProduct<< "\n";


    std::cout << "\n\n--- End of program ---\n";
    std::cout << "Enter any character to exit\n";
    std::string input;
    std::cin >> input;

    return 0;
}
