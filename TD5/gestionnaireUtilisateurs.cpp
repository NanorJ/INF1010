/********************************************
* Titre: Travail pratique #5 - gestionnaireUtilisateurs.cpp
* Date: 4 novembre 2018
* Auteur: Ryan Hardie
*******************************************/

#include "gestionnaireUtilisateurs.h"
#include "utilisateurPremium.h"
#include "utilisateurRegulier.h"
#include <vector>//no se 
#include <iterator>//iteratorsssssssss?

vector<double> GestionnaireUtilisateurs:: getComptes() const{
	vector<double>compte;
	unsigned int index = 0;
	//parcourir avec un iterator conteneur pour les utilisateurs
	for (auto it = conteneur_.begin(); it != conteneur_.end(); it++) {
		//on accede second: la valeur dedans
		compte.push_back(getElementParIndex(index).second);
		index++;
	}
	return compte;
};

int GestionnaireUtilisateurs:: estExistant(Utilisateur* utilisateur) const{
	//on veut parcourir le conteneur 
	auto fin = conteneur_.end();
	for (auto i = conteneur_.begin(); i != fin; i++) {
		//on cherche le first (cle) et verfie si sont pareilles
		if (i->first == utilisateur)
			return true;
	}
	return false;
};
void GestionnaireUtilisateurs::mettreAJourComptes(Utilisateur* payePar, double montant){
	//Verifier si payePar existe
	if (estExistant(payePar)) {

		//pour garder la variable payeur
		auto payeur = conteneur_.begin();
		auto it = conteneur_.begin();
		auto fin = conteneur_.end();
		for (it; it != fin; it++) {//parcourir le conteneur
			if (it->first == payePar)
				payeur = it;//variable locales d'ou la necessité de declarer payeur plus haut

		}
		//mis a jour des comptes
		double montantReparti = montant / getNombreElements();
		//lui rajouter a son compte le montant qu'il a paye moins le montant du groupe
		payeur->second += montant - montantReparti;

		//parcourir la boucle et retirer a tous les elements suf le payeur le montant reparti
		//auto fin = conteneur_.end();
		for (it = conteneur_.begin(); it != fin; it++)
		{
			//if (it->first != payePar)//si le champ Utilisateur de it est different  de l'adresse de paye par 
			if (it != payeur)//si l'iterateur it est different de l'iterateur payeur
				it->second -= montantReparti;
		}
		//rajouter a tous le monde sauf lui le montant reparti 
	}
}
pair<Utilisateur*, double>& GestionnaireUtilisateurs::getMax() const{

};
pair<Utilisateur*, double>& GestionnaireUtilisateurs::getMin() const{

};
Utilisateur * GestionnaireUtilisateurs::getUtilisateurSuivant(Utilisateur* utilisateur, double montant) const{

};
vector<pair<Utilisateur*, double>> GestionnaireUtilisateurs::getUtilisateursEntre(double borneInf, double borneSup) const{

};
GestionnaireUtilisateurs & GestionnaireUtilisateurs::setCompte(pair<Utilisateur*, double> p){

};
