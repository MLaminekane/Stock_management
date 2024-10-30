//
// Created by mlami on 10/17/2024.
//

#ifndef COMPOSANTT2_H
#define COMPOSANTT2_H
#include "Composant.h"
#include "Compteur.h"


class Composant2 : public Composant {
private:
    static Compteur compteur;
public:
    Composant2(int qualite, int prix) : Composant("COMPOSANT #2", 7, 96, prix) {
        Compteur::ajouterConstructeur();
    }
    Composant2(const Composant2& composant2) : Composant(composant2) {
        Compteur::ajouterConstructeurCopie();
    }
    ~Composant2() {
        Compteur::ajouterDestructeur();
    }

};



#endif //COMPOSANTT2_H
