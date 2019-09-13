#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include<ctype.h>

const int A=65;
const int Z=90;
const int MINA = 97;
const int MINZ = 122;

void scan(char*);
int n_words(char[]);
int longest(char[]);
void frequence (int*tab,char**dico, char*entre, int nbr);
void display(char**,int*, int);
void add_dico(char**, char*,int,int);
int check_in_dico(char**, char[],int);
//void display_frequence(int *, int);
void sort(char**, int *, int,int);
void tolowerString(char *);
void free_memory(char**, int);


int main(int argc, char* argv[]) {
  char entre[100];
  printf("La phrase \n");
  gets (entre);
  int nbr = n_words(entre);
  int*tab;
  tab=(int*)malloc((nbr+1)*sizeof(int));
  int lgst = longest(entre);
  //printf("fr = %d nbre= %d \n", frq, nbr);

  char **dico = (char**)malloc((nbr+1) * sizeof(char*));

  add_dico(dico,entre,nbr,lgst);

  //printf("%s",entre);
  //parse(entre,&dico);

  frequence(tab,dico, entre, nbr);

  sort(dico,tab,nbr,lgst);
  display(dico,tab, nbr);
  //display_frequence(tab, nbr);
  free_memory(dico, nbr);
  free(tab);
   free(dico);
   return 789;

}

void free_memory(char** dico, int nbr){
    int i;
    for(i=0; i<nbr; i++){
        free(dico[i]);
    }

}
void scan(char entree[]){
  printf("Veuillez rentrer le texte: \n");
  gets(entree);
}

int check_in_dico(char**dico, char mot[],int nbr){
    int i, pos;
    for(i=0; i<nbr; i++){
        if(strlen(mot)!=0 && strlen(dico[i])!=0){
            if(strcmp(mot,dico[i])==0){
                return i;
            }
           pos=i;
        }
    }
    return nbr+pos;
}

void tolowerString(char *letter){
    int i, index, ascii;
    for(i=0; i<(int)strlen(letter); i++){
        ascii=letter[i];
        if(ascii>=A && ascii <=Z){
            //maj
            index = ascii-A;
            ascii = MINA + index;
            letter[i] = tolower(ascii);
            //add value
        }
    }
}

void add_dico(char**dico, char *entre,int nbr,int longest){
    char *str;
    str = (char*)malloc((strlen(entre)+1)*sizeof(char));
    strcpy(str,entre);
   const char s[22] = "- ,;_\\%/*^£$?.!'\\";
   char *token;

   token = strtok(str, s);
   int i = 0, n=0;
    for(n=0; n<nbr; n++){
        dico[n] = (char *)malloc((longest+1) * sizeof(char));
    }
   while(token != NULL) {
       i+=1;
       tolowerString(token);
       if(strlen(token)!=0 && check_in_dico(dico,token,nbr)>=nbr){
            dico[i] = (char *)malloc((strlen(token)+1) * sizeof(char));
	        strcpy(dico[i], token);
	        //printf("%s\n",dico[i]);
       }
      token = strtok(NULL, s);
   }
   free(str);
}

void display(char** dico,int*tab, int nbr){
    int i;
    printf("mot:  | frequence: \n");
    for(i=0; i<nbr+1; i++){
        if(strlen(dico[i]) !=0){
            printf("%s | %d\n", dico[i], tab[i]);

        }
    }
    printf("\n");
}

void display_frequence(int *tab, int nbr){
    int i;
    for(i=0; i<nbr; i++){
        printf("%d ", tab[i]);
    }
}

void sort(char**dico, int *tab, int nbr,int longest){
    int i;
    int j;
    int tmp;
    char *temp;
    temp = (char*)malloc((longest+1)*sizeof(char));

    printf("mot:            frequence:  \n");
    for(i=0; i<nbr; i++){
        for(j=i+1;j<nbr;j++){
            if(tab[j]>tab[i]){
                strcpy(temp,dico[i]);
                strcpy(dico[i],dico[j]);
                strcpy(dico[j],temp);
                tmp = tab[i];
                tab[i] = tab[j];
                //strcpy(temp,dico[i]);
                tab[j]=tmp;
            }
        }
    }
    free(temp);
}


int n_words(char entree[]){
    int n = 0;
    for (int i = 0; i<=(int)strlen(entree);i++){
        if (entree[i] == ' '||entree[i] == '\''||entree[i] == '?'||entree[i] == '!'||entree[i] == ','||entree[i] == ':'){
            n += 1;
            i++;
        }
    }
    return n;
}

int longest(char entree[]){
    int i = 0;
    int n = 0;
    int max = 0;
    while (i<=(int)strlen(entree)){
        if( entree[i] == ' ' || entree[i] == '\0'){
            if (n>max){
                max = n;
            }
            n = 0;
            i+= 1;
        }else{
            n += 1;
            i += 1;
        }

    }
    return max;
    }

void frequence (int*tab,char**dico, char*entre, int nbr){
        char *str;
        str = (char*)malloc((strlen(entre)+1)*sizeof(char));
        strcpy(str,entre);
       const char s[15] = "- ,:/*^£$?.!'";
       char *token;
       token = strtok(str, s);
       int position;

       /* walk through other tokens */
       while(token != NULL ) {
          position = check_in_dico(dico, token,nbr);
          if (position<nbr){
             tab[position] +=1;
          }
          else{
              position=position-nbr;
              tab[position+1]=1;
              //printf( " %d et tab = %d \n", position, tab[position] );
          }
          token = strtok(NULL, s);
       }
        free(str);
       }
