
#ifndef GROUPE_H
#define GROUPE_H

#include <string>

using namespace std;

#include "transfert.h"

class Groupe {
public:
	//Constructeurs
	Groupe();
	Groupe(const string& nom, unsigned int tailleTabDepenses, unsigned int tailleTabUtilisateurs);

	//Destructeur
	~Groupe();

	//methode d'acces
	string getNom() const;
	unsigned int getNombreDepenses() const;
	double getTotal() const;

	//Methodes de modification
	void setNom(const string& nom);

	//Methodes d'ajout
	void ajouterDepense(Depense* uneDepense, Utilisateur* payePar);
	void ajouterUtilisateur(Utilisateur* unUtilisateur);

	//Méthode de calcul
	void calculerTotalDepenses();
	void equilibrerComptes();

	//methode d'affichage
	void afficherGroupe() const;

private:
	string nom_;
	double totalDepenses_;
	Utilisateur** listeUtilisateurs_;
	unsigned int nombreDepenses_;
	unsigned int nombreUtilisateurs_;
	unsigned int tailleTabUtilisateurs_;
	unsigned int tailleTabDepenses_;
	Depense** listeDepenses_;
	double* comptes_;
	Transfert** listeTransferts_;
	unsigned int nombreTransferts_;

};

#endif 
