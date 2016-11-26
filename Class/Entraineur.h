#pragma once
#ifndef ENTRAINEUR_H_
#define ENTRAINEUR_H_
#include <string>
#include "Palmares.h"
#include <vector>
#include "Date.h"
#include "Club.h"
#include "Sportif.h"

class Entraineur : public Sportif
{
//Variables de l'entraîneur
private:
	string lieuObtention;
	vector<Palmares> vect_titre;

public:
	//Constructeurs
	Entraineur(void);
	Entraineur(string, string, string);
	// Ajoute un palmares (Titre, jours, mois, annee, club mérité* )
	void ajouterPalmares(string, string, string, string, Club*);

	//Accesseur GET
	string getNom(void) { return nom; }
	string getPrenom(void){return prenom;}
	string getlieuObtention(void){return lieuObtention;}
	int getNbPalmares(void){return vect_titre.size();}
	Palmares* getPalmares(int i){return &vect_titre.at(i);}
};
#endif