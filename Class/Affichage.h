#pragma once
#ifndef AFFICHAGE_H
#define AFFICHAGE_H

#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <future>
#include <cstdlib>

#include "LigueSoccer.h"
#include "Joueur.h"
#include "Club.h"
#include "Match.h"
#include "Rencontre.h"
#include "Calendrier.h"
#include "Rupture.h"
#include "Negociateur.h"
#include "NegoAcheteur.h"
#include "NegoVendeur.h"

using namespace std;

class Affichage
{
private:
	//Variables
	LigueSoccer* ligueSoccer;
	Calendrier calendrierRencontres;
	
public:
	//Constructeur
	Affichage(LigueSoccer*);
	//Ligue précodé
	void ligueHardcoder();
	//Menu ajouter un club
	void ajouterClub();
	//Menu afficher les clubs
	void afficherClub();
	//Menu supprimer les clubs
	void supprimerClub();
	//Menu afficher les joueurs
	void afficherJoueur();
	//Menu afficher les entraineurs
	void afficherEntraineurs();
	//Menu afficher les meilleurs entraineurs
	void afficherMeilleurEntraineur();
	//Menu afficher le meilleur club
	void afficherMeilleurClub();
	//Menu afficher le calendrier
	void afficherCalendrier();
	//Menu ajouter joueur
	void ajouterJoueur();
	//Menu rompre un contrat
	void rompreContrat();
	//Menu ajouter un match au calendrier des rencontres
	void ajouterMatch();
	//Menu afficher les rencontres d'un club
	void afficherRencontresClub();
	//Menu afficher les rencontres pour une date
	void afficherRencontresDate();
	//Menu afficher les montants encaisses par un club avant une date
	void afficherEncaisses();
	//Menu afficherTest
	void negocier();
};
#endif