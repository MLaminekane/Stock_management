#include "Commande.h"
#include "Compteur.h"

int Commande::validerQuantite(int q) {
    if (q < 0) {
        return 0;
    } else if (q > 10) {
        return 10;
    } else {
        return q;
    }
}

Commande::Commande() : noCommande(0) {
    Compteur::ajouterConstructeur();
    for (int i = 0; i < 5; i++) {
        quantiteProduits[i] = 0;
    }
}

Commande::Commande(int noCommande, int qteProduits[]) : noCommande(noCommande) {
    for (int i = 0; i < 5; i++) {
        quantiteProduits[i] = validerQuantite(qteProduits[i]);
    }
    Compteur::ajouterConstructeur();
}

Commande::Commande(int noCommande) : noCommande(noCommande) {
    for (int i = 0; i < 5; i++) {
        quantiteProduits[i] = 0;
    }
    Compteur::ajouterConstructeur();
}

Commande::Commande(const Commande& other) : noCommande(other.noCommande) {
    for (int i = 0; i < 5; i++) {
        quantiteProduits[i] = other.quantiteProduits[i];
    }
    Compteur::ajouterConstructeurCopie();
}

Commande::~Commande() {
    Compteur::ajouterDestructeur();
}

int Commande::getQuantiteProduit(int idProduit) {
    if (idProduit >= 0 && idProduit < 5) {
        return quantiteProduits[idProduit];
    }
    return 0;
}

int Commande::getNoCommande() const {
    return noCommande;
}

ostream &operator<<(ostream &out, const Commande &commande) {
    out << "-------------------------------------" << endl;
    out << "COMMANDE" << endl;
    out << "No de commande : " << commande.noCommande << endl;

    for (int i = 0; i < 5; i++) {
        out << "- Produit demande {" << i << "} --> " << commande.quantiteProduits[i] << endl;
    }

    out << "-------------------------------------" << endl;
    return out;
}
