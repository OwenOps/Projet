/* ****************************************************************************************************** */
/*                                                                                                        */
/*                                                     :::++++++++::    :::        :::   :::+++::+++:::   */
/*    ft_string.h                                      :::        :::   :::        :::         ::         */
/*                                                     :::        :::   :::        :::         ++         */
/*    By: Owen and Paul                                :::++++++++::    :::        :::         ++         */
/*                                                     :::++++++++::    :::        :::         ++         */
/*  Created: 2022/11/24 by Rebeller with Perigault     :::        :::   :::        :::         ++         */
/*                                                     :::        :::   :::        :::         ::         */
/*                                                     :::++++++++::    :::++++++++:::         ::         */
/*                                                                                                        */
/* ****************************************************************************************************** */
/**
 * @file Partie_fichier.h
 * Projet SAE-S1.02 Comparaison d’approches algorithmiques
 * @authors Owen Rebeller et Paul Perigault
 * Toute les fonctions permettant de manipuler les char* donc les chaines de caracteres.
 */
#ifndef PROJET_FINAL_FT_STRING_H
#define PROJET_FINAL_FT_STRING_H
using namespace std;

/**
 * @brief Compare les n premiers caractères de deux chaînes de caractères.
 *
 * @param[in] s1 Première chaîne de caractères à comparer.
 * @param[in] s2 Deuxième chaîne de caractères à comparer.
 * @param[in] n Nombre de caractères à comparer.
 *
 * @return 0 si les n premiers caractères de s1 et s2 sont égaux.
 * @return la différence entre les codes ASCII des premiers caractères différents de s1 et s2 sinon.
 *
 * @pre s1 et s2 doivent être des pointeurs vers des chaînes de caractères valides
 * @pre n doit être un entier positif
 */
int	ft_strncmp(const char* s1, const char* s2, const unsigned int n);



/**
 * @brief Calcule la longueur d'une chaîne de caractères.
 *
 * @param[in] str Chaîne de caractères.
 *
 * @return La longueur de la chaîne de caractères, en nombre de caractères.
 *
 * @pre     La chaîne de caractères doit être terminée par le caractère de fin de chaîne \0.
 */
int	ft_strlen(const char* str);



/**
 * @brief Convertit toutes les lettres minuscules d'une chaîne de caractères en majuscules.
 *
 * @param[in,out] str Chaîne de caractères à convertir.
 *
 * @return La chaîne de caractères convertie en majuscules.
 *
 * @pre str doit être une chaîne de caractères non vide.
 */
char* ft_strupcase(char* str);



/**
 * @brief Ajoute un caractère à la fin d'une chaîne de caractères.
 *
 * @param[in,out] str Chaîne de caractères à laquelle ajouter le caractère.
 * @param[in] c Caractère à ajouter.
 *
 * @return La chaîne de caractères avec le caractère ajouté à la fin.
 */
char* addchar(char* str, const char c);



/**
 * @brief Compare deux chaînes de caractères.
 *
 * @param[in] s1 Première chaîne de caractères à comparer.
 * @param[in] s2 Deuxième chaîne de caractères à comparer.
 *
 * @return 0 si s1 et s2 sont égales.
 * @return la différence entre les codes ASCII des premiers caractères différents de s1 et s2 sinon.
 */
int	ft_strcmp(const char* s1, const char* s2);



/**
 * @brief Copie les n caractères d'une chaîne de caractères dans une autre.
 *
 * @param[in,out] dest Chaîne de caractères de destination de la copie.
 * @param[in] src Chaîne de caractères source à copier.
 * @param[in] n Nombre maximum de caractères à copier.
 *
 * @return La chaîne de caractères de destination avec les caractères copiés.
 *
 *
 */
char* ft_strncpy(char* dest, const char* src, const unsigned int n);



#endif //PROJET_FINAL_FT_STRING_H
