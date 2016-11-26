#pragma once
#ifndef JOUEURAUTONOME_H
#define JOUEURAUTONOME_H

#include "Joueur.h"
#include <string>

using namespace std;

class JoueurAutonome : public Joueur
{
private:
	float penalite = 1000;

public:
	//Constructeurs
	JoueurAutonome(void);
	JoueurAutonome(string, string, float, float, string);

	//Accesseurs GET
	string getNom() { return nom; }
	string getPrenom() { return prenom; }
	float getTaille();
	float getPoids();
	string getVilleNaissance();

	float briserContrat();
};
#endif