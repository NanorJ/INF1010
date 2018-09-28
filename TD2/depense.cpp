/********************************************
* Titre: Travail pratique #2 - depense.cpp
* Date: 16 septembre 2018
* Auteur: Wassim Khene
*******************************************/

#include "depense.h"

// Constucteurs
Depense::Depense() : nom_(""), montant_(0) {
}

/*Depense::Depense(const string& nom, double montant) : nom_(nom), montant_(montant) {
}*/

Depense::Depense(const string& nom, double montant, string* lieu) : nom_(nom), montant_(montant), lieu_(lieu) {
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

void Depense::setLieu(string* lieu) {
	lieu_ = lieu;
}

// Methode d'affichage
ostream& operator<<(ostream &os, const Depense& depense) {
	os << "Achat : " << depense.getNom()
		<< " Prix : " << depense.getMontant()
		<< endl;

	return os;
}
