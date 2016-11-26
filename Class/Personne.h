#ifndef PERSONNE_H
#define PERSONNE_H

#include <string>

using namespace std;

class Personne
{
private:
	string nom;
	string prenom;
	int age;
	string tache;

public:
	Personne();
	Personne(string nomPers, string prenomPers, int agePers, string tachePers);
	~Personne();

	string leNom();
	string lePrenom();
	int lAge();
	string laTache();
};
#endif