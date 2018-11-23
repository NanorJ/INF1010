/********************************************
* Titre: Travail pratique #5 - gestionnaireUtilisateurs.h
* Date: 4 novembre 2018
* Auteur: Ryan Hardie
*******************************************/


#include "utilisateur.h"
#include "gestionnaireGenerique.h"
#include "foncteur.h"
#include <iterator>
#include "exceptionutilisateurinexistant.h"

#include <map>

class GestionnaireUtilisateurs : public GestionnaireGenerique < Utilisateur*, map<Utilisateur*, double>, pair< Utilisateur*, double>, AjouterUtilisateur > {
public:
	vector<double> getComptes() const;
	pair<Utilisateur*, double>& getMax() const;
	pair<Utilisateur*, double>& getMin() const;
	Utilisateur* getUtilisateurSuivant(Utilisateur* utilisateur, double montant) const;
	vector<pair<Utilisateur*, double>> getUtilisateursEntre(double borneInf, double borneSup) const;
    int getNbUtilisateurs() const;

	bool estExistant(Utilisateur* utilisateur) const;
    Utilisateur* trouverUtilisateurParNom(const string& nom) const;
	GestionnaireUtilisateurs& setCompte(pair<Utilisateur*, double> p);
	void mettreAJourComptes(Utilisateur* payePar, double montant);
};
