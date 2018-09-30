/********************************************************************************
* Titre: Travail pratique #2 - depense.cpp
* Auteur: Wassim Khene
* Modifié par : Nanor Janjikian (1901777) et Stéphanie Mansour (1935595)
* Date: 2 octobre 2018
* Description: Ce code contient les méthodes implémentées de depense.h
*********************************************************************************/

#include "depense.h"

// Implémentation du constucteur par défault
Depense::Depense() : nom_(""), montant_(0) {
}
// Implémentation du constucteur par paramètres
Depense::Depense(const string& nom, double montant, const string& lieu) : nom_(nom), montant_(montant), lieu_(nullptr) {
	lieu_ = new string(lieu);
}
//Implémentation du constructeur par copie
Depense::Depense(const Depense& depense) :
	lieu_(nullptr), nom_(depense.nom_),montant_(depense.montant_)
{
	lieu_ = new string(*(depense.lieu_));
}
//implementation de la surcharge de l'operateur =
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


// Implémentation des methodes d'acces
string Depense::getNom() const {
	return nom_;
}

double Depense::getMontant() const {
	return montant_;
}

string* Depense::getLieu() const {
	return lieu_;
}

//Implémentation des methodes de modifications
void Depense::setNom(const string& nom) {
	nom_ = nom;
}

void Depense::setMontant(double montant) {
	montant_ = montant;
}

void Depense::setLieu(const string& lieu) {
	delete lieu_;
	lieu_ = new string(lieu);
}

//implémentation de la methode d'affichage
ostream& operator<<(ostream &os, const Depense& depense) {
	os << "Achat : " << depense.getNom()
		<< " Prix : " << depense.getMontant()
		<< endl;

	return os;
}
