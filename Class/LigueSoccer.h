#pragma once
#ifndef LIGUESOCCER_H_
#define LIGUESOCCER_H_

#include "Date.h"
#include "Palmares.h"
#include "Club.h"
#include "Entraineur.h"
#include "Joueur.h"
#include "Contrat.h"
#include "Parcours.h"
#include <vector>
#include <string>
#include "Rupture.h"

using namespace std;

class Palmares;
class Club;

class LigueSoccer
{
public:
	//Variables
	vector<Club*> vect_club;
	vector<Contrat*> vect_contrat;
	vector<Entraineur*> vect_entraineur;

	//Constructeur
	LigueSoccer(void);
	//Destructeur
	~LigueSoccer();
	//Ajoute un club (Nom, Histoire, Couleur, Ville, Adresse )
	void ajouterClub(string, string, string, string, string);
	//Ajoute un joueur a un club
	void ajouterJoueurAClub(string, string, float, float, string, Club*, Contrat* contrat);
	//Ajoute un entraineur a un club
	void ajouterEntraineur(string, string, string);
	//Supprime un club
	void supprimerClub(int);


	//Accesseur GET
	vector<Club*>* getVectClub() {return &vect_club;}
	Club* getClub(int i) {return vect_club[i];}
	Contrat* getContrat(int i) {return vect_contrat[i];}
	Entraineur* getEntraineur(int i){return vect_entraineur[i];}
	int getNbEntraineur(void){return vect_entraineur.size();}
	int getNbClub(void){return vect_club.size();}

	void ajouterContrat(Joueur*, Club*, Club*, int, Date, Reglement, Date);
	int trouverJoueurContrat(string);
	int trouverJoueurClub(string, int);
	int trouverClubJoueur(string nom);
	void finContrat(Joueur*, Club*, Club*, int, Date, Date, Reglement, int, int);
	void ruptureContrat(Joueur*, Club*, Club*, int, Date, Date, Reglement, int, int, string);
};
#endif