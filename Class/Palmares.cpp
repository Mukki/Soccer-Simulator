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

Palmares::~Palmares()
{
	//NOP
}

string Palmares::leTitre()
{
	return titre;
}

Date Palmares::laDate()
{
	return date;
}

Club* Palmares::leClub()
{
	return club;
}