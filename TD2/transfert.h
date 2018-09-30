/***************************************************************************
* Titre: Travail pratique #2 - transfert.h
* Auteur: Wassim Khene
* Modifié par : Nanor Janjikian (1901777) et Stéphanie Mansour (1935595)
* Date : 2 octobre 2018
***************************************************************************/
#ifndef TRANSFERT_H
#define TRANSFERT_H
#include "utilisateur.h"
#include <iostream>
#include <stdio.h>

class Transfert {
public:

	// Constructeur par default
	Transfert();
	// constructeur par parametre
	Transfert(double montant, Utilisateur* expediteur, Utilisateur* receveur_);

	// Méthodes d'accès
	Utilisateur* getExpediteur() const;
	Utilisateur* getReceveur() const;
	double getMontant() const;


	// Méthodes d'affichage
	void setMontant(double montant);
	void setExpediteur(Utilisateur* expediteur);
	void setReceveur(Utilisateur* receveur);

	//Remplacer affichage par une surcharge de l'operateur <<
	friend ostream& operator<<(ostream& os, const Transfert& transfert);

private:
	double montant_;
	Utilisateur* expediteur_;
	Utilisateur* receveur_;

};

#endif