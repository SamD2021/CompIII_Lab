/*
    Program: Lab 2
    Group: Samuel Dasilva, Melissa Ing, Luka Metias, Camila Salinas Camacho
    Due Date: 09/26/2023
*/

#include <iostream>
#include <cmath>

using namespace std;
// functions declaration below

void driver_code();
void getUserInput(int& pounds, double& ounces);
void displayConversion (int pounds, double ounces, int kilograms, double grams);
void convert_pounds_and_oz_to_kilograms_and_grams(int pounds, double oz, int& kilograms, double& grams);

// Constants
const double KG = 0.45359237;

int main(int argc, char* argv[]){
    driver_code(); // executes all the functions
    
    return 0;
}

void driver_code(){
    // call all functions from here
    int pounds, kilograms;
    double ounces, grams;
    getUserInput(pounds, ounces);
    convert_pounds_and_oz_to_kilograms_and_grams(pounds,ounces, kilograms, grams);
    displayConversion(pounds, ounces, kilograms, grams);
}

void getUserInput(int& pounds, double& ounces){
    while ((cout << "Please enter the number of pounds: ") && (!(cin >> pounds) || pounds < 0)) {
        cout << "That is not a number greater than or equal to 0. " << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    while ((cout << "Please enter the number of ounces: ") && (!(cin >> ounces) || ounces < 0.0 || ounces >= 16.0)) {
        cout << "That is not a number greater than or equal to 0 and less than 16. " << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

void displayConversion (int pounds, double ounces, int kilograms, double grams)
{
    cout << pounds << " pounds and " << ounces << " ounces converts to " << endl;
    cout.precision(8);
    cout << kilograms << " kilograms and " << fixed << grams << " grams " << endl;
}

void convert_pounds_and_oz_to_kilograms_and_grams(int pounds, double oz, int& kilograms, double& grams){
    double totalPounds;
    double totalWeight;
    
    totalPounds = (oz/16.0) + pounds;
    totalWeight = totalPounds * KG;
    kilograms = floor(totalWeight);
    grams = (totalWeight - kilograms) * 1000;
}
