#include "Studentas.h"
#include "funkcijos.h"

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

using std::cout;
using std::cin;
using std::endl;
using std::setw;
using std::left;



int main()
{
    //Zmogus z;

    char ats;
    cout << "Jei norite, kad butu atliktas STRUKTUROS ir KLASES spartos analize spauskite 'T' (taip), jeigu ne - spauskite 'N': ";
    cin >> ats;
    if (ats == 't' || ats == 'T')
    {
        testas("stud100000.txt");
    }
    else
    {
        uzpildymas();
    }

}