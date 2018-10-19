#include "utilisateurPremium.h"

UtilisateurPremium::UtilisateurPremium(const string& nom, double interet, TypeUtilisateur type, unsigned int joursRestants, double taux, double totalDepense): Utilisateur(nom, type, interet, totalDepense) {
	joursRestants_ = joursRestants;
	taux_ = taux;
}

UtilisateurPremium::UtilisateurPremium(const Utilisateur& utilisateur): Utilisateur::Utilisateur(utilisateur) {
	taux_ = TAUX_REGULIER;
	joursRestants_ = 30;
}

unsigned int UtilisateurPremium::getJoursRestants() const {
	return joursRestants_;
}

double UtilisateurPremium::getTaux() const {
	return taux_;
}

void UtilisateurPremium::setJoursRestants(unsigned int joursRestants) {
	joursRestants_ = joursRestants;
}

void UtilisateurPremium::calculerTaux() {
	unsigned int count = Utilisateur::getNombreDepenses();
	if (count == 2)
		taux_ -= 0.01;
}

UtilisateurPremium& UtilisateurPremium::operator= (Utilisateur* utilisateur) {
	if (this != utilisateur)
		static_cast<Utilisateur> (*utilisateur) = *this; //deep copy
	return *this;
}

ostream& operator << (ostream& os, const UtilisateurPremium& utilisateur) {
	os << "Le taux est de : " << utilisateur.getTaux()
		<< "le nombre de jours restants est de : " << utilisateur.getJoursRestants()
		<< endl;
	return os;
}
