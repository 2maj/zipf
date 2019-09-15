int check_in_dico(char ** dico, char mot[], int nbr) {
  int i, pos;
  for (i = 0; i < nbr; i++) {
    if (strlen(mot) != 0 && strlen(dico[i]) != 0) {
      if (strcmp(mot, dico[i]) == 0) {
        return i;
      }
      pos = i;
    }
  }
  return nbr + pos;
}
void add_dico(char ** dico, char * entre, int nbr, int longest) {
  char * str;
  str = (char * ) malloc((strlen(entre) + 1) * sizeof(char));
  strcpy(str, entre);
  const char s[22] = "- ,;_\\%/*^£$?.!'\\";
  char * token;

  token = strtok(str, s);
  int i = 0, n = 0;
  for (n = 0; n < nbr; n++) {
    dico[n] = (char * ) malloc((longest + 1) * sizeof(char));
  }
  while (token != NULL) {
    i += 1;
    tolowerString(token);
    if (strlen(token) != 0 && check_in_dico(dico, token, nbr) >= nbr) {
      dico[i] = (char * ) malloc((strlen(token) + 1) * sizeof(char));
      strcpy(dico[i], token);
      //printf("%s\n",dico[i]);
    }
    token = strtok(NULL, s);
  }
  free(str);
}
int n_words(char entree[]) {
  int n = 0;
  for (int i = 0; i <= (int) strlen(entree); i++) {
    if (entree[i] == ' ' || entree[i] == '\'' || entree[i] == '?' || entree[i] == '!' || entree[i] == ',' || entree[i] == ':') {
      n += 1;
      i++;
    }
  }
  return n;
}
int longest(char entree[]) {
  int i = 0;
  int n = 0;
  int max = 0;
  while (i <= (int) strlen(entree)) {
    if (entree[i] == ' ' || entree[i] == '\0') {
      if (n > max) {
        max = n;
      }
      n = 0;
      i += 1;
    } else {
      n += 1;
      i += 1;
    }

  }
  return max;
}
void display(char ** dico, int * tab, int nbr) {
  int i;
  printf("mot:  | frequence: \n");
  for (i = 0; i <= nbr + 1; i++) {
      if(tab[i]==0){
      tab[i]+=1;}
    if (strlen(dico[i]) != 0) {
      printf("%s | %d\n", dico[i], tab[i]);

    }
  }
  printf("\n");
}
void free_memory(char ** dico, int nbr) {
  int i;
  for (i = 0; i < nbr; i++) {
    free(dico[i]);
  }

}
