#include "Rencontre.h"

//Constructeurs
Rencontre::Rencontre(void) 
{
	//NOP
}

Rencontre::Rencontre(Date dateRencontre, Club* clubLocal, Club* clubVisiteur)
{
	this->dateRencontre = dateRencontre;
	this->clubLocal = clubLocal;
	this->clubVisiteur = clubVisiteur;
	this->match = NULL;
}

Rencontre::Rencontre(Date dateRencontre, Club* clubLocal, Club* clubVisiteur, Match* match)
{
	this->dateRencontre = dateRencontre;
	this->clubLocal = clubLocal;
	this->clubVisiteur = clubVisiteur;
	this->match = match;
}

Rencontre::~Rencontre() {
	delete match;
}

Match* Rencontre::getMatch()
{
	return match;
}