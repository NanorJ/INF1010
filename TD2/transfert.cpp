/******************************************************************************
* Titre: Travail pratique #2 - transfert.cpp
* Auteur: Wassim Khene
* Modifi� par : Nanor Janjikian (1901777) et St�phanie Mansour (1935595)
* Date: 2 octobre 2018
* Description: Ce code contient les m�thodes impl�ment�es de transfert.h
*********************************************************************************/

#include "transfert.h"

//implementation des constructeurs par default et par parametred
Transfert::Transfert() : montant_(0), expediteur_(nullptr), receveur_(nullptr) {
}

Transfert::Transfert(double montant, Utilisateur* expediteur, Utilisateur* receveur) : 
	montant_(montant), expediteur_(expediteur), receveur_(receveur) {
}

//implementation des methodes d'acces
double Transfert::getMontant() const {
	return montant_;
}

Utilisateur* Transfert::getExpediteur() const {
	return expediteur_;
}

Utilisateur* Transfert::getReceveur() const {
	return receveur_;
}

//implementation des methodes de modifications
void Transfert::setMontant(double montant) {
	montant_ = montant;
}

void Transfert::setExpediteur(Utilisateur *donneur) {
	expediteur_ = donneur;
}

void Transfert::setReceveur(Utilisateur *receveur) {
	receveur_ = receveur;
}
//implementation de la methode d'affichage
ostream& operator<<(ostream& os, const Transfert& transfert) {
	os << "Transfert fait par " << transfert.expediteur_->getNom()
		<< " vers " << transfert.receveur_->getNom()
		<< " d'un montant de " << transfert.montant_
		<< endl;

	return os;
}


//Methode affichage
/*void Transfert::afficherTransfert() const {
	cout << "Transfert fait par " << expediteur_->getNom() << " vers " << receveur_->getNom() 
		<< " d'un montant de " << montant_ << endl;
}*/
