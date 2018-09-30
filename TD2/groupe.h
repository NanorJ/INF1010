/***************************************************************************
* Titre: Travail pratique #2 - groupe.h
* Auteur: Wassim Khene
* Modifié par : Nanor Janjikian (1901777) et Stéphanie Mansour (1935595)
* Date : 2 octobre 2018
***************************************************************************/

#ifndef GROUPE_H
#define GROUPE_H

#include <string>
#include "transfert.h"

using namespace std;

class Groupe {
public:
	// Constructeurs default et parametres
	Groupe();
	Groupe(const string& nom);

	// Destructeur
	~Groupe();

	// Methodes d'acces
	string getNom() const;
	double getTotalDepenses() const;

	// Methodes de modification
	void setNom(const string& nom);

	// Methodes d'ajout
	// Modification pour utiliser la surcharge d'operateur
	Groupe ajouterDepense(Depense* depense, Utilisateur* utilisateur);
	Groupe& operator+=(Utilisateur* unUtilisateur);

	// Methodes de calcul
	void calculerComptes();
	void equilibrerComptes();

	// Remplacer par une surcharge de l'operateur <<
	friend ostream& operator<<(ostream& os, const Groupe& groupe);

private:
	string nom_;
	// Remplacer les doubles pointeurs par des vecteurs
	vector<Utilisateur*> utilisateurs_;
	vector<Depense*> depenses_;
	vector<Transfert*> transferts_;
	vector<double> comptes_;
};

#endif
