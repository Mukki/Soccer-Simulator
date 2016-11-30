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
	JoueurNonAutonome();
	JoueurNonAutonome(string nom, string prenom, float taille, float poids, string villeNaissance);
	~JoueurNonAutonome();

	float briserContrat();
};
#endif