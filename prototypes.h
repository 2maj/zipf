const int A = 65;
const int Z = 90;
const int MINA = 97;
const int MINZ = 122;

void scan(char * );
int n_words(char[]);
int longest(char[]);
void frequence(int * tab, char ** dico, char * entre, int nbr);
void display(char ** , int * , int);
void add_dico(char ** , char * , int, int);
int check_in_dico(char ** , char[], int);
//void display_frequence(int *, int);
void sort(char ** , int * , int, int);
void tolowerString(char * );
void free_memory(char ** , int);
FILE * open_file(FILE ** , char * );
