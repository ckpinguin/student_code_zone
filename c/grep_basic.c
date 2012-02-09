#include <stdio.h>
#include <stdlib.h>

/* From "Beautiful code" (Brian Kerninghan) */


/* Search for regexp anywhere in text */
int match (char *regexp, char *text)
{
  if (regexp[0] == '^')
	return matchhere(regexp+1, text);
  do { /* must look even if string is empty */
	if (matchhere(regexp, text))
	  return 1;
  } while (*text++ != '\0');

  return 0;
}

/* Search for regexp at beginning of text */
int matchhere(char *regexp, char *text)
{
  if (regexp[0] == '\0')
	return 1;
  if (regexp[1] == '*')
	return matchstar(regexp[0], regexp+2, text);
  if (regexp[0] == '$' && regexp[1] == '\0')
	return *text == '\0';
  if (*text != '\0' && (regexp[0] == '.' || regexp[0] == *text))
	return matchhere(regexp+1, text+1);

  return 0;
}

/* Search for c*regexp at beginning of text */
int matchstar(int c, char *regexp, char *text)
{
  do {
	if (matchhere(regexp, text))
	  return 1;
  } while (*text != '\0' && (*text++ == c || c == '.'));
  
  return 0;
}


void read_from_pipe(int file)
{
  FILE *stream;
  int c;
  stream = fdopen (file, "r");
  while ((c = fgetc (stream)) != EOF)
    putchar (c);
  fclose (stream);
}

int main(int argc, char **argv)
{
  if (argc != 3) {
	fputs ("Usage: grep <regex> <text>\n", stderr);
	exit(EXIT_FAILURE);
  }
  char *regexp = argv[1];
  char *text = argv[2];
  
  if (match(regexp, text)) {
	fprintf(stdout, "Found \"%s\" in the text!\n", regexp);
	return EXIT_SUCCESS;
  } else {
	fprintf(stdout, "Did not find \"%s\" in the text.\n", regexp);
	return EXIT_SUCCESS;
  }

  /* Read from STDIN */
  //  read_from_pipe(1);

}
