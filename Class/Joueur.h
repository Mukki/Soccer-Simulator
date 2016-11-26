#pragma once
#ifndef JOUEUR_H_
#define JOUEUR_H_
#include <string>
#include "Parcours.h"
#include "Sportif.h"
#include <vector>

using namespace std;

class Joueur : public Sportif
{
protected:
	//Variables Joueur
	float taille;
	float poids;
	string villeNaissance;
	vector<Parcours> vect_parcours;

public:
	//Constructeurs
	Joueur(void);
	Joueur(string, string, float, float, string);

	//Gestion des parcours
	void ajoutParcours(string, Date);

	//Accesseurs GET
	string getNom();
	string getPrenom();
	float getTaille();
	float getPoids();
	string getVilleNaissance();

	virtual float briserContrat();
};
#endif