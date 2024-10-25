#include "functions.h"
#include "Mylib.h"

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

bool skaitytiDuomenisIsFailo(vector<Student>& studentai, const string& failoPavadinimas) {
    ifstream inputFile(failoPavadinimas);
    if (!inputFile.is_open()) {
        cerr << "Nepavyko atidaryti failo: " << failoPavadinimas << endl;
        return false;
    }

    string headerLine;
    getline(inputFile, headerLine);

    string eilute;
    int lineNumber = 1;
    while (getline(inputFile, eilute)) {
        lineNumber++;
        istringstream iss(eilute);
        Student student;

        if (!(iss >> student.vardas >> student.pavarde)) {
            cerr << "Klaida eilutėje " << lineNumber << ": Nepavyko nuskaityti vardo ir pavardės." << endl;
            continue;
        }

        int temp;
        bool valid = true;

        while (iss >> temp) {
            if (temp >= 0 && temp <= 10) {
                student.nd.push_back(temp);
            } else {
                cerr << "Klaida eilutėje " << lineNumber << ": Neteisingas skaičius ar formatas." << endl;
                valid = false;
                break;
            }
        }

        if (!valid || student.nd.empty()) {
            continue;
        }

        student.egz = student.nd.back();
        student.nd.pop_back();

        student.skaiciuotiGalutiniVid();
        student.skaiciuotiGalutiniMed();

        studentai.push_back(student);
    }

    inputFile.close();
    return true;
}

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

string pasirinktiFaila() {
    int failoPasirinkimas;
    cout << "Pasirinkite faila, kuri norite nuskaityti:\n";
    cout << "1 - kursiokai.txt\n" << "2 - studentai10000.txt\n" << "3 - studentai100000.txt\n" << "4 - studentai1000000.txt\n";
    cout << "Iveskite pasirinkima (1-4): ";
    cin >> failoPasirinkimas;

    switch (failoPasirinkimas) {
        case 1:
            return "kursiokai.txt";
        case 2:
            return "studentai10000.txt";
        case 3:
            return "studentai100000.txt";
        case 4:
            return "studentai1000000.txt";
        default:
            cerr << "Neteisingas pasirinkimas. Naudojamas kursiokai.txt\n";
            return "kursiokai.txt";
    }
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

bool compareByName(const Student& a, const Student& b) {
    return a.vardas < b.vardas;
}

bool compareBySurname(const Student& a, const Student& b) {
    return a.pavarde < b.pavarde;
}

bool compareByGrade(const Student& a, const Student& b) {
    return a.galutinisVid > b.galutinisVid;
}

void generuotiStudentuFaila(int studentuSkaicius, const string& failoPavadinimas) {
    ofstream failas(failoPavadinimas);

    if (!failas.is_open()) {
        cerr << "Nepavyko atidaryti failo." << endl;
        return;
    }

    failas << setw(15) << left << "Vardas" << setw(15) << left << "Pavarde" << setw(5) << left << "ND1" << setw(5) << left << "ND2"
           << setw(5) << left << "ND3" << setw(5) << left << "ND4" << setw(5) << left << "ND5" << setw(5) << left << "Egzaminas\n";

    for (int i = 1; i <= studentuSkaicius; ++i) {
        string vardas = "Vardas" + to_string(i);
        string pavarde = "Pavarde" + to_string(i);

        failas << setw(15) << left << vardas << " " << setw(15) << left << pavarde;

        for (int j = 0; j < 5; ++j) {
            failas << setw(5) << left << atsitiktiniaiBalai(1, 10);
        }

        failas << setw(5) << left << atsitiktiniaiBalai(1, 10) << "\n";
    }

    failas.close();
}

void rusiuotiStudentus(const vector<Student>& studentai, vector<Student>& vargsiukai, vector<Student>& kietiakiai) {
    for (const auto& studentas : studentai) {
        if (studentas.galutinisVid < 5.0) {
            vargsiukai.push_back(studentas);
        } else {
            kietiakiai.push_back(studentas);
        }
    }
}

void spausdintiStudentusIFaila(const vector<Student>& studentai, const string& failoPavadinimas) {
    ofstream failas(failoPavadinimas);

    if (!failas.is_open()) {
        cerr << "Nepavyko atidaryti failo: " << failoPavadinimas << endl;
        return;
    }

    failas << setw(15) << left << "Vardas" << setw(15) << left << "Pavarde" << setw(15) << left << "Galutinis (Vid.)\n";
    for (const auto& studentas : studentai) {
        failas << setw(15) << left << studentas.vardas << " " << setw(15) << left << studentas.pavarde << " " << setw(15)
               << left << fixed << setprecision(2) << studentas.galutinisVid << "\n";
    }

    failas.close();
}

void rusiuotiStudentusIrIssaugotiIFailus(vector<Student>& studentai) {
    vector<Student> vargsiukai;
    vector<Student> kietiakiai;

    rusiuotiStudentus(studentai, vargsiukai, kietiakiai);

    spausdintiStudentusIFaila(vargsiukai, "vargsiukai.txt");

    spausdintiStudentusIFaila(kietiakiai, "kietiakiai.txt");
    cout << "Duomenys sekmingai surusiuoti ir isspausdinti i failus.\n";
}

void laikuMatavimaiBeGeneravimo(const string& failoPavadinimas, char sortChoice) {
    auto readStart = high_resolution_clock::now();

    vector<Student> studentai;
    if (!skaitytiDuomenisIsFailo(studentai, failoPavadinimas)) {
        cerr << "Nepavyko nuskaityti duomenu is failo." << endl;
        return;
    }

    auto readEnd = high_resolution_clock::now();
    duration<double> readTime = readEnd - readStart;
    cout << "Failo nuskaitymo laikas: " << readTime.count() << " s\n";

    auto sortStart = high_resolution_clock::now();
    if (sortChoice == '1') {
        sort(studentai.begin(), studentai.end(), compareByName);
    } else if (sortChoice == '2') {
        sort(studentai.begin(), studentai.end(), compareBySurname);
    } else if (sortChoice == '3') {
        sort(studentai.begin(), studentai.end(), compareByGrade);
    } else {
        cerr << "Neteisingas pasirinkimas!" << endl;
    }
    auto sortEnd = high_resolution_clock::now();
    duration<double> sortTime = sortEnd - sortStart;
    cout << "Rusiavimo laikas: " << sortTime.count() << " s\n";

    auto divideStart = high_resolution_clock::now();
    vector<Student> vargsiukai, kietiakiai;
    rusiuotiStudentus(studentai, vargsiukai, kietiakiai);
    auto divideEnd = high_resolution_clock::now();
    duration<double> divideTime = divideEnd - divideStart;
    cout << "Dalijimo i kietiakus ir vargsiukus laikas: " << divideTime.count() << " s\n";

    auto saveVargsiukaiStart = high_resolution_clock::now();
    spausdintiStudentusIFaila(vargsiukai, "vargsiukai.txt");
    auto saveVargsiukaiEnd = high_resolution_clock::now();
    duration<double> saveVargsiukaiTime = saveVargsiukaiEnd - saveVargsiukaiStart;
    cout << "Vargsiuku isvedimo i faila laikas: " << saveVargsiukaiTime.count() << " s\n";

    auto saveKietiakiaiStart = high_resolution_clock::now();
    spausdintiStudentusIFaila(kietiakiai, "kietiakiai.txt");
    auto saveKietiakiaiEnd = high_resolution_clock::now();
    duration<double> saveKietiakiaiTime = saveKietiakiaiEnd - saveKietiakiaiStart;
    cout << "Kietiaku isvedimo i faila laikas: " << saveKietiakiaiTime.count() << " s\n";
}



void laikuMatavimai(int studentuSkaicius, const string& failoPavadinimas) {
    auto start = high_resolution_clock::now();

    generuotiStudentuFaila(studentuSkaicius, failoPavadinimas);

    auto end = high_resolution_clock::now();
    duration<double> generationTime = end - start;
    cout << "Sugeneruotas failas: " << failoPavadinimas << " su " << studentuSkaicius << " irasu.\n";
    cout << "Failo generavimo laikas: " << generationTime.count() << " s\n";

    auto readStart = high_resolution_clock::now();
    vector<Student> studentai;
    skaitytiDuomenisIsFailo(studentai, failoPavadinimas);

    auto readEnd = high_resolution_clock::now();
    duration<double> readTime = readEnd - readStart;
    cout << "Failo nuskaitymo laikas: " << readTime.count() << " s\n";

    auto sortStart = high_resolution_clock::now();
    sort(studentai.begin(), studentai.end(), compareByName);
    auto sortEnd = high_resolution_clock::now();
    duration<double> sortTime = sortEnd - sortStart;
    cout << "Rusiavimo pagal varda laikas: " << sortTime.count() << " s\n";

    auto divideStart = high_resolution_clock::now();
    vector<Student> vargsiukai, kietiakiai;
    rusiuotiStudentus(studentai, vargsiukai, kietiakiai);
    auto divideEnd = high_resolution_clock::now();
    duration<double> divideTime = divideEnd - divideStart;
    cout << "Dalijimo i kietiakus ir vargsiukus laikas: " << divideTime.count() << " s\n";

    auto saveVargsiukaiStart = high_resolution_clock::now();
    spausdintiStudentusIFaila(vargsiukai, "vargsiukai.txt");
    auto saveVargsiukaiEnd = high_resolution_clock::now();
    duration<double> saveVargsiukaiTime = saveVargsiukaiEnd - saveVargsiukaiStart;
    cout << "Vargsiuku isvedimo i faila laikas: " << saveVargsiukaiTime.count() << " s\n";

    auto saveKietiakiaiStart = high_resolution_clock::now();
    spausdintiStudentusIFaila(kietiakiai, "kietiakiai.txt");
    auto saveKietiakiaiEnd = high_resolution_clock::now();
    duration<double> saveKietiakiaiTime = saveKietiakiaiEnd - saveKietiakiaiStart;
    cout << "Kietiaku isvedimo i faila laikas: " << saveKietiakiaiTime.count() << " s\n";
}

void apdorotiVisusFailus() {
    vector<int> studentCounts = {1000, 10000, 100000, 1000000, 10000000};
    for (size_t i = 0; i < studentCounts.size(); ++i) {
        string failoPavadinimas = "studentai_" + to_string(studentCounts[i]) + ".txt";
        laikuMatavimai(studentCounts[i], failoPavadinimas);
        cout << endl;
    }
}
