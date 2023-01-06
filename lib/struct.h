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
 * @file struct.h
 * Projet SAE-S1.02 Comparaison d’approches algorithmiques
 * @authors Owen et Paul
 * Nos structures pour realiser notre projet
 */

#ifndef PROJET_FINAL_STRUCT_H
#define PROJET_FINAL_STRUCT_H
/**
 * @brief Constantes utilisées dans le programme
 *
 */
enum {
    MIN_MOT = 2, /**< Seuil minimum de longueur pour un mot valide */
    MAX_MOT = 26, /**< Seuil maximum de longueur pour un mot valide */
    MAX_SCORE = 1, /**< Nombre de points gagnés lorsqu'un mot est trouvé */
};


/**
 * @brief Structure qui contient les informations sur le fichier de mots
 *
 */
typedef struct {
    unsigned int nbrMot; /**< Nombre de mots dans le fichier */
    unsigned int fichierTaille; /**< Taille du fichier en octets */
    char* donneDico; /**< Pointeur sur un tableau de caractères qui contient les mots du fichier, chaque caractère est un élément du tableau */
    char** monFichier; /**< Pointeur de pointeurs de caractères qui contient le fichier, chaque mot est un élément du tableau */
}DICO;

/**
 * @brief Structure qui contient les informations sur un joueur
 *
 */
typedef struct {
    double score; /**< Score du joueur */
    unsigned int numJoueur; /**< Numéro du joueur */
    char typesJoueur; /**< Type de joueur ('H' ou 'R') */
}JOUEUR;


/**
 * @brief Structure qui contient les informations sur la partie en cours
 *
 */
typedef struct
{
    unsigned int nbrjoueur; /**< Nombre de joueurs */
    char mot; /**< Lettre proposée par les joueurs */
    char* tabmot; /**< Pointeur sur un tableau de caractères qui contient le mot à chercher */
    unsigned int tailletableau; /**< Taille du tableau tabmot */
    char tabmotaverif[MAX_MOT]; /**< Tableau de caractères qui contient le mot à vérifier avec des '?' */
    DICO* dico; /**< Pointeur sur une structure de type DICO qui contient le fichier de mots */
    JOUEUR* joueur; /**< Pointeur sur une structure de type JOUEUR qui contient les informations sur les joueurs */
}PARTIE;



#endif //PROJET_FINAL_STRUCT_H
