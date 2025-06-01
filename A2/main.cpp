# include<iostream>

class Complex{
    private:
    double real;
    double imag;

    public:
    Complex(double r = 0.0, double i = 0.0){
        real = r;
        imag = i;
    }

    Complex sum(Complex c1, Complex c2){ return Complex(c1.real+c2.real, c1.imag+c2.imag); }
    Complex diff(Complex c1, Complex c2){ return Complex(c1.real-c2.real, c1.imag-c2.imag); }
    Complex product(Complex c1, Complex c2){ return Complex(c1.real*c2.real, c1.imag*c2.imag); }

    // helper functions
    void display(){
        // std::cout << "Real part:\t" << real << "\n";
        // std::cout << "Imaginary part:\t" << imag << "\n";
        char symbol = '\0';
        if (imag>=0) symbol = '+';
        std::cout << real << symbol << imag << "i\n";
    }
};

Complex input(){
    double r, i;
    std::cout << "Enter the real part: ";
    std::cin >> r;
    std::cout << "Enter the imaginary part: ";
    std::cin >> i;
    return Complex(r, i);
}

void testInputs(Complex c1, Complex c2){
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

    testInputs(c1, c2);

    // compute sum, difference and product
    Complex cSum = Complex().sum(c1, c2);
    Complex cDiff = Complex().diff(c1, c2);
    Complex cProduct = Complex().product(c1, c2);

    std::cout << "\n\nResults of their Sum, Difference and Products\n";
    std::cout << "Sum:\n";
    cSum.display();

    std::cout << "\nDiff:\n";
    cDiff.display();

    std::cout << "\nProduct:\n";
    cProduct.display();

    // prefix and postfix
    std::cout << "\n\nPrefix and Postfix\n";
    std::cout << "Before prefix:\t" << "\n";
    std::cout << "After prefix:\t" << "\n";

    std::cout << "Before postfix:\t" << "\n";
    std::cout << "After postfix:\t" << "\n";



    std::cout << "\n\n--- End of program ---\n";
    std::cout << "Enter any character to exit\n";
    std::string input;
    std::cin >> input;

    return 0;
}
