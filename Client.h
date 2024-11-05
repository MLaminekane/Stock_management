//
// Created by mlami on 11/1/2024.
//

#ifndef CLIENT_H
#define CLIENT_H
#include <string>
#include <iostream>
#include <list>
#include "Commande.h"
#include "Reception.h"
#include "Compteur.h"
using namespace std;


class Client {
private:
    string nom;
    int seuilQualite;
    Commande* commandesA2024[4];
    Reception* reception;
    static Compteur compteur;
public:
    Client();
    Client(string nom, int seuilQualite);
    Client(const Client& client);
    virtual ~Client();

    void preparerCommande2024();
    Commande getCommande(int id) const;
    Reception* getReception() const;
    int getSeuilQualite() const;
    string getNom() const;
    void recevoirCommande(Reception* reception);
    void consommerProduits();
    int getSatisfactionProduit(int idProduits) const;

    friend ostream& operator<<(ostream& os, const Client& client);
};
ostream& operator<<(ostream& os, const Client& client);



#endif //CLIENT_H
