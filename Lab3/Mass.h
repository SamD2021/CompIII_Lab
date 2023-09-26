//
// Created by Sam Dasilva on 9/26/23.
//

#ifndef COMPIII_LAB_MASS_H
#define COMPIII_LAB_MASS_H


class Mass {
public:
    void setMassAvoirdupoisPounds(double mass);
    void setMassTroyPounds(double mass);
    void setMassMetricGrams(double mass);
    double getMassAvoirdupoisPounds(void);
    double getMassTroyPounds(void);
    double getMassMetricGrams(void);
private:
    double avoirdupoisPounds;
    double troyPounds;
    double metricGrams;
};


#endif //COMPIII_LAB_MASS_H
