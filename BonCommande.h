#ifndef BONCOMMANDE_H
#define BONCOMMANDE_H

#include <iostream>
#include "Commande.h"
#include "Compteur.h"
#include "Entrepot.h"

class BonCommande {
private:
    int idBonCommande;
    Commande* commande;
    int quantiteProduits[5];

    void initialiser();
    static Compteur compteur;

public:
    BonCommande(int idBonCommande, Commande* commande);
    BonCommande(const BonCommande& bonCommande);
    BonCommande(const Entrepot& bonCommande);
    virtual ~BonCommande();

    void ajouterProduits(int quantite, int id);
    int getQuantiteProduits(int id);
    Commande* getCommande();
    int getIdBonCommande();

    friend ostream& operator<<(ostream& os, const BonCommande& bonCommande);
};
ostream& operator<<(ostream& os, const BonCommande& bonCommande);

#endif // BONCOMMANDE_H