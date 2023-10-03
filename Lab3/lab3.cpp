#include <iostream>
#include <string>
#include <limits>
#include "Mass.h"
using namespace std;
int main(int argc, char* argv[]){

    int userInput = 0;
    double pounds;
    string chosenUnit;
    Mass myMass;
    do{
        cout << "Please enter 1 to use Avoirdupois pounds, 2 to use Troy pounds, 3 to use grams, or 0 to exit:" << endl;
        cin >> userInput;
        switch (userInput){
            case 0:
                return 0;
                break;
            case 1:
                chosenUnit = "Avoirdupois pounds";
            case 2:
                chosenUnit = "Troy pounds";
                break;
            case 3:
                chosenUnit = "grams";
                break;
            default:
                while ((cout << "Please enter the number of pounds: ") && (!(cin >> pounds) || pounds < 0)) {
                    cout << "Not a valid number, please try again. " << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
        }
        cout << "Please enter a mass in " << chosenUnit << ": ";
        while ((cout << "Please enter the number of pounds: ") && (!(cin >> pounds) || pounds < 0)) {
            cout << "That is not a number greater than or equal to 0. " << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        if(chosenUnit == "Avoirdupois pounds"){
            myMass.setMassAvoirdupoisPounds(pounds);
        }else if(chosenUnit == "Troy pounds"){
            myMass.setMassTroyPounds(pounds);
        }else if (chosenUnit == "grams"){
            myMass.setMassMetricGrams(pounds);
        }
        cout << myMass.getMassAvoirdupoisPounds() << endl;
        cout << myMass.getMassTroyPounds() << endl;
        cout << myMass.getMassMetricGrams() << endl;
    }while(userInput);

    return 0;
}
/*
Please enter 1 to use Avoirdupois pounds, 2 to use Troy pounds, 3 to use grams, or 0 to exit: 1
Please enter a mass in Avoirdupois pounds: 1
*/