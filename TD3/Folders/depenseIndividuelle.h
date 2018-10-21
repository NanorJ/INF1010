/********************************************************************************
* Titre: Travail pratique #3 - depenseIndividuelle.h
* Auteur: Nanor Janjikian (1901777) et Stéphanie Mansour (1935595)
* Date: 22 octobre 2018
*********************************************************************************/

#ifndef DEPENSE_INDIVIDUELLE_H
#define DEPENSE_INDIVIDUELLE_H

#include "depense.h"
#include "string"
#include <iostream>

using namespace std; 

class DepenseIndividuelle : public Depense {

public :
	DepenseIndividuelle(const string & nom, double montant, const string& lieu);
	friend ostream& operator<< (ostream& os, const DepenseIndividuelle& depense); 
 
};

#endif // !DEPENSE_INDIVIDUELLE_H

