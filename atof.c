#include <stdio.h>

int main() {
  double atof(char s[]);
  printf("%f", atof("-1.2345"));
}

// converting string to float
double atof(char s[]) {
  double val, power;
  int i, sign;

  for (i = 0; s[i] == ' ' || s[i] == '\n' || s[i] == '\t'; i++)
    ;       // skip whitespace - spaces, newlines and tabs
  sign = 1; // initialize sign to positive
  if (s[i] == '+' || s[i] == '-')
    sign = (s[i++] == '+') ? 1 : -1;

  for (val = 0; s[i] >= '0' && s[i] <= '9'; i++) // for numerical characters
    val = 10 * val + s[i] - '0'; // set our value to ten times itself plus
                                 // whatever value we just scanned
  if (s[i] == '.')               // when we hit the dot
    i++; // skip over it and begin treating these next characters as powers
  for (power = 1; s[i] >= '0' && s[i] <= '9'; i++) {
    val = 10 * val + s[i] - '0';
    power *= 10;
  }
  return (sign * val / power);
}
