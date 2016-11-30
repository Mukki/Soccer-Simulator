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
	vector<Club*> vect_club;
	vector<Contrat*> vect_contrat;
	vector<Entraineur*> vect_entraineur;

	LigueSoccer();
	~LigueSoccer();

	vector<Club*>* leVecteurClub();
	Club* leClub(int i);
	Contrat* leContrat(int i);
	Entraineur* lEntraineur(int i);
	int leNbEntraineur();
	int leNbClub();

	void ajouterClub(string nom, string histoire, string couleur, string ville, string adresse);
	void ajouterJoueurAClub(string nom, string prenom, float taille, float poids, string villeNaissance, Club* club, Contrat* contrat);
	void ajouterEntraineur(string nom, string prenom, string lieuObtention);
	void supprimerClub(int i);
	void ajouterContrat(Joueur* joueurContractant, Club* clubContractant, Club* clubLibere, int dureeContrat, Date dateEntree, Reglement reglement, Date dateContrat);
	int trouverJoueurContrat(string prenom);
	int trouverJoueurClub(string prenom, int clubCourant);
	int trouverClubJoueur(string nom);
	void finContrat(Joueur* joueurContractant, Club* clubContractant, Club* clubLibere, int dureeContrat, Date dateEntree, Date dateContrat, Reglement nouveauReglement, int nouveauClub, int clubCourant);
	void ruptureContrat(Joueur* joueurContractant, Club* clubContractant, Club* clubLibere, int dureeContrat, Date dateEntree, Date dateContrat, Reglement nouveauReglement, int nouveauClub, int clubCourant, string raison);
};
#endif