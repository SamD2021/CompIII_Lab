//
// Created by Sam Dasilva on 9/26/23.
//

#include "Mass.h"

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
