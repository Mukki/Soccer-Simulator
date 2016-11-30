#pragma once
#ifndef PARCOURS_H_
#define PARCOURS_H_

#include <string>
#include "Date.h"

using namespace std;

class Parcours
{
private:

	string nomClub;
	Date datePassage;

public:
	Parcours();
	Parcours(string nomClub, Date datePassage);
	~Parcours();

	string leClub();
	Date laDate();
};
#endif