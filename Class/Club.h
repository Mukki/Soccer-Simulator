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
//#include "Rupture.h"

using namespace std;
class Palmares;
class Rupture;
class Contrat;
class Club
{
private:
	//Variables de club
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
	//Constructeurs
	Club(void);
	Club(string, string, string, string, string);

	//Destructeur
	~Club();
	
	//Gestion des joueurs
	//Nom,Prénom,Taille,Poid,Ville de naissance
	void ajoutJoueur(string, string, float, float, string);
	void ajoutJoueurAutonome(string, string, float, float, string);
	void ajoutJoueurNonAutonome(string, string, float, float, string);
	void supprimerJoueur(int);

	//Gestion des palmares
	//Titre,Jours,Mois,Annee
	void ajoutPalmares(string, string, string, string);

	//Gestion des contrats
	void ajoutContratEchu(Contrat*);
	void ajoutContratRompu(Rupture*);

	//Accesseurs GET
	string getNom(void){return nom;}
	string getHist(void){return histoire;}
	string getCoul(void){return couleur;}
	string getVille(void){return ville;}
	string getAdr(void){return adresse;}
	int getNbJoueur(void) { return vect_joueurs.size(); }
	Joueur* getJoueur(int i){return vect_joueurs[i];}
	Palmares* getPalmares(int i){return &vect_palmares.at(i);}
	int getNbPalmares(void){return vect_palmares.size();}
	Contrat* getContratEchu(int i){return vect_contratEchu[i];}
	int getNbContratEchu() {return vect_contratEchu.size();}

	int trouverJoueurDansJoueur(string);
};
#endif