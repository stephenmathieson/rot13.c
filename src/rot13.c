
//
// rot13.c
//
// Copyright (c) 2013 Stephen Mathieson
// MIT licensed
//

#include "rot13.h"

/*
 * Rotate the given `str` inline
 */

char *rot13(char *str) {
  for (int i = 0; '\0' != str[i]; i++) {
    char c = *(str + i);
    if (('a' <= c && 'n' > c) || ('A' <= c && 'N' > c)) {
      // a-m
      *(str + i) += 13;
    } else if (('n' <= c && 'z' >= c) || ('N' <= c && 'Z' >= c)) {
      // n-z
      *(str + i) -= 13;
    }
  }
  return str;
}
