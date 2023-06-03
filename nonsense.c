#include <stdio.h>
#include <stdlib.h>

size_t get_line(char **line, FILE *stream);
int cmp_int_desc(const void *a, const void *b);
int cmp_int_asc(const void *a, const void *b);

int main(int argc, char **argv) {
  char *line = NULL;
  size_t line_len = 0;

  int calories[4] = {0};

  while (line_len != -1) {
    line_len = get_line(&line, stdin);
    if (line_len == -1 || line_len == 0) {
      qsort(calories, 4, sizeof(int), cmp_int_desc);
      calories[3] = 0;
    } else {
      calories[3] += atoi(line);
    }
  }

  printf("most cals: %d\n", calories[0]);
}

size_t get_line(char **line, FILE *stream) {
  size_t size = 0;
  size_t line_len = getline(line, &size, stream);
  if ((*line)[line_len - 1] == '\n') {
    (*line)[line_len - 1] = '\0';
    line_len--;
  }
  return line_len;
}

int cmp_int_desc(const void *a, const void *b) {
  return -1 * cmp_int_asc(a, b);
}

int cmp_int_asc(const void *a, const void *b) {
  return (*(int *)a - *(int *)b);
}
