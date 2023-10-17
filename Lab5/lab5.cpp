#include <iostream>

using namespace std;

class ComplexNumber {
private:
    int realNum;
    int imagNum;

public:
    // Default constructor
    ComplexNumber(): realNum(0), imagNum(0) {}

    // Value constructor
    ComplexNumber(double r, double i): realNum(r), imagNum(i) {}

};