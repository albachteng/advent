#include <stdio.h>
#include <string.h>

#define MAP_SIZE 100
#define KEY_SIZE 100

int size = 0;
char keys[MAP_SIZE][KEY_SIZE];
char *values[MAP_SIZE];

int getIndex(char key[]) {
  for (int i = 0; i < size; i++) {
    if (strcmp(keys[i], key) == 0) {
      return i;
    }
  }
  return -1;
}

void insert(char key[], char *value) {
  int index = getIndex(key);
  if (index == -1) {
    strcpy(keys[size], key);
    values[size] = value;
    size++;
  } else {
    values[index] = value;
  }
}

char *get(char key[]) {
  int index = getIndex(key);
  if (index == -1) {
    return "";
  } else {
    return values[index];
  }
}

void printMap() {
  for (int i = 0; i < size; i++) {
    printf("%s: %s\n", keys[i], values[i]);
  }
}
