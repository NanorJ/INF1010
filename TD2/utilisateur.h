/***************************************************************************
* Titre: Travail pratique #2 - utilisateur.h
* Auteur: Wassim Khene
* Modifié par : Nanor Janjikian (1901777) et Stéphanie Mansour (1935595)
* Date : 2 octobre 2018
***************************************************************************/

#ifndef UTILISATEUR_H
#define UTILISATEUR_H

#include<vector>
#include <string>
#include <iostream>

#include "depense.h"

using namespace std;

class Utilisateur {
public:
	// Constructeurs par défault
	Utilisateur();
	//Constructeur par paramètres
	Utilisateur(const string& nom);
	//Ajout du constructeur par copie
	Utilisateur(const Utilisateur& utilisateur);

	// Destructeur
	~Utilisateur();

	// Methodes d'accès
	string getNom() const;
	double getTotalDepenses() const;

	// Methodes de modification
	void setNom(const string& nom);

	//Ajout des operateurs += et =
	Utilisateur& operator+=(Depense* uneDepense);
	Utilisateur& operator=(const Utilisateur& utilisateur);

	//Remplacer methode d'affichage par une surcharge de l'operateur <<
	friend ostream& operator<<(ostream& os, const Utilisateur& utilisateur);

private:
	string nom_;
	//Remplacer depenses_ par un vecteur
	vector <Depense*> depenses_;
};
#endif