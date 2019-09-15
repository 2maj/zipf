void scan(char entree[]) {
  printf("Veuillez rentrer le texte: \n");
  gets(entree);
}


void tolowerString(char * letter) {
  int i, index, ascii;
  for (i = 0; i < (int) strlen(letter); i++) {
    ascii = letter[i];
    if (ascii >= A && ascii <= Z) {
      //maj
      index = ascii - A;
      ascii = MINA + index;
      letter[i] = tolower(ascii);
      //add value
    }
  }
}
