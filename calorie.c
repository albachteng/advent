#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

int main() {
  FILE *fp;
  char buf[100];
  int max, secondMax, thirdMax, curr = 0;
  char *len = 0;

  fp = fopen("./input.txt", "r");

  while ((len = fgets(buf, 100, fp)) != NULL) {
    // printf("%s\n", len);
    if (curr > max) {
      // printf("new max: %d", max);
      thirdMax = secondMax;
      secondMax = max;
      max = curr;
    } else if (curr > secondMax) {
      thirdMax = secondMax;
      secondMax = curr;
    } else if (curr > thirdMax) {
      thirdMax = curr;
    }
    if (strlen(buf) == 1 || strlen(buf) == 0) {
      printf("%s, %s\n", buf, len);
      // printf("empty line\n");
      curr = 0;
    } else {
      // printf("%s, %s\n", buf, len);
      // printf("non-empty: %d\n", parseCalories(buf));
      curr += atoi(buf);
      printf("curr: %d\n", curr);
    }
  }

  fclose(fp);
  printf("max: %d\nsecond: %d\nthird: %d", max, secondMax, thirdMax);
  printf("total: %d", max + secondMax + thirdMax);
}

_Bool isNewBag(char c) {
  if (c == '\n')
    return 1;
  return 0;
}
