//
// Created by Sam Dasilva on 9/26/23.
//

#include <iostream>
#include "Mass.h"

using namespace std; 

void Mass::setMassTroyPounds(double mass)
{
    if (mass >= 0) { // check if non-negative
        troyPounds = mass; // stores input mas value directly since it's already in Troy pounds
        avoirdupoisPounds = mass/96.0; // converts input mass to avoirdupois (1 Troy = 1/96 Avoirdupois)
        metricGrams = mass * 373.2417; // converts input mass to grams (1 Troy = 373.24g)
    } else {
        cout << "Error: Mass cannot be negative." << endl; // if negative -> error message
    }
}

double Mass::getMassTroyPounds(void)
{
    return troyPounds;
}
>>>>>>> ad7b400 (Set and get troyPounds functions implemented)
