/********************************************
* Titre: Travail pratique #2 - utilisateur.h
* Date: 16 septembre 2018
* Auteur: Wassim Khene
*******************************************/

#ifndef UTILISATEUR_H
#define UTILISATEUR_H

#include<vector>
#include <string>
#include <iostream>

#include "depense.h"

using namespace std;

class Utilisateur {
public:
	// Constructeurs
	Utilisateur();
	Utilisateur(const string& nom);
	// TODO: Ajouter un constructeur par copie
	Utilisateur(const Utilisateur& utilisateur);

	// Destructeur
	~Utilisateur();

	// Methodes d'accès
	string getNom() const;
	unsigned int getNombreDepense() const;
	double getTotalDepenses() const;

	// Methodes de modification
	void setNom(const string& nom);

	// TODO: Ajouter un operateur += et =
	//void ajouterDepense(Depense* uneDepense);
	Utilisateur& operator+=(Depense* uneDepense);
	Utilisateur& operator=(const Utilisateur& utilisateur);

	// TODO: Remplacer par une surcharge de l'operateur <<
	//void afficherUtilisateur() const;
	friend ostream& operator<<(ostream& os, const Utilisateur& utilisateur);

private:
	string nom_;
	// TODO: Remplacer depenses_ par un vecteur
	//unsigned int tailleTabDepense_;
	unsigned int nombreDepenses_;
	vector <Depense*> depenses_;

};
#endif