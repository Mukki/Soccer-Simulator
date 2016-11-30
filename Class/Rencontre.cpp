#include "Rencontre.h"

Rencontre::Rencontre() 
{
	//NOP
}

Rencontre::Rencontre(Date dateRencontre, Club* clubLocal, Club* clubVisiteur, Match* match)
{
	this->dateRencontre = dateRencontre;
	this->clubLocal = clubLocal;
	this->clubVisiteur = clubVisiteur;
	this->match = match;
}

Rencontre::~Rencontre()
{
	//NOP
}

Date Rencontre::laDateRencontre()
{
	return dateRencontre;
}

Club* Rencontre::leClubLocal()
{
	return clubLocal;
}

Club* Rencontre::leClubVisiteur()
{
	return clubVisiteur;
}

Match* Rencontre::leMatch()
{
	return match;
}