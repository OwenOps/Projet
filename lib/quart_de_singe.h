/* ****************************************************************************************************** */
/*                                                                                                        */
/*                                                     :::++++++++::    :::        :::   :::+++::+++:::   */
/*    quart_de_singe.h                                 :::        :::   :::        :::         ::         */
/*                                                     :::        :::   :::        :::         ++         */
/*    By: Owen and Paul                                :::++++++++::    :::        :::         ++         */
/*                                                     :::++++++++::    :::        :::         ++         */
/*  Created: 2022/11/24 by Rebeller with Perigault     :::        :::   :::        :::         ++         */
/*                                                     :::        :::   :::        :::         ::         */
/*                                                     :::++++++++::    :::++++++++:::         ::         */
/*                                                                                                        */
/* ****************************************************************************************************** */
/**
 * @file quart_de_singe.h
 * Projet SAE-S1.02 Comparaison d’approches algorithmiques
 * @authors Owen Rebeller et Paul Perigault
 * Les fonctions qui commencent et termine notre jeu
 */
#ifndef PROJET_FINAL_QUART_DE_SINGE_H
#define PROJET_FINAL_QUART_DE_SINGE_H
#include "struct.h"
#include "Partie_fichier.h"
using namespace std;


/**
 * @brief Affiche un presentation du jeux
 */
void presentation();


/**
 * @brief Alloue de l'espace mémoire pour stocker un tableau de caractères dans la structure PARTIE.
 *
 * @param[in,out] partie Structure PARTIE qui contient la taille du tableau à allouer et le pointeur sur le tableau à initialiser.
 *
 * @return void
 *
 * @pre partie ne doit pas être un pointeur nul
 */
void allouerTableau(PARTIE& partie);


/**
 * @brief Initialise les champs de la structure PARTIE et alloue de l'espace mémoire pour les joueurs et le tableau de caractères.
 *
 * @param[in,out] p Pointeur sur la structure PARTIE à initialiser.
 * @param[in] types Chaîne de caractères qui contient les types de joueurs à créer.
 *
 * @return void
 *
 * @pre `p` ne doit pas être un pointeur nul
 * @pre `types` doit être un tableau de caractères terminé par un caractère nul
 * @pre La longueur de `types` doit être supérieure ou égale à 2
 */
void init(PARTIE* p, const char* types);


/**
 * @brief Libère l'espace mémoire alloué pour les champs de la structure DICO et de la structure PARTIE.
 *
 * @param[in,out] d Pointeur sur la structure DICO à désallouer.
 * @param[in,out] p Pointeur sur la structure PARTIE à désallouer.
 *
 * @return void
 *
 * @pre `d` et `p` ne doivent pas être des pointeurs nuls
 */
void detruire(DICO* d, PARTIE* p);

#endif //PROJET_FINAL_QUART_DE_SINGE_H
