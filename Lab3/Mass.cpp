//
// Created by Sam Dasilva on 9/26/23.
//

#include "Mass.h"

void Mass::setMassAvoirdupoisPounds(double mass) {
    double convertedMass;
    convertedMass = mass/256;
    avoirdupoisPounds = convertedMass;
}

double Mass::getMassAvoirdupoisPounds() const  {
    return avoirdupoisPounds;
}
