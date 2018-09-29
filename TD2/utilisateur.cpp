/********************************************************************************
* Titre: Travail pratique #2 - utilisateur.cpp
* Date: 16 septembre 2018
* Auteur: Wassim Khene
* Modifié par : Nanor Janjikian (1901777) et Stéphanie Mansour (1935595)
* Date: 2 octobre 2018
* Description: Ce code contient les méthodes implémentées de utilisateur.h
*********************************************************************************/

#include "utilisateur.h"

// Constructeurs
Utilisateur::Utilisateur() : nom_("") {
}

Utilisateur::Utilisateur(const string& nom)
	: nom_(nom) {
}

Utilisateur::Utilisateur(const Utilisateur& utilisateur):
	nom_(utilisateur.nom_) {
}



//Destructeur
Utilisateur::~Utilisateur() {
}

// Methodes d'acces
string Utilisateur::getNom() const {
	return nom_;
}


double Utilisateur::getTotalDepenses() const {
	double total = 0;
	for (int i = 0; i < depenses_.size(); i++) {
		total += depenses_[i]->getMontant();
	}
	return total;
}

//Methodes de modification
void Utilisateur::setNom(const string& nom) {
	nom_ = nom;
}

Utilisateur& Utilisateur::operator+=(Depense* uneDepense) {
	depenses_.push_back(uneDepense);	
	return *this;
}

Utilisateur& Utilisateur::operator=(const Utilisateur& utilisateur) {
	if (this != &utilisateur)
	{
		depenses_ = utilisateur.depenses_;
		nom_ = utilisateur.nom_;
	}
	return *this;
}


// Methode d'affichage
ostream& operator<<(ostream &os, const Utilisateur& utilisateur) {
	os << "Utilisateur : " << utilisateur.getNom()
		<< " a depense pour un total de : " 
		<< utilisateur.getTotalDepenses() << endl
		<< "\t Liste de depenses : " << endl; 

	for (int i = 0; i < utilisateur.depenses_.size(); i++) {
		os << "\t\t" << utilisateur.depenses_[i];
	
	}
	return os;
}

