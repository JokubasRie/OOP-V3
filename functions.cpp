#include "functions.h"
#include "Mylib.h"




void skaitytiDuomenisIsVartotojo(vector<Student>& studentai) {
    int studentuKiekis;
    cout << "Keliu studentu duomenis norite ivesti? ";
    cin >> studentuKiekis;

    for (int i = 0; i < studentuKiekis; ++i) {
        Student student;
        string vardas, pavarde;

        cout << "Iveskite " << i + 1 << "-ojo studento varda: ";
        cin >> vardas;
        cout << "Iveskite " << i + 1 << "-ojo studento pavarde: ";
        cin >> pavarde;

        student.vardas = vardas;
        student.pavarde = pavarde;

        char pasirinkimas;
        cout << "Ar norite ivesti namu darbu ir egzamino pazymius patys ar juos sugeneruoti automatiskai? 0 - patys, 1 - sugeneruoti ";
        cin >> pasirinkimas;

        if (pasirinkimas == '1') {
            int kiekNd;
            cout << "Kiek namu darbu pazymiu sugeneruoti? ";
            cin >> kiekNd;
            generuotiAtsitiktiniusBalus(student, kiekNd);
        } else {
            int nd, egzaminas;

            cout << "Iveskite namu darbu pazymius (iveskite -1, jei norite baigti): " << endl;
            while (true) {
                cin >> nd;
                if (nd == -1) break;

                if (cin.fail() || nd < 0 || nd > 10) {
                    cerr << "Ivedamas balas turi buti desimtbaleje sistemoje. Iveskite is naujo: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                } else {
                    student.nd.push_back(nd);
                }
            }

            cout << "Iveskite egzamino rezultata: ";
            while (!(cin >> egzaminas) || egzaminas < 0 || egzaminas > 10) {
                cerr << "Ivedamas balas turi buti desimtbaleje sistemoje. Iveskite is naujo: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            student.egz = egzaminas;
        }

        student.skaiciuotiGalutiniVid();
        student.skaiciuotiGalutiniMed();

        studentai.push_back(student);
    }
}

int atsitiktiniaiBalai(int min, int max) {
    static random_device rd;
    static mt19937 gen(rd());
    uniform_int_distribution<> distrib(min, max);
    return distrib(gen);
}
void generuotiAtsitiktiniusBalus(Student& student, int kiekNd) {
    student.nd.clear();
    for (int i = 0; i < kiekNd; ++i) {
        int atsitiktinisBalas = atsitiktiniaiBalai();
        student.nd.push_back(atsitiktinisBalas);
    }
    student.egz = atsitiktiniaiBalai();
}

void Student::skaiciuotiGalutiniVid() {
    if (nd.size() == 0) {
        galutinisVid = 0;
        return;
    }
    double ndVidurkis = accumulate(nd.begin(), nd.end(), 0.0) / nd.size();
    galutinisVid = 0.4 * ndVidurkis + 0.6 * egz;

}
void Student::skaiciuotiGalutiniMed() {
    if (nd.size() == 0) {
        galutinisMed = 0;
        return;
    }
    vector<int> sorted_nd = nd;
    sort(sorted_nd.begin(), sorted_nd.end());
    if (sorted_nd.size() % 2 == 0)
        galutinisMed = (sorted_nd[sorted_nd.size() / 2 - 1] + sorted_nd[sorted_nd.size() / 2]) / 2.0;
    else
        galutinisMed = sorted_nd[sorted_nd.size() / 2];
    galutinisMed = 0.4 * galutinisMed + 0.6 * egz;
}
void spausdintiStudentusVidurki(const vector<Student>& studentai) {
    cout << setw(15) << left << "Vardas" << setw(15) << left << "Pavarde"
              << setw(20) << left << "Galutinis (Vid.)" << endl;
    cout << "-------------------------------------------" << endl;

    for (const auto& student : studentai) {
        cout << setw(15) << left << student.vardas << setw(15) << left << student.pavarde
                  << setw(20) << left << fixed << setprecision(2) << student.galutinisVid << endl;
    }
}
void spausdintiStudentusMediana(const vector<Student>& studentai) {
    cout << setw(15) << left << "Vardas" << setw(15) << left << "Pavarde"
              << setw(20) << left << "Galutinis (Med.)" << endl;
    cout << "-------------------------------------------" << endl;

    for (const auto& student : studentai) {
        cout << setw(15) << left << student.vardas << setw(15) << left << student.pavarde
                  << setw(20) << left << fixed << setprecision(2) << student.galutinisMed << endl;
    }
}
void spausdintiStudentus(const vector<Student>& studentai) {
    cout << setw(15) << left << "Vardas" << setw(15) << left << "Pavarde"
              << setw(20) << left << "Galutinis (Vid.)" << setw(20) << left << "Galutinis (Med.)" << endl;
    cout << "--------------------------------------------------------------------" << endl;

    for (const auto& student : studentai) {
        cout << setw(15) << left << student.vardas << setw(15) << left << student.pavarde
                  << setw(20) << left << fixed << setprecision(2) << student.galutinisVid
                  << setw(20) << left << fixed << setprecision(2) << student.galutinisMed << endl;
    }
}
