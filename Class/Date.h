#pragma once
#ifndef DATE_H_
#define DATE_H_
#define _CRT_SECURE_NO_WARNINGS

#include <ctime>
#include <string>

using namespace std;

class Date
{
	string jour;
	string mois;
	string annee;

public:
	Date();
	Date(string jour, string mois, string annee);
	~Date();

	string leJour();
	string leMois();
	string lAnnee();

	string laDateEnTexte();
};
#endif