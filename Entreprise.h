//
// Created by mlami on 11/5/2024.
//

#ifndef ENTREPRISE_H
#define ENTREPRISE_H



#include "Commande.h"
#include "BonCommande.h"
#include "Entrepot.h"
#include "Fournisseur.h"
#include "Inventaire.h"
#include "ProduitA.h"
#include "ProduitB.h"
#include "ProduitC.h"
#include "ProduitD.h"
#include "Reception.h"
#include "RapportAssuranceQualite.h"
#include "Client.h"
#include "Compteur.h"

class Entreprise
{
private:
    Entrepot entrepot;
    Fournisseur fournisseur;
    Inventaire inventaire;
    static int numeroBonCommande;

    ProduitA* produireProduitA();
    ProduitB* produireProduitB();
    ProduitC* produireProduitC();
    ProduitD* produireProduitD();
    ProduitE* produireProduitE();
    void commanderComposantsFournisseur(int idComposant, int quantiteNecessaire);
    int genererNoBonCommande() { return numeroBonCommande++; }

public:
    Entreprise() { Compteur::ajouterConstructeur(); }
    ~Entreprise() { Compteur::ajouterDestructeur(); }
    Entreprise(const Entreprise& entreprise) = delete;

    BonCommande* traiterCommande(Commande& commande);
    Reception* recupererCommande(BonCommande* bonCommande);
    void validerSatisfaction(RapportAssuranceQualite& aq, Client& client);
};



#endif //ENTREPRISE_H
