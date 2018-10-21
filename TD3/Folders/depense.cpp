/*************************************************************************************
* Titre: Travail pratique #3 - depense.cpp
* Auteur: Wassin khene & David Dratwa
* Modifié par: Nanor Janjikian (1901777) et Stéphanie Mansour (1935595)
* Date: 22 octobre 2018
* Description: Ce code contient les méthodes implémentées de depense.h
**************************************************************************************/

#include "depense.h"

// Constucteurs
Depense::Depense(const string& nom, double montant, const string& lieu, TypeDepense type) {
	nom_ = nom;
	lieu_ = new string(lieu);
	montant_ = montant;
	type_ = type; 
}

Depense::Depense(const Depense& depense) :
	nom_(depense.nom_), montant_(depense.montant_), lieu_(new string(*(depense.lieu_))), type_(depense.type_) {
}

Depense::~Depense()
{	
	if (lieu_ != nullptr)
		delete lieu_;
}

// Methodes d'acces
string Depense::getNom() const {
	return nom_;
}

double Depense::getMontant() const {
	return montant_;
}

string* Depense::getLieu() const {
	return lieu_;
}

TypeDepense Depense::getType() const {
	return type_;
}


// Methodes de modifications
void Depense::setNom(const string& nom) {
	nom_ = nom;
}

void Depense::setMontant(double montant) {
	montant_ = montant;
}

void Depense::setLieu(const string& nom) {
	delete lieu_;
	lieu_ = new string(nom);
}


void Depense::setType(TypeDepense type) {
	type_ = type; 
}

Depense& Depense::operator=(const Depense& depense) {
	if (this != &depense)
	{
		delete lieu_;
		lieu_ = new string(*(depense.lieu_));
		nom_ = depense.nom_;
		montant_ = depense.montant_;
		type_ = depense.type_;
	}
	return *this;
}

ostream& operator<<(ostream &os, const Depense& depense) {
	os << "\n\t\t Achat fait a " << *(depense.getLieu()) << ": " << depense.getNom()
		<< " pour un prix de " << depense.getMontant() << "$";

	return os;
}
