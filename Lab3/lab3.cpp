#include <iostream>
#include <string>

using namespace std;

int main(){
    int userInput;
    string chosenUnit = "";
    double units;
    
    do {
        cout << "Please enter 1 to use Avoirdupois pounds, 2 to use Troy pounds, 3 to use grams, or 0 to exit: ";
        cin >> userInput;
        
        switch (userInput){
        case 0:
            cout << "Thanks for using the mass conversion program!" << endl;
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
        }
    } while ((userInput < 0) || (userInput > 3));

    if (chosenUnit != ""){
        while ((cout << "Please enter a mass in " << chosenUnit << ": ") && (!(cin >> units) || units < 0.0)) {
            cout << "That is not a number greater than or equal to 0. " << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    return 0;
}