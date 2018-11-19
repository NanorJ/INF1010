/********************************************
* Titre: Travail pratique #5 - groupe.h
* Auteur: Ryan Hardie
* Modifie par : Nanor Janjikian (1901777) et Stephanie Mansour (1935595)
* Date: 19 novembre 2018
*******************************************/

#ifndef GROUPE_H
#define GROUPE_H

#include "depense.h"
#include "transfertInterac.h"
#include "transfertPaypal.h"
#include "gestionnaireDepenses.h"
#include "gestionnaireUtilisateurs.h"

#include <string>

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
    
	vector<Transfert*> getTransferts() const;

<<<<<<< HEAD
=======
	// TODO : À modifier :
>>>>>>> 2e0a03edff7db9ac333d5ef6a06baa6c92ea4351
	vector<double> getComptes() const;
    
	double getTotalDepenses() const;
    
	vector<Depense*> getDepenses() const;
<<<<<<< HEAD
    
	map<Utilisateur*, double>  getUtilisateurs() const; 

=======
	map<Utilisateur*, double>  getUtilisateurs() const; // changed from vector<Utilisateur*>


	// Ajouté :
>>>>>>> 2e0a03edff7db9ac333d5ef6a06baa6c92ea4351
	GestionnaireUtilisateurs* getGestionnaireUtilisateurs();
    
	GestionnaireDepenses* getGestionnaireDepenses();

	// Methodes de modification
	void setNom(const string& nom);

	// Methodes d'ajout
	Groupe& ajouterDepense(double montant, Utilisateur* payePar, const string& nom = "", const string& lieu = "Montreal");
	Groupe& operator+=(Utilisateur* utilisateur);

	// Methodes de calcul
	void equilibrerComptes();

	// Methode d'affichage
	friend ostream& operator<<(ostream& os, const Groupe& groupe);

private:
	string nom_;
	vector<Transfert*> transferts_;

<<<<<<< HEAD
=======
	// TODO : À modifier :
	vector<double> comptes_;

	// Retiré :
	// vector<Utilisateur*> utilisateurs_;
	// vector<Depense*> depenses_;

	// Ajouté :
>>>>>>> 2e0a03edff7db9ac333d5ef6a06baa6c92ea4351
	GestionnaireUtilisateurs* gestionnaireUtilisateurs_;
	GestionnaireDepenses* gestionnaireDepenses_;
};

#endif
