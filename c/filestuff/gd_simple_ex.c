/* gd1.c */

#include <stdio.h>
#include <gd.h>

int main()
{
   /*image initialisieren*/
   gdImagePtr image;
   FILE *png;
   int black, white, red, blue, yelow;
   /*Wir erzeugen ein Image mit 100x100 Pixel*/
   image=gdImageCreate(100,100);

   /*Speicher für die Farben allozieren*/
   white=gdImageColorAllocate(image,0,0,0);   /*Weiss*/
   black=gdImageColorAllocate(image,255,255,255); /*Schwarz*/
   red  =gdImageColorAllocate(image,255,0,0); /*rot*/
   blue =gdImageColorAllocate(image,0,0,255); /*blau*/
   yelow=gdImageColorAllocate(image,255,255,0); /*gelb*/

   gdImageRectangle(image,0,0,99,99,black);
   gdImageRectangle(image,1,1,49,49,yelow);
   gdImageFill(image,25,25,red);
   gdImageRectangle(image,50,1,98,49,yelow);
   gdImageFill(image,75,25, blue);
   gdImageRectangle(image,1,50,49,98,yelow);
   gdImageFill(image, 25,75,blue);
   gdImageRectangle(image,50,50,98,98,yelow);
   gdImageFill(image, 75,75,red);

   png = fopen("bild1.png", "wb");

   gdImagePng(image,png);

   fclose(png);

   gdImageDestroy(image);

   return 0;
}
