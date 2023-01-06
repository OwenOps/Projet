/* ****************************************************************************************************** */
/*                                                                                                        */
/*                                                     :::++++++++::    :::        :::   :::+++::+++:::   */
/*    Partie_fichier.h                                 :::        :::   :::        :::         ::         */
/*                                                     :::        :::   :::        :::         ++         */
/*    By: Owen and Paul                                :::++++++++::    :::        :::         ++         */
/*                                                     :::++++++++::    :::        :::         ++         */
/*  Created: 2022/11/24                                :::        :::   :::        :::         ++         */
/*                                                     :::        :::   :::        :::         ::         */
/*                                                     :::++++++++::    :::++++++++:::         ::         */
/*                                                                                                        */
/* ****************************************************************************************************** */
/**
 * @file Partie_joueur.h
 * Projet SAE-S1.02 Comparaison d’approches algorithmiques
 * @authors Owen et Paul
 * Toute les fonctions permettant d'avoir des joueurs pour notre partie.
 */
#ifndef PROJET_FINAL_PARTIE_JOUEUR_H
#define PROJET_FINAL_PARTIE_JOUEUR_H
#include "quart_de_singe.h"
#include "Partie_fichier.h"
#include "struct.h"
using namespace std;


/**
 * @brief Alloue de l'espace mémoire pour stocker les joueurs de la structure PARTIE.
 *
 * @param[in,out] partie Structure PARTIE qui contient le nombre de joueurs à allouer et le pointeur sur la liste de joueurs à initialiser.
 *
 * @return void
 * @pre partie.nbrJoueur >= 2;
 */
void allouerJoueurs(PARTIE& partie);


/**
 * @brief Ajoute 0.25 au score du joueur spécifié dans la structure PARTIE et affiche le classement des joueurs.
 *
 * @param[in,out] p Pointeur sur la structure PARTIE qui contient le score du joueur à modifier.
 * @param[in] indice Indice du joueur dans la structure PARTIE dont le score doit être modifié.
 *
 * @return void
 * @pre indice doit etre un indice valable
 */
void ajoutScore(PARTIE* p, const int indice);

/**
 * @brief Affiche le classement des joueurs de la structure PARTIE, avec leur numéro, leur type et leur score.
 *
 * @param[in] p Pointeur sur la structure PARTIE qui contient les joueurs à afficher.
 * @pre le pointeur p doit etre non nul
 * @return void
 */
void classementJoueur(const PARTIE* p);

/**
 * @brief Vérifie si le score d'un joueur de la structure PARTIE a atteint la valeur maximale.
 *
 * @param[in] p Pointeur sur la structure PARTIE qui contient le score du joueur à vérifier.
 * @param[in] indice Indice du joueur dans la structure PARTIE dont le score doit être vérifié.
 *
 * @return true Si le score du joueur a atteint la valeur maximale.
 * @return false Si le score du joueur n'a pas atteint la valeur maximale.
 *
 * @pre L'indice doit être un indice valide pour tableau p->joueur.
 */
bool scoreFinal(const PARTIE* p, const int indice);


/**
 * @brief Le joueur robot qui complete les mots
 *
 * @param[in,out] partie Pointeur sur la structure PARTIE qui contient le champ mot à remplir et le tableau tabmot à vérifier.
 * @param[in] dico Pointeur sur la structure DICO qui contient le dictionnaire de mots monFichier.
 *
 * @return void
 * @pre Les pointeurs partie et dico doivent être non nuls.
 */
void robot(PARTIE* partie, const DICO* dico);


/**
 * @brief Le joueur robot quand on pose une question
 *
 * @param[in] partie Structure PARTIE qui contient notamment le tableau tabmot et tabmotaverif à remplir.
 * @param[in] dico Structure DICO qui contient le dictionnaire de mots monFichier.
 *
 * @return void
 * @pre partie et dico doivent être initialisées.
 */
void mrRobot(PARTIE& partie, const DICO& dico);

#endif //PROJET_FINAL_PARTIE_JOUEUR_H
