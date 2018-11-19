/********************************************
 * Titre: Travail pratique #5 - foncteur.h
 * Auteur : Nanor Janjikian (1901777) et Stephanie Mansour (1935595)
 * Date: 19 novembre 2018
 *******************************************/
#pragma once

#include "depense.h"
#include "utilisateur.h"
#include "gestionnaireGenerique.h"

#include <algorithm>

class GestionnaireDepenses : public GestionnaireGenerique<Depense*, vector<Depense*>, Depense*, AjouterDepense> 
{
	public:
        //Methode d'acces
		double getTotalDepenses() const;
};
