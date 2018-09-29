/********************************************
* Titre: Travail pratique #2 - groupe.h
* Date: 16 septembre 2018
* Auteur: Wassim Khene
*******************************************/

#ifndef GROUPE_H
#define GROUPE_H

#include <string>
#include "transfert.h"

using namespace std;

class Groupe {
public:
	// Constructeurs
	Groupe();
	Groupe(const string& nom);

	// Destructeur
	~Groupe();

	// Methodes d'acces
	string getNom() const;
	unsigned int getNombreDepenses() const;
	double getTotalDepenses() const;

	// Methodes de modification
	void setNom(const string& nom);

	// Methodes d'ajout
	// TODO: Modifier pour utiliser la surcharge d'operateur
	Groupe ajouterDepense(Depense* depense, Utilisateur* utilisateur);
	
	//void ajouterUtilisateur(Utilisateur* utilisateur);
	Groupe& operator+=(Utilisateur* unUtilisateur);

	// Methodes de calcul
	void calculerComptes();
	void equilibrerComptes();

	// TODO: Remplacer par une surcharge de l'operateur <<
	//void afficherGroupe() const;
	friend ostream& operator<<(ostream& os, const Groupe& groupe);

private:
	string nom_;
	// Remplacer les doubles pointeurs par des vecteurs
	vector<Utilisateur*> utilisateurs_;
	//unsigned int nombreUtilisateurs_;
	//unsigned int tailleTabUtilisateurs_;
	vector<Depense*> depenses_;
	//unsigned int nombreDepenses_;
	//unsigned int tailleTabDepenses_;
	vector<Transfert*> transferts_;
	//unsigned int nombreTransferts_;
	vector<double> comptes_;

};

#endif
