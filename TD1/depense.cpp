/***********************************************************************
* Titre: Travail pratique #1 - depense.cpp
* Date: 24 janvier 2018
* Auteur: Nanor Janjikian (1901777) et Stéphanie Mansour (1935595)
* Desciption: Ce code contient les méthodes implémentées de depense.h
************************************************************************/
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

#include "depense.h"
//implémentation du constructeur par défault
Depense::Depense()
{
	titre_ = "unknown";
	montant_ = 0.0;
}
//implémentation du constructeur par paramètres
//ajout de const avant le titre parce qu'il est constant (ne change pas)
Depense::Depense(const string& titre, double montant)
{
	titre_ = titre;
	montant_ = montant;
}
//implémentation des méthodes d'accès (const : on est en train d'accéder)
string Depense::getTitre() const {
	return titre_;
}

double Depense::getMontant() const {
	return montant_;
}
//implémentation des méthodes de modifications 
void Depense::setTitre(const string& titre) {
	titre_ = titre;
}

void Depense::setMontant(double montant) {
	montant_ = montant;
}
//implémentation du méthode affichage (const parce que les variables ne changent pas, juste de l'affichage)
void Depense::afficherDepense() const {
	cout << "Achat : " << titre_ << " Prix : " << montant_ << " ; "<< endl;
}