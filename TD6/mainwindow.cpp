#include <QAction>
#include <QMenu>
#include <QMenuBar>
#include <QStyle>
#include <QKeySequence>
#include <QDebug>
#include <QPushButton>
#include <QMessageBox>
#include <QRadioButton>
#include <QButtonGroup>
#include <QComboBox>
#include <QSlider>
#include <QListWidget>
#include <QListWidgetItem>
#include <QLineEdit>
#include <QLabel>
#include <QFrame>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <list>
#include <QDoubleValidator>

#include <typeinfo>
#include <string>



#include "mainwindow.h"
#include "ui_mainwindow.h"


using namespace std;

Q_DECLARE_METATYPE(Utilisateur*)
Q_DECLARE_METATYPE(Depense*)
Q_DECLARE_METATYPE(Transfert*)

MainWindow::MainWindow( Groupe* groupe, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    groupe_ = groupe;
    setup();
}

MainWindow::~MainWindow()
{

}

void MainWindow::setup(){
   //setMenu();
   setUI();
   //chargerUtilisateurs();
   //chargerDepenses();
   //nettoyerVue();
}

void MainWindow::setMenu() {
    // On crée un bouton 'Exit'

    // On ajoute un raccourci clavier qui simulera l'appui sur ce bouton (Ctrl+Q)

    // On connecte le clic sur ce bouton avec l'action de clore le programme

    // On crée un nouveau menu 'File'

    // Dans lequel on ajoute notre bouton 'Exit'


}

void MainWindow::setUI(){

    ///selecteur pour les utilisateurs et connect approprie

    //liste des depenses
    QLabel* utilisateursLabel = new QLabel;
    utilisateursLabel->setText("Utilisateurs : ");
    listeDepenses_ = new QListWidget(this);
    listeDepenses_->setSortingEnabled(true);
    //connect selection depense


    //liste des utilisateurs
    QLabel* depensesLabel = new QLabel;
    depensesLabel->setText("Depenses : ");
    listeUtilisateurs_ = new QListWidget(this);
    listeUtilisateurs_->setSortingEnabled(true);
    //Connect selection utilisateur



    ///Bouton equilibrer les comptes
    ///etablir le connect qui équilibre les comptes et affiche les transferts

    ///Bouton afficher comptes
    ///établir le connect qui affiche les comptes


    //Layout des deux bouttons
    QHBoxLayout* bouttonsComptesLayout = new QHBoxLayout;
    bouttonsComptesLayout->addWidget(boutonAfficherComptes_);
    bouttonsComptesLayout->addWidget(boutonEquilibrerComptes_);

    //label du nom
     QLabel* nomLabel = new QLabel;
     nomLabel->setText("Depense (nom) : ");
     editeurNomDepense_ = new QLineEdit;

     QHBoxLayout* nomLayout = new QHBoxLayout;
     nomLayout->addWidget(nomLabel);
     nomLayout->addWidget(editeurNomDepense_);

    //Label du lieu
     QLabel* lieuLabel = new QLabel;
     lieuLabel->setText("Lieu : ");
     editeurLieu_ = new QLineEdit;

     QHBoxLayout* lieuLayout = new QHBoxLayout;
     lieuLayout->addWidget(lieuLabel);
     lieuLayout->addWidget(editeurLieu_);

    //label du prix
     QLabel* montantLabel = new QLabel;
     montantLabel->setText("Montant : ");
     editeurMontant_ = new QLineEdit;

     QHBoxLayout* montantLayout = new QHBoxLayout;
     montantLayout->addWidget(montantLabel);
     montantLayout->addWidget(editeurMontant_);

     //label du payer Par
     QLabel* payeParLabel = new QLabel;
     payeParLabel->setText("Paye Par (Nom): ");
     editeurPayePar_ = new QLineEdit;

     QHBoxLayout* payeParLayout = new QHBoxLayout;
     payeParLayout->addWidget(payeParLabel);
     payeParLayout->addWidget(editeurPayePar_);


     ///bouton ajout de depense
     ///connect approprie


     //ligne seprant les ajouts de depenses
     //et d'utilisateurs
     QFrame* horizontaleFrameLine = new QFrame;
     horizontaleFrameLine->setFrameShape(QFrame::HLine);

    //nom utilisateur
     QLabel* nomUtilisateurLabel = new QLabel;
     nomUtilisateurLabel->setText("Nom (Utilisateur) : ");
     editeurNomUtilisateur_ = new QLineEdit;

     QHBoxLayout* nomUtilisateurLayout = new QHBoxLayout;
     nomUtilisateurLayout->addWidget(nomUtilisateurLabel);
     nomUtilisateurLayout->addWidget(editeurNomUtilisateur_);

     //jours restanst dans le cas de premium
     QLabel* joursRestantsLabel = new QLabel;
     joursRestantsLabel->setText("Nombre de jours restants : ");
     editeurJoursRestants_ = new QLineEdit;

     QHBoxLayout* joursRestantsLayout = new QHBoxLayout;
     joursRestantsLayout->addWidget(joursRestantsLabel);
     joursRestantsLayout->addWidget(editeurJoursRestants_);

     //Adresse interac
     QLabel* interacLabel = new QLabel;
     interacLabel->setText("Interac : ");
     editeurInterac_ = new QLineEdit;

     QHBoxLayout* interacLayout = new QHBoxLayout;
     interacLayout->addWidget(interacLabel);
     interacLayout->addWidget(editeurInterac_);

     //idPaypal
     QLabel* labelPaypal = new QLabel;
     labelPaypal->setText("ID PayPal : ");
     editeurPaypal_ = new QLineEdit;

     QHBoxLayout* paypalLayout = new QHBoxLayout;
     paypalLayout->addWidget(labelPaypal);
     paypalLayout->addWidget(editeurPaypal_);

     //boutons radio pour definit le type de transfert preferentiel
    QRadioButton* boutonRadioInterac = new QRadioButton("&Interac", this);
    boutonsRadioMethodeDePaiement_.push_back(boutonRadioInterac);

    QRadioButton* boutonRadioPayPal = new QRadioButton("&Paypal", this);
    boutonsRadioMethodeDePaiement_.push_back(boutonRadioPayPal);

    QHBoxLayout* boutonsRadioPaiementLayout = new QHBoxLayout;
    boutonsRadioPaiementLayout->addWidget(boutonRadioInterac);
    boutonsRadioPaiementLayout->addWidget(boutonRadioPayPal);

     //Boutons radio pour definir le type dutilisateur
     QRadioButton* utilisateurPremiumBouton = new QRadioButton("&UtilisateurPremium", this);
     boutonsRadioUtilisateurs_.push_back(utilisateurPremiumBouton);

     QRadioButton* utilisateurRegulierBouton = new QRadioButton("&UtilisateurRegulier", this);
     boutonsRadioUtilisateurs_.push_back(utilisateurRegulierBouton);

     QButtonGroup* typeUtilisateurGroupeBoutons = new QButtonGroup;
     typeUtilisateurGroupeBoutons->addButton(utilisateurPremiumBouton);
     typeUtilisateurGroupeBoutons->addButton(utilisateurRegulierBouton);

     QHBoxLayout* typeUtilisateurLayout = new QHBoxLayout;
     typeUtilisateurLayout->addWidget(utilisateurPremiumBouton);;
     typeUtilisateurLayout->addWidget(utilisateurRegulierBouton);

     //Boutton pour l'ajout d'un utilisateur
     //et connect


     //label comptes
     QLabel* labelComptes = new QLabel;
     labelComptes->setText("Comptes : ");

     //Affichage Comptes 
     comptes_ = new QListWidget(this);
     comptes_->setSortingEnabled(true);

     //label transferts
     QLabel* labelTransferts = new QLabel;
     labelTransferts->setText("Transferts a effectuer pour equilibrer : ");


     //Affichage transferts
     listeTransferts_ = new QListWidget();
     listeTransferts_->setSortingEnabled(true);
    
    //layout gauche
    QVBoxLayout* layoutHautGauche = new QVBoxLayout;

    layoutHautGauche->addWidget(utilisateursLabel);
    layoutHautGauche->addWidget(listeUtilisateurs_);
    layoutHautGauche->addWidget(depensesLabel);
    layoutHautGauche->addWidget(listeDepenses_);
    layoutHautGauche->addLayout(bouttonsComptesLayout);

    //layout droite
     QVBoxLayout* layoutHautDroite = new QVBoxLayout;

     layoutHautDroite->addLayout(nomUtilisateurLayout);
     layoutHautDroite->addLayout(joursRestantsLayout);
     layoutHautDroite->addLayout(boutonsRadioPaiementLayout);
     layoutHautDroite->addLayout(interacLayout);
     layoutHautDroite->addLayout(paypalLayout);
     layoutHautDroite->addLayout(typeUtilisateurLayout);
     //layoutHautDroite->addWidget(boutonAjouterUtilisateur_);
     layoutHautDroite->addWidget(horizontaleFrameLine);
     layoutHautDroite->addLayout(nomLayout);
     layoutHautDroite->addLayout(lieuLayout);
     layoutHautDroite->addLayout(montantLayout);
     layoutHautDroite->addLayout(payeParLayout);
     //layoutHautDroite->addWidget(boutonAjouterDepense_);


    //ligne verticale
    QFrame* verticalFrameLine = new QFrame;
    verticalFrameLine->setFrameShape(QFrame::VLine);

    //Layout du haut
    QHBoxLayout* layoutHaut = new QHBoxLayout;
    layoutHaut->addLayout(layoutHautGauche);
    layoutHaut->addWidget(verticalFrameLine);
    layoutHaut->addLayout(layoutHautDroite);

    //layout bas gauche
    QVBoxLayout* layoutBasGauche = new QVBoxLayout;
    layoutBasGauche->addWidget(labelComptes);
    layoutBasGauche->addWidget(comptes_);

    //layout bas droite
    QVBoxLayout* layoutBasDroite = new QVBoxLayout;
    layoutBasDroite->addWidget(labelTransferts);
    layoutBasDroite->addWidget(listeTransferts_);

    //ligne verticale
    QFrame* verticalBasFrameLine = new QFrame;
    verticalBasFrameLine->setFrameShape(QFrame::VLine);

    //layout bas
    QHBoxLayout* layoutBas = new QHBoxLayout;
    layoutBas->addLayout(layoutBasGauche);
    layoutBas->addWidget(verticalBasFrameLine);
    layoutBas->addLayout(layoutBasDroite);

    //ligne horizontale
    QFrame* horizontaleBasFrameLine = new QFrame;
    horizontaleBasFrameLine->setFrameShape(QFrame::HLine);

    //Main layout
    QVBoxLayout* mainLayout = new QVBoxLayout;
    mainLayout->addLayout(layoutHaut);
    mainLayout->addWidget(horizontaleBasFrameLine);
    mainLayout->addLayout(layoutBas);

    QWidget* widget = new QWidget;
    widget->setLayout(mainLayout);

    setCentralWidget(widget);

    string title = "Bienvenue sur PolyCount pour l'evenement : " + groupe_->getNom() + " !";
    setWindowTitle(title.c_str());
}

void MainWindow::afficherMessage(QString msg) {

}

void MainWindow::chargerUtilisateurs(){
    //vider la liste

        //recuperer le pointeur vers utilisateur


        //ajouter en tant qu'item a la liste :
        //Nom affiche et pointeur stocke



}

void MainWindow::chargerDepenses(){
    //voir charger liste utilisateurs

}

//Fonction qui modifie UI quand on selectionne un utilisateur
void MainWindow::selectionnerUtilisateur(QListWidgetItem* item){
    //nettoyer la vue

    //afficher chaque champs avec la valeur appropriee
    ///Attention : si user regulier ne pas afficher le nombre de jours

    //Desactiver le boutton d'ajout


}
//Fonction qui modifie UI quand on selectionne une depense
void MainWindow::selectionnerDepense(QListWidgetItem* item){
    //nettoyer la vue

    //afficher chaque champs avec la valeur appropriee

    //desactiver le boutond d'ajout
}

void MainWindow::nettoyerVue() {
    //reactive tous les champs sans valeurs dedans

    //check les boutons radios
}

void MainWindow::ajouterDepense() {


}

//slot pour l'ajout d'un nouvel utilisateur
void MainWindow::ajouterUtilisateur(){


}
void MainWindow::chargerTransferts() {

}
void MainWindow::equilibrerComptes(){

}

void MainWindow::afficherComptes() {

}

void MainWindow::chargerComptes(){

}

bool MainWindow::filtrerMasque(Utilisateur* utilisateur) {
    return true;
}


void MainWindow::filtrerListe(int index){

}
