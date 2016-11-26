#include "Club.h"

//Constructeur par commandes
Club::Club()
{
	//NOP
}

//Constructeur de base du club
Club::Club(string nom, string histoire, string couleur, string ville, string adresse)
{
	this->nom = nom;
	this->histoire = histoire;
	this->couleur = couleur;
	this->ville = ville;
	this->adresse = adresse;

	this->dateCreation = Date("0", "0", "0");
	this->stadeClub = Stade();

	vect_joueurs = vector<Joueur*>();
	vect_rupture = vector<Rupture*>();
	vect_contratEchu = vector<Contrat*>();
}

Club::~Club() 
{
	for (vector<Joueur*>::iterator i = vect_joueurs.begin(); i != vect_joueurs.end(); ++i)
		delete *i;

	for (vector<Rupture*>::iterator i = vect_rupture.begin(); i != vect_rupture.end(); ++i)
		delete *i;

	for (vector<Contrat*>::iterator i = vect_contratEchu.begin(); i != vect_contratEchu.end(); ++i)
		delete *i;
}

//Gestion des joueurs
void Club::ajoutJoueur(string nom,string prenom,float taille,float poids,string villeNaissance)
{
	Joueur* leJoueur;
	leJoueur = new Joueur(nom, prenom, taille, poids, villeNaissance);
	vect_joueurs.insert(vect_joueurs.begin(), leJoueur);
}

void Club::ajoutJoueurAutonome(string nom, string prenom, float taille, float poids, string villeNaissance)
{
	JoueurAutonome* leJoueur;
	leJoueur = new JoueurAutonome(nom, prenom, taille, poids, villeNaissance);
	vect_joueurs.insert(vect_joueurs.begin(), leJoueur);
}

void Club::ajoutJoueurNonAutonome(string nom, string prenom, float taille, float poids, string villeNaissance)
{
	JoueurNonAutonome* leJoueur;
	leJoueur = new JoueurNonAutonome(nom, prenom, taille, poids, villeNaissance);
	vect_joueurs.insert(vect_joueurs.begin(), leJoueur);
}

void Club::supprimerJoueur(int indice)
{
	delete vect_joueurs[indice];
	vect_joueurs.erase(vect_joueurs.begin() + indice);
}

//Gestion des palmares
void Club::ajoutPalmares(string titre,string jours,string mois,string annee)
{
	Date laDate(jours,mois,annee);
	Palmares lePalmares(titre,laDate,this);
	vect_palmares.insert(vect_palmares.begin(), lePalmares);
}

void Club::ajoutContratEchu(Contrat * leContrat)
{
	vect_contratEchu.insert(vect_contratEchu.begin(), leContrat);
}

void Club::ajoutContratRompu(Rupture * laRupture)
{
	vect_rupture.insert(vect_rupture.begin(), laRupture);
}

int Club::trouverJoueurDansJoueur(string prenom)
{
	string prenomCmp;

	for (unsigned int i = 0; i < vect_joueurs.size(); i++) {
		prenomCmp = vect_joueurs[i]->getPrenom();
		if (prenomCmp == prenom)
			return i;
	}
	return 999;
}
