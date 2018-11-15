/********************************************
* Titre: Travail pratique #5 - gestionnaireUtilisateurs.cpp
* Date: 4 novembre 2018
* Auteur: Ryan Hardie
*******************************************/

#include "gestionnaireUtilisateurs.h"
#include "utilisateurPremium.h"
#include "utilisateurRegulier.h"

vector<double> gestionnaireUtilisateurs:: getComptes() const{}
int gestionnaireUtilisateurs::estExistant(Utilisateur* utilisateur) const{}
voidgestionnaireUtilisateurs::mettreAJourComptes(Utilisateur* payePar, double montant){}
pair<Utilisateur*, double>& gestionnaireUtilisateurs::getMax() const{}
pair<Utilisateur*, double>& gestionnaireUtilisateurs::getMin() const{}
Utilisateur * gestionnaireUtilisateurs::getUtilisateurSuivant(Utilisateur* utilisateur, double montant) const{}
vector<pair<Utilisateur*, double>> gestionnaireUtilisateurs::getUtilisateursEntre(double borneInf, double borneSup) const{}
GestionnaireUtilisateurs & gestionnaireUtilisateurs::setCompte(pair<Utilisateur*, double> p){}
