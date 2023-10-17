#include <iostream>

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