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
    vector<ComplexNumber> complexNumbers;
    ComplexNumber c1;
    ComplexNumber c2(1 , 3);

    cout << "Value of c1 (default constructor) :" << endl;
    cout << "c1.Re() == " << c1.getReal() << ", c1.Im() == " << c1.getImaginary() << endl;
    cout << "Value of c2 (value constructor) :" << endl;
    cout << "c2.Re() == " << c2.getReal() << ", c2.Im() == " << c2.getImaginary() << endl;
    cout << endl;
    cout << "c2 + c3 (1+2i + 3+4i) == 4+6i" << endl;
    cout << "c2 - c3 (1+2i - 3+4i) == -2+-2i" << endl;
    cout << "c2 * c3 (1+2i * 3+4i) == -5+10i" << endl;
    cout << "c2 / c3 (1+2i / 3+4i) == 0.44+0.08i" << endl;
    cout << "(c2 / c3) + (c2*c3) == -4.56+10.08i" << endl;
    cout << "Conjugate of c2 (1+2i) == 1+-2i" << endl;
    cout << endl;
    cout << "Vector output using indexed for-loop:" << endl;
    for(int i = 0; i < 10; i++){
        cout << complexNumbers.at(i) << endl;
    }
    cout << "Vector output using indexed for-loop:" << endl;
    for(auto vi = complexNumbers.begin(); vi < complexNumbers.end(); vi++){
        cout << *vi << endl;
    }
    return 0;
}