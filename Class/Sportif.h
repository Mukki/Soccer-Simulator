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
	Sportif(void);
	Sportif(string nom, string prenom);
};
#endif
