//
// Created by Sam Dasilva on 9/26/23.
//

#ifndef COMPIII_LAB_MASS_H
#define COMPIII_LAB_MASS_H


class Mass {
public:
    Mass():drams(0){}
    void setMassAvoirdupoisPounds(double mass);
    void setMassTroyPounds(double mass);
    void setMassMetricGrams(double mass);
    double getMassAvoirdupoisPounds(void) const;
    double getMassTroyPounds(void) const;
    double getMassMetricGrams(void) const;
private:
    double drams;
};


#endif //COMPIII_LAB_MASS_H
