#include <iostream>

using namespace std;

void user_input (double& annual_interest_rate, double& amount_to_receive, int& loan_period);
double calculateLoanAmount(double initialFaceValue, double interestRate, int durationMonths, double& monthlyPayment);

int main(int argc, char *argv[]) {
    double annual_interest_rate, amount_to_receive;
    int loan_period;

    user_input(annual_interest_rate, amount_to_receive, loan_period);

    return 0;
}

void user_input (double& annual_interest_rate, double& amount_to_receive, int& loan_period)
{
    cout << "Please enter the annual interest rate as a percentage: ";
    cin >> annual_interest_rate;

    if (annual_interest_rate != 0) {
        cout << "Please enter the amount you would like to receive: ";
        cin >> amount_to_receive;
        
        cout << "Please enter loan period in months: ";
        cin >> loan_period;
    }
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
