/**************************************************************************
* Titre: Travail pratique #4 - depense.cpp
* Auteur: Nanor Janjikian (1901777) et Stephanie Mansour (1935595)
* Date: 19 novembre 2018
* Description: Ce code contient les méthodes implémentées de gestionnaireDepense.h
***************************************************************************/
#include "gestionnaireDepenses.h"

//Methode d'acces
double GestionnaireDepenses::getTotalDepenses() const {
	double totalDepenses = 0;

    for (Depense* depense : conteneur_)
		totalDepenses += depense->getMontant();
    return totalDepenses;
}

