#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#include <vector>
#include <string>
#include "student.h"

bool skaitytiDuomenisIsFailo(vector<Student>& students, const string& failoPavadinimas);

void skaitytiDuomenisIsVartotojo(vector<Student>& students);

void spausdintiStudentus(const vector<Student>& students);
void spausdintiStudentusVidurki(const vector<Student>& students);
void spausdintiStudentusMediana(const vector<Student>& students);

bool compareByName(const Student& a, const Student& b);

int atsitiktiniaiBalai(int min = 0, int max = 10);
void generuotiAtsitiktiniusBalus(Student& student, int kiekNd);

string pasirinktiFaila();

#endif // FUNCTIONS_H_INCLUDED
