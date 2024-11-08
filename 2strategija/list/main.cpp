#include <iostream>
#include "functions.h"
#include <list>
#include <iterator> // Reikia iteratoriams

using namespace std;

int main() {
    char mainChoice;

    while (true) {
        cout << "Ar norite sugeneruoti studentu duomenu failus? 1 - Taip, 0 - Ne, 2 - Naudoti jau sugeneruotus failus: ";
        cin >> mainChoice;

        if (mainChoice == '1' || mainChoice == '0' || mainChoice == '2') {
            break;
        } else {
            cerr << "Neteisingas pasirinkimas. Prasome ivesti 1, 0 arba 2.\n";
        }
    }

    if (mainChoice == '1') {
        // Klausimas apie failų generavimą
        cout << "Koki faila norite sugeneruoti?\n";
        cout << "1 - studentai_1000.txt\n";
        cout << "2 - studentai_10000.txt\n";
        cout << "3 - studentai_100000.txt\n";
        cout << "4 - studentai_1000000.txt\n";
        cout << "5 - studentai_10000000.txt\n";
        cout << "0 - sugeneruoti visus failus\n";
        char fileChoice;
        cin >> fileChoice;

        list<int> studentCounts = {1000, 10000, 100000, 1000000, 10000000};

        if (fileChoice >= '1' && fileChoice <= '5') {
            int index = fileChoice - '1';

            // Naudokite iteratorių, kad pasiektumėte n-tąjį elementą iš sąrašo
            auto it = studentCounts.begin();
            advance(it, index); // Pereiname prie reikiamo elemento

            string failoPavadinimas = "studentai_" + to_string(*it) + ".txt";
            laikuMatavimai(*it, failoPavadinimas);

        } else if (fileChoice == '0') {
            list<int> studentCounts = {1000, 10000, 100000, 1000000, 10000000};
            for (int count : studentCounts) {
                string failoPavadinimas = "studentai_" + to_string(count) + ".txt";
                laikuMatavimai(count, failoPavadinimas);
            }
        } else {
            cerr << "Neteisingas pasirinkimas!" << endl;
        }
    } else if (mainChoice == '2') {
        string failoPavadinimas = pasirinktiFaila();
        if (!failoPavadinimas.empty()) {
            char sortChoice;
            cout << "Pagal ka norite rusiuoti? 1 - pagal varda, 2 - pagal pavarde, 3 - pagal galutini pazymi: ";
            cin >> sortChoice;

            laikuMatavimaiBeGeneravimo(failoPavadinimas, sortChoice);
        }
    } else if (mainChoice == '0') {
        list<Student> studentai;
        char pasirinkimas;

        try {
            cout << "Ar norite ivesti duomenis rankiniu budu, ar nuskaityti is failo? 0 - rankiniu budu, 1 - is failo: ";
            cin >> pasirinkimas;

            if (pasirinkimas == '1') {
                string failoPavadinimas = pasirinktiFaila();
                if (!skaitytiDuomenisIsFailo(studentai, failoPavadinimas)) {
                    cerr << "Nepavyko nuskaityti duomenu is failo." << endl;
                    return 1;
                }
            } else if (pasirinkimas == '0') {
                skaitytiDuomenisIsVartotojo(studentai);
            } else {
                cerr << "Atsiprasome, tokio pasirinkimo nera." << endl;
                return 1;
            }

            list<Student> vargsiukai;
            rusiuotiStudentus(studentai, vargsiukai);

            // Dabar „studentai“ sąraše liko tik „kietiakai“, o „vargsiukai“ yra atskirame sąraše
            char calcChoice;
            cout << "Ka norite apskaiciuoti? 1 - vidurkis, 2 - mediana, 0 - abu \n";
            cin >> calcChoice;

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
                    cerr << "Neteisingas pasirinkimas!" << endl;
            }

        } catch (const exception& e) {
            cerr << "Ivyko klaida: " << e.what() << endl;
        }
    }

    return 0;
}
