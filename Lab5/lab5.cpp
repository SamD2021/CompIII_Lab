#include <iostream>
#include <vector>

using namespace std;

class ComplexNumber{
public:
    ComplexNumber();
    int getReal()const;
    void setReal(int num);
    void setImaginary(const string& num);
    string getImaginary()const;
    friend ostream& operator<<(ostream& out, const ComplexNumber& cn);
    ComplexNumber& operator+(const ComplexNumber& rhs);
    ComplexNumber& operator-(const ComplexNumber& rhs);
    ComplexNumber& operator*(const ComplexNumber& rhs);
    ComplexNumber& operator/(const ComplexNumber& rhs);
    ComplexNumber& operator!(const ComplexNumber& rhs);
private:
    int real;
    string imaginary;
};


int main(int argc, char* argv[]){
    return 0;
}