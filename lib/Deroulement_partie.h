/* ****************************************************************************************************** */
/*                                                                                                        */
/*                                                     :::++++++++::    :::        :::   :::+++::+++:::   */
/*    Deroulement_partie.h                             :::        :::   :::        :::         ::         */
/*                                                     :::        :::   :::        :::         ++         */
/*    By: Owen and Paul                                :::++++++++::    :::        :::         ++         */
/*                                                     :::++++++++::    :::        :::         ++         */
/*  Created: 2022/11/24 by Rebeller with Perigault     :::        :::   :::        :::         ++         */
/*                                                     :::        :::   :::        :::         ::         */
/*                                                     :::++++++++::    :::++++++++:::         ::         */
/*                                                                                                        */
/* ****************************************************************************************************** */
/**
 * @file Deroulement_partie.h
 * Projet SAE-S1.02 Comparaison d’approches algorithmiques
 * @authors Owen Rebeller et Paul Perigault
 * Toute les fonctions permettant de realiser le jeu.
 */
#ifndef PROJET_FINAL_DEROULEMENT_PARTIE_H
#define PROJET_FINAL_DEROULEMENT_PARTIE_H
#include "quart_de_singe.h"
#include "Partie_fichier.h"
#include "struct.h"
using namespace std;

/**
* @brief Vérifie si les arguments passés en ligne de commande sont
 *       valides et quitte le programme en cas d'erreur.
*
* @param[in] types Chaîne de caractères contenant les types de joueurs.
* @param[in] argc Nombre d'arguments passés en ligne de commande.
 * @pre argc > 0
*/
void erreur1(char* types, const int argc);

/**
 * @brief Vérifie si un joueur abandonne la manche et met à jour les scores en conséquence.
 *
 * @param[in,out] p Pointeur vers un objet de type PARTIE.
 * @param[in] indice Indice du joueur dans l'objet PARTIE.
 *
 * @return true si le joueur a abandonné la manche.
 * @return false sinon.
 */
bool verification1(PARTIE* p, int indice);


/**
 *@brief Verifie si la lettre entrée est un point d'interrogation
 *       pose la question au joueur et met a jour les scores en consequence
 * @param [in,out] p : Pointeur vers la structure de la partie
 * @param [in] d : Pointeur vers la structure du DICO
 * @param [in] indice : Indice du joueur dans le tableau de joueurs
 * @return indice - 1 si le mot a été trouvé dans le dictionnaire.
 * @return indice du joueur sinon.
 * @pre p != NULL
 * @pre d != NULL
 */
int verification2(PARTIE* p, const DICO* d, int indice);


/**
 *@brief  Demande au joueur de saisir une lettre
 * @param[in,out] p Pointeur vers la structure de la partie.
 * @param[in] d Pointeur vers la structure du DICO.
 * @param[in] indice Indice du joueur.
 * @param[in] typeJoueur Type de joueur ('R' pour robot, 'H' pour humain).
 * @pre p != NULL
 * @pre d != NULL
 */
void saisir(PARTIE* p, const DICO* d, const int indice, const char typeJoueur);




/**
 *@brief Réinitialiser le mot formé par les joueurs
 * @param [in,out] p : Pointeur sur la structure de la partie
 * @pre p doit être initialisée.
 */
void clearMot(PARTIE* p);



/**
 * @brief Recherche un mot dans un dictionnaire.
 *
 * @param[in] p Pointeur vers PARTIE.
 * @param[in] dico Référence du Dictionnaire.
 *
 * @return 1 si le mot existe dans le dictionnaire et qu'il commence comme le mot courant.
 * @return -1 si le mot existe pas dans le dictionnaire et qu'il commence comme le mot courant.
 * @return -2 si le mot qu'il commence pas comme le mot courant.
 * @pre p doit être initialisée.
 */
int rechercheMot(const PARTIE* p, const DICO& dico);

/**
 * @brief Vérifie si un mot est identique au mot courant
 *
 * @param[in] p Référence sur un objet de type PARTIE.
 *
 * @return true si le mot est identique au mot courant
 * @return false sinon.
 * @pre p doit être initialisée.
 */
bool motavant(const PARTIE& p);



#endif //PROJET_FINAL_DEROULEMENT_PARTIE_H
