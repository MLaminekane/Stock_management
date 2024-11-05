//
// Created by mlami on 10/30/2024.
//

#ifndef ENTREPOT_H
#define ENTREPOT_H

#include <list>
#include "Composant.h"
#include "Compteur.h"


class Entrepot {
private:
    std::list<Composant*> composants[5];
    static Compteur compteur;
    void initializer();


public:
    Entrepot();
    virtual ~Entrepot();
    Entrepot(const Entrepot& autre);

    void ajouterComposants(std::list<Composant*> listeComposants, int id);
    void ajouterComposant(Composant* composant, int id);
    Composant* recupererComposant(int id);
    int getQuantiteComposants(int id);
};



#endif //ENTREPOT_H
