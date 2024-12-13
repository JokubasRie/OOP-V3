#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED

#include "Mylib.h"

class Zmogus {
protected:
    string vardas;
    string pavarde;

public:
    Zmogus() : vardas(""), pavarde("") {}
    Zmogus(const string& v, const string& p) : vardas(v), pavarde(p) {}
    virtual ~Zmogus() = 0;

    string getVardas() const { return vardas; }
    string getPavarde() const { return pavarde; }

    void setVardas(const string& v) { vardas = v; }
    void setPavarde(const string& p) { pavarde = p; }

    virtual void spausdintiInfo() const = 0;
};

inline Zmogus::~Zmogus() {}

class Student : public Zmogus {
private:
    list<int> nd;
    int egz;
    double galutinisVid;
    double galutinisMed;

public:
    Student() : Zmogus(), egz(0), galutinisVid(0), galutinisMed(0) {}
    Student(const string& v, const string& p) : Zmogus(v, p), egz(0), galutinisVid(0), galutinisMed(0) {}

    Student(const Student& other) : Zmogus(other.vardas, other.pavarde), nd(other.nd), egz(other.egz), galutinisVid(other.galutinisVid), galutinisMed(other.galutinisMed) {}

    Student& operator=(const Student& other) {
        if (this == &other) return *this;
        vardas = other.vardas;
        pavarde = other.pavarde;
        nd = other.nd;
        egz = other.egz;
        galutinisVid = other.galutinisVid;
        galutinisMed = other.galutinisMed;
        return *this;
    }

    void setNd(const list<int>& n) { nd = n; }
    void setEgz(int e) { egz = e; }

    list<int> getNd() const { return nd; }
    int getEgz() const { return egz; }
    double getGalutinisVid() const { return galutinisVid; }
    double getGalutinisMed() const { return galutinisMed; }

    void skaiciuotiGalutiniVid() {
        if (nd.empty()) {
            galutinisVid = 0;
            return;
        }
        double ndVidurkis = accumulate(nd.begin(), nd.end(), 0.0) / nd.size();
        galutinisVid = 0.4 * ndVidurkis + 0.6 * egz;
    }

    void skaiciuotiGalutiniMed() {
        if (nd.empty()) {
            galutinisMed = 0;
            return;
        }
        list<int> sortedNd = nd;
        sortedNd.sort();
        auto middle = next(sortedNd.begin(), sortedNd.size() / 2);
        if (sortedNd.size() % 2 == 0) {
            galutinisMed = (*prev(middle) + *middle) / 2.0;
        } else {
            galutinisMed = *middle;
        }
        galutinisMed = 0.4 * galutinisMed + 0.6 * egz;
    }

    void spausdintiInfo() const override {
        cout << setw(15) << left << vardas
                  << setw(15) << left << pavarde
                  << setw(20) << fixed << setprecision(2) << galutinisVid
                  << setw(20) << fixed << setprecision(2) << galutinisMed << endl;
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
            std::cout << "Kiek namu darbu pazymiu sugeneruoti? ";
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

    friend ostream& operator<<(ostream& out, const Student& student) {
        out << setw(15) << left << student.vardas
            << setw(15) << left << student.pavarde
            << setw(20) << fixed << setprecision(2) << student.galutinisVid
            << setw(20) << fixed << setprecision(2) << student.galutinisMed;
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
