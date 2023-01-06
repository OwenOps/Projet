/* ****************************************************************************************************** */
/*                                                                                                        */
/*                                                     :::++++++++::    :::        :::   :::+++::+++:::   */
/*    ft_string.cpp                                    :::        :::   :::        :::         ::         */
/*                                                     :::        :::   :::        :::         ++         */
/*    By: Owen and Paul                                :::++++++++::    :::        :::         ++         */
/*                                                     :::++++++++::    :::        :::         ++         */
/*  Created: 2022/11/24 by Rebeller with Perigault     :::        :::   :::        :::         ++         */
/*                                                     :::        :::   :::        :::         ::         */
/*                                                     :::++++++++::    :::++++++++:::         ::         */
/*                                                                                                        */
/* ****************************************************************************************************** */
int	ft_strncmp(const char* s1, const char* s2, const unsigned int n)
{
    unsigned int	i;

    i = 0;
    if (n == 0) // Si aucun caractère n'est à comparer, retourner 0
        return (0);
    while (s1[i] && s1[i] == s2[i] && i < n - 1) // Parcourir les chaînes de caractères en comparant les caractères
        i++;
    return (s1[i] - s2[i]); // Retourner la différence entre les codes ASCII des caractères s'ils sont différents
}


int	ft_strlen(const char* str)
{
    int	nbchar;

    nbchar = 0;
    while (*str++) // Parcourir la chaine de caractères jusqu'à trouver le caractère de fin de chaîne
        nbchar++;
    return (nbchar);
}


char* ft_strupcase(char* str)
{
    int	up;

    up = 0;
    while (str[up] != '\0')// Parcourir la chaine de caractères jusqu'à trouver le caractère de fin de chaîne
    {
        if (str[up] >= 'a' && str[up] <= 'z')// Si la lettre est en minuscule
            str[up] -= 32;// La transformer en majuscule en soustrayant 32 à son code ASCII
        up++;
    }
    return (str);
}


char* addchar(char* str, const char c)
{
    int i;
    i = ft_strlen(str); // Déterminer la longueur de la chaîne de caractères
    str[i] = c; // Ajouter le caractère à la fin de la chaîne
    return (str);
}


int	ft_strcmp(const char* s1, const char* s2)
{
    int	i;

    i = 0;
    while (s1[i] && s1[i] == s2[i]) // Parcourir les chaînes de caractères en comparant les caractères
    {
        i++;
    }
    return (s1[i] - s2[i]); // Retourner la différence entre les codes ASCII des caractères s'ils sont différents
}

char* ft_strncpy(char* dest, const char* src, const unsigned int n)
{
    unsigned int	i;

    i = 0;
    while (src[i] && i < n)
    {
        dest[i] = src[i];
        i++;
    }
    while (i < n)
    {
        dest[i] = '\0';
        i++;
    }
    return (dest);
}