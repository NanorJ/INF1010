#include "depenseGroupe.h"


DepenseGroupe::DepenseGroupe(const string& nom, double montant, const string& lieu, TypeDepense type, unsigned int nombreParticipants) : Depense(nom, montant, lieu) {
	nombreParticipants_ = nombreParticipants;
	Depense::setType(groupe);
}

DepenseGroupe::DepenseGroupe(const DepenseGroupe& depense): Depense::Depense(depense)
{
	nombreParticipants_ = depense.nombreParticipants_;
}

 
unsigned int DepenseGroupe::getNombreParticipants() const {
	return nombreParticipants_;

}
double DepenseGroupe::getMontantPersonnel() const {
	if (nombreParticipants_ == 0)
		return 0;
	else
		return Depense::getMontant();
}

void DepenseGroupe::setNombreParticipants(unsigned int nombre) {
	nombreParticipants_ = nombre;
}


 
ostream& operator<<(ostream& os, const DepenseGroupe& depense) {
	os << static_cast<Depense> (depense) << "\n"
		<< "Nombre de personne implique ; " << depense.getNombreParticipants()
		<< "Montant Personnel : " << depense.getMontantPersonnel()
		<< endl;

	return os;
}