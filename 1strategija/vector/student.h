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


class ChronoTimer {
public:
    ChronoTimer() : start_time(std::chrono::high_resolution_clock::now()) {}

    double getElapsedTime() const {
        auto end_time = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = end_time - start_time;
        return elapsed.count();
    }

    void reset() {
        start_time = std::chrono::high_resolution_clock::now();
    }

private:
    std::chrono::time_point<std::chrono::high_resolution_clock> start_time;
};


#endif
