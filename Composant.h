//
// Created by mlami on 10/17/2024.
//

#ifndef COMPOSANT_H
#define COMPOSANT_H
#include <string>

#include "Compteur.h"
using namespace std;

class Composant {
private:
    string nom;
    int poids;
    int qualite;
    int prix;
    static Compteur compteur;

public:
    string getNom();
    int getPoids();
    int getQualite();
    int getPrix();
    Composant(string nom, int poids);
    Composant(string nom, int poids, int prix);
    Composant(const Composant&);
    virtual ~Composant();
    virtual Composant* clone() const;
protected:
    Composant(string nom, int poids, int qualite, int prix);
};

#endif //COMPOSANT_H