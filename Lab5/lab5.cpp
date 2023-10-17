#include <iostream>
#include <vector>

using namespace std;

class ComplexNumber{
public:
    ComplexNumber();
    ComplexNumber(double real,double imaginary);
    double getReal()const;
    void setReal(double num);
    void setImaginary(double num);
    double getImaginary()const;
    friend ostream& operator<<(ostream& out, const ComplexNumber& cn);
    ComplexNumber& operator+(const ComplexNumber& rhs);
    ComplexNumber& operator-(const ComplexNumber& rhs);
    ComplexNumber& operator*(const ComplexNumber& rhs);
    ComplexNumber& operator/(const ComplexNumber& rhs);
    ComplexNumber& operator!(const ComplexNumber& rhs);
private:
    double real;
    double imaginary;
};


int main(int argc, char* argv[]){
    return 0;
}