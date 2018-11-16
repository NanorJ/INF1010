#pragma once

#include "depense.h"
#include "utilisateur.h"
#include "gestionnaireGenerique.h"

#include <algorithm>
#include <functional>


double GestionnaireDepenses::getTotalDepenses() const {
	double totalDepenses = 0;
	for (int i = 0; i < getNombreElements(); i++) 
		totalDepenses += getElementParIndex(i)->getMontant();
	return totalDepenses;
}

