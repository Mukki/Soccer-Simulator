#include "Date.h"
#include <iostream>

Date::Date()
{
	time_t t = time(0);
	struct tm * now = localtime(&t);

	this->jour = now->tm_mday;
	this->mois = (now->tm_mon + 1);
	this->annee = (now->tm_year + 1900);
}

Date::Date(string jour, string mois, string annee)
{
	this->jour = jour;
	this->mois = mois;
	this->annee = annee;
}

Date::~Date()
{
	//NOP
}

string Date::leJour()
{
	return jour;
}

string Date::leMois()
{
	return mois;
}

string Date::lAnnee()
{
	return annee;
}

string Date::laDateEnTexte()
{
	return jour + "/" + mois + "/" + annee;
}