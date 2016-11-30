#include "LigueSoccer.h"

LigueSoccer::LigueSoccer()
{
	vect_club = vector<Club*>();
	vect_contrat = vector<Contrat*>();
	vect_entraineur = vector<Entraineur*>();
}

LigueSoccer::~LigueSoccer()
{
	for (vector<Club*>::iterator i = vect_club.begin(); i != vect_club.end(); ++i)
		delete *i;

	for (vector<Contrat*>::iterator i = vect_contrat.begin(); i != vect_contrat.end(); ++i)
		delete *i;

	for (vector<Entraineur*>::iterator i = vect_entraineur.begin(); i != vect_entraineur.end(); ++i)
		delete *i;
}

vector<Club*>* LigueSoccer::leVecteurClub()
{
	return &vect_club;
}

Club* LigueSoccer::leClub(int i)
{
	return vect_club[i];
}

Contrat* LigueSoccer::leContrat(int i)
{
	return vect_contrat[i];
}

Entraineur* LigueSoccer::lEntraineur(int i)
{
	return vect_entraineur[i];
}

int LigueSoccer::leNbEntraineur()
{
	return vect_entraineur.size();
}

int LigueSoccer::leNbClub()
{
	return vect_club.size();
}

void LigueSoccer::ajouterClub(string nom,string histoire,string couleur,string ville,string adresse)
{
	Club* tempClub = new Club(nom, histoire, couleur, ville, adresse);
	vect_club.insert(vect_club.begin(), tempClub);
}

void LigueSoccer::ajouterEntraineur(string nom,string prenom,string lieuObtention)
{
	Entraineur* tempEntraineur = new Entraineur(nom, prenom, lieuObtention);
	vect_entraineur.insert(vect_entraineur.begin(), tempEntraineur);	
}

void LigueSoccer::supprimerClub(int i)
{
	int nbClub = vect_club.capacity();

	if(i >= 0 && i <= nbClub)
		{
			vect_club.erase(vect_club.begin() + i);
		}
}

void LigueSoccer::ajouterContrat(Joueur* joueurContractant, Club* clubContractant, Club* clubLibere, int dureeContrat, Date dateEntree, Reglement reglement, Date dateContrat)
{
	Contrat* unContrat = new Contrat(joueurContractant, clubContractant, clubLibere, dureeContrat, dateEntree, reglement, dateContrat);
	vect_contrat.push_back(unContrat);
}

void LigueSoccer::ajouterJoueurAClub(string nom,string prenom,float taille,float poids,string villeNaissance,Club* club, Contrat* contrat)
{
	club->ajoutJoueur(nom, prenom, taille, poids, villeNaissance);
	vect_contrat.push_back(contrat);
}

int LigueSoccer::trouverJoueurContrat(string prenom)
{
	string prenomCmp;
	
	for (int i = 0; i < vect_contrat.size(); i++)
	{
		prenomCmp = vect_contrat[i]->leJoueurContractant()->lePrenom();
		if (prenomCmp == prenom)
			return i;
	}
	return 999;
}

int LigueSoccer::trouverJoueurClub(string prenom, int clubCourant)
{
	string prenomCmp;

	for (int i = 0; i < vect_club[clubCourant]->leNbJoueur(); i++)
	{
		prenomCmp = vect_club[clubCourant]->leJoueur(i)->lePrenom();
		if (prenomCmp == prenom)
			return i;
	}
	return 999;
}

int LigueSoccer::trouverClubJoueur(string prenom)
{
	string nomCmp;

	for (int i = 0; i < vect_club.size(); i++)
	{
		nomCmp = vect_club[i]->leNom();
		if (nomCmp == prenom)
			return i;
	}
	return 999;
}

void LigueSoccer::finContrat(Joueur* joueurContractant, Club* clubContractant, Club* clubLibere, int dureeContrat, Date dateEntree, Date dateContrat, Reglement nouveauReglement, int nouveauClub, int clubCourant)
{
	Contrat * ancienContrat = new Contrat(*vect_contrat[LigueSoccer::trouverJoueurContrat(joueurContractant->lePrenom())]);

	vect_club[clubCourant]->ajoutContratEchu(ancienContrat);

	if (joueurContractant->briserContrat() == 0)
		vect_club[nouveauClub]->ajoutJoueurNonAutonome(joueurContractant->lePrenom(), joueurContractant->leNom(), joueurContractant->laTaille(), joueurContractant->lePoids(), joueurContractant->laVilleNaissance());
	else
		vect_club[nouveauClub]->ajoutJoueurAutonome(joueurContractant->lePrenom(), joueurContractant->leNom(), joueurContractant->laTaille(), joueurContractant->lePoids(), joueurContractant->laVilleNaissance());

	vect_club[clubCourant]->supprimerJoueur(clubLibere->trouverJoueurDansJoueur(joueurContractant->lePrenom()));
}

void LigueSoccer::ruptureContrat(Joueur* joueurContractant, Club* clubContractant, Club* clubLibere, int dureeContrat, Date dateEntree, Date dateContrat, Reglement nouveauReglement, int nouveauClub, int clubCourant, string raison)
{
	Contrat * ancienContrat = new Contrat(*vect_contrat[LigueSoccer::trouverJoueurContrat(joueurContractant->lePrenom())]);

	vect_club[clubCourant]->ajoutContratEchu(ancienContrat);

	Rupture * laRupture = new Rupture(joueurContractant, raison, clubContractant, joueurContractant->briserContrat());

	vect_club[clubCourant]->ajoutContratRompu(laRupture);

	if (joueurContractant->briserContrat() == 0)
		vect_club[nouveauClub]->ajoutJoueurNonAutonome(joueurContractant->lePrenom(), joueurContractant->leNom(), joueurContractant->laTaille(), joueurContractant->lePoids(), joueurContractant->laVilleNaissance());
	else
		vect_club[nouveauClub]->ajoutJoueurAutonome(joueurContractant->lePrenom(), joueurContractant->leNom(), joueurContractant->laTaille(), joueurContractant->lePoids(), joueurContractant->laVilleNaissance());

	vect_club[clubCourant]->supprimerJoueur(clubLibere->trouverJoueurDansJoueur(joueurContractant->lePrenom()));
}
