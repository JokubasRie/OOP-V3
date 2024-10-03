#include "student.h"
#include "functions.h"
#include "Mylib.h"
#include <exception>
#include <string>
#include <iostream>

using namespace std;

int main() {
    vector<Student> studentai;

    cout << "Atsakykite i pateiktus klausimus apie studentu duomenis: " << endl;
    skaitytiDuomenisIsVartotojo(studentai);

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
