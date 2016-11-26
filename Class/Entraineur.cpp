#include "Entraineur.h"

//Constructeur
Entraineur::Entraineur(void)
{
	//NOP
}

//Constructeur
Entraineur::Entraineur(string e_nom, string e_prenom, string lieu) : Sportif(e_nom, e_prenom)
{
	this->lieuObtention = lieu;
}

//Ajoute un palmares a l'entraineur
void Entraineur::ajouterPalmares(string titre, string jours, string mois, string annee, Club* club)
{
	Date laDate(jours, mois, annee);
	Palmares lePalmares(titre, laDate, club);
	vect_titre.insert(vect_titre.begin(), lePalmares);

}

