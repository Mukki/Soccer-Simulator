#include "Arbitre.h"
#include "Sportif.h"

Arbitre::Arbitre()
{
	//NOP
}

Arbitre::Arbitre(string nom, string prenom, string lieuObt, int experience) : Sportif(nom, prenom)
{
	this->lieuObt = lieuObt;
	this->experience = experience;
}

Arbitre::~Arbitre()
{
	//NOP
}

string Arbitre::leLieuObt()
{
	return lieuObt;
}

int Arbitre::lExperience()
{
	return experience;
}