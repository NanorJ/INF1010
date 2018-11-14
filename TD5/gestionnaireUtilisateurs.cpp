/********************************************
* Titre: Travail pratique #5 - gestionnaireUtilisateurs.cpp
* Date: 4 novembre 2018
* Auteur: Ryan Hardie
*******************************************/

#include "gestionnaireUtilisateurs.h"
#include "utilisateurPremium.h"
#include "utilisateurRegulier.h"

vector<double> getComptes() const{}
int estExistant(Utilisateur* utilisateur) const{}
void mettreAJourComptes(Utilisateur* payePar, double montant){}
pair<Utilisateur*, double>& getMax() const{}
pair<Utilisateur*, double>& getMin() const{}
Utilisateur * getUtilisateurSuivant(Utilisateur* utilisateur, double montant) const{} 
vector<pair<Utilisateur*, double>> getUtilisateursEntre(double borneInf, double borneSup) const{} 
GestionnaireUtilisateurs & setCompte(pair<Utilisateur*, double> p){}
