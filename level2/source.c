#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void no(void)
{
  puts("Nope.");
  exit(1);
}

void ok(void)
{
  puts("Good job.");
  return;
}

// Commentaire général pour le mdp: le premier et le second char seront toujours '0'
// L'input ne doit pas exceder 23chars
// le résultat atoi de ce char est ajouté à la suite de la chaine finale qui sera comparée avec le mot "delabere"
// chaine finale automatiquement init avec come premier char 'd'

// Comprendre le mot de passe à saisir:
// Les deux premiers chiffres sont à '0' obligatoirement
// et ensuite tu dois constituer le reste du mot "elabere" en ascii (car "d" est mis d'office comme premier caractère pour chaine de comparaison finale)
// Soit : e = 101, l = 108, a = 097, b = 098, e = 101, r = 114, e = 101
// Password = 00101108097098101114101

int main(void)
{
  unsigned int parcour_de_l_input;
  size_t len;
  int atoi_result;
  bool boolean;
  char user_input [24];
  char valeur_finale [9];
  unsigned int index_input;
  int i;
  int read;

  printf("Please enter key: ");

  // Si la lecture réussit, read sera 1.
  // Si la lecture échoue, read sera 0.
  read = scanf("%23s", user_input);
  if (read != 1)
  {
    no();
  }

  // Check si le deuxième caractère est diff de '0'
  if (user_input[1] != '0')
  {
    no();
  }
  
  // Check si le premier caractère est diff de '0'
  if (user_input[0] != '0')
  {
    no();
  }

  // Vide le tampon d'entrée
  fflush(stdin);
  
  // Initialise les 9 premiers octets du tableau valeur_finale à 0
  // En mettant tous les octets à 0, on s'assure que la chaîne sera correctement terminée, même si elle n'est pas entièrement remplie plus tard.
  memset(valeur_finale,0,9);

  // Premier caractère de la chaine à comparé mit à la valeur 'd'
  valeur_finale[0] = 'd';

  index_input = 2;
  i = 1;

  // Boucle infinie
  while(true) 
  {
    // valeur_finale est égale à "d\0\0\0\0\0\0\0\0"
    len = strlen(valeur_finale);
    
    // parcour_de_l_input prend la valeur (2 si debut) de l'indexation de la chaine reçue en input
    parcour_de_l_input = index_input;
    
    // boolean
    boolean = false;

    // Si la len de valeur_finale < 8
    // len prend la valeur strlen de l'input user
    if (len < 8)
    {
      len = strlen(user_input);
      // Si parcour_de_l_input qui est à 2 et plus petit que la len de l'input
      // tant que l'on a pas parcouru toute la chaine reçue en input, boolean == false
      boolean = parcour_de_l_input < len;
    }

    // Si boolean == false, sortir de la boucle infinie
    // on a parcouru toute la chaine reçue en input
    if (!boolean) break;

    // Ces trois var sont de chars
    // ils prennent la valeur de user_input index : 2, 3 et 4 (suite de trois chiffres à partir du troisième char de l'input user)
    char trio[4];
    trio[3] = '\0';
    trio[0] = user_input[index_input];
    trio[1] = user_input[index_input + 1];
    trio[2] = user_input[index_input + 2];

    // convertie tous les chars num après avoir jump les ws jusqu'au premier char non num
    // la deuxieme valeur de l'input user)
    atoi_result = atoi(trio);

    // assigne l'int retourné par atoi à l'index 2 de la valeur finale (int devient le char ASCII associée au nombre)
    valeur_finale[i] = (char)atoi_result;

    // l'index se pose sur le premier char des trois prochaines valeurs suivantes
    index_input = index_input + 3;
    i = i + 1;
  }

  valeur_finale[i] = '\0';
  // strcmp de la valeur finale avec le mot "delabere"
  // met le resultat dans la var atoi_result
  atoi_result = strcmp(valeur_finale,"delabere");

  // Si les deux mots comparés sont les mêmes : appel de ok()
  if (atoi_result == 0)
  {
    ok();
  }
  else // Sinon appel de no()
  {
    no();
  }
  return 0;
}
