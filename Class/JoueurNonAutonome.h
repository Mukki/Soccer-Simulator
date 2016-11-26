#pragma once
#ifndef JOUEURNONAUTONOME_H
#define JOUEURNONAUTONOME_H

#include "Joueur.h"
#include <string>

using namespace std;

class JoueurNonAutonome : public Joueur
{
private:
	float penalite = 0;

public:
	//Constructeurs
	JoueurNonAutonome(void);
	JoueurNonAutonome(string, string, float, float, string);

	//Accesseurs GET
	string getNom() { return nom; }
	string getPrenom() { return prenom; }
	float getTaille();
	float getPoids();
	string getVilleNaissance();

	float briserContrat();
};
#endif