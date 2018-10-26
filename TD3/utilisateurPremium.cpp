/***********************************************************************************************
* Titre: Travail pratique #3 - utilisateurPremium.cpp
* Auteur: Nanor Janjikian (1901777) et Stéphanie Mansour (1935595)
* Date: 22 octobre 2018
* Description: Ce code contient les méthodes implémentées de utilisateurPremium.h
*************************************************************************************************/

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

//calcul le taux en fonction du nombre de dépenses 
void UtilisateurPremium::calculerTaux() {
	if (getNombreDepenses() < 10)
		taux_ = 0.05 - (0.01 * (getNombreDepenses() / 2));
	else taux_ = 0.0;
}
//operateur = utilise la surcharge de la classe Utilisateur
UtilisateurPremium& UtilisateurPremium::operator= (Utilisateur* utilisateur) { 
	if (this != utilisateur)
		static_cast<Utilisateur> (*utilisateur) = *this; //deep copy
	return *this;
}
//opérateur << de la classe de base et afficher le taux et le nombre de jours
ostream& operator << (ostream& os, const UtilisateurPremium& utilisateur) {
	os << "\t Utilisateur " << utilisateur.getNom() << " (Premium) "
		<< static_cast<Utilisateur>(utilisateur)
		<< "\t\t Autres informations : taux final de " << utilisateur.getTaux()*100 
		<< " % et son abonnement expire dans " << utilisateur.getJoursRestants() << " jours"
		<< endl;
	
	return os;
}
