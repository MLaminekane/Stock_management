// Client.h (no changes here)

#include "Client.h"
#include "Compteur.h"

Client::Client() {
}

Client::Client(string nom, int seuilQualite) {
    Compteur::ajouterConstructeur();
    this->nom = nom;
    this->seuilQualite = seuilQualite;
    reception = nullptr;
    preparerCommande2024();
}

Client::Client(const Client &client) {
    this->nom = client.nom;
    this->seuilQualite = client.seuilQualite;
    this->reception = nullptr;
    for (int i = 0; i < 4; ++i) {
        if (client.commandesA2024[i] != nullptr) {
            this->commandesA2024[i] = new Commande(*client.commandesA2024[i]);
        } else {
            this->commandesA2024[i] = nullptr;
        }
    }
    Compteur::ajouterConstructeurCopie();
}

Client::~Client() {
    for (int i = 0; i < 4; i++) {
        delete commandesA2024[i];
        commandesA2024[i] = nullptr;
    }
    if (reception) {
        delete reception;
        reception = nullptr;
    }
    Compteur::ajouterDestructeur();
}

void Client::preparerCommande2024() {
    int quantites[4][5] = {
        {3, 3, 3, 3, 3},
        {5, 3, 3, 3, 10},
        {-1, 0, 5, 5, 4},
        {1, 2, 12, 0, 0}
    };
    for (int i = 0; i < 4; i++) {
        commandesA2024[i] = new Commande(2024, quantites[i]);
    }
}

Commande Client::getCommande(int id) const {
    return *commandesA2024[id];
}

Reception* Client::getReception() const {
    return reception;
}

int Client::getSeuilQualite() const {
    return seuilQualite;
}

string Client::getNom() const {
    return nom;
}

void Client::recevoirCommande(Reception *reception) {
    this->reception = reception;
}

void Client::consommerProduits() {
    if (reception) {
        delete reception;
        reception = nullptr;
    }
}

int Client::getSatisfactionProduit(int idProduits) const {
    std::list<Produit*> produitsRecus = reception->getProduits(idProduits);
    int nbProduitsCommandes = commandesA2024[idProduits]->getQuantiteProduit(idProduits);
    int total = 0;
    for (Produit* produit : produitsRecus) {
        int qualite = produit->evaluerQualite();
        if (qualite > seuilQualite) {
            total += 5;
        }
        else if (qualite == seuilQualite) {
            total += 4;
        }
        else {
            total += 3;
        }
    }
    if (total == 0) {
        return 0;
    }
    return total / nbProduitsCommandes;
}

std::ostream & operator<<(ostream &os, const Client &client) {
    os << "Nom: " << client.nom << "\n";
    os << "Seuil de Qualite: " << client.seuilQualite << "\n";
    return os;
}
