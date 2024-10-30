//
// Created by mlami on 10/17/2024.
//

#ifndef COMPTEUR_H
#define COMPTEUR_H



class Compteur {
private:
    static int Constructeur;
    static int ConstructeurCopie;
    static int Destructeur;

public:
    static void ajouterConstructeur();
    static void ajouterConstructeurCopie();
    static void ajouterDestructeur();
    static int getNbConstructeurs();
    static int getNbConstructeursCopie();
    static int getNbDestructeurs();
    Compteur() = default;
    virtual ~Compteur() = default;
};
#endif //COMPTEUR_H