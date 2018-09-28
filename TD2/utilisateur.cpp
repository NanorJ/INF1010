/********************************************
* Titre: Travail pratique #2 - utilisateur.cpp
* Date: 16 septembre 2018
* Auteur: Wassim Khene
*******************************************/

#include "utilisateur.h"

// Constructeurs
Utilisateur::Utilisateur() : nom_(""), nombreDepenses_(0) {
}

Utilisateur::Utilisateur(const string& nom)
	: nom_(nom), nombreDepenses_(0) {
}

Utilisateur::Utilisateur(const Utilisateur& utilisateur):
	nom_(utilisateur.nom_), nombreDepenses_(utilisateur.nombreDepenses_) {
}



//Destructeur
Utilisateur::~Utilisateur() {
}

// Methodes d'acces
string Utilisateur::getNom() const {
	return nom_;
}

unsigned int Utilisateur::getNombreDepense() const {
	return nombreDepenses_;
}

double Utilisateur::getTotalDepenses() const {
	double total = 0;
	for (int i = 0; i < nombreDepenses_; i++) {
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

/*void Utilisateur::ajouterDepense(Depense* depense) {
	if (nombreDepenses_ == tailleTabDepense_) {
		tailleTabDepense_ *= 2;

		Depense** listeTemp = new Depense*[tailleTabDepense_];
		for (unsigned int i = 0; i < nombreDepenses_; i++) {
			listeTemp[i] = depenses_[i];
		}
		delete[] depenses_;

		depenses_ = listeTemp;
	}
	depenses_[nombreDepenses_++] = depense;
}*/

Utilisateur& Utilisateur::operator=(const Utilisateur& utilisateur) {
	if (this != &utilisateur)
	{
		depenses_ = utilisateur.depenses_;
		nom_ = utilisateur.nom_;
		nombreDepenses_ = utilisateur.nombreDepenses_;
	}
	return *this;
}


// Methode d'affichage
ostream& operator<<(ostream &os, const Utilisateur& utilisateur) {
	os << "Utilisateur : " << utilisateur.getNom()
		<< " a depense pour un total de : " 
		<< utilisateur.getTotalDepenses() << endl
		<< "\t Liste de depenses : " << endl; 

	for (int i = 0; i < utilisateur.nombreDepenses_; i++) {
		os << "\t\t" << utilisateur.depenses_[i]->;
	
	}
	return os;
}

/*void Utilisateur::afficherUtilisateur() const {

	cout << "Utilisateur : " << nom_ << " a depense pour un total de : " << getTotalDepenses() << endl;
	cout << "\t Liste de depenses : " << endl;
	for (int i = 0; i < nombreDepenses_; i++) {
		cout << "\t\t";
		depenses_[i]->afficherDepense();
	}

}*/
