/********************************************
* Titre: Travail pratique #2 - utilisateur.cpp
* Date: 16 septembre 2018
* Auteur: Wassim Khene & David Dratwa 
*******************************************/

#include "utilisateur.h"

// Constructeurs



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

void Utilisateur::calculerTotalDepenses() {
	
}

Utilisateur& Utilisateur::operator=(Utilisateur * utilisateur)
{
	
}


void Utilisateur::ajouterInteret(double montant) {
	interet_ += montant;
}

Utilisateur& Utilisateur::operator+=(Depense* depense) {
	
}

// Methode d'affichage
ostream& operator<<(ostream& os, const Utilisateur& utilisateur)

{

}
