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
	float taille;
	float poids;
	string villeNaissance;
	vector<Parcours> vect_parcours;

public:
	Joueur();
	Joueur(string nom, string prenom, float taille, float poids, string villeNaissance);
	~Joueur();

	string leNom();
	string lePrenom();
	float laTaille();
	float lePoids();
	string laVilleNaissance();

	void ajoutParcours(string nomCub, Date datePassage);
	virtual float briserContrat();
};
#endif