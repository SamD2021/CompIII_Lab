//
// Created by Sam Dasilva on 9/26/23.
//

#include "Mass.h"
double const GRAMS = 1.7718451953125;

void Mass::setMassAvoirdupoisPounds(double mass) {
    drams = mass*256;
;
}

double Mass::getMassAvoirdupoisPounds() const  {
    return drams/256;
}

void Mass::setMassTroyPounds(double mass)
{
    drams = mass*96;
}

double Mass::getMassTroyPounds() const
{
    return drams/96;
}

void Mass::setMassMetricGrams(double mass) {
    drams = mass/GRAMS;
}

double Mass::getMassMetricGrams() const {
    return drams * GRAMS;
}


