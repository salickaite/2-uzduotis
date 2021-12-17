#pragma once

#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;
using std::istream;
using std::cout;
using std::cin;
using std::endl;

class Zmogus
{
protected:
	string vardas_;
	string pavarde_;
public:
	Zmogus() {
		vardas_ = "";
		pavarde_ = "";
	}

	virtual string vardas() = 0;
	virtual string pavarde() = 0;
	~Zmogus() {};
};



class Studentas : public Zmogus {
private:
	int egzaminas_;
	float galutinisVid_;
	vector<float> nd_;

public:
	Studentas()
	{
		egzaminas_ = 0;
		galutinisVid_ = 0;
		nd_.clear();
	}

	Studentas(string, string, float);
	/// Copy konstruktorius.

	Studentas(const Studentas& st);
	/// Priskyrimo operatorius.

	Studentas& operator=(const Studentas& st);
	inline string vardas() { return vardas_; }
	inline string pavarde() { return pavarde_; }
	inline int egzaminas() const { return egzaminas_; }
	inline vector<float> nd() const { return nd_; }
	inline float galutinisVid() const { return galutinisVid_; }

	void setVardas(string);
	void setPavarde(string);
	void setEgzaminas(int);
	void setND(vector<float>);
	void setGalutinisVid(float);
	/// Destruktorius.
	~Studentas() {
		nd_.clear();
	}

	/// Užpildymo funkcija.
	void pild();

	float vidurkis();

	float galBalas(const char);

	static void nuskaitymas_vec_(string read);

	static void padalijimas3_(vector<Studentas>& vec);

	static bool pred_(const Studentas& st);

	static void isvedimas_(vector<Studentas>& vec, string pav);

	friend std::ostream& operator<<(std::ostream& out, const Studentas& a);
	/// Sulyginimo operatorius.
	friend bool operator==(const Studentas& a, const Studentas& b);
};