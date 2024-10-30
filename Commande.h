//
// Created by mlami on 10/17/2024.
//

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
    ~Commande();

    Commande(const Commande&);
    int getQuantiteProduit(int idProduit);
    int getNoCommande();

    friend ostream& operator<<(ostream& out, const Commande& commande);

};

#endif //COMMANDE_H