#include "utilisateurPremium.h"

UtilisateurPremium::UtilisateurPremium(const string& nom, double interet, TypeUtilisateur type, unsigned int joursRestants, double taux, double totalDepense): Utilisateur(nom, type, interet, totalDepense) {
	joursRestants_ = joursRestants;
	taux_ = taux;
}

UtilisateurPremium::UtilisateurPremium(const Utilisateur& utilisateur): Utilisateur(utilisateur) {
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
	if (getNombreDepenses() < 10)
		taux_ = 0.05 - (0.01 * (getNombreDepenses() / 2));
	else taux_ = 0.0;
}

UtilisateurPremium& UtilisateurPremium::operator= (Utilisateur* utilisateur) { //might cause an error
	if (this != utilisateur)
		static_cast<Utilisateur> (*utilisateur) = *this; //deep copy
	return *this;
}

ostream& operator << (ostream& os, const UtilisateurPremium& utilisateur) {
	os << "Utilisateur : " << utilisateur.getNom() << "(Premium)"
		<< static_cast<Utilisateur>(utilisateur)
		<< "Le taux final est de : " << utilisateur.getTaux()
		<< "Il reste " << utilisateur.getJoursRestants() << " jours a son abonnement. \n"
		<< endl;
	return os;
}
