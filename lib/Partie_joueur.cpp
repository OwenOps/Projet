/* ****************************************************************************************************** */
/*                                                                                                        */
/*                                                     :::++++++++::    :::        :::   :::+++::+++:::   */
/*    Partie_joueur.cpp                                :::        :::   :::        :::         ::         */
/*                                                     :::        :::   :::        :::         ++         */
/*    By: Owen and Paul                                :::++++++++::    :::        :::         ++         */
/*                                                     :::++++++++::    :::        :::         ++         */
/*  Created: 2022/11/24 by Rebeller with Perigault     :::        :::   :::        :::         ++         */
/*                                                     :::        :::   :::        :::         ::         */
/*                                                     :::++++++++::    :::++++++++:::         ::         */
/*                                                                                                        */
/* ****************************************************************************************************** */
#include <iostream>
#include <random> // Remplace le srand
#include "quart_de_singe.h"
#include "Partie_joueur.h"
#include "ft_string.h"
using namespace std;

void allouerJoueurs(PARTIE& partie)
{
    partie.joueur = new JOUEUR[partie.nbrjoueur];
}

void ajoutScore(PARTIE* p, const int indice)
{
    p->joueur[indice].score += 0.25;
    classementJoueur(p);
}

void classementJoueur(const PARTIE* p)
{
    for (unsigned i = 0; i < p->nbrjoueur; ++i) {
        cout << p->joueur[i].numJoueur << p->joueur[i].typesJoueur << " : " << p->joueur[i].score;

        if (i != p->nbrjoueur - 1) {
            cout << "; ";
        }
    }

    cout << "\n";
}

bool scoreFinal(const PARTIE* p, const int indice)
{
    if (p->joueur[indice].score == MAX_SCORE) {
        cout << "La partie est finie" << endl;
        return true; // Pour arreter la boucle
    }
    return false;
}

void robot(PARTIE* partie, const DICO* dico) {

    random_device rd; // Remplace srand car srand va jusqu'a 30 000 et nous on veut plus haut.// Remplace srand car srand va jusqu'a 30 000 et nous on veut plus haut.
    mt19937 generator(rd());
    uniform_int_distribution<int> dist2('A', 'Z');
    //char *test = partie->tabmotaverif;

    if (ft_strlen(partie->tabmot) == 0)
    {
        partie->mot = static_cast<char>(dist2(generator)); // Si le robot commence
    }
    else
    {
        if (is_in_the_file(*dico, partie->tabmot))
        {
            for (unsigned int i = 0; i < dico->nbrMot; ++i) // Les mots
            {
                if (ft_strncmp(partie->tabmot, dico->monFichier[i], ft_strlen(partie->tabmot)) == 0) { // Si le mot correspond aux premieres lettres
                    for (unsigned int j = 0; j < ft_strlen(dico->monFichier[i]); ++j) { // Les lettres
                        if (dico->monFichier[i][j] != partie->tabmot[j]) // != '\0' Pour eviter de completer le mot
                        {
                            if (dico->monFichier[i][j + 1] == '\0' && ft_strlen(partie->tabmot) >= MIN_MOT)
                            {
                                partie->mot = '?'; // Si aucun mot correspond
                                return;
                            }
                            partie->mot = dico->monFichier[i][j]; // Si il trouve un mot qui correspond il renvoie la lettre
                            return;
                        }
                    }
                }
            }
        }
        partie->mot = '?';
    }
}

void mrRobot(PARTIE& partie, const DICO& dico) // Pour le "?"
{
    random_device rd; // Remplace srand car srand va jusqu'a 30 000 et nous on veut plus haut.
    mt19937 generator(rd());
    uniform_int_distribution<int> dist(0, dico.nbrMot); // De 0 a nombre de mot

    int random = dist(generator);

    if (ft_strlen(partie.tabmot) != 0)
    {
        for (unsigned int i = 0; i < dico.nbrMot; ++i)
        {
            if (ft_strncmp(dico.monFichier[i], partie.tabmot, ft_strlen(partie.tabmot)) == 0)
            {
                ft_strncpy(partie.tabmotaverif, dico.monFichier[i], MAX_MOT);
                return;
            }
        }
    }
    ft_strncpy(partie.tabmotaverif, dico.monFichier[random], MAX_MOT);
}