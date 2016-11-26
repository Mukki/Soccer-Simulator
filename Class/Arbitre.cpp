#include "Arbitre.h"
#include "Sportif.h"

Arbitre::Arbitre(void)
{
	//NOP
}

//Constructeur Joueur
Arbitre::Arbitre(string j_nom, string j_prenom, string lieuObt, int experience) : Sportif(j_prenom, j_nom)
{
	this->lieuObt = lieuObt;
	this->experience = experience;
}

//Accesseur GET
string Arbitre::getNom() { return nom; }
string Arbitre::getPrenom() { return prenom; }
string Arbitre::getLieuObt() { return lieuObt; }
int Arbitre::getExperience() { return experience; }