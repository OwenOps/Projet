/* ****************************************************************************************************** */
/*                                                                                                        */
/*                                                     :::++++++++::    :::        :::   :::+++::+++:::   */
/*    quart_de_singe.cpp                               :::        :::   :::        :::         ::         */
/*                                                     :::        :::   :::        :::         ++         */
/*    By: Owen and Paul                                :::++++++++::    :::        :::         ++         */
/*                                                     :::++++++++::    :::        :::         ++         */
/*  Created: 2022/11/24 by Rebeller with Perigault     :::        :::   :::        :::         ++         */
/*                                                     :::        :::   :::        :::         ::         */
/*                                                     :::++++++++::    :::++++++++:::         ::         */
/*                                                                                                        */
/* ****************************************************************************************************** */
#include <iostream>
#include <cassert>
#include "Partie_joueur.h"
#include "quart_de_singe.h"
#include "ft_string.h"
using namespace std;

void presentation()
{
    system("color 3");
    cout << "   _                               _         _            _                  " << endl;
    cout << "  | | ___    __ _ _   _  __ _ _ __| |_    __| | ___   ___(_)_ __   __ _  ___ " << endl;
    cout << "  | |/ _ \\  / _` | | | |/ _` | '__| __|  / _` |/ _ \\ / __| | '_ \\ / _` |/ _ \\" << endl;
    cout << "  | |  __/ | (_| | |_| | (_| | |  | |_  | (_| |  __/ \\__ \\ | | | | (_| |  __/" << endl;
    cout << "  |_|\\___|  \\__, |\\__,_|\\__,_|_|   \\__|  \\__,_|\\___| |___/_|_| |_|\\__, |\\___|" << endl;
    cout << "               |_|                                                |___/       \n\n" << endl;
    system("color c");
    cout << "\t   Bienvenue sur le jeu le quart de singe voici les regles : \n" << endl;
    cout << "  Chaque joueur doit chacun son tour ecrire UNE lettre pour former un mot." << endl;
    cout << "\tCelui qui forme un mot de plus de 2 lettres prend 1/4 de singe (0.25)" << endl;
    cout << "\t  Si vous doutez sur le mot que pense votre adversaire precedent faites (?)" << endl;
    cout << "\t\tSi vous souhaitez abandonne la manche faites (!)" << endl;
    cout << endl;
    system("color 0");
}

void allouerTableau(PARTIE& partie)
{
    partie.tabmot = new char[partie.tailletableau];
}

void init(PARTIE* p, const char* types)
{
    assert(ft_strlen(types) != 1 && "Le nombre de joueur doit etre => a 2");
    p->nbrjoueur = ft_strlen(types);
    p->tailletableau = MAX_MOT;

    allouerJoueurs(*p);
    for (unsigned i = 0; i < p->nbrjoueur; ++i)
    {
        p->joueur[i].score = 0.0;
        p->joueur[i].numJoueur = i + 1; // Pour enlever le joueur 0
        p->joueur[i].typesJoueur = types[i];
    }

    allouerTableau(*p);
    for (unsigned int i = 0; i < p->tailletableau; ++i) // Les cases a 0
    {
        p->tabmot[i] = '\0';
    }
}

void detruire(DICO* d, PARTIE* p)
{
    delete[] p->tabmot;
    delete[] p->joueur;
    delete[] d->donneDico;
    delete[] d->monFichier;
}