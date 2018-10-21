/***************************************************************************************************
* Titre: Travail pratique #3 - depenseIndividuelle.cpp
* Auteur: Nanor Janjikian (1901777) et Stéphanie Mansour (1935595)
* Date: 22 octobre 2018
* Description: Ce code contient les méthodes implémentées de depenseIndividuelle.h
****************************************************************************************************/

#include "depenseIndividuelle.h"

DepenseIndividuelle::DepenseIndividuelle(const string & nom, double montant, const string& lieu) : Depense(nom, montant, lieu, individuelle)
{}

ostream& operator<< (ostream& os, const DepenseIndividuelle& depense) {
	os << "Depense individuelle : " << endl
		<< "\t" << static_cast<Depense> (depense);
	return os; 
 }