// Disk converter for Briel Altair DSK-88 format files
// Currently only converts in one direction

// Public domain by Al Williams al.williams@awce.com
// If you like it, consider donating to St. Jude's 
// Children's Hospital -- even if you don't like it
// perhaps consider it anyway!

// Compile:
// gcc -o diskcvt diskcvt.c


#include <stdio.h>

int main(int argc, char *argv[])
{
  if (argc!=3)
    {
      fprintf(stderr,"%s", "Disk converter to convert physical Altair "
"disk images (such as those from the Briel Altair DSK-88 to"
"images that can be read from cpmtools\n"
"For 119 track images, add this to your diskdef (nominally)"
" /etc/cpmtools/diskdefs:\n\n"
	      "diskdef briel119\n"
	      "seclen 128\n"
	      "tracks 119\n"
	      "sectrk 32\n"
	      "blocksize 2048\n"
	      "maxdir 128\n"
	      "skew 2\n"
	      "boottrk 3\n"
	      "os 2.2\n");
      return 10;
    }
  
  FILE *in=fopen(argv[1],"r");
  FILE *out=fopen(argv[2],"w");
  if (!in) 
    {
      perror(argv[1]);
      return 1;
    }
  if (!out)
    {
      perror(argv[2]);
      return 2;
    }
  
		  

  int byte=0;
  while (!feof(in))
    {
      int c=getc(in);
      if (byte<3) 
	{
	  byte++;
	  continue;
	}
      
      if (byte==136) 
	{
	  byte=0;
	  continue;
	}
      if ((byte-3)<128) putc(c,out);
      byte++;
    }
  printf("Processed %d bytes\n",byte);
  fclose(in);
  fclose(out);
  return 0;
}
