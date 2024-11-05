#include "Fournisseur.h"
#include <random>
#include <ctime>

Compteur Fournisseur::compteur;

void Fournisseur::initializer() {
    for(int i = 0; i < 5; i++) {
        quantiteComposants[i] = 1000;
    }
}

Fournisseur::Fournisseur() {
    initializer();
    compteur.ajouterConstructeur();
}

Fournisseur::Fournisseur(const Fournisseur& f) {
    initializer();
    compteur.ajouterConstructeurCopie();
}

Fournisseur::~Fournisseur() {
    compteur.ajouterDestructeur();
}

int random(int min, int max) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(min, max);
    return dis(gen);
}

Composant1* Fournisseur::produireComposant1() {
    if (quantiteComposants[0] <= 0) return nullptr;
    quantiteComposants[0]--;
    int qualite = random(90, 100);
    int prix = 30 + (100 - qualite);
    return new Composant1(qualite, prix);
}

Composant2* Fournisseur::produireComposant2() {
    if (quantiteComposants[1] <= 0) return nullptr;
    quantiteComposants[1]--;
    int qualite = random(93, 99);
    int prix = random(33, 37);
    return new Composant2(qualite, prix);
}

Composant3* Fournisseur::produireComposant3() {
    if (quantiteComposants[2] <= 0) return nullptr;
    quantiteComposants[2]--;
    int prix = random(38, 45);
    return new Composant3(prix);
}

Composant4* Fournisseur::produireComposant4() {
    if (quantiteComposants[3] <= 0) return nullptr;
    quantiteComposants[3]--;
    int qualite = random(80, 100);
    return new Composant4(qualite);
}

Composant5* Fournisseur::produireComposant5() {
    if (quantiteComposants[4] <= 0) return nullptr;
    quantiteComposants[4]--;
    int qualite = random(95, 100);
    int variation = random(-5, 5);
    int prix = 33 + (100 - qualite);
    return new Composant5(qualite, variation, prix);
}

std::list<Composant*> Fournisseur::commanderComposant(int idComposant, int quantite) {
    std::list<Composant*> composants;
    for (int i = 0; i < quantite; ++i) {
        Composant* composant = nullptr;
        switch (idComposant) {
            case 0: composant = produireComposant1(); break;
            case 1: composant = produireComposant2(); break;
            case 2: composant = produireComposant3(); break;
            case 3: composant = produireComposant4(); break;
            case 4: composant = produireComposant5(); break;
        }
        if (composant) {
            composants.push_back(composant);
        }
    }
    return composants;
}