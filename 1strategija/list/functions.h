#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#include <list>
#include <string>
#include "student.h"

bool skaitytiDuomenisIsFailo(std::list<Student>& students, const std::string& failoPavadinimas);
void skaitytiDuomenisIsVartotojo(std::list<Student>& students);
void spausdintiStudentus(const std::list<Student>& students);
void spausdintiStudentusVidurki(const std::list<Student>& students);
void spausdintiStudentusMediana(const std::list<Student>& students);

bool compareByName(const Student& a, const Student& b);
int atsitiktiniaiBalai(int min = 0, int max = 10);
std::string pasirinktiFaila();
void generuotiStudentuFaila(int studentuSkaicius, const std::string& failoPavadinimas);
void rusiuotiStudentus(const std::list<Student>& studentai, std::list<Student>& vargsiukai, std::list<Student>& kietiakiai);
void spausdintiStudentusIFaila(const std::list<Student>& studentai, const std::string& failoPavadinimas);
void rusiuotiStudentusIrIssaugotiIFailus(std::list<Student>& studentai);
void laikuMatavimai(int studentuSkaicius, const std::string& failoPavadinimas);
void apdorotiVisusFailus();
void laikuMatavimaiBeGeneravimo(const std::string& failoPavadinimas, char sortChoice);

bool compareBySurname(const Student& a, const Student& b);
bool compareByGrade(const Student& a, const Student& b);

#endif // FUNCTIONS_H_INCLUDED
