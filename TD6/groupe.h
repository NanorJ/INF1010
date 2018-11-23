/********************************************
* Titre: Travail pratique #4 - groupe.h
* Date: 19 octobre 2018
* Auteur: Wassim Khene & Ryan Hardie
*******************************************/

#ifndef GROUPE_H
#define GROUPE_H

#include <string>
#include <vector>


#include "utilisateurPremium.h"
#include "utilisateurRegulier.h"
#include "transfertInterac.h"
#include "transfertPaypal.h"

#include "gestionnaireDepenses.h"
#include "gestionnaireUtilisateurs.h"



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
	vector<Depense*> getDepenses() const;
	map<Utilisateur*, double> getUtilisateurs() const;
	vector<Transfert*> getTransferts() const;
	vector<double> getComptes() const;
	double getTotalDepenses() const;
    int getNombreUtilisateurs() const;
    int getNombreDepenses() const;

	// Ajouté :
	GestionnaireUtilisateurs* getGestionnaireUtilisateurs() const;
	GestionnaireDepenses* getGestionnaireDepenses() const;

	// Methodes de modification
	void setNom(const string& nom);

	// Methodes d'ajout
    Groupe& ajouterDepense(double montant,const string& nomUtilisateur, const string& nom = "", const string& lieu = "Montreal");
	Groupe& operator+=(Utilisateur* utilisateur);

	// Methodes de calcul
	void equilibrerComptes();

	// Methode d'affichage
	friend ostream& operator<<(ostream& os, const Groupe& groupe);

private:
	string nom_;

	// Ajouté :
	GestionnaireUtilisateurs* gestionnaireUtilisateurs_;
	GestionnaireDepenses* gestionnaireDepenses_;

	vector<Transfert*> transferts_;


};

#endif
