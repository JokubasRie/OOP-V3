#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED

#include <string>
#include <list>
#include <chrono>
#include <numeric>
#include <algorithm>
#include <iostream>

class Student {
private:
    std::string vardas;
    std::string pavarde;
    std::list<int> nd;
    int egz;
    double galutinisVid;
    double galutinisMed;
public:
    Student();
    Student(const std::string& v, const std::string& p);
    ~Student(){
        nd.clear();
    }

    std::string getVardas() const;
    std::string getPavarde() const;
    int getEgz() const;
    std::list<int> getNd() const;
    double getGalutinisVid() const;
    double getGalutinisMed() const;

    void setVardas(const std::string& v);
    void setPavarde(const std::string& p);
    void setEgz(int e);
    void setNd(const std::list<int>& n);

    void skaiciuotiGalutiniVid();
    void skaiciuotiGalutiniMed();
};

class ChronoTimer {
public:
    ChronoTimer();

    double getElapsedTime() const;
    void reset();

private:
    std::chrono::time_point<std::chrono::high_resolution_clock> start_time;
};

#endif // STUDENT_H_INCLUDED
