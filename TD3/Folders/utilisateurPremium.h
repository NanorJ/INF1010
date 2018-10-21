/*********************************************************************************************
* Titre: Travail pratique #3 - utilisateurPremium.h
* Auteur: David Dratwa
* Modifié par: Nanor Janjikian (1901777) et Stéphanie Mansour (1935595)
* Date: 22 octobre 2018
**********************************************************************************************/

#ifndef UTILISATEUR_PREMIUM_H
#define UTILISATEUR_PREMIUM_H

#include "utilisateur.h"

class UtilisateurPremium : public Utilisateur {
public :

	//constructeurs 
	UtilisateurPremium(const string& nom = "", double interet = 0.0, TypeUtilisateur type = Premium, unsigned int joursRestants = 30, double taux = 0.05, double totalDepense = 0.0);
	UtilisateurPremium(const Utilisateur& utilisateur); 


	//getters
	unsigned int getJoursRestants() const; 
	double getTaux() const; 

	//setters 
	void setJoursRestants(unsigned int joursRestants); 

	//methode de calcul 
	void calculerTaux(); 

	//operateurs
	UtilisateurPremium& operator= (Utilisateur* utilisateur); 

	friend ostream& operator << (ostream& os, const UtilisateurPremium& utilisateur); 

private : 
	unsigned int joursRestants_; 
	double taux_; 
};

#endif 
