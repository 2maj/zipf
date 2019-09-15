void display_frequence(int * tab, int nbr) {
  int i;
  for (i = 0; i < nbr; i++) {
    printf("%d ", tab[i]);
  }
}

void sort(char ** dico, int * tab, int nbr, int longest) {
  int i;
  int j;
  int tmp;
  char * temp;
  temp = (char * ) malloc((longest + 1) * sizeof(char));

  for (i = 0; i < nbr; i++) {
    for (j = i + 1; j < nbr; j++) {
      if (tab[j] > tab[i]) {
        strcpy(temp, dico[i]);
        strcpy(dico[i], dico[j]);
        strcpy(dico[j], temp);
        tmp = tab[i];
        tab[i] = tab[j];
        //strcpy(temp,dico[i]);
        tab[j] = tmp;
      }
    }
  }
  free(temp);
}





void frequence(int * tab, char ** dico, char * entre, int nbr) {
  char * str;
  str = (char * ) malloc((strlen(entre) + 1) * sizeof(char));
  strcpy(str, entre);
  const char s[15] = "- ,:/*^£$?.!'";
  char * token;
  token = strtok(str, s);
  int position;

  /* walk through other tokens */
  while (token != NULL) {
    position = check_in_dico(dico, token, nbr);
    if (position < nbr) {
      tab[position] += 1;
    } else {
      position = position - nbr;
      tab[position + 1] = 1;
      //printf( " %d et tab = %d \n", position, tab[position] );
    }
    token = strtok(NULL, s);
  }
  free(str);
}
