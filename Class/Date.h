#pragma once
#ifndef DATE_H_
#define DATE_H_
#include <string>

using namespace std;

class Date
{
	//Variables de Date
	string jour;
	string mois;
	string annee;

public:
	Date(void);
	Date(string, string, string);

	//Format d'affichage
	string getDateToString(void){return jour+"/"+mois+"/"+annee;}

	//Accesseur GET
	string getJours(void){return jour;}
	string getMois(void){return mois;}
	string getAnnee(void){return annee;}
};
#endif
