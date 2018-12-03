/********************************************
* Titre: Travail pratique #5 - gestionnaireDepenses.h
* Date: 4 novembre 2018
* Auteur: Ryan Hardie
*******************************************/

#pragma once

#include "depense.h"
#include "gestionnaireGenerique.h"
#include "foncteur.h"

class GestionnaireDepenses : public GestionnaireGenerique<Depense*, vector<Depense*>, Depense*, AjouterDepense> {
public:
	double getTotalDepenses();
    int getNombreDepense() const;
};
