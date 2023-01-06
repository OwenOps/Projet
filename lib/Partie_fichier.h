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
 * @file Partie_fichier.h
 * Projet SAE-S1.02 Comparaison d’approches algorithmiques
 * @authors Owen et Paul
 * Toute les fonctions permettant de manipuler le fichier, du stockage a la recherche.
 */
#ifndef PROJET_FINAL_PARTIE_FICHIER_H
#define PROJET_FINAL_PARTIE_FICHIER_H
#include "quart_de_singe.h"
#include "struct.h"
#include "fstream"
using namespace std;


/**
 * @brief Alloue de la mémoire pour stocker un dictionnaire de mots.
 *
 * @param[in,out] d Pointeur vers une structure DICO dans laquelle allouer la mémoire.
 * @pre d ne doit pas être un pointeur nul
 */
void allouerDico(DICO* d);


/**
 * @brief Compte le nombre de mots dans un dictionnaire et sépare chaque mot dans une case d'un tableau.
 * @pre d ne doit pas être un pointeur nul
 * @param[in,out] d Pointeur vers une structure DICO contenant le dictionnaire et où stocker les mots séparés.
 */
void nombreMot(DICO* d);


/**
 * @brief Alloue de la mémoire pour stocker les données d'un dictionnaire de mots.
 * @pre d ne doit pas être un pointeur nul
 * @param[in,out] d Pointeur vers une structure DICO dans laquelle allouer la mémoire.
 */
void allouerDicoDonnees(DICO* d);



/**
 * @brief Lit et stock le contenu d'un fichier
 * @param[in] fichier ifstream permettant d'ouvrir le fichier contenant le dictionnaire.
 * @param[in,out] d Pointeur vers une structure DICO dans laquelle stocker
 *                  les données du dictionnaire et les mots séparés.
 * @pre fichier doit être un fichier valide et ouvert en lecture
 * @pre d ne doit pas être un pointeur nul
 */
void dico(ifstream& fichier, DICO* d);

/**
 * @brief      Recherche un mot dans un dictionnaire à l'aide de la méthode de la
 *             recherche dichotomique.
 *
 * @param[in] partie  Référence de la partie en cours
 * @param[in] d       Référence du dictionnaire
 * @param[in] str     Le mot à rechercher
 * @return true si le mot a été trouvé, false sinon.
 * @pre partie et d ne doivent pas être des pointeurs nuls
 * @pre str doit être un tableau de caractères terminé par un caractère nul
 */
bool rechercheDichotomique(const PARTIE& partie, const DICO& d, const char* str);


/**
 * @brief Vérifie si le mot du joueur se trouve dans le fichier
 *
 * @param[in] dico Structure de type DICO qui contient le fichier
 * @param[in] str Pointeur sur un tableau de caractères qui contient le mot du joueur
 * @return true Si le mot du joueur se trouve dans le fichier
 * @return false Si le mot du joueur ne se trouve pas dans le fichier
 * @pre dico et str ne doivent pas être des pointeurs nuls
 * @pre str doit être un tableau de caractères terminé par un caractère nul
 */
bool is_in_the_file(const DICO& dico, const char* str);


/**
 * @brief Recherche le mot de la partie dans le fichier
 *
 * @param[in] partie Structure de type PARTIE qui contient le mot de la partie
 * @param[in] d Structure de type DICO qui contient le fichier
 * @return true Si le mot de la partie se trouve dans le fichier
 * @return false Si le mot de la partie ne se trouve pas dans le fichier
 */
//bool rechercherlemot(PARTIE& partie,DICO& d);

/**
 * @brief Vérifie si le mot de la partie a une longueur supérieure à MIN_MOT
 *
 * @param[in] d Structure de type DICO qui contient le fichier
 * @param[in] p Structure de type PARTIE qui contient le mot de la partie
 * @return true Si la longueur du mot de la partie est supérieure a MIN_MOT
 * @return false Si la longueur du mot de la partie est inférieure ou égale a MIN_MOT
 * @pre d et p ne doivent pas être des pointeurs nuls
 * @pre p.tabmot doit être un tableau de caractères terminé par un caractère nul
 *
 */
bool commencementRecherche(const DICO& d, const PARTIE& p);


/**
 * @brief Recherche le mot de la partie dans le fichier et met à jour le score du joueur
 *        si le mot est trouvé
 *
 * @param[in] p Pointeur sur une structure de type
 *              PARTIE qui contient le mot de la partie et les informations sur les joueurs
 * @param[in] dico Structure de type DICO qui contient le fichier
 * @param[in] i Entier indiquant le numéro du joueur actuel
 * @return i Entier indiquant le numéro du joueur suivant
 * @pre p et dico ne doivent pas être des pointeurs nuls
 * @pre p.tabmot doit être un tableau de caractères terminé par un caractère nul
 */
int rechercheMot2(PARTIE* p, const DICO& dico, int i);

#endif //PROJET_FINAL_PARTIE_FICHIER_H
