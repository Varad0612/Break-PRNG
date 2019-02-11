#include <stdlib.h>
#include <stdio.h>
#include <time.h>

//Return a byte at a time of the rand() keystream
char randchar() {
  static int key;
  static int i = 0;
  i = i % 4;
  if (i == 0) key = rand();
  return ((char *)(&key))[i++];
}

int main(int argc, const char* argv[]) {
	static char randstate[64];

  //Integer formed by the first 4 bytes of the keystream
  int k_1;
  ((char*)(&k_1))[0] = 235;
  ((char*)(&k_1))[1] = 83;
  ((char*)(&k_1))[2] = 122;
  ((char*)(&k_1))[3] = 97;
  printf("%d\n", k_1);

  // Key obtained from the getkey.py function
  int seed = 1536588602;

  initstate(seed, randstate,31);

  FILE *input, *output;
  input = fopen("hw2.tex.enc", "rb");
  output = fopen("out1.txt", "w");

  int c;
  while ((c = fgetc(input)) != EOF)
  fputc(c^randchar(),output);

  fclose(input);
  fclose(output);
}

