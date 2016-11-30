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
	Rencontre();
	Rencontre(Date, Club*, Club*, Match* = NULL);
	~Rencontre();

	Date laDateRencontre();
	Club* leClubLocal();
	Club* leClubVisiteur();
	Match* leMatch();
};
#endif