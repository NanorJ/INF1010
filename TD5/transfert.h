/********************************************
* Titre: Travail pratique #4 - transfert.h
* Date: 19 octobre 2018
* Auteur: Wassim Khene & Ryan Hardie
*******************************************/

#ifndef TRANSFERT_H
#define TRANSFERT_H

#include "utilisateur.h"
#include "utilisateurPremium.h"

#include <iostream>

#include <stdio.h>

class Transfert {
public:
	// Constructeurs
	Transfert();
	Transfert(double montant, Utilisateur* expediteur, Utilisateur* receveur_);

	// Methodes d'acces
	Utilisateur* getExpediteur() const;
	Utilisateur* getReceveur() const;
	double getMontant() const;
	virtual double getFraisTransfert() const = 0;

	// Methodes d'affichage
	void setMontant(double montant);
	void setExpediteur(Utilisateur* expediteur);
	void setReceveur(Utilisateur* receveur);
	void effectuerTransfert();

	friend ostream& operator<<(ostream& os, const Transfert& transfert);

protected:
	double montant_;
	Utilisateur* expediteur_;
	Utilisateur* receveur_;
};

#endif
