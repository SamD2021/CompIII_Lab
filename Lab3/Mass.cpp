//
// Created by Sam Dasilva on 9/26/23.
//

#include "Mass.h"

void Mass::setMassMetricGrams(double mass){

    metricGrams = mass * 1.7718451953125;
}

double Mass::getMassMetricGrams(void) const
{
    return metricGrams;
}
