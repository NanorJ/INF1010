/************************************************************************************
* Titre: Travail pratique #3 - groupe.h
* Auteur: Wassin khene & David Dratwa
* Modifié par: Nanor Janjikian (1901777) et Stéphanie Mansour (1935595)
* Date: 22 octobre 2018
*************************************************************************************/

#ifndef GROUPE_H
#define GROUPE_H

#include <string>
#include <vector>
#include "depenseGroupe.h"
#include"utilisateurPremium.h"
#include "utilisateurRegulier.h"
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
	vector<DepenseGroupe*> getDepenses() const;
	vector<Utilisateur*> getUtilisateurs() const;
	vector<Transfert*> getTransferts() const; 
	double getTotalDepenses() const;

	// Methodes de modification
	void setNom(const string& nom);

	// Methodes d'ajout
	Groupe& ajouterDepense(Depense* depense, Utilisateur* payePar, vector<Utilisateur*> payePour);
	Groupe& operator+=(Utilisateur* utilisateur);

	// Methodes de calcul
	void equilibrerComptes();
	void calculerTotalDepense() ; 

	// Methode d'affichage
	friend ostream& operator<<(ostream& os, const Groupe& groupe);

private:
	string nom_;
	vector<Utilisateur*> utilisateurs_;
	vector<DepenseGroupe*> depenses_;
	vector<Transfert*> transferts_;
	double totalDepenses_; 
	vector<double> comptes_; 
};

#endif
