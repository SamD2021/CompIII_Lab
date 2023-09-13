#include <iostream>

using namespace std;

double calculateLoanAmount(double initialFaceValue, double interestRate, int durationMonths, double& monthlyPayment);

int main(int argc, char *argv[]) {

    return 0;
}


double calculateLoanAmount(double amountNeeded, double interestRate, int durationMonths, double& monthlyPayment){
    double durationYears;
    double totalInterest;
    double faceValue;
    double amountReceived;
    interestRate = interestRate/100; // transition from percentage to decimal
    durationYears = durationMonths/12.0;
    totalInterest = (amountNeeded * (interestRate)) * durationYears;
    amountReceived = amountNeeded - totalInterest;
    faceValue = amountReceived/(1-(interestRate*durationYears));
    monthlyPayment = faceValue/durationMonths;

    return amountReceived;
}
