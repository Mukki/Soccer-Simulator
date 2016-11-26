#include "Palmares.h"

Palmares::Palmares()
{
	//NOP
}

Palmares::Palmares(string titre, Date date, Club* club)
{
	this->titre = titre;
	this->date = date;
	this->club = club;
}

