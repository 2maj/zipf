#define MAX 1024
FILE * open_file(FILE ** file, char * name) {
  file = fopen(name, "r");
  if (!file) {
    printf("Error ! \n");
  } else {
    printf("Success ! \n");
  }
  return file;
}
