#include <iostream>
#include <list>
#include "functions.h"
#include "student.h"

int main() {
    char mainChoice;

    while (true) {
        std::cout << "Ar norite sugeneruoti studentu duomenu failus? 1 - Taip, 0 - Ne, 2 - Naudoti jau sugeneruotus failus: ";
        std::cin >> mainChoice;

        if (mainChoice == '1' || mainChoice == '0' || mainChoice == '2') {
            break;
        } else {
            std::cerr << "Neteisingas pasirinkimas. Prasome ivesti 1, 0 arba 2.\n";
        }
    }

    if (mainChoice == '1') {
        char fileChoice;
        std::cout << "Koki faila norite sugeneruoti?\n";
        std::cout << "1 - studentai_1000.txt\n";
        std::cout << "2 - studentai_10000.txt\n";
        std::cout << "3 - studentai_100000.txt\n";
        std::cout << "4 - studentai_1000000.txt\n";
        std::cout << "5 - studentai_10000000.txt\n";
        std::cout << "0 - sugeneruoti visus failus\n";
        std::cin >> fileChoice;

        if (fileChoice >= '1' && fileChoice <= '5') {
            int studentCount = std::stoi(std::string(1, fileChoice)) * 1000;
            std::string failoPavadinimas = "studentai_" + std::to_string(studentCount) + ".txt";
            laikuMatavimai(studentCount, failoPavadinimas);
        } else if (fileChoice == '0') {
            apdorotiVisusFailus();
        } else {
            std::cerr << "Neteisingas pasirinkimas!" << std::endl;
        }
    } else if (mainChoice == '2') {
        std::string failoPavadinimas = pasirinktiFaila();
        if (!failoPavadinimas.empty()) {
            char sortChoice;
            std::cout << "Pagal ka norite rusiuoti? 1 - pagal varda, 2 - pagal pavarde, 3 - pagal galutini pazymi: ";
            std::cin >> sortChoice;
            laikuMatavimaiBeGeneravimo(failoPavadinimas, sortChoice);
        }
    } else if (mainChoice == '0') {
        std::list<Student> studentai;
        char pasirinkimas;

        std::cout << "Ar norite ivesti duomenis rankiniu budu, ar nuskaityti is failo? 0 - rankiniu budu, 1 - is failo: ";
        std::cin >> pasirinkimas;

        if (pasirinkimas == '1') {
            std::string failoPavadinimas = pasirinktiFaila();
            if (!skaitytiDuomenisIsFailo(studentai, failoPavadinimas)) {
                std::cerr << "Nepavyko nuskaityti duomenu is failo." << std::endl;
                return 1;
            }
        } else if (pasirinkimas == '0') {
            skaitytiDuomenisIsVartotojo(studentai);
        } else {
            std::cerr << "Atsiprasome, tokio pasirinkimo nera." << std::endl;
            return 1;
        }

        std::list<Student> vargsiukai;
        rusiuotiStudentus(studentai, vargsiukai);

        char calcChoice;
        std::cout << "Ka norite apskaiciuoti? 1 - vidurkis, 2 - mediana, 0 - abu \n";
        std::cin >> calcChoice;

        switch (calcChoice) {
            case '1':
                spausdintiStudentusVidurki(vargsiukai);
                spausdintiStudentusVidurki(studentai);
                break;
            case '2':
                spausdintiStudentusMediana(vargsiukai);
                spausdintiStudentusMediana(studentai);
                break;
            case '0':
                spausdintiStudentus(vargsiukai);
                spausdintiStudentus(studentai);
                break;
            default:
                std::cerr << "Neteisingas pasirinkimas!" << std::endl;
        }
    }

    return 0;
}
