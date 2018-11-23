/********************************************
* Titre: Travail pratique #5 - gestionnaireDepenses.cpp
* Date: 4 novembre 2018
* Auteur: Ryan Hardie
*******************************************/

#include "gestionnaireDepenses.h"

#include <algorithm>
#include <functional>

double GestionnaireDepenses::getTotalDepenses()
{
	double totalDepenses = 0;
	for (int i = 0; i < conteneur_.size(); i++) {
		totalDepenses += conteneur_[i]->getMontant();
	}
	return totalDepenses;
}

int GestionnaireDepenses::getNombreDepense() const{
    return conteneur_.size();
}


