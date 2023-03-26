#include <string.h>
#include <strings.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
  
  FILE *fp;
  char buf[5];
  char* len = 0;

  fp = fopen("./input.txt", "r");

  while ((len = fgets(buf, 100, fp)) != NULL) {
    char *word, *second;
    char *delim = " ";
    word = strtok(buf, delim);
    second = strtok(buf, delim);
    printf("%s\n%s", word, second);
  }
  return 0;
}

// _Bool didWin(char* str[]) {
//   
// }
