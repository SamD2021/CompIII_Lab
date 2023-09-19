#include <iostream>
#include <cmath>

using namespace std;
// functions declaration below

void driver_code();
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
    // convert_pounds_and_oz_to_kilograms_and_grams(pounds,ounces, kilograms, grams);
    // displayConversion(pounds, ounces, kilograms, grams);
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
    kilograms = totalWeight;
    grams = (totalWeight - kilograms) * 1000;
}
