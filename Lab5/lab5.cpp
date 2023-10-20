#include <iostream>
#include <vector>

using namespace std;

class ComplexNumber{
public:
    // Default constructor
    ComplexNumber() : _real(0), _imaginary(0) {}

    // Value constructor
    ComplexNumber(double real, double imaginary) : _real(real), _imaginary(imaginary) {}

    // Accessor functions
    double getReal() const { return _real; }
    double getImaginary() const { return _imaginary; }

    // Mutator functions
    void setReal(double real) { _real = real; }
    void setImaginary(double imaginary) { imaginary = imaginary; }

    // Insertion operator
    friend ostream& operator<< (ostream& out, const ComplexNumber& cn);

    // Overloaded operations
    ComplexNumber& operator+ (const ComplexNumber& rhs);
    ComplexNumber& operator- (const ComplexNumber& rhs);
    ComplexNumber& operator* (const ComplexNumber& rhs);
    ComplexNumber& operator/ (const ComplexNumber& rhs);
    ComplexNumber& operator! (const ComplexNumber& rhs);

private:
    double _real;
    double _imaginary;
};

ostream& operator<< (ostream& out, const ComplexNumber& cn) {
	out << cn._real << "+" << cn._imaginary << "i";
}

ComplexNumber operator+ (const ComplexNumber& rhs) {
	return ComplexNumber((this->_real + rhs._real), (this->_imaginary + rhs._imaginary));
}

ComplexNumber operator/ (const ComplexNumber& rhs) {
	// For reference: a / b = [(xu+yv)+(uy-xv)i] / (u^2 + v^2) where a = x+yi and b u+vi
    double divFactor = ((rhs._real * rhs._real) + (rhs._imaginary * rhs._imaginary));
    return ComplexNumber(((this->_real * rhs._real) + (this->_imaginary * rhs.imaginary)) / divFactor,
            ((rhs._real * this->_imaginary) - (this->_real * rhs._imaginary)) / divFactor);
}

int main (int argc, char* argv[])
{
    // Driver code
    return 0;
}