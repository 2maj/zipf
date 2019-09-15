#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include<ctype.h>
#include "dico.h"
#include "prototypes.h"
#include "function_file.h"
#include "annexe_functions.h"
#include "filter_functions.h"



int main() {
  char entre[100];
  int frq;
  //Get text from File
  /*
  char name[] ="example.text"; // File name
  FILE *fptr;
  fptr = open_file(fptr, name);
  fgets(entre, MAX , fptr);
  */
  //Get text from keyboard
  printf("Veuillez entrer le texte \n");
  gets(entre);
  int nbr = n_words(entre); // Get number of word in the text
  int * tab_frqc;
  tab_frqc = (int * ) malloc((nbr + 1) * sizeof(int));
  int lgst = longest(entre); //get the most longest word in the text
  //printf("fr = %d nbre= %d \n", frq, nbr);

  char ** dico = (char ** ) malloc((nbr + 1) * sizeof(char * ));

  add_dico(dico, entre, nbr, lgst); //add words in dico by removing the occurences

  //printf("%s",entre);
  //parse(entre,&dico);

  frequence(tab_frqc, dico, entre, nbr); // Get frequences of each word in the text

  sort(dico, tab_frqc, nbr, lgst); //Sort frequences and dico in descending order
  display(dico, tab_frqc, nbr);
  //display_frequence(tab, nbr);
  //fclose(fptr); //To close file
  free_memory(dico, nbr);
  free(tab_frqc);
  free(dico);

  return 0;

}
