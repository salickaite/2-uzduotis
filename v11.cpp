#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <vector>
#include <random>
#include <chrono>
#include <algorithm>
#include <numeric>
#include <sstream>

#include "studentas.h"
#include "testavimas.h"
#include "rand_int.h"


using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::vector;
using std::accumulate;
using std::ifstream;
using std::getline;
using std::stringstream;



int main()
{
    /*srand(time(NULL));
    float vid, med;
    int kiek;
    string ivestis, gal_ivestis, read_type, generuoti;
    studentas temp_student;
    vector <studentas> grupe;*/

    int kiek;
    string ivestis, gal_ivestis, read_type, generuoti, vardas, pavarde;
    Studentas temp_student;
    vector <Studentas> grupe;
    vector<double> nd;
    double egz, gal;

    //PASIRINKIMAS AR ATLIKTI GREICIO ANALIZE

    cout << "Jei norite atlikti programos veikimo greicio analize spauskite T (taip), jei nenorite spauskite N (ne). ";
    cin >> generuoti;

    while (generuoti != "T" && generuoti != "t" && generuoti != "N" && generuoti != "n")
        try
    {
        if (generuoti != "T" && generuoti != "t" && generuoti != "N" && generuoti != "n") throw std::runtime_error("Neatpazinta ivedimo komanda. ");
    }
    catch (std::runtime_error& e)
    {
        cout << e.what() << endl;
        cin.clear();
        cout << "Pasirinkite T (taip) arba N (ne). ";
        cin >> generuoti;
    }
    if (generuoti == "T" || generuoti == "t")
    {
        cout << "Iveskite studentu skaiciu: ";
        cin >> kiek;
        while (kiek < 0)
            try
        {
            if (kiek < 0) throw std::runtime_error("Studentu skaicius turi buti didesnis arba lygus 1 ");
        }
        catch (std::runtime_error& e)
        {
            cout << e.what() << endl;
            cin.clear();
            cout << "Iveskite studentu skaiciu dar karta: ";
            cin >> kiek;
        }
        test(kiek);
    }


    if (generuoti == "N" || generuoti == "n")
    {
        cout << "Jei norite duomenis nuskaityti is FAILO spauskite F.\nJei norite ivesti ranka, spauskite R. ";
        cin >> read_type;
        do
        {
            try
            {
                if (read_type != "F" && read_type != "f" && read_type != "R" && read_type != "r") throw std::runtime_error("Neatpazinta komanda");
            }
            catch (std::runtime_error& e) {
                cout << e.what() << endl;
                cin.clear();
                cout << "Pasirinkite F arba R ";
                cin >> read_type;
            }
        }
        while (read_type != "F" && read_type != "f" && read_type != "R" && read_type != "r");
        cout << "Jei norite galutini pazymi skaiciuoti pagal namu darbu vidurki, spauskite V. \nJei pagal mediana, spauskite M. ";
        cin >> gal_ivestis;
        do
        {
            try
            {
                if (gal_ivestis != "V" && gal_ivestis != "v" && gal_ivestis != "M" && gal_ivestis != "m") throw std::runtime_error("Neatpazinta komanda");
            }
            catch (std::runtime_error& e) 
            {
                cout << e.what() << endl;
                cin.clear();
                cout << "Pasirinkite V arba M ";
                cin >> gal_ivestis;
            }
        }
        while (gal_ivestis != "V" && gal_ivestis != "v" && gal_ivestis != "M" && gal_ivestis != "m");

        if (read_type == "F" || read_type == "f")
        {
            int rows = 0, cols = 0;
            //float temp_paz;
            string eil, item;
            std::stringstream buff;
            ifstream open_f("kursiokai.txt");
            
            try {
                if (open_f.fail()) throw std::runtime_error("Nepavyko atidaryti failo");
            }
            catch (std::runtime_error& e) 
            {
                cout << e.what() << endl;;
                exit(1);
            }

            buff << open_f.rdbuf();
            open_f.close();

            while (buff)
            {
                if (!buff.eof())
                {
                    getline(open_f, eil);
                    rows++;
                    if (rows == 1)
                    {
                        stringstream ss(eil);
                        while (ss >> item) cols++;
                    }
                    temp_student.readStudent(buff, cols - 3);
                    gal = galutinis(temp_student, gal_ivestis);
                    temp_student.setGalutinis(gal);
                    grupe.push_back(temp_student);

                    
                }
                else break;
            }

            
        }
        if (read_type == "R" || read_type == "r")
        {
            cout << "Jei norite, kad studentu pazymiai butu generuojami AUTOMATISKAI spauskite \"A\".\n Jei norite pazymius suvesti PATYS spauskite \"P\".";
            cin >> ivestis;

            while (ivestis != "A" && ivestis != "a" && ivestis != "P" && ivestis != "p")
            {
                try
                {
                    if (ivestis != "A" && ivestis != "a" && ivestis != "P" && ivestis != "p") throw std::invalid_argument("Netinkamai ivesta komanda. ");
                }
                catch (std::invalid_argument& e)
                {
                    cout << e.what();
                    cout << "Pasirinkite A (automatiskai) arba P (patys). ";
                    cin >> ivestis;
                }
            }
            int studentu_sk, x;
            float laik_paz;
            cout << "Iveskite studentu skaiciu: ";
            cin >> studentu_sk;

            while (studentu_sk < 0)
            {
                try
                {
                    if (studentu_sk < 0) throw std::invalid_argument("Studentu skaicius turi buti didesnis arba lygu 1. ");
                }
                catch (std::invalid_argument& e)
                {
                    cout << e.what() << endl;
                    cin.clear();
                    cout << "Iveskite studentu skaiciu. ";
                    cin >> studentu_sk;
                }
            } while (studentu_sk <= 0);

            for (int i = 0; i < studentu_sk; i++)
            {
                cout << "Iveskite " << i + 1 << " -o studento varda ir pavarde : ";
                cin >> vardas >> pavarde;

                temp_student.setVardas(vardas);
                temp_student.setPavarde(pavarde);

                if (ivestis == "A" || ivestis == "a")
                {
                    cout << "Iveskite " << i + 1 << " -o studento namu darbu kieki : ";
                    cin >> x;
                    while (x <= 0)
                    {
                        try
                        {
                            if (x < 0) throw std::invalid_argument("Namu darbu kiekis negali buti 0. Bandykite dar karta. ");
                        }
                        catch (std::invalid_argument& e)
                        {
                            cout << e.what() << endl;
                            cin.clear();
                            cout << "Iveskite namu darbu kieki. ";
                            cin >> x;
                        }
                    }
                    nd.reserve(x);
                    for (int j = 0; j < x; j++)
                    {
                        nd.push_back(rand_int());
                    }
                    temp_student.setNd(nd);
                    egz = rand_int();
                    temp_student.setEgzaminas(egz);
                    gal = galutinis(temp_student, gal_ivestis);
                    temp_student.setGalutinis(gal);
                    grupe.push_back(temp_student);
                    nd.clear();
                }
                if (ivestis == "P" || ivestis == "p")
                {
                    cout << "Iveskite namu darbu pazymius (kai baigsite iveskite +): ";
                    while (cin >> laik_paz)
                    {
                        while (laik_paz < 1 || laik_paz > 10)
                        {
                            try
                            {
                                if (laik_paz < 1 || laik_paz > 10) throw std::invalid_argument("Namu darbu pazymiai turi buti nuo 1 iki 10 (imtinai). ");
                            }
                            catch (std::invalid_argument& e)
                            {
                                cout << e.what() << endl;
                                cin.clear();
                                cout << "Iveskite namu darbu pazymius dar karta. ";
                                cin >> laik_paz;
                            }

                        }
                        nd.push_back(laik_paz);

                    }
                    if (nd.empty())
                    {
                        cout << "Privaloma ivesti namu darbu pazymius. Bandykite dar karta.";
                        return 1;
                    }
                    cin.clear();
                    cin.ignore(10000, '\n');

                    cout << "Iveskite " << i + 1 << "-o studento egzamino pazymi : ";
                    cin >> egz;

                    while (egz < 1 || egz > 10)
                    {
                        try
                        {
                            if (egz < 1 || egz > 10) throw std::invalid_argument("Egzamino pazymys turi buti nuo 1 iki 10 (imtinai). ");
                        }
                        catch (std::invalid_argument& e)
                        {
                            cout << e.what() << endl;
                            cin.clear();
                            cout << "Iveskite egzamino pazymi. ";
                            cin >> egz;
                        }
                    }
                    temp_student.setEgzaminas(egz);
                    gal = galutinis(temp_student, gal_ivestis);
                    temp_student.setGalutinis(gal);
                    grupe.push_back(temp_student);
                    nd.clear();
                }

            }
        }

        print_student(grupe);
    }
    cin.get();

}