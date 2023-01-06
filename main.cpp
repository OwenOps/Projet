/* ****************************************************************************************************** */
/*                                                                                                        */
/*                                                     :::++++++++::    :::        :::   :::+++::+++:::   */
/*    SAE_S1_02.cpp                                    :::        :::   :::        :::         ::         */
/*                                                     :::        :::   :::        :::         ++         */
/*    By: Owen and Paul                                :::++++++++::    :::        :::         ++         */
/*                                                     :::++++++++::    :::        :::         ++         */
/*  Created: 2022/11/24 by Rebeller with Perigault     :::        :::   :::        :::         ++         */
/*                                                     :::        :::   :::        :::         ::         */
/*                                                     :::++++++++::    :::++++++++:::         ::         */
/*                                                                                                        */
/* ****************************************************************************************************** */

#include <iostream>
#include "lib/Partie_fichier.h"
#include "lib/Partie_joueur.h"
#include "lib/quart_de_singe.h"
#include "lib/Deroulement_partie.h"
using namespace std;

int main(int argc, char *argv[]){
    // presentation();
    PARTIE p;
    DICO d;

    erreur1(argv[1], argc); // H ou R
    init(&p, argv[1]);
    ifstream f("ods4.txt");
    dico(f,&d);

    unsigned int fin = 0;
    while (fin == 0) {
        for (int i = 0; i < p.nbrjoueur; ++i) { // Parcourir les joueurs

            if (scoreFinal(&p, i) == 1) // Eviter de relancer une boucle
            {
                fin++;
                break;
            }

            saisir(&p, &d, i, p.joueur[i].typesJoueur);

            if (verification1(&p, i)) // Si le mot c'est "!"
            {
                i--; // Faire rejouer le meme joueur quand il perd
            };

            i = verification2(&p, &d, i);  // Si le mot c'est "?"

            if (commencementRecherche(d, p) == 1) // On commence la recherche partie de MIN_MOT
            {
                i = rechercheMot2(&p, d, i);
            }

            if (scoreFinal(&p, i) == 1) {
                fin++;
                break;
            }
        }
    }
    detruire(&d,&p); // On desalloue tout
    return 0;
}