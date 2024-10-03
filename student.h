#ifndef STUDENT_H
#define STUDENT_H

#include "Mylib.h"

struct Student {
    string vardas;
    string pavarde;
    vector<int> nd;
    int egz;
    double galutinisVid;
    double galutinisMed;

    void skaiciuotiGalutiniVid();
    void skaiciuotiGalutiniMed();
};



#endif
