#include "student.h"
#include "Mylib.h"
Student::Student() : egz(0), galutinisVid(0), galutinisMed(0) {}

Student::Student(const string& v, const string& p)
    : vardas(v), pavarde(p), egz(0), galutinisVid(0), galutinisMed(0) {}

string Student::getVardas() const { return vardas; }
string Student::getPavarde() const { return pavarde; }
int Student::getEgz() const { return egz; }
list<int> Student::getNd() const { return nd; }
double Student::getGalutinisVid() const { return galutinisVid; }
double Student::getGalutinisMed() const { return galutinisMed; }

void Student::setVardas(const string& v) { vardas = v; }
void Student::setPavarde(const string& p) { pavarde = p; }
void Student::setEgz(int e) { egz = e; }
void Student::setNd(const list<int>& n) { nd = n; }

void Student::skaiciuotiGalutiniVid() {
    if (nd.empty()) {
        galutinisVid = 0;
        return;
    }
    double ndVidurkis = accumulate(nd.begin(), nd.end(), 0.0) / nd.size();
    galutinisVid = 0.4 * ndVidurkis + 0.6 * egz;
}

void Student::skaiciuotiGalutiniMed() {
    if (nd.empty()) {
        galutinisMed = 0;
        return;
    }
    list<int> sorted_nd = nd;
    sorted_nd.sort();
    auto middle = next(sorted_nd.begin(), sorted_nd.size() / 2);
    if (sorted_nd.size() % 2 == 0) {
        galutinisMed = (*prev(middle) + *middle) / 2.0;
    } else {
        galutinisMed = *middle;
    }
    galutinisMed = 0.4 * galutinisMed + 0.6 * egz;
}

ChronoTimer::ChronoTimer() : start_time(chrono::high_resolution_clock::now()) {}

double ChronoTimer::getElapsedTime() const {
    auto end_time = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = end_time - start_time;
    return elapsed.count();
}

void ChronoTimer::reset() {
    start_time = chrono::high_resolution_clock::now();
}
