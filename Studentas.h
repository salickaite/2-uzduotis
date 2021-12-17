#pragma once
#include <iostream>;
#include <string>;
#include <vector>;

using std::string;
using std::vector;
using std::istream;
using std::cout;
using std::cin;
using std::endl;

class Studentas {
private:
	string vardas_;
	string pavarde_;
	int egzaminas_;
	float galutinisVid_;
	vector<float> nd_;

public:
	Studentas() {
		egzaminas_ = 0;
		galutinisVid_ = 0;
	}
	Studentas(string, string, int, float);


	inline string vardas() const { return vardas_; }
	inline string pavarde() const { return pavarde_; }
	inline int egzaminas() const { return egzaminas_; }
	inline vector<float> nd() const { return nd_; }
	inline float galutinisVid() const { return galutinisVid_; }

	void setVardas(string);
	void setPavarde(string);
	void setEgzaminas(int);
	void setND(vector<float>);
	void setGalutinisVid(float);


	void pild();
	float vidurkis();
	float galBalas(const char);
	static void nuskaitymas_vec_(string read);
	static void padalijimas3_(vector<Studentas>& vec);
	static bool pred_(const Studentas& st);

	static void isvedimas_(vector<Studentas>& vec, string pav);
};