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
	JoueurAutonome();
	JoueurAutonome(string nom, string prenom, float taille, float poids, string villeNaissance);
	~JoueurAutonome();

	float briserContrat();
};
#endif