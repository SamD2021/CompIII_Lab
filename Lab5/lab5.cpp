#include <iostream>
#include <vector>

using namespace std;

class ComplexNumber{
public:
    ComplexNumber(): realNum(0), imagNum(0) {}
    ComplexNumber(double r, double i): realNum(r), imagNum(i) {}
    double getRealNum() const { return realNum; }
    double getImagNum() const { return imagNum; }
    void setRealNum(double r) { realNum = r; }
    void setImagNum(double i) { imagNum = i; }
    friend ostream& operator<<(ostream& out, const ComplexNumber& cn);
    ComplexNumber operator+(const ComplexNumber& rhs) const;
    ComplexNumber operator-(const ComplexNumber& rhs) const;
    ComplexNumber operator*(const ComplexNumber& rhs) const;
    ComplexNumber operator/(const ComplexNumber& rhs) const;
    ComplexNumber operator!() const;
private:
    double imagNum;
    double realNum;
};

ostream& operator<< (ostream& out, const ComplexNumber& cn);

int main(int argc, char* argv[]){
    vector<ComplexNumber> complexNumbers;
    ComplexNumber c1;
    ComplexNumber c2(1 , 2);
    ComplexNumber c3(3,4);
    cout << "Value of c1 (default constructor) :" << endl
    << "c1.Re() == " << c1.getRealNum() << ", c1.Im() == " << c1.getImagNum() << endl
    << "Value of c2 (value constructor) :" << endl
    << "c2.Re() == " << c2.getRealNum() << ", c2.Im() == " << c2.getImagNum() << endl
    << endl
    << "c2 + c3 (1+2i + 3+4i) == " << c2 + c3 << endl
    << "c2 - c3 (1+2i - 3+4i) == " << c2 - c3 << endl
    << "c2 * c3 (1+2i * 3+4i) == " << c2 * c3 << endl
    << "c2 / c3 (1+2i / 3+4i) == " << c2 / c3 << endl
    << "(c2 / c3) + (c2*c3) == " << (c2 / c3) + (c2*c3) << endl
    << "Conjugate of c2 (1+2i) == " << !c2 << endl
    << endl
    << "Vector output using indexed for-loop:" << endl;
    ComplexNumber temp;
    for(int i = 0; i < 10; i++){
        temp.setRealNum(i);
        temp.setImagNum(2*i);
        complexNumbers.push_back(temp);
    }
    for(int i = 0; i < 10; i++){
        cout << complexNumbers.at(i) << endl;
    }
    cout << "Vector output using indexed for-loop:" << endl;
    for(auto vi = complexNumbers.begin(); vi < complexNumbers.end(); vi++){
        cout << *vi << endl;
    }
    return 0;
}

ostream& operator<< (ostream& out, const ComplexNumber& cn) {
    out << cn.realNum << "+" << cn.imagNum << "i";
    return out;
}

ComplexNumber ComplexNumber::operator+ (const ComplexNumber& rhs) const {
    return {(this->realNum + rhs.realNum), (this->imagNum + rhs.imagNum)};
}

ComplexNumber ComplexNumber::operator/ (const ComplexNumber& rhs) const {
    // For reference: a / b = [(xu+yv)+(uy-xv)i] / (u^2 + v^2) where a = x+yi and b u+vi
    double divFactor = ((rhs.realNum * rhs.realNum) + (rhs.imagNum * rhs.imagNum));
    return {((this->realNum * rhs.realNum) + (this->imagNum * rhs.imagNum)) / divFactor,
            ((rhs.realNum * this->imagNum) - (this->realNum * rhs.imagNum)) / divFactor};
}

ComplexNumber ComplexNumber::operator!() const {
    return {this->realNum,this->imagNum *-1};
}

ComplexNumber ComplexNumber::operator-(const ComplexNumber& rhs) const{
    return {this->realNum - rhs.realNum, this->imagNum - rhs.imagNum};

};

ComplexNumber ComplexNumber::operator* (const ComplexNumber &rhs) const{
    return {(this->realNum * rhs.realNum - this->imagNum * rhs.imagNum),this->imagNum * rhs.realNum + this->realNum * rhs.imagNum};

}