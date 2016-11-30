#include "Parcours.h"

Parcours::Parcours()
{
	//NOP
}

Parcours::Parcours(string nomClub, Date datePassage)
{
	this->nomClub = nomClub;
	this->datePassage = datePassage;
}

Parcours::~Parcours()
{
	//NOP
}

string Parcours::leClub()
{
	return nomClub;
}

Date Parcours::laDate()
{
	return datePassage;
}