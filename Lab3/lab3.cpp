#include <iostream>
#include <string>
#include <limits>
#include "Mass.h"
using namespace std;
int main(int argc, char* argv[]){

    int userInput;
    double units;
    string chosenUnit = "";
    Mass myMass;

    do {
        chosenUnit = "";
        cout << "Please enter 1 to use Avoirdupois pounds, 2 to use Troy pounds, 3 to use grams, or 0 to exit: ";
        cin >> userInput;

        switch (userInput){
            case 0:
                cout << "Thanks for using the mass conversion program!" << endl;
                return 0;
                break;
            case 1:
                chosenUnit = "Avoirdupois pounds";
                break;
            case 2:
                chosenUnit = "Troy pounds";
                break;
            case 3:
                chosenUnit = "grams";
                break;
            default:
                cout << "Not a valid number, please try again." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
        }

        if (chosenUnit != ""){
            while ((cout << "Please enter a mass in " << chosenUnit << ": ") && (!(cin >> units) || units < 0.0)) {
                cout << "That is not a number greater than or equal to 0." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }

        if (chosenUnit == "Avoirdupois pounds"){
            myMass.setMassAvoirdupoisPounds(units);
        } else if (chosenUnit == "Troy pounds"){
            myMass.setMassTroyPounds(units);
        } else if (chosenUnit == "grams"){
            myMass.setMassMetricGrams(units);
        }
        if(chosenUnit != ""){
            cout << "Mass in " << "Avoirdupois pounds" << " is " << myMass.getMassAvoirdupoisPounds() << endl;
            cout << "Mass in " << "Troy pounds" << " is " << myMass.getMassTroyPounds() << endl;
            cout << "Mass in " << "grams" << " is " << myMass.getMassMetricGrams() << endl;
        }
    } while(userInput);

    return 0;
}