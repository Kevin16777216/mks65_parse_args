#include <string.h>
#include <stdio.h>
char ** parse_args( char * line ){
  char *token;
  char **out = malloc(strlen(line) * sizeof(char *));
  int i = 0;
  while(line){
    char * tmp = strsep(&line," ");
    out[i] = tmp;
    i++;
  }
  return out;
}
int main(int argc, char * argv[]){
  char input[256] = "";
  int j = 1;
  if (argc > 1) {
      while(j < argc){
        strcat(input, argv[j]);
        strcat(input, " ");
        j++;
      }
  } else {
      printf("Please enter a command:");
      fgets(input, 254, stdin);
  }
  input[strlen(input)-1] = '\0';
  char ** test = parse_args(input);
  printf("\n\nARRAY:\n\n");
  int i = 0;
  while(test[i]){
    printf("%s\n",test[i++]);
  }
  printf("\n\nRunning command ... \n\n");
  execvp(test[0], test);



  return 0;
}
