#pragma once
#ifndef PALMARES_H_
#define PALMARES_H_
#include <string>
#include "Date.h"

using namespace std;
class Club;
class Palmares
{
private:
	//Variables
	string titre;
	Date date;
	Club* club;

public:
	//Constructeurs
	Palmares(void);
	Palmares(string, Date, Club*);

	//Acceseur GET
	string getTitre(void){return titre;}
	string getDate(void){return date.getDateToString();}
	Club* getClub(void){return club;}
};
 #endif