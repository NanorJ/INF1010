/********************************************************************************************
* Titre: Travail pratique #3 - depenseGroupe.cpp
* Auteur: Nanor Janjikian (1901777) et Stéphanie Mansour (1935595)
* Date: 22 octobre 2018
* Description: Ce code contient les méthodes implémentées de depenseGroupe.h
**********************************************************************************************/

#include "depenseGroupe.h"

DepenseGroupe::DepenseGroupe(const string& nom, double montant, const string& lieu, TypeDepense type, unsigned int nombreParticipants) : Depense(nom, montant, lieu) {
	nombreParticipants_ = nombreParticipants;
	setType(groupe);
}

DepenseGroupe::DepenseGroupe(const DepenseGroupe& depense): Depense(depense) { 
	nombreParticipants_ = depense.nombreParticipants_;
}
 
unsigned int DepenseGroupe::getNombreParticipants() const {
	return nombreParticipants_;
}

//retourner le montant à payer par personne
double DepenseGroupe::getMontantPersonnel() const {
	if (nombreParticipants_ == 0)
		return 0.0;
	else
		return (getMontant()/nombreParticipants_);
}

void DepenseGroupe::setNombreParticipants(unsigned int nombre) {
	nombreParticipants_ = nombre;
}
 
//Surchage opérateur << pour afficher une dépense groupée
ostream& operator<<(ostream& os, const DepenseGroupe& depense) {
	os << "\t\t Depense de groupe :" << static_cast<Depense> (depense)
		<< " \t\t\t fait par : " << depense.getNombreParticipants() << " personnes"
		<< ", soit un montant de " << depense.getMontantPersonnel() << " $ par personne. \n";

	return os;
}