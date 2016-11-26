#include "Date.h"
#include <iostream>

//Constructeurs
Date::Date(void)
{
	//NOP
}

Date::Date(string jour, string mois, string annee)
{
	this->jour = jour;
	this->mois = mois;
	this->annee = annee;
}

