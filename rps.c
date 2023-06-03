#include "./map.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

_Bool didWin(char *first, char *second);

// map
void insert(char key[], char *value);
char *get(char key[]);
void printMap();

int main() {

  // win map
  insert("A", "Z");
  insert("B", "X");
  insert("C", "Y");
  printMap();

  FILE *fp;
  char buf[4];
  char *len = 0;

  fp = fopen("./input.txt", "r");

  while ((len = fgets(buf, 100, fp)) != NULL) {
    char *first, *second;
    char delim[2] = " \n";
    first = strtok(buf, delim);
    second = strtok(NULL, delim);
    printf("%s %s", first, second);
    if (didWin(first, second)) {
      printf("YOU WON\n");
    }
  }
  return 0;
}

_Bool didWin(char *first, char *second) {
  printf("comparing %s and %s\n", second, get(first));
  if (strcmp(second, get(first))) {
    return 0;
  }
  return 1;
}
