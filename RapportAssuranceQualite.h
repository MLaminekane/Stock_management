//
// Created by mlami on 11/5/2024.
//

#ifndef RAPPORTASSURANCEQUALITE_H
#define RAPPORTASSURANCEQUALITE_H



#include <iostream>
#include "Client.h"
using namespace std;

class RapportAssuranceQualite
{
private:
    string nomClient;
    int noCommande;
    int idBonCommande;
    int quantitesProduitsCommandes[5];
    int quantitesProduitsRecus[5];
    int satisfactionClient[5];

    int calculerSatisfactionGlobaleClient();
    static Compteur compteur;
public:
    RapportAssuranceQualite();
    ~RapportAssuranceQualite();
    RapportAssuranceQualite(RapportAssuranceQualite&);

    void setNomClient(string nomClient) { this->nomClient = nomClient; }
    void setNoCommande(int noCommande) { this->noCommande= noCommande; }
    void setIdBonCommande(int idBonCommande) { this->idBonCommande = idBonCommande; }
    void setQuantiteProduitCommande(int quantite, int idProduit) { quantitesProduitsCommandes[idProduit] = quantite; }
    void setQuantiteProduitRecu(int quantite, int idProduit) { quantitesProduitsRecus[idProduit] = quantite; }
    void setSatisfactionClient(int satisfaction, int idProduit) { satisfactionClient[idProduit] = satisfaction; }
    string genererRapport(const Client& client);
};



#endif //RAPPORTASSURANCEQUALITE_H
