/* ****************************************************************************************************** */
/*                                                                                                        */
/*                                                     :::++++++++::    :::        :::   :::+++::+++:::   */
/*    Partie_fichier.cpp                               :::        :::   :::        :::         ::         */
/*                                                     :::        :::   :::        :::         ++         */
/*    By: Owen and Paul                                :::++++++++::    :::        :::         ++         */
/*                                                     :::++++++++::    :::        :::         ++         */
/*  Created: 2022/11/24 by Rebeller with Perigault     :::        :::   :::        :::         ++         */
/*                                                     :::        :::   :::        :::         ::         */
/*                                                     :::++++++++::    :::++++++++:::         ::         */
/*                                                                                                        */
/* ****************************************************************************************************** */
#include <iostream>
#include "Partie_fichier.h"
#include "Partie_joueur.h"
#include "ft_string.h"
#include "Deroulement_Partie.h"
using namespace std;

void allouerDico(DICO* d)
{
    d->monFichier = new char* [d->nbrMot * sizeof(char*)]; // necessaire pour aucun probleme de stockage
}


void nombreMot(DICO* d)
{
    unsigned int cmpt1 = 0;
    for (unsigned int i = 0; i < d->fichierTaille; ++i) { // Lire lettre par lettre
        if (d->donneDico[i] == '\n')
        {
            d->donneDico[i] = '\0';
            cmpt1++;
        }
    }

    if (cmpt1++ == 0)
    {
        cerr << "Il doit y avoir minimum 1 mot dans le dico." << endl;
        exit(EXIT_FAILURE);
    }

    d->nbrMot = cmpt1;
    allouerDico(d);

    unsigned int motE = 0;
    for (unsigned int i = 0; i < d->fichierTaille; ++i) {
        if (i == 0 || d->donneDico[i - 1] == '\0') {
            d->monFichier[motE] = d->donneDico + i;
            motE++;
        }
    }
}

void allouerDicoDonnees(DICO* d)
{
    d->donneDico = new char[d->fichierTaille];
}

void dico(ifstream& fichier, DICO* d) {

    if (!fichier)
    {
        std::cerr << "Impossible d'ouvrir le fichier" << endl;
        return;
    }
    fichier.seekg(0, ios::end); // Mettre le curseur a la fin
    d->fichierTaille = fichier.tellg(); // Tellg = connaitre position, ici vu que c'est la fin, ca va etre le nbr de donnees
    allouerDicoDonnees(d);

    fichier.seekg(0, ios::beg); // Met curseur au debut
    fichier.read(d->donneDico, d->fichierTaille); // on lire le nb d'octet et stocker dans donne
    fichier.close(); // Plus besoin du fichier

    nombreMot(d);
}

bool rechercheDichotomique(const PARTIE& partie, const DICO& d, const char* str)
{
    int debut = 0;
    int fin = d.nbrMot; // Le nombre de mot - 1
    int milieu, cmp;
    while (debut <= fin)
    {
        milieu = (debut + fin) / 2; // le nombre de mot / 2
        cmp = ft_strcmp(d.monFichier[milieu], str);
        if (cmp == 0)
            return true;
        else if (cmp > 0) // Si sa retourne une valeur > 0
            fin = milieu - 1;
        else
            debut = milieu + 1;
    }
    return false;
}

bool is_in_the_file(const DICO& dico, const char* str) // Le fichier + le mot du joueur
{
    for (int i = 0; i < dico.nbrMot; ++i) {
        if (ft_strncmp(str, dico.monFichier[i], ft_strlen(str)) == 0)  // Si c'est vrai
        {
            return true;
        }
    }
    return false;
}

bool commencementRecherche(const DICO& d, const PARTIE& p)
{
    if (ft_strlen(p.tabmot) > MIN_MOT)
        return true;
    else
        return false;
}


int rechercheMot2(PARTIE* p, const DICO& dico, int i) // Pour tous les mots
{
    if (rechercheDichotomique(*p, dico, p->tabmot))
    {
        std::cout << "le mot " << p->tabmot << " existe, le joueur "
                  << p->joueur[i].numJoueur << p->joueur[i].typesJoueur << " prend un quart de singe\n";
        ajoutScore(p, i);
        clearMot(p);
        i--;
    }
    return i;
}