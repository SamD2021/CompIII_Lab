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
