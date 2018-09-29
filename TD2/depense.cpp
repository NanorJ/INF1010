/********************************************************************************
* Titre: Travail pratique #2 - depense.cpp
* Date: 16 septembre 2018
* Auteur: Wassim Khene
* Modifié par : Nanor Janjikian (1901777) et Stéphanie Mansour (1935595)
* Date: 2 octobre 2018
* Description: Ce code contient les méthodes implémentées de depense.h
*********************************************************************************/

#include "depense.h"

// Constucteurs
Depense::Depense() : nom_(""), montant_(0) {
}

Depense::Depense(const string& nom, double montant, const string& lieu) : nom_(nom), montant_(montant), lieu_(nullptr) {
	lieu_ = new string(lieu);
}

Depense::Depense(const Depense& depense) :
	lieu_(nullptr), nom_(depense.nom_),montant_(depense.montant_)
{
	lieu_ = new string(*(depense.lieu_));
}

Depense& Depense::operator=(const Depense& depense) {
	if (this != &depense)
	{
		delete lieu_;

		lieu_ = new string(*(depense.lieu_));
		nom_ = depense.nom_;
		montant_ = depense.montant_;
	}
	return *this;
}


// Methodes d'acces
string Depense::getNom() const {
	return nom_;
}

double Depense::getMontant() const {
	return montant_;
}

// Methodes de modifications
void Depense::setNom(const string& nom) {
	nom_ = nom;
}

void Depense::setMontant(double montant) {
	montant_ = montant;
}

void Depense::setLieu(const string& lieu) {
	lieu_ = new string(lieu);
}

// Methode d'affichage
ostream& operator<<(ostream &os, const Depense& depense) {
	os << "Achat : " << depense.getNom()
		<< " Prix : " << depense.getMontant()
		<< endl;

	return os;
}
