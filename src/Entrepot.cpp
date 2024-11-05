//
// Created by mlami on 10/30/2024.
//

#include "Entrepot.h"
void Entrepot::initializer() {
    for(int i = 0; i < 5; i++) {
        composants[i] = std::list<Composant*>();
    }
}
Entrepot::Entrepot()  {
    initializer();
    compteur.ajouterConstructeur();
}

Entrepot::Entrepot(const Entrepot &autre) {
    initializer();
    for (int i = 0; i < 5; ++i) {
        for (Composant *composant : autre.composants[i]) {
            composants[i].push_back(composant->clone());
        }
    }
    compteur.ajouterConstructeurCopie();
}

Entrepot::~Entrepot() {
    for (int i = 0; i < 5; ++i) {
        for (Composant *composant : composants[i]) {
            delete composant;
        }
    }
    compteur.ajouterDestructeur();
}



void Entrepot::ajouterComposant(Composant *composant, int id) {
    if (id >= 0 && id < 5) {
        composants[id].push_back(composant);
    }
}

void Entrepot::ajouterComposants(std::list<Composant *> listeComposants, int id) {
    for (Composant *composant : listeComposants) {
        ajouterComposant(composant, id);
    }
}

Composant * Entrepot::recupererComposant(int id) {
    if(composants[id].empty()) {
        return nullptr;
    }else {
        Composant *composant = composants[id].front();
        composants[id].pop_front();
        return composant;
    }
}

int Entrepot::getQuantiteComposants(int id) {
    return composants[id].size();
}
