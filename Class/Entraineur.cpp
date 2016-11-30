#include "Entraineur.h"

Entraineur::Entraineur()
{
	//NOP
}

Entraineur::Entraineur(string nom, string prenom, string lieu, float salaireHoraire, float salaireAnnuel) : Sportif(nom, prenom), Employe(salaireHoraire, salaireAnnuel)
{
	this->lieuObtention = lieu;
}

Entraineur::~Entraineur()
{
	//NOP
}

string Entraineur::lelieuObtention()
{
	return lieuObtention;
}

int Entraineur::leNbPalmares()
{
	return vect_titre.size();
}

Palmares* Entraineur::lePalmares(int i)
{
	return &vect_titre.at(i);
}

void Entraineur::ajouterPalmares(string titre, string jours, string mois, string annee, Club* club)
{
	Date laDate(jours, mois, annee);
	Palmares lePalmares(titre, laDate, club);
	vect_titre.insert(vect_titre.begin(), lePalmares);
}