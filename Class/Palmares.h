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
	string titre;
	Date date;
	Club* club;

public:
	Palmares();
	Palmares(string titre, Date date, Club* club);
	~Palmares();

	string leTitre();
	Date laDate();
	Club* leClub();
};
 #endif