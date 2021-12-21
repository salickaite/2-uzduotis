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

class Studentas 
{
private:
	string vardas_;
	string pavarde_;
	int egz_;
	float gal_vid_;
	vector<float> nd_;

public:
	Studentas() 
	{
		egz_ = 0;
		gal_vid_ = 0;
	}
	Studentas(string, string, int, float);


	inline string vardas() const { return vardas_; }
	inline string pavarde() const { return pavarde_; }
	inline int egz() const { return egz_; }
	inline vector<float> nd() const { return nd_; }
	inline float gal_vid() const { return gal_vid_; }

	void setVardas(string);
	void setPavarde(string);
	void setEgz(int);
	void setND(vector<float>);
	void setGal_vid(float);


	void pild();
	float vidurkis();
	float galBalas(const char);
	static void nuskaitymas_v_(string read);
	static void padalijimas3_(vector<Studentas>& vec);
	static bool pred_(const Studentas& st);

	static void isvedimas_(vector<Studentas>& vec, string pav);
};
