#pragma once
#include "gestionnaireDepenses.h"

#include <algorithm>
#include <functional>


double GestionnaireDepenses::getTotalDepenses() const {
	double totalDepenses = 0;
	for (Depense* depense : conteneur_)
		totalDepenses += depense->getMontant();
	return totalDepenses;
}


