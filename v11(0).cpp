#include "funkcijos.h"
#include <cstdio>
#include "laikmatis.h"
#include "Studentas.h";


using std::cout;
using std::cin;
using std::endl;
using std::setw;
using std::left;



int main()
{
    char ats;
    cout << "Jei norite, kad butu atliktas STRUKTUROS ir KLASES spartos analize spauskite 'T' (taip), jeigu ne - spauskite 'N': ";
    cin >> ats;
    if (ats == 't' || ats == 'T') 
    {
        testas("stud1000000.txt"); 
    }
    else 
    {
        uzpildymas(); 
    }
    system("pause");
}
