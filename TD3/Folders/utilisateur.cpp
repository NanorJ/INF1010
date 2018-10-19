/********************************************
* Titre: Travail pratique #2 - utilisateur.cpp
* Date: 16 septembre 2018
* Auteur: Wassim Khene & David Dratwa 
*******************************************/

#include "utilisateur.h"

// Constructeurs

Utilisateur::Utilisateur(const string& nom, TypeUtilisateur type, double interet, double totalDepense) {
	nom_ = nom;
	type_ = type;
	interet_ = interet;
	totalDepense_ = totalDepense;
}
Utilisateur::Utilisateur(const Utilisateur& utilisateur): 
	type_(utilisateur.type_), nom_(utilisateur.nom_), interet_(utilisateur.interet_), 
	totalDepense_(utilisateur.totalDepense_) /*depenses_(utilisateur.depenses_)*/ {
}

Utilisateur::~Utilisateur() {
}

// Methodes d'acces
string Utilisateur::getNom() const {
	return nom_;
}

double Utilisateur::getTotalDepenses() const {
	return totalDepense_;
}

TypeUtilisateur Utilisateur::getType() const {
	return type_; 
}

double Utilisateur::getInteret() const {
	return interet_; 
}

unsigned int Utilisateur::getNombreDepenses() const {
	return depenses_.size();
}

vector <Depense*> Utilisateur::getDepenses() const {
	return depenses_; 
}

//Methodes de modification
void Utilisateur::setNom(const string& nom) {
	nom_ = nom;
}

Utilisateur& Utilisateur::operator=(Utilisateur * utilisateur){
	if (this != utilisateur)
	{
		type_ = utilisateur->type_;
		nom_ = utilisateur->nom_;
		interet_ = utilisateur->interet_;
		totalDepense_ = utilisateur->totalDepense_;
		depenses_ = utilisateur->depenses_;
	}
	return *this;
}


void Utilisateur::ajouterInteret(double montant) {
	interet_ += montant;
}

Utilisateur& Utilisateur::operator+=(Depense* depense) {
	depenses_.push_back(depense);
	return *this;
}

void Utilisateur::calculerTotalDepenses() {
	for (int i = 0; i < depenses_.size(); i++) {
		if (depenses_[i]->getType() == groupe)
			totalDepense_ += static_cast<DepenseGroupe*>(depenses_[i])->getMontantPersonnel();
		else
			totalDepense_ += depenses_[i]->getMontant();
	}
}

// Methode d'affichage
ostream& operator<<(ostream& os, const Utilisateur& utilisateur){
	os << " a depense pour un total de : " << utilisateur.getTotalDepenses()
		<< ", Polycount prend en interet " << utilisateur.getInteret() << endl
		<< "\t\t Liste de depenses : " << endl;

	for (int i = 0; i < utilisateur.depenses_.size(); i++) {
		if (utilisateur.depenses_[i]->getType() == groupe)
			os << *static_cast<DepenseGroupe*>(utilisateur.depenses_[i]);
		else
			os << "\t\t\t" << *(utilisateur.depenses_[i]);
	}
	return os;
}
