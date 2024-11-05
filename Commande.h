#ifndef COMMANDE_H
#define COMMANDE_H
#include <iostream>
#include <list>
#include <string>
#include "Compteur.h"

using namespace std;

class Commande {
private:
    int noCommande;
    int quantiteProduits[5];
    int validerQuantite(int q);
public:
    Commande();
    Commande(int noCommande, int qteProduits[]);
    explicit Commande(int noCommande);

    virtual ~Commande();

    Commande(const Commande& other);
    int getQuantiteProduit(int idProduit);
    int getNoCommande() const;

    friend ostream& operator<<(ostream& out, const Commande& commande);
};

#endif //COMMANDE_H
