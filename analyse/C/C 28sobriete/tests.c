#include "RLE.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compareStrings(const char *expected, const char *actual) {
  if (strcmp(expected, actual) == 0) {
    return 1;
  } else {
    printf("Erreur: Résultat attendu : '%s', Résultat obtenu : '%s'\n",
           expected, actual);
    return 0;
  }
}

void testRLE() {
  char *result = RLE("");

  if (!compareStrings("", result)) {
    printf("Test 'RLE(\"\")' a échoué.\n");
  }

  free(result);

  result = RLE("abc");
  if (!compareStrings("1a1b1c", result)) {
    printf("Test 'RLE(\"abc\")' a échoué.\n");
  }

  free(result);

  result = RLE("abbccc");
  if (!compareStrings("1a2b3c", result)) {
    printf("Test 'RLE(\"abbccc\")' a échoué.\n");
  }

  free(result);

  result = RLE("aaabaa");
  if (!compareStrings("3a1b2a", result)) {
    printf("Test 'RLE(\"aaabaa\")' a échoué.\n");
  }

  free(result);

  result = RLE("aAa");
  if (!compareStrings("1a1A1a", result)) {
    printf("Test 'RLE(\"aAa\")' a échoué.\n");
  }

  free(result);

  result = RLE("WWWWWWWWWWWWW");
  if (!compareStrings("9W4W", result)) {
    printf("Test 'RLE(\"WWWWWWWWWWWWW\")' a échoué.\n");
  }

  free(result);
}

void testRLE_recursive() {
  char *result = RLE_recursive("", 3);

  if (!compareStrings("", result)) {
    printf("Test 'RLE_recursif(\"\")' a échoué.\n");
  }

  free(result);

  result = RLE_recursive("abc", 3);
  if (!compareStrings("311a311b311c", result)) {
    printf("Test 'RLE_recursif(\"abc\")' a échoué.\n");
  }

  free(result);

  result = RLE_recursive("abbccc", 3);
  if (!compareStrings("311a1112111b1113111c", result)) {
    printf("Test 'RLE_recursif(\"abbccc\")' a échoué.\n");
  }

  free(result);

  result = RLE_recursive("aaabaa", 3);
  if (!compareStrings("1113111a311b1112111a", result)) {
    printf("Test 'RLE_recursif(\"aaabaa\")' a échoué.\n");
  }

  free(result);

  result = RLE_recursive("aAa", 3);
  if (!compareStrings("311a311A311a", result)) {
    printf("Test 'RLE_recursif(\"aAa\")' a échoué.\n");
  }

  free(result);

  result = RLE_recursive("WWWWWWWWWWWWW", 3);
  if (!compareStrings("1119111W1114111W", result)) {
    printf("Test 'RLE_recursif(\"WWWWWWWWWWWWW\")' a échoué.\n");
  }

  free(result);
}

/*void testUnRLE() {
  char *result = unRLE("");

  if (!compareStrings("", result)) {
    printf("Test 'unRLE(\"\")' a échoué.\n");
  }

  free(result);

  result = unRLE("1a1b1c");
  if (!compareStrings("abc", result)) {
    printf("Test 'unRLE(\"1a1b1c\")' a échoué.\n");
  }

  free(result);

  result = unRLE("1a2b3c");
  if (!compareStrings("abbccc", result)) {
    printf("Test 'unRLE(\"1a2b3c\")' a échoué.\n");
  }

  free(result);

  result = unRLE("3a1b2a");
  if (!compareStrings("aaabaa", result)) {
    printf("Test 'unRLE(\"3a1b2a\")' a échoué.\n");
  }

  free(result);

  result = unRLE("1a1A1a");
  if (!compareStrings("aAa", result)) {
    printf("Test 'unRLE(\"1a1A1a\")' a échoué.\n");
  }

  free(result);

  result = unRLE("9W4W");
  if (!compareStrings("WWWWWWWWWWWWW", result)) {
    printf("Test 'unRLE(\"9W4W\")' a échoué.\n");
  }

  free(result);
}

void testUnRLE_recursif() {
  char *result = unRLE_recursif("", 3);

  if (!compareStrings("", result)) {
    printf("Test 'unRLE_recursif(\"\")' a échoué.\n");
  }

  free(result);

  result = unRLE_recursif("311a311b311c", 3);
  if (!compareStrings("abc", result)) {
    printf("Test 'unRLE_recursif(\"1a1b1c\")' a échoué.\n");
  }

  free(result);

  result = unRLE_recursif("311a1112111b1113111c", 3);
  if (!compareStrings("abbccc", result)) {
    printf("Test 'unRLE_recursif(\"1a2b3c\")' a échoué.\n");
  }

  free(result);

  result = unRLE_recursif("1113111a311b1112111a", 3);
  if (!compareStrings("aaabaa", result)) {
    printf("Test 'unRLE_recursif(\"3a1b2a\")' a échoué.\n");
  }

  free(result);

  result = unRLE_recursif("311a311A311a", 3);
  if (!compareStrings("aAa", result)) {
    printf("Test 'unRLE_recursif(\"1a1A1a\")' a échoué.\n");
  }

  free(result);

  result = unRLE_recursif("1119111W1114111W", 3);
  if (!compareStrings("WWWWWWWWWWWWW", result)) {
    printf("Test 'unRLE_recursif(\"9W4W\")' a échoué.\n");
  }

  free(result);
}*/

void runTests() {
  testRLE();
  testRLE_recursive();
  // testUnRLE();
  // testUnRLE_recursif();
}
