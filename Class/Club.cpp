#include "Club.h"

Club::Club()
{
	//NOP
}

Club::Club(string nom, string histoire, string couleur, string ville, string adresse)
{
	this->nom = nom;
	this->histoire = histoire;
	this->couleur = couleur;
	this->ville = ville;
	this->adresse = adresse;

	this->dateCreation = Date();
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

string Club::leNom()
{
	return nom;
}

string Club::lHistoire()
{
	return histoire;
}

string Club::laCouleur()
{
	return couleur;
}

string Club::laVille()
{
	return ville;
}

string Club::lAdresse()
{
	return adresse;
}

int Club::leNbJoueur()
{
	return vect_joueurs.size();
}

Joueur* Club::leJoueur(int i)
{
	return vect_joueurs[i];
}

Palmares* Club::lePalmares(int i)
{
	return &vect_palmares.at(i);
}

int Club::leNbPalmares()
{
	return vect_palmares.size();
}

Contrat* Club::leContratEchu(int i)
{
	return vect_contratEchu[i];
}

int Club::leNbContratEchu()
{
	return vect_contratEchu.size();
}

void Club::ajoutJoueur(string nom, string prenom, float taille, float poids, string villeNaissance)
{
	Joueur* leJoueur = new Joueur(nom, prenom, taille, poids, villeNaissance);
	vect_joueurs.insert(vect_joueurs.begin(), leJoueur);
}

void Club::ajoutJoueurAutonome(string nom, string prenom, float taille, float poids, string villeNaissance)
{
	JoueurAutonome* leJoueur = new JoueurAutonome(nom, prenom, taille, poids, villeNaissance);
	vect_joueurs.insert(vect_joueurs.begin(), leJoueur);
}

void Club::ajoutJoueurNonAutonome(string nom, string prenom, float taille, float poids, string villeNaissance)
{
	JoueurNonAutonome* leJoueur = new JoueurNonAutonome(nom, prenom, taille, poids, villeNaissance);
	vect_joueurs.insert(vect_joueurs.begin(), leJoueur);
}

void Club::supprimerJoueur(int indice)
{
	delete vect_joueurs[indice];
	vect_joueurs.erase(vect_joueurs.begin() + indice);
}

void Club::ajoutPalmares(string titre, string jours, string mois, string annee)
{
	Date laDate(jours, mois, annee);
	Palmares lePalmares(titre, laDate, this);
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

	for (int i = 0; i < vect_joueurs.size(); i++)
	{
		prenomCmp = vect_joueurs[i]->lePrenom();
		if (prenomCmp == prenom)
			return i;
	}
	return 999;
}