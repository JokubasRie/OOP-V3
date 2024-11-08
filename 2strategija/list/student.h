#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED

#include <list>
#include <string>
#include "Mylib.h"

struct Student {
    std::string vardas;
    std::string pavarde;
    std::list<int> nd;
    int egz;
    double galutinisVid;
    double galutinisMed;

    void skaiciuotiGalutiniVid();
    void skaiciuotiGalutiniMed();
};

// ChronoTimer klasė laikui matuoti
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

#endif // STUDENT_H_INCLUDED
