#include "Calendrier.h"

//Constructeur
Calendrier::Calendrier(void)
{
	vect_rencontre = vector<Rencontre*>();
}

//Destructeur
Calendrier::~Calendrier()
{
	for (vector<Rencontre*>::iterator i = vect_rencontre.begin(); i != vect_rencontre.end(); ++i)
		delete * i;
}

//Accesseur GET
Rencontre* Calendrier::getRencontre(int i)
{
	return vect_rencontre[i];
}

string Calendrier::getDate(int i)
{
	return vect_rencontre[i]->getDateRencontre().getDateToString();
}

string Calendrier::getNomClubLocal(int i)
{
	return vect_rencontre[i]->getClubLocal()->getNom();
}

string Calendrier::getNomClubVisit(int i)
{
	return vect_rencontre[i]->getClubVisiteur()->getNom();
}

int Calendrier::getSizeof()
{
	return vect_rencontre.size();
}

//Ajouter une rencontre
void Calendrier::ajoutRencontre(Rencontre* uneRencontre)
{	
	vect_rencontre.push_back(uneRencontre);
}