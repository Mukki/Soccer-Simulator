#include "LigueSoccer.h"

LigueSoccer::LigueSoccer(void)
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

//Ajoute un club
void LigueSoccer::ajouterClub(string nom,string histoire,string couleur,string ville,string adresse)
{
	Club* tempClub;
	tempClub = new Club(nom, histoire, couleur, ville, adresse);
	vect_club.insert(vect_club.begin(),tempClub); //Complexité algo moins grande qu'avec .push_back()
}

//Ajoute un entraineur
void LigueSoccer::ajouterEntraineur(string nom,string prenom,string lieuObtention)
{
	Entraineur* tempEntraineur;
	tempEntraineur = new Entraineur(nom, prenom, lieuObtention);
	vect_entraineur.insert(vect_entraineur.begin(),tempEntraineur);	
}

//Supprime un club
void LigueSoccer::supprimerClub(int i)
{
	int nbClub = vect_club.capacity();

	//Validation du numeros
	if(i >= 0 && i <= nbClub)
		{
			vect_club.erase(vect_club.begin() + i);
		}
}

void LigueSoccer::ajouterContrat(Joueur* joueurContractant, Club* clubContractant, Club* clubLibere, int dureeContrat, Date dateEntree, Reglement reglement, Date dateContrat)
{
	Contrat* unContrat;
	unContrat = new Contrat(joueurContractant, clubContractant, clubLibere, dureeContrat, dateEntree, reglement, dateContrat);
	vect_contrat.push_back(unContrat);
}

//Ajoute un joueur à un club
void LigueSoccer::ajouterJoueurAClub(string nom,string prenom,float taille,float poids,string villeNaissance,Club* club, Contrat* contrat)
{
	club->ajoutJoueur(nom, prenom, taille, poids, villeNaissance);
	vect_contrat.push_back(contrat);
}

int LigueSoccer::trouverJoueurContrat(string prenom)
{
	string prenomCmp;
	
	for (unsigned int i = 0; i < vect_contrat.size(); i++) {
		prenomCmp = vect_contrat[i]->getJoueurContractant()->getPrenom();
		if (prenomCmp == prenom)
			return i;
	}
	return 999;
}

int LigueSoccer::trouverJoueurClub(string prenom, int clubCourant)
{
	string prenomCmp;

	for (unsigned int i = 0; i < vect_club[clubCourant]->getNbJoueur(); i++) {
		prenomCmp = vect_club[clubCourant]->getJoueur(i)->getPrenom();
		if (prenomCmp == prenom)
			return i;
	}
	return 999;
}

int LigueSoccer::trouverClubJoueur(string nom)
{
	string nomCmp;

	for (unsigned int i = 0; i < vect_club.size(); i++) {
		nomCmp = vect_club[i]->getNom();
		if (nomCmp == nom)
			return i;
	}
	return 999;
}

void LigueSoccer::finContrat(Joueur* joueurContractant, Club* clubContractant, Club* clubLibere, int dureeContrat, Date dateEntree, Date dateContrat, Reglement nouveauReglement, int nouveauClub, int clubCourant)
{
	Contrat * ancienContrat = new Contrat(*vect_contrat[LigueSoccer::trouverJoueurContrat(joueurContractant->getPrenom())]);

	vect_club[clubCourant]->ajoutContratEchu(ancienContrat);

	vect_contrat[LigueSoccer::trouverJoueurContrat(joueurContractant->getPrenom())]->setdUnCoup(joueurContractant, clubContractant, clubLibere, dureeContrat, dateEntree, nouveauReglement, dateContrat);

	if (joueurContractant->briserContrat() == 0)
		vect_club[nouveauClub]->ajoutJoueurNonAutonome(joueurContractant->getPrenom(), joueurContractant->getNom(), joueurContractant->getTaille(), joueurContractant->getPoids(), joueurContractant->getVilleNaissance());
	else
		vect_club[nouveauClub]->ajoutJoueurAutonome(joueurContractant->getPrenom(), joueurContractant->getNom(), joueurContractant->getTaille(), joueurContractant->getPoids(), joueurContractant->getVilleNaissance());

	vect_club[clubCourant]->supprimerJoueur(clubLibere->trouverJoueurDansJoueur(joueurContractant->getPrenom()));
}

void LigueSoccer::ruptureContrat(Joueur* joueurContractant, Club* clubContractant, Club* clubLibere, int dureeContrat, Date dateEntree, Date dateContrat, Reglement nouveauReglement, int nouveauClub, int clubCourant, string raison)
{
	Contrat * ancienContrat = new Contrat(*vect_contrat[LigueSoccer::trouverJoueurContrat(joueurContractant->getPrenom())]);

	vect_club[clubCourant]->ajoutContratEchu(ancienContrat);

	vect_contrat[LigueSoccer::trouverJoueurContrat(joueurContractant->getPrenom())]->setdUnCoup(joueurContractant, clubContractant, clubLibere, dureeContrat, dateEntree, nouveauReglement, dateContrat);

	Rupture * laRupture = new Rupture(joueurContractant, raison, clubContractant, joueurContractant->briserContrat());

	vect_club[clubCourant]->ajoutContratRompu(laRupture);

	if (joueurContractant->briserContrat() == 0)
		vect_club[nouveauClub]->ajoutJoueurNonAutonome(joueurContractant->getPrenom(), joueurContractant->getNom(), joueurContractant->getTaille(), joueurContractant->getPoids(), joueurContractant->getVilleNaissance());
	else
		vect_club[nouveauClub]->ajoutJoueurAutonome(joueurContractant->getPrenom(), joueurContractant->getNom(), joueurContractant->getTaille(), joueurContractant->getPoids(), joueurContractant->getVilleNaissance());

	vect_club[clubCourant]->supprimerJoueur(clubLibere->trouverJoueurDansJoueur(joueurContractant->getPrenom()));
}
