/* malloc1.c */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
   int *p;

   p = malloc(sizeof(int));
   // ansi c++ would be:
   //
p = (int *) malloc(sizeof(int));
   if(p != NULL) {
      *p=99;
      printf("Allokationerfolgreich ... \n");
   }
   else {
      printf("Kein virtueller RAM mehr verfügbar ...\n");
      return EXIT_FAILURE;
   }
   return EXIT_SUCCESS;
}
