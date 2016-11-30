#include "Calendrier.h"

Calendrier::Calendrier()
{
	vect_rencontre = vector<Rencontre*>();
}

Calendrier::~Calendrier()
{
	for (vector<Rencontre*>::iterator i = vect_rencontre.begin(); i != vect_rencontre.end(); ++i)
		delete * i;
}

Rencontre* Calendrier::laRencontre(int i)
{
	return vect_rencontre[i];
}

Date Calendrier::laDate(int i)
{
	return vect_rencontre[i]->laDateRencontre();
}

string Calendrier::leNomClubLocal(int i)
{
	return vect_rencontre[i]->leClubLocal()->leNom();
}

string Calendrier::leNomClubVisiteur(int i)
{
	return vect_rencontre[i]->leClubVisiteur()->leNom();
}

int Calendrier::leNbRencontre()
{
	return vect_rencontre.size();
}

void Calendrier::ajoutRencontre(Rencontre* uneRencontre)
{	
	vect_rencontre.push_back(uneRencontre);
}