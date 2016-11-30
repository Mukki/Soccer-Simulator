#pragma once
#ifndef CLUB_H
#define CLUB_H

#include <string>
#include "Palmares.h"
#include "Joueur.h"
#include "JoueurAutonome.h"
#include "JoueurNonAutonome.h"
#include <vector>
#include <iostream>
#include "Date.h"
#include "Stade.h"
#include "Personne.h"

using namespace std;

class Palmares;
class Rupture;
class Contrat;

class Club
{
private:
	string nom;
	string histoire;
	string couleur;
	Date dateCreation;
	vector<Joueur*> vect_joueurs;
	vector<Palmares> vect_palmares;
	Stade stadeClub;
	string ville;
	string adresse;
	vector<Personne> vect_staffTech;
	vector<Rupture*> vect_rupture;
	vector<Contrat*> vect_contratEchu;

public:
	Club();
	Club(string nom, string histoire, string couleur, string ville, string adresse);
	~Club();
	
	string leNom();
	string lHistoire();
	string laCouleur();
	string laVille();
	string lAdresse();
	int leNbJoueur();
	Joueur* leJoueur(int i);
	Palmares* lePalmares(int i);
	int leNbPalmares();
	Contrat* leContratEchu(int i);
	int leNbContratEchu();

	void ajoutJoueur(string nom, string prenom, float taille, float poids, string villeNaissance);
	void ajoutJoueurAutonome(string nom, string prenom, float taille, float poids, string villeNaissance);
	void ajoutJoueurNonAutonome(string nom, string prenom, float taille, float poids, string villeNaissance);
	void supprimerJoueur(int i);
	void ajoutPalmares(string titre, string jours, string mois, string annee);
	void ajoutContratEchu(Contrat* leContrat);
	void ajoutContratRompu(Rupture* laRupture);
	int trouverJoueurDansJoueur(string prenom);
};
#endif