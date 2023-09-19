#include <iostream>
#include <cmath>

using namespace std;

void driver_code();
void displayConversion (int pounds, double ounces, int kilograms, double grams);

int main(int argc, char* argv[]){
    driver_code(); // executes all the functions
    return 0;
}

void driver_code(){
    // call all functions from here

    // displayConversion(pounds, ounces, kilograms, grams);
}


void displayConversion (int pounds, double ounces, int kilograms, double grams)
{
    cout << pounds << " pounds and " << ounces << " ounces converts to " << endl;
    cout.precision(8);
    cout << kilograms << " kilograms and " << fixed << grams << " grams " << endl;
}