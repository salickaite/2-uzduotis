#pragma once
#include "Studentas.h"

#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <vector>
#include <fstream>
#include <sstream> 
#include <random>
#include <numeric>
#include <list>

using std::string;
using std::vector;
using std::list;

/// Struktūra 'studentas'
struct studentas
{
    string vardas, pavarde;
    vector<float> nd;
    int egz;
    float gal_vid;
    float gal_med;
    char skaiciavimas;
};

extern vector<studentas> grupe_vec;
extern vector<studentas> vargsiukai_v;
extern vector<studentas> kietiakai_v;

extern vector<Studentas> grupe_vec_;
extern vector <Studentas> vargsiukai_v_;

extern list<studentas> grupe_lst;
extern list<studentas> vargsiukai_l;
extern list<studentas> kietiakai_l;

void pild(studentas& kint);
void printas(studentas& kin);

/// medianos skaiciavimo funkcija
float mediana(vector<float> vec);
bool compare_final(studentas& a, studentas& b);
void print_student(studentas& stud);

/// tikrinimo funkcija
///
/// patikrina ar teisinga ivestis
void tikrinimas(int& a);

/// failo generavimo funkcija
void create_file(string name, float sk);

bool func(studentas st);
bool pred(studentas st);


/// testavimo funkcija
void testas(string name);

/// uzpildymo funkcija
void uzpildymas();

//VEKTORIAI
void nuskaitymas_v(string read);
void padalijimas1(vector<studentas>& vec);
void padalijimas2(vector<studentas>& vec);
void padalijimas3(vector<studentas>& vec);
void isvedimas(vector<studentas>& vec, string pav);


//LISTAI
void nuskaitymas_l(string read);
void padalijimas1(list<studentas>& lst);
void padalijimas2(list<studentas>& lst);
void padalijimas3(list<studentas>& lst);
void isvedimas(list<studentas>& lst, string pav);
