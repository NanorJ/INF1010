<<<<<<< HEAD
/**************************************************************************
* Titre: Travail pratique #4 - depense.cpp
* Auteur: Nanor Janjikian (1901777) et Stephanie Mansour (1935595)
* Date: 19 novembre 2018
* Description: Ce code contient les méthodes implémentées de gestionnaireDepense.h
***************************************************************************/
#include "gestionnaireDepenses.h"
=======
#pragma once
#include "gestionnaireDepenses.h"

#include <algorithm>
#include <functional>

>>>>>>> 2e0a03edff7db9ac333d5ef6a06baa6c92ea4351

//Methode d'acces
double GestionnaireDepenses::getTotalDepenses() const {
	double totalDepenses = 0;
<<<<<<< HEAD

    for (Depense* depense : conteneur_)
		totalDepenses += depense->getMontant();
    return totalDepenses;
=======
	for (Depense* depense : conteneur_)
		totalDepenses += depense->getMontant();
	return totalDepenses;
>>>>>>> 2e0a03edff7db9ac333d5ef6a06baa6c92ea4351
}


