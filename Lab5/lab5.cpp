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

using namespace std;

class ComplexNumber {
private:
    double realNum;
    double imagNum;

public:
    // Default constructor
    ComplexNumber(): realNum(0), imagNum(0) {}

    // Value constructor
    ComplexNumber(double r, double i): realNum(r), imagNum(i) {}

    // Accessor functions
    double getRealNum() const { return realNum; }
    double getImagNum() const { return imagNum; }

    // Mutator functions
    double setRealNum(double r) { realNum = r; }
    double setImagNum(double i) { imagNum = i; }
};

int main (int argc, char* argv[])
{
    // Driver code
    
    return 0;
}