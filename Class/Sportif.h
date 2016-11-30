#pragma once
#ifndef SPORTIF_H
#define SPORTIF_H

#include <string>

using namespace std;

class Sportif
{
protected:
	string nom;
	string prenom;

public:
	Sportif();
	Sportif(string nom, string prenom);
	~Sportif();

	string leNom();
	string lePrenom();
};
#endif