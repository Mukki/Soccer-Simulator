#pragma once
#ifndef RENCONTRE_H
#define RENCONTRE_H

#include "Match.h"
#include "Club.h"

class Rencontre
{
private:
	Date dateRencontre;
	Club* clubLocal;
	Club* clubVisiteur;
	Match* match;

public:
	//Constructeurs
	Rencontre(void);
	Rencontre(Date, Club*, Club*);
	Rencontre(Date, Club*, Club*, Match*);
	~Rencontre();

	//Accesseurs GET
	Date getDateRencontre() { return dateRencontre; }
	Club* getClubLocal() { return clubLocal; }
	Club* getClubVisiteur() { return clubVisiteur; }
	Match* getMatch();
};
#endif