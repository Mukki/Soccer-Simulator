#pragma once
#ifndef AFFICHAGE_H
#define AFFICHAGE_H

#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <future>
#include <cstdlib>
#include <fstream>

#include "LigueSoccer.h"
#include "Exception.h"
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
	LigueSoccer* ligueSoccer;
	Calendrier calendrierRencontres;
	
public:
	Affichage(LigueSoccer*);
	Affichage();

	void lireFichier();
	void enregistrerFichier();
	void ligueHardcoder();
	void ajouterClub();
	void afficherClub();
	void supprimerClub();
	void afficherJoueur();
	void afficherEntraineurs();
	void afficherMeilleurEntraineur();
	void afficherMeilleurClub();
	void afficherCalendrier();
	void ajouterJoueur();
	void rompreContrat();
	void ajouterMatch();
	void afficherRencontresClub();
	void afficherRencontresDate();
	void afficherEncaisses();
	void negocier();
};
#endif