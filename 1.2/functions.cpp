#include "functions.h"
#include "Mylib.h"
#include "student.h"

int atsitiktiniaiBalai(int min, int max) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(min, max);
    return distrib(gen);
}

void generuotiAtsitiktiniusBalus(Student& student, int kiekNd) {
    std::list<int> nd;
    for (int i = 0; i < kiekNd; ++i) {
        nd.push_back(atsitiktiniaiBalai());
    }
    student.setNd(nd);
    student.setEgz(atsitiktiniaiBalai());
}

bool skaitytiDuomenisIsFailo(std::list<Student>& studentai, const std::string& failoPavadinimas) {
    std::ifstream inputFile(failoPavadinimas);
    if (!inputFile.is_open()) {
        std::cerr << "Nepavyko atidaryti failo: " << failoPavadinimas << std::endl;
        return false;
    }

    std::string headerLine;
    std::getline(inputFile, headerLine);

    std::string eilute;
    int lineNumber = 1;
    while (std::getline(inputFile, eilute)) {
        ++lineNumber;
        std::istringstream iss(eilute);
        std::string vardas, pavarde;
        if (!(iss >> vardas >> pavarde)) {
            std::cerr << "Klaida eilutėje " << lineNumber << ": Nepavyko nuskaityti vardo ir pavardės." << std::endl;
            continue;
        }

        Student student;
        student.setVardas(vardas);
        student.setPavarde(pavarde);

        std::list<int> nd;
        int temp;
        bool valid = true;

        while (iss >> temp) {
            if (temp >= 0 && temp <= 10) {
                nd.push_back(temp);
            } else {
                std::cerr << "Klaida eilutėje " << lineNumber << ": Neteisingas skaičius ar formatas." << std::endl;
                valid = false;
                break;
            }
        }

        if (!valid || nd.empty()) {
            continue;
        }

        student.setNd(nd);
        student.setEgz(nd.back());
        nd.pop_back();

        student.skaiciuotiGalutiniVid();
        student.skaiciuotiGalutiniMed();

        studentai.push_back(student);
    }

    inputFile.close();
    return true;
}

void skaitytiDuomenisIsVartotojo(std::list<Student>& studentai) {
    int studentuKiekis;
    std::cout << "Keliu studentu duomenis norite ivesti? ";
    std::cin >> studentuKiekis;

    for (int i = 0; i < studentuKiekis; ++i) {
        Student student;
        std::string vardas, pavarde;

        std::cout << "Iveskite " << i + 1 << "-ojo studento varda: ";
        std::cin >> vardas;
        student.setVardas(vardas);

        std::cout << "Iveskite " << i + 1 << "-ojo studento pavarde: ";
        std::cin >> pavarde;
        student.setPavarde(pavarde);

        char pasirinkimas;
        std::cout << "Ar norite ivesti namu darbu ir egzamino pazymius patys ar juos sugeneruoti automatiskai? 0 - patys, 1 - sugeneruoti ";
        std::cin >> pasirinkimas;

        if (pasirinkimas == '1') {
            int kiekNd;
            std::cout << "Kiek namu darbu pazymiu sugeneruoti? ";
            std::cin >> kiekNd;
            generuotiAtsitiktiniusBalus(student, kiekNd);
        } else {
            std::list<int> nd;
            int ndBalas;

            std::cout << "Iveskite namu darbu pazymius (iveskite -1, jei norite baigti):\n";
            while (std::cin >> ndBalas && ndBalas != -1) {
                nd.push_back(ndBalas);
            }

            student.setNd(nd);

            int egz;
            std::cout << "Iveskite egzamino rezultata: ";
            std::cin >> egz;
            student.setEgz(egz);
        }

        student.skaiciuotiGalutiniVid();
        student.skaiciuotiGalutiniMed();
        studentai.push_back(student);
    }
}




string pasirinktiFaila() {
    int failoPasirinkimas;
    cout << "Pasirinkite faila, kuri norite nuskaityti:\n";
    cout << "1 - studentai10000.txt\n" << "2 - studentai100000.txt\n" << "3 - studentai1000000.txt\n" << "4 - studentai10000000.txt\n";
    cout << "Iveskite pasirinkima (1-4): ";
    cin >> failoPasirinkimas;

    switch (failoPasirinkimas) {
        case 1:
            return "studentai10000.txt";
        case 2:
            return "studentai100000.txt";
        case 3:
            return "studentai1000000.txt";
        case 4:
            return "studentai10000000.txt";
        default:
            cerr << "Neteisingas pasirinkimas. Naudojamas studentai10000.txt\n";
            return "studentai10000.txt";
    }
}


void spausdintiStudentusVidurki(const std::list<Student>& studentai) {
    std::cout << std::setw(15) << std::left << "Vardas"
              << std::setw(15) << std::left << "Pavarde"
              << std::setw(20) << std::left << "Galutinis (Vid.)" << std::endl;
    std::cout << "-------------------------------------------" << std::endl;

    for (const auto& student : studentai) {
        std::cout << std::setw(15) << std::left << student.getVardas()
                  << std::setw(15) << std::left << student.getPavarde()
                  << std::setw(20) << std::left << std::fixed
                  << std::setprecision(2) << student.getGalutinisVid() << std::endl;
    }
}


void spausdintiStudentusMediana(const std::list<Student>& studentai) {
    std::cout << std::setw(15) << std::left << "Vardas"
              << std::setw(15) << std::left << "Pavarde"
              << std::setw(20) << std::left << "Galutinis (Med.)" << std::endl;
    std::cout << "-------------------------------------------" << std::endl;

    for (const auto& student : studentai) {
        std::cout << std::setw(15) << std::left << student.getVardas()
                  << std::setw(15) << std::left << student.getPavarde()
                  << std::setw(20) << std::left << std::fixed
                  << std::setprecision(2) << student.getGalutinisMed() << std::endl;
    }
}


void spausdintiStudentus(const std::list<Student>& studentai) {
    if (studentai.empty()) {
        std::cout << "\n";
        return;
    }

    // Spausdiname antraštę tik vieną kartą
    std::cout << std::setw(15) << std::left << "Vardas"
              << std::setw(15) << std::left << "Pavarde"
              << std::setw(20) << std::left << "Galutinis (Vid.)"
              << std::setw(20) << std::left << "Galutinis (Med.)"
              << std::setw(25) << std::left << "Adresas atmintyje"
              << std::endl;
    std::cout << std::string(95, '-') << std::endl;

    // Naudojame operatorių << spausdinti studentų duomenims
    for (const auto& student : studentai) {
        std::cout << student << std::setw(25) << std::left << &student << std::endl;
    }
}





bool compareByName(const Student& a, const Student& b) {
    return a.getVardas() < b.getVardas();
}

bool compareBySurname(const Student& a, const Student& b) {
    return a.getPavarde() < b.getPavarde();
}

bool compareByGrade(const Student& a, const Student& b) {
    return a.getGalutinisVid() > b.getGalutinisVid();
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

void rusiuotiStudentus(std::list<Student>& studentai, std::list<Student>& vargsiukai) {
    auto it = std::remove_if(studentai.begin(), studentai.end(), [&](const Student& student) {
        if (student.getGalutinisVid() < 5.0) {
            vargsiukai.push_back(student);
            return true;
        }
        return false;
    });
    studentai.erase(it, studentai.end());
}



void spausdintiStudentusIFaila(const std::list<Student>& studentai, const std::string& failoPavadinimas) {
    std::ofstream failas(failoPavadinimas);

    if (!failas.is_open()) {
        std::cerr << "Nepavyko atidaryti failo: " << failoPavadinimas << std::endl;
        return;
    }

    failas << std::setw(15) << std::left << "Vardas"
           << std::setw(15) << std::left << "Pavarde"
           << std::setw(15) << std::left << "Galutinis (Vid.)\n";

    for (const auto& studentas : studentai) {
        failas << std::setw(15) << std::left << studentas.getVardas()
               << std::setw(15) << std::left << studentas.getPavarde()
               << std::setw(15) << std::left << std::fixed << std::setprecision(2) << studentas.getGalutinisVid() << "\n";
    }

    failas.close();
}


void rusiuotiStudentusIrIssaugotiIFailus(list<Student>& studentai) {
    studentai.sort(compareByName);
    list<Student> vargsiukai;

    rusiuotiStudentus(studentai, vargsiukai);

    spausdintiStudentusIFaila(vargsiukai, "vargsiukai.txt");
    spausdintiStudentusIFaila(studentai, "kietiakiai.txt");
    cout << "Duomenys sekmingai surusiuoti ir isspausdinti i failus.\n";
}

void laikuMatavimaiBeGeneravimo(const std::string& failoPavadinimas, char sortChoice) {
    ChronoTimer timer;

    std::list<Student> studentai;
    if (!skaitytiDuomenisIsFailo(studentai, failoPavadinimas)) {
        std::cerr << "Nepavyko nuskaityti duomenu is failo." << std::endl;
        return;
    }
    std::cout << "Failo nuskaitymo laikas: " << timer.getElapsedTime() << " s\n";

    timer.reset();
    if (sortChoice == '1') {
        studentai.sort(compareByName);
        std::cout << "Rusiavimo pagal varda laikas: " << timer.getElapsedTime() << " s\n";
    } else if (sortChoice == '2') {
        studentai.sort(compareBySurname);
        std::cout << "Rusiavimo pagal pavarde laikas: " << timer.getElapsedTime() << " s\n";
    } else if (sortChoice == '3') {
        studentai.sort(compareByGrade);
        std::cout << "Rusiavimo pagal galutini pazymi laikas: " << timer.getElapsedTime() << " s\n";
    } else {
        std::cerr << "Neteisingas pasirinkimas!" << std::endl;
        return;
    }

    timer.reset();
    std::list<Student> vargsiukai;
    rusiuotiStudentus(studentai, vargsiukai);
    std::cout << "Dalijimo i kietiakus ir vargsiukus laikas: " << timer.getElapsedTime() << " s\n";

    timer.reset();
    spausdintiStudentusIFaila(vargsiukai, "vargsiukai.txt");
    std::cout << "Vargsiuku isvedimo i faila laikas: " << timer.getElapsedTime() << " s\n";

    timer.reset();
    spausdintiStudentusIFaila(studentai, "kietiakiai.txt");
    std::cout << "Kietiaku isvedimo i faila laikas: " << timer.getElapsedTime() << " s\n";
}


void laikuMatavimai(int studentuSkaicius, const string& failoPavadinimas) {
    char sortChoice;
    cout << "Pagal ka norite rusiuoti? 1 - pagal varda, 2 - pagal pavarde, 3 - pagal galutini pazymi: ";
    cin >> sortChoice;

    ChronoTimer timer;
    generuotiStudentuFaila(studentuSkaicius, failoPavadinimas);
    cout << "Sugeneruotas failas: " << failoPavadinimas << " su " << studentuSkaicius << " irasu.\n";
    cout << "Failo generavimo laikas: " << timer.getElapsedTime() << " s\n";

    timer.reset();
    list<Student> studentai;
    skaitytiDuomenisIsFailo(studentai, failoPavadinimas);
    cout << "Failo nuskaitymo laikas: " << timer.getElapsedTime() << " s\n";

    timer.reset();
    if (sortChoice == '1') {
        studentai.sort(compareByName);
        cout << "Rusiavimo pagal varda laikas: " << timer.getElapsedTime() << " s\n";
    } else if (sortChoice == '2') {
        studentai.sort(compareBySurname);
        cout << "Rusiavimo pagal pavarde laikas: " << timer.getElapsedTime() << " s\n";
    } else if (sortChoice == '3') {
        studentai.sort(compareByGrade);
        cout << "Rusiavimo pagal galutini pazymi laikas: " << timer.getElapsedTime() << " s\n";
    } else {
        cerr << "Neteisingas pasirinkimas!" << endl;
        return;
    }

    timer.reset();
    list<Student> vargsiukai;
    rusiuotiStudentus(studentai, vargsiukai);
    cout << "Dalijimo i kietiakus ir vargsiukus laikas: " << timer.getElapsedTime() << " s\n";

    timer.reset();
    spausdintiStudentusIFaila(vargsiukai, "vargsiukai.txt");
    cout << "Vargsiuku isvedimo i faila laikas: " << timer.getElapsedTime() << " s\n";

    timer.reset();
    spausdintiStudentusIFaila(studentai, "kietiakiai.txt");
    cout << "Kietiaku isvedimo i faila laikas: " << timer.getElapsedTime() << " s\n";
}

void apdorotiVisusFailus() {
    list<int> studentCounts = {1000, 10000, 100000, 1000000, 10000000};
    auto it = studentCounts.begin();
    for (size_t i = 0; i < studentCounts.size(); ++i) {
        advance(it, i);
        string failoPavadinimas = "studentai_" + to_string(*it) + ".txt";
        laikuMatavimai(*it, failoPavadinimas);
        cout << endl;
    }
}
