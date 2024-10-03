#include "student.h"
#include "functions.h"
#include "Mylib.h"
#include <exception>
#include <string>
#include <iostream>

using namespace std;

int main() {
   vector<Student> studentai;
    char pasirinkimas;

    try {
        cout << "Ar norite ivesti duomenis rankiniu budu, ar nuskaityti is failo? 0 - rankiniu budu, 1 - is failo: ";
        cin >> pasirinkimas;

        if (pasirinkimas == '1') {
            string failoPavadinimas = pasirinktiFaila();
            if (!skaitytiDuomenisIsFailo(studentai, failoPavadinimas)) {
                cerr << "Nepavyko nuskaityti duomenų iš failo." << endl;
                return 1;
            }
        } else if (pasirinkimas == '0') {
            skaitytiDuomenisIsVartotojo(studentai);
        } else {
            cerr << "Atsiprasome, tokio pasirinkimo nera." << endl;
            return 1;
        }

    char calcChoice;
        cout << "Ka norite apskaiciuoti? 1 - vidurkis, 2 - mediana, 0 - abu \n";
        cin >> calcChoice;

        switch (calcChoice) {
            case '1':
                spausdintiStudentusVidurki(studentai);
                break;
            case '2':
                spausdintiStudentusMediana(studentai);
                break;
            case '0':
                spausdintiStudentus(studentai);
                break;
            default:
                cerr << "Neteisingas pasirinkimas!" << endl;
        }

    return 0;
}
