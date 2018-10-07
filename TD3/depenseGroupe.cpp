/********************************************
* Titre: Travail pratique #2 - depenseGroupe.cpp
*
*******************************************/

#include "depenseGroupe.h"

DepenseGroupe::DepenseGroupe(const string& nom, double montant, const string& lieu, unsigned int nombreParticipants, TypeDepense type) : Depense(nom,montant,lieu,type),nombreParticipants_(nombreParticipants) {
	
}
//Implémentation du constructeur par copie
DepenseGroupe::DepenseGroupe (const DepenseGroupe& depense) : Depense(depense),nombreParticipants_(depense.nombreParticipants_)
{

}

//Implémentation du constructeur par copie
Depense::Depense(const Depense& depense) :
	lieu_(nullptr), nom_(depense.nom_), montant_(depense.montant_)
{
	lieu_ = new string(*(depense.lieu_));
}
//getters
unsigned int DepenseGroupe::getNombreParticipants() const {

	return nombreParticipants_;
}
double DepenseGroupe::getMontantPersonnel() const {

	if (nombreParticipants_ == 0)
		return 0;

	return Depense::getMontant();
}
//setters
void DepenseGroupe::setNombreParticipants(unsigned int nombre) {
	nombreParticipants_ = nombre;
}

//implémentation de la methode d'affichage (surchage)
ostream& operator<<(ostream &os, const DepenseGroupe& depense) {
	os << "Achat : " << depense.getNom()
		<< " Prix : " << depense.getMontant()
		<< "Nombre de Personnes : " << depense.getNombreParticipants()
		<< "Montant personnel : " << depense.getMontantPersonnel()
		<< endl;

	return os;
}
