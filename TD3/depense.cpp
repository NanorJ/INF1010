/********************************************
* Titre: Travail pratique #2 - depense.cpp
* Date: 16 septembre 2018
* Auteur: Wassim Khene & David Dratwa
*******************************************/

#include "depense.h"

// Constucteurs

Depense::Depense(const string& nom, double montant, const string& lieu, TypeDepense type) {
	nom_ = nom;
	lieu_ = new string(lieu);
	montant_ = montant;
	type_ = type;
}

Depense::Depense(const Depense& depense) :
	nom_(depense.nom_), montant_(depense.montant_), lieu_(nullptr), type_(depense.type_) {
	lieu_ = new string(*(depense.lieu_));
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

string* Depense::getLieu() const
{
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

void Depense::setLieu(const string& nom)
{
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
	os << "Achat : " << depense.getNom()
		<< " Prix : " << depense.getMontant()
		<< " Lieu d'achat : " << depense.getLieu()
		<< endl;

	return os;
}
