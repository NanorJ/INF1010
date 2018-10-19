#include "utilisateurRegulier.h"


UtilisateurRegulier::UtilisateurRegulier(const string& nom, double interet, TypeUtilisateur type, bool estGroupe, double totalDepense): Utilisateur(nom, type, interet, totalDepense) {
	estGroupe_ = estGroupe;
}
UtilisateurRegulier::UtilisateurRegulier(const Utilisateur& utilisateur) : Utilisateur::Utilisateur(utilisateur) {
	 estGroupe_ = false;
}


bool UtilisateurRegulier::estGroupe() const{
	return estGroupe_;
}

//setters
void UtilisateurRegulier::setEtatGroupe(bool etat) {
	estGroupe_ = etat;
}

//surcharge
UtilisateurRegulier& UtilisateurRegulier::operator=(Utilisateur* utilisateur) {
	if (this != utilisateur)
		static_cast<Utilisateur> (*utilisateur) = *this; // ca copie les attibuts de utilisateurRegulier (this) dans utilisateur
	return *this;
}

ostream& operator<< (ostream& os, const UtilisateurRegulier& utilisateur){
	os << "l'utilisateur est groupe :" << utilisateur.estGroupe()
		<< endl;
	return os;
}

