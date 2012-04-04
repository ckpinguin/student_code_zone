/* struct1.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct index {
   int seite;
   char titel[30];
};

int main(void) {
   struct index lib[12];

   lib[0].seite = 23;
   strcpy(lib[0].titel, "C-Programmieren");
   int i;
   for (i = 0; i <= sizeof(lib); i++) {
     printf("%d, %s\n",lib[i].seite, lib[1].titel);
   }
   return EXIT_SUCCESS;
}
