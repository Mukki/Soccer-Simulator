#include "LigueSoccer.h"
#include "Affichage.h"
#include <iostream>
#include <thread>

using namespace std;

LigueSoccer* ligueSoccer = new LigueSoccer();
Affichage affichage(ligueSoccer);

void menuPrincipale(){
	cout << "Soccer Simulator (c) Soft.inc" << endl << endl;
	cout << "1.  Ajouter un club" << endl;
	cout << "2.  Afficher les clubs" << endl;
	cout << "3.  Supprimer un club" << endl;
	cout << "4.  Afficher les joueurs" << endl;
	cout << "5.  Afficher liste entraineurs" << endl;
	cout << "6.  Afficher l'entraineur le plus titre" << endl;
	cout << "7.  Afficher le club le plus titre" << endl;
	cout << "8.  Afficher le calendrier des rencontres" << endl;
	cout << "9.  Ajouter un joueur" << endl;
	cout << "10. Transfert ou rupture de contrat" << endl;
	cout << "11. Ajouter une rencontre" << endl;
	cout << "12. Afficher les rencontres pour un club" << endl;
	cout << "13. Afficher les rencontres pour une date" << endl;
	cout << "14. Afficher les montants encaisses par un club" << endl;
	cout << "15. Demarrer une negociation pour un joueur" << endl;
	cout << "16. Enregistrer un fichier de club" << endl;
	cout << endl;
	cout << "0.  Quitter" << endl;
	cout << endl << "Votre choix : ";
}

int main()
{
	int input;
	cout << "Voulez-vous lire des fichiers ou utiliser la ligue hard coder?" << endl;
	cout << "1.  Lire un fichier" << endl;
	cout << "2.  Utiliser la ligue hard code" << endl;
	cin >> input;

	switch (input)
	{
		case 1: affichage.lireFichier();
			break;
		case 2: affichage.ligueHardcoder();
			break;
		default: cout << "Choix invalide! La ligue hard code sera apeller." << endl;
			affichage.ligueHardcoder();
			break;
	}

	system("cls");

	cout << "   _____                            _____ _                 _       _             " << endl;
	cout << "  / ____|                          / ____(_)               | |     | |            " << endl;
	cout << " | (___   ___   ___ ___ ___ _ __  | (___  _ _ __ ___  _   _| | __ _| |_ ___  _ __ " << endl;
	cout << "  \\___ \\ / _ \\ / __/ __/ _ \\ '__|  \\___ \\| | '_ ` _ \\| | | | |/ _` | __/ _ \\| '__|" << endl;
	cout << "  ____) | (_) | (_| (_|  __/ |     ____) | | | | | | | |_| | | (_| | || (_) | |   " << endl;
	cout << " |_____/ \\___/ \\___\\___\\___|_|    |_____/|_|_| |_| |_|\\__,_|_|\\__,_|\\__\\___/|_|   " << endl;
	cout << "                                                                      (c) Soft.inc" << endl;

	menuPrincipale();
	cin >> input;

	while(input != 0)
		{
			switch(input)
			{
				case 1: affichage.ajouterClub();					
					break;
		
				case 2: affichage.afficherClub();
					break;

				case 3: affichage.supprimerClub();
					break;
			
				case 4: affichage.afficherJoueur();
					break;

				case 5: affichage.afficherEntraineurs();
					break;

				case 6: affichage.afficherMeilleurEntraineur();
					break;

				case 7: affichage.afficherMeilleurClub();
					break;

				case 8: affichage.afficherCalendrier();
					break;

				case 9: affichage.ajouterJoueur();
					break;

				case 10: affichage.rompreContrat();
					break;

				case 11: affichage.ajouterMatch();
					break;

				case 12: affichage.afficherRencontresClub();
					break;

				case 13: affichage.afficherRencontresDate();
					break;

				case 14: affichage.afficherEncaisses();
					break;

				case 15: affichage.negocier();
					break;

				case 16: affichage.enregistrerFichier();
					break;
	
				default : cout << "Choix invalide" << endl;
			}

			system("pause");
			system("cls");

			menuPrincipale();
			cin >> input;
		}

	return 0;
}