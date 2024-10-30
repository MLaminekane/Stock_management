//
// Created by mlami on 10/17/2024.
//

#ifndef INVENTAIRE_H
#define INVENTAIRE_H

#include <list>
#include "Compteur.h"
#include "Produit.h"
#include "ProduitA.h"
#include "ProduitB.h"
#include "ProduitC.h"
#include "ProduitD.h"
#include "ProduitE.h"

using namespace std;

class Inventaire {
private:
    list<Produit*> produits[5];
    void ajouterProduits(Produit* produit, int idProduit);
    static Compteur compteur;

public:
    Inventaire();
    Inventaire(const Inventaire&);
    virtual ~Inventaire();
    virtual Inventaire* clone() const;
    void ajouterProduit(ProduitA* produit);
    void ajouterProduit(ProduitB* produit);
    void ajouterProduit(ProduitC* produit);
    void ajouterProduit(ProduitD* produit);
    void ajouterProduit(ProduitE* produit);

    Produit* recupererProduit(int idProduit);
};

#endif // INVENTAIRE_H
