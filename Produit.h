#ifndef PRODUIT_H
#define PRODUIT_H

#include <string>
#include <list>
#include <iostream>
#include "Composant.h"
#include "Compteur.h"

using namespace std;

class Produit {
private:
    string nom;
    list<Composant*> composants;
    static Compteur compteur;
public:
    Produit(const Produit& other);

    Produit(string nom);
    virtual ~Produit();

    int calculerPoids() const;
    int calculerPrix() const;

    void ajouterComposant(Composant* composant);

    string getNom() const;
    virtual string getDescription() const;
    int evaluerQualite() const;

    friend ostream& operator<<(ostream& os, const Produit& produit);
    virtual Produit* clone() const;

};

#endif //PRODUIT_H