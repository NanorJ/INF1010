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
double DepenseGroupe::getMontantPersonnel() const {
	if (nombreParticipants_ == 0)
		return 0.0;
	else
		return (getMontant()/nombreParticipants_);
}

void DepenseGroupe::setNombreParticipants(unsigned int nombre) {
	nombreParticipants_ = nombre;
}
 
ostream& operator<<(ostream& os, const DepenseGroupe& depense) {
	os << "\n\t\t Depense de groupe :" << static_cast<Depense> (depense)
		<< " fait par " << depense.getNombreParticipants() << " personne"
		<< " (soit d'un montant de " << depense.getMontantPersonnel() << "$ par personne)";

	return os;
}