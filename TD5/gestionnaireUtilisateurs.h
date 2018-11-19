/********************************************
* Titre: Travail pratique #5 - gestionnaireUtilisateurs.h
* Auteur: Ryan Hardie
* Modifie par : Nanor Janjikian (1901777) et Stephanie Mansour (1935595)
* Date: 19 novembre 2018
*******************************************/
#include "utilisateur.h"
#include "gestionnaireGenerique.h"

#include <algorithm>
#include <iterator>

using namespace std::placeholders;

class GestionnaireUtilisateurs : public GestionnaireGenerique <Utilisateur*, map<Utilisateur*, double>, pair<Utilisateur*, double>, AjouterUtilisateur> {
	public:
		bool estExistant(Utilisateur* utilisateur) const;
    
        //Methode d'acces
        vector<double> getComptes() const;
    
		pair<Utilisateur*, double>& getMax() const;
    
		pair<Utilisateur*, double>& getMin() const;
    
		Utilisateur * getUtilisateurSuivant(Utilisateur* utilisateur, double montant) const;
    
		vector<pair<Utilisateur*, double>> getUtilisateursEntre(double borneInf, double borneSup) const;
    
        //Methode de modification
		GestionnaireUtilisateurs & setCompte(pair<Utilisateur*, double> p);
    
        void mettreAJourComptes(Utilisateur* payePar, double montant);
	
};
