#include "testavimas.h"
#include "rand_int.h"
#include<sstream>

using std::cout;
using std::left;
using std::setw;
using std::endl;
using std::fixed;
using std::setprecision;
using std::cin;
using std::string;
using std::to_string;
using std::ofstream;
using std::ifstream;
using std::vector;
using std::list;

void file(int kiekis)
{
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> dist(1., 10.);
    double gal_rand;

    string pav = "studentai" + to_string(kiekis) + ".txt"; //pav - failo pavadinimas
    ofstream outfile(pav);
    outfile << left << setw(20) << "Vardas" << left << setw(20) << "Pavarde" << left << setw(20) << "Galutinis" << endl;
    for (int i = 1; i <= kiekis; i++)
    {
        gal_rand = dist(mt);
        outfile << setw(20) << left << "Vardas" + to_string(i) << setw(20) << left << "Pavarde" + to_string(i)
            << setw(20) << fixed << setprecision(2) << left << gal_rand << endl;
    }
}

void write(vector<Studentas>& v, string pav)
{
    ofstream outfile(pav);
    outfile << left << setw(20) << "Vardas" << left << setw(20) << "Pavarde" << left << setw(20) << "Galutinis" << endl;
    for (Studentas s : v)
    {
        outfile << left << setw(20) << s.getVardas() << left << setw(20) << s.getPavarde() << left << setw(20) << s.getGalutinis() << endl;
    }
}

void test(int kiek)
{
    int strat;
    cout << endl;
    cout << "VECTOR strukturos rezultatai: " << endl;
    auto start1 = std::chrono::high_resolution_clock::now();
    Studentas temp;
    vector<Studentas> studentai;
    string vard, pav;
    double gal;
    studentai.resize(kiek);
    string eil;
    ifstream openf("studentai" + to_string(kiek) + ".txt");
    try
    {
        if (openf.fail()) throw std::runtime_error("Nepavyko atidaryti failo");
    }
    catch (std::runtime_error& e)
    {
        cout << e.what();
        exit(1);
    }
    std::stringstream buff;
    buff << openf.rdbuf();
    openf.close();
    getline(buff, eil);
    for (auto& i : studentai)
    {
        i.readStudent(buff);
    }
    //openf.close();
    auto end1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff1 = end1 - start1;
    cout << "Failo su " << kiek << " studentu nuskaitymas uztruko " << diff1.count() << " s" << endl;

    vector<Studentas> vargsiukai;
    //vargsiukai.reserve(0.6 * kiekis);
    std::sort(studentai.begin(), studentai.end(), compare_mark);
    auto start2 = std::chrono::high_resolution_clock::now();
    vector<Studentas>::iterator it = std::find_if(studentai.begin(), studentai.end(), passed);
    vargsiukai = vector<Studentas>(studentai.begin(), it);
    vargsiukai.shrink_to_fit();
    vector<Studentas>::iterator it1 = studentai.begin();
    studentai.erase(studentai.begin(), it);
    auto end2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff2 = end2 - start2;
    cout << kiek << " studentu suskirstymas i uztruko " << diff2.count() << " s" << endl;

    string vargsiukai_pav = "vargsiukai" + to_string(kiek) + ".txt";
    write(vargsiukai, vargsiukai_pav);
    vargsiukai.clear();

    string kietiakai_pav = "kietiakai" + to_string(kiek) + ".txt";
    write(studentai, kietiakai_pav);
    studentai.clear();
}
