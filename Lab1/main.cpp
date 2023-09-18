/*
    Program: Lab 1
    Group: Samuel Dasilva, Melissa Ing (Presenter), Luka Metias, Camila Salinas Camacho
    Due Date: 09/19/2023
*/

#include <iostream>

using namespace std;

void user_input (double& annual_interest_rate, double& amount_to_receive, int& loan_period);
double calculateLoanAmount(double amountNeeded, double interestRate, int durationMonths, double& monthlyPayment);

int main(int argc, char *argv[]) {
    double annual_interest_rate, amount_to_receive, temp_total;
    int loan_period;
    double temp_monthly_payment;

    user_input(annual_interest_rate, amount_to_receive, loan_period);
    temp_total = calculateLoanAmount(amount_to_receive, annual_interest_rate, loan_period, temp_monthly_payment);
    cout << "The total amount of a loan with an annual interest rate of " << annual_interest_rate << "% is $" << temp_total << "." << endl;
    cout << "The monthly payment for " << loan_period << " months will be $" << temp_monthly_payment << "." << endl;

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
    faceValue = amountNeeded/((1-interestRate)*durationYears);
    monthlyPayment = faceValue/durationMonths;

    return faceValue;
}
