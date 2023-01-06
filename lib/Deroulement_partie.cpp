#include <cassert>
#include <iomanip>
#include <iostream>
#include "ft_string.h"
#include "quart_de_singe.h"
#include "Partie_joueur.h"
#include "Deroulement_partie.h"
#include "Partie_fichier.h"

using namespace std;

void erreur1(char* types, const int argc)
{
    assert(argc != 1 && "Le nombre d'argument > 2 : <type joueurs>");
    types = ft_strupcase(types);

    for (int j = 0; j < ft_strlen(types); ++j)
    {
        if (types[j] != 'H' && types[j] != 'R')
        {
            cerr << "Les types : '" << types[j] << "', ne sont pas des types Joueurs ou Robots." << endl;
            exit(EXIT_FAILURE);
        }
    }
}

bool verification1(PARTIE* p, const int indice)
{
    if (p->mot == '!')
    {
        cout << "le joueur " << p->joueur[indice].numJoueur << p->joueur[indice].typesJoueur << " abandonne la manche et prend un quart de singe" << endl;
        ajoutScore(p, indice);
        clearMot(p);
        return true;
    }
    return false;
}

int verification2(PARTIE* p, const DICO* d, int indice)
{
    if (p->mot == '?')
    {
        if (indice == 0) // Si le premier joueur demande, alors on demande au joueur max
        {
            indice = p->nbrjoueur - 1;
            cout << p->joueur[indice].numJoueur << p->joueur[indice].typesJoueur << ", " << "saisir le mot > ";

            if (p->joueur[indice].typesJoueur == 'R') // Si c'est un robot
            {
                mrRobot(*p, *d);
                cout << p->tabmotaverif << endl;
            }
            else
            {
                cin >> setw(MAX_MOT) >> p->tabmotaverif; // Si le mot dépasse, on prend MAX_MOT caracteres = eviter dépassement
                cin.ignore(INT_MAX, '\n'); // Ensuite on vide le buffer
            }

            ft_strupcase(p->tabmotaverif);

            if (rechercheMot(p, *d) == 1) // Si le mot existe
            {
                indice = 0;
                std::cout << "le mot " << p->tabmotaverif << " existe, le joueur "
                          << p->joueur[indice].numJoueur << p->joueur[indice].typesJoueur << " prend un quart de singe\n";
                ajoutScore(p, indice);
                clearMot(p);
                indice--; // Pour faire rejouer
            }
            else if (rechercheMot(p, *d) == -1) // Si le debut correspond, mais il n'existe pas
            {
                indice = p->nbrjoueur - 1;
                std::cout << "le mot " << p->tabmotaverif << " n'existe pas, le joueur "
                          << p->joueur[indice].numJoueur << p->joueur[indice].typesJoueur << " prend un quart de singe\n";
                ajoutScore(p, indice);
                clearMot(p);
                indice--;
            }
            else if (rechercheMot(p, *d) == -2) // Si different du mot du debut
            {
                indice = p->nbrjoueur - 1;
                std::cout << "le mot " << p->tabmotaverif << " ne commence pas par les lettres attendues, le joueur "
                          << p->joueur[indice].numJoueur << p->joueur[indice].typesJoueur << " prend un quart de singe\n";
                ajoutScore(p, indice);
                clearMot(p);
                indice--;
            }
        }
        else // Sinon on demande au joueur d'avant
        {
            int tmp = indice;
            indice--; // Le joueur d'avant
            cout << p->joueur[indice].numJoueur << p->joueur[indice].typesJoueur << ", " << "saisir le mot > ";

            if (p->joueur[indice].typesJoueur == 'R') // Si c'est un robot
            {
                mrRobot(*p, *d);
                cout << p->tabmotaverif << endl;
            }
            else
                cin >> setw(MAX_MOT) >> p->tabmotaverif; // Sinon c'est le joueur
            ft_strupcase(p->tabmotaverif);

            if (rechercheMot(p, *d) == 1) // Si le mot existe
            {
                indice = tmp;
                std::cout << "le mot " << p->tabmotaverif << " existe, le joueur "
                          << p->joueur[indice].numJoueur << p->joueur[indice].typesJoueur << " prend un quart de singe\n";
                ajoutScore(p, indice);
                clearMot(p);
                indice--;
            }
            else if (rechercheMot(p, *d) == -1) // Si existe pas
            {
                std::cout << "le mot " << p->tabmotaverif << " n'existe pas, le joueur "
                          << p->joueur[indice].numJoueur << p->joueur[indice].typesJoueur << " prend un quart de singe\n";
                ajoutScore(p, indice);
                clearMot(p);
                indice--; // Pour faire rejouer le joueur
            }
            else if (rechercheMot(p, *d) == -2) // Si different du mot du debut
            {
                std::cout << "le mot " << p->tabmotaverif << " ne commence pas par les lettres attendues, le joueur "
                          << p->joueur[indice].numJoueur << p->joueur[indice].typesJoueur << " prend un quart de singe\n";
                ajoutScore(p, indice);
                clearMot(p);
                indice--; // Pour faire rejouer le joueur
            }
        }
    }
    return indice;
}


void saisir(PARTIE* p, const DICO* d, const int indice, const char typeJoueur)
{
    std::cout << p->joueur[indice].numJoueur << p->joueur[indice].typesJoueur << ", " << "(" << p->tabmot << ")" << " > ";

    if (typeJoueur == 'R')
    {
        robot(p, d);
        cout << p->mot << endl;
    }

    if (typeJoueur == 'H')
    {
        cin >> p->mot;
        cin.ignore(INT_MAX, '\n'); // Pour lire 1 caractere
    }

    if (p->mot != '!' && p->mot != '?')
    {
        if (p->mot >= 'a' && p->mot <= 'z') // On Met en majuscule pour ensuite l'ajouter au mot
            p->mot -= 32;

        addchar(p->tabmot, p->mot);
    }
}


void clearMot(PARTIE* p)
{
    for (int i = 0; i < MAX_MOT; ++i)
    {
        p->tabmot[i] = '\0';
    }
}

int rechercheMot(const PARTIE* p, const DICO& dico) // Pour le ?
{
    if (motavant(*p) && rechercheDichotomique(*p, dico, p->tabmotaverif))
    {
        return 1; // Si existe
    }
    else if (motavant(*p) && !rechercheDichotomique(*p, dico, p->tabmotaverif))
    {
        return -1; // Si le debut correspond, mais il n'existe pas
    }
    else if (!motavant(*p))
    {
        return -2; // Si different du mot du debut
    }
    return 0;
}

bool motavant(const PARTIE& p) // Que pour le ?
{
    if (ft_strncmp(p.tabmot, p.tabmotaverif, ft_strlen(p.tabmot)) == 0)
        return true;
    return false;
}