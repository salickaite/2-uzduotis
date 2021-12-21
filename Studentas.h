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

/// Klase 'Zmogus'
/// 
/// klase, kuri yra abstrakti bazine
class Zmogus
{
protected:
	string vardas_;
	string pavarde_;
public:
	Zmogus()
	{
		vardas_ = "";
		pavarde_ = "";
	}

	virtual string vardas() = 0;
	virtual string pavarde() = 0;
	~Zmogus() {};
};

/// Klase 'Studentas'
/// 
/// isvestine klase is 'Zmogus'
class Studentas : public Zmogus
{
private:
	int egz_;
	float gal_vid_;
	vector<float> nd_;

public:
	///Default constructor
	Studentas()
	{
		egz_ = 0;
		gal_vid_ = 0;
		nd_.clear();
	}

	Studentas(string, string, float);
	/// Copy constructor
	Studentas(const Studentas& st);
	/// Copy asignment operator
	Studentas& operator=(const Studentas& st);

	inline string vardas() { return vardas_; }
	inline string pavarde() { return pavarde_; }
	inline int egz() const { return egz_; }
	inline vector<float> nd() const { return nd_; }
	inline float gal_vid() const { return gal_vid_; }

	void setVardas(string);
	void setPavarde(string);
	void setEgz(int);
	void setND(vector<float>);
	void setGal_vid(float);
	/// Destructor
	~Studentas()
	{
		nd_.clear();
	}

	/// Uzpildymo funkcija
	void pild();

	/// Vidurkio funkcija
	float vidurkis();

	/// Galutinio balo (ivertinimo) funkcija
	float galBalas(const char);

	/// Nuskaitymo funkcija
	static void nuskaitymas_v_(string read);

	/// Studentu padalijimo (rusiavimo) funkcija
	static void padalijimas3_(vector<Studentas>& vec);

	static bool pred_(const Studentas& st);

	/// Isvedimo i faila funkcija
	static void isvedimas_(vector<Studentas>& vec, string pav);

	/// Isvedimo funkcija
	///
	/// perdengtas operatorius. Isveda varda, pavarde, galutini ivertinima
	friend std::ostream& operator<<(std::ostream& out, const Studentas& a);
	/// Sulyginimo operatorius
	///
	/// Perdengtas operatorius
	friend bool operator==(const Studentas& a, const Studentas& b);
};
