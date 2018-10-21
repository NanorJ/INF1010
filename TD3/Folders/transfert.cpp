/************************************************************************************
* Titre: Travail pratique #3 - transfert.cpp
* Auteur: Wassin khene
* Modifié par: Nanor Janjikian (1901777) et Stéphanie Mansour (1935595)
* Date: 22 octobre 2018
* Description: Ce code contient les méthodes implémentées de transfert.h
*************************************************************************************/

#include "transfert.h"

// Constructeurs
Transfert::Transfert() : montant_(0), expediteur_(nullptr), receveur_(nullptr) {
}

Transfert::Transfert(double montant, Utilisateur* expediteur, Utilisateur* receveur) : 
	montant_(montant), expediteur_(expediteur), receveur_(receveur) {
}

// Methodes d'acces
double Transfert::getMontant() const {
	return montant_;
}

Utilisateur* Transfert::getExpediteur() const {
	return expediteur_;
}

Utilisateur* Transfert::getReceveur() const {
	return receveur_;
}

// Methodes de modifications
void Transfert::setMontant(double montant) {
	montant_ = montant;
}

void Transfert::setExpediteur(Utilisateur *donneur) {
	expediteur_ = donneur;
}

void Transfert::setReceveur(Utilisateur *receveur) {
	receveur_ = receveur;
}

//Methode affichage
ostream& operator<<(ostream& os, const Transfert& transfert) {
	return os << "Transfert fait par " << transfert.getExpediteur()->getNom() << " vers " << transfert.getReceveur()->getNom() << " d'un montant de " << transfert.getMontant() << endl;
}
