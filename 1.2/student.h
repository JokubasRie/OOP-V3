#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED

#include <string>
#include <list>
#include <iostream>
#include <iomanip>
#include <numeric>
#include <algorithm>
#include <chrono>

class Student {
private:
    std::string vardas;
    std::string pavarde;
    std::list<int> nd;
    int egz;
    double galutinisVid;
    double galutinisMed;

public:
    Student() : egz(0), galutinisVid(0), galutinisMed(0) {}
    Student(const std::string& v, const std::string& p)
        : vardas(v), pavarde(p), egz(0), galutinisVid(0), galutinisMed(0) {}
    ~Student() { nd.clear(); }

    Student(const Student& other)
        : vardas(other.vardas), pavarde(other.pavarde), nd(other.nd), egz(other.egz),
          galutinisVid(other.galutinisVid), galutinisMed(other.galutinisMed) {}

    Student& operator=(const Student& other) {
        if (this != &other) {
            vardas = other.vardas;
            pavarde = other.pavarde;
            nd = other.nd;
            egz = other.egz;
            galutinisVid = other.galutinisVid;
            galutinisMed = other.galutinisMed;
        }
        return *this;
    }

    std::string getVardas() const { return vardas; }
    std::string getPavarde() const { return pavarde; }
    int getEgz() const { return egz; }
    std::list<int> getNd() const { return nd; }
    double getGalutinisVid() const { return galutinisVid; }
    double getGalutinisMed() const { return galutinisMed; }

    void setVardas(const std::string& v) { vardas = v; }
    void setPavarde(const std::string& p) { pavarde = p; }
    void setEgz(int e) { egz = e; }
    void setNd(const std::list<int>& n) { nd = n; }

    void skaiciuotiGalutiniVid() {
        if (nd.empty()) {
            galutinisVid = 0;
            return;
        }
        double ndVidurkis = std::accumulate(nd.begin(), nd.end(), 0.0) / nd.size();
        galutinisVid = 0.4 * ndVidurkis + 0.6 * egz;
    }

    void skaiciuotiGalutiniMed() {
        if (nd.empty()) {
            galutinisMed = 0;
            return;
        }
        std::list<int> sorted_nd = nd;
        sorted_nd.sort();
        auto middle = std::next(sorted_nd.begin(), sorted_nd.size() / 2);
        if (sorted_nd.size() % 2 == 0) {
            galutinisMed = (*std::prev(middle) + *middle) / 2.0;
        } else {
            galutinisMed = *middle;
        }
        galutinisMed = 0.4 * galutinisMed + 0.6 * egz;
    }

    friend std::istream& operator>>(std::istream& in, Student& student) {
        std::cout << "Iveskite studento varda: ";
        in >> student.vardas;

        std::cout << "Iveskite studento pavarde: ";
        in >> student.pavarde;

        char pasirinkimas;
        std::cout << "Ar norite ivesti namu darbu ir egzamino pazymius patys, ar juos sugeneruoti? (0 - patys, 1 - sugeneruoti): ";
        in >> pasirinkimas;

        if (pasirinkimas == '1') {
            int kiekNd;
            std::cout << "Kiek namu darbu pažymiu sugeneruoti? ";
            in >> kiekNd;

            for (int i = 0; i < kiekNd; ++i) {
                student.nd.push_back(rand() % 11); // Atsitiktiniai balai nuo 0 iki 10
            }
            student.egz = rand() % 11; // Atsitiktinis egzamino balas
        } else {
            int ndBalas;
            student.nd.clear();
            std::cout << "Iveskite namu darbu balus (iveskite -1, jei norite baigti):\n";
            while (in >> ndBalas && ndBalas != -1) {
                student.nd.push_back(ndBalas);
            }

            std::cout << "Iveskite egzamino rezultata: ";
            in >> student.egz;
        }

        student.skaiciuotiGalutiniVid();
        student.skaiciuotiGalutiniMed();

        return in;
    }

    friend std::ostream& operator<<(std::ostream& out, const Student& student) {
        out << std::setw(15) << std::left << student.vardas
            << std::setw(15) << std::left << student.pavarde
            << std::setw(20) << std::fixed << std::setprecision(2) << student.galutinisVid
            << std::setw(20) << std::fixed << std::setprecision(2) << student.galutinisMed;
        return out;
    }
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

#endif // STUDENT_H_INCLUDED
