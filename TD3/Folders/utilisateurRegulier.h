/*************************************************************************************
* Titre: Travail pratique #3 - utilisateurRegulier.h
* Auteur: David Dratwa
* Modifié par: Nanor Janjikian (1901777) et Stéphanie Mansour (1935595)
* Date: 22 octobre 2018
**************************************************************************************/

#ifndef UTILISATEUR_REGULIER_H
#define UTILISATEUR_REGULIER_H

#include "utilisateur.h"

class UtilisateurRegulier : public Utilisateur {
public : 

	//constructeurs 
	UtilisateurRegulier(const string& nom = "", double interet = 0.0, TypeUtilisateur type = Regulier, bool estGroupe = false, double totalDepense = 0.0);
	UtilisateurRegulier(const Utilisateur& utilisateur); 


	//getters
	bool estGroupe() const; 
	 
	//setters
	void setEtatGroupe(bool etat); 
	

	//surcharge
	UtilisateurRegulier& operator=(Utilisateur* utilisateur);
	friend ostream& operator<< (ostream& os, const UtilisateurRegulier& utilisateur); 
	
	private :
	bool estGroupe_; 	
};

#endif // !UTILISATEUR_REGULIER_H
