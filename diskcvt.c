// Disk converter for Briel Altair DSK-88 format files

// Public domain by Al Williams al.williams@awce.com
// If you like it, consider donating to St. Jude's 
// Children's Hospital -- even if you don't like it
// perhaps consider it anyway!

// Compile:
// gcc -o diskcvt diskcvt.c


#include <stdio.h>
#include <string.h>

int tocpm(FILE *in, FILE *out)
  {
  int total=0;
  int byte=0;
  while (!feof(in))
    {
      int c=getc(in);
      if (c==EOF) break;
      total++;
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
  return total;
}

int fromcpm(FILE *in, FILE *out)
{
  fprintf(stderr,"Not implemented (yet)!\n");
  return 0;
}




int main(int argc, char *argv[])
{
  if (argc!=4)
    {
      fprintf(stderr,"%s", "Disk converter to convert physical Altair "
"disk images (such as those from the Briel Altair DSK-88 to "
"images that can be read from cpmtools\n"
"Usage: diskcvt option input_file output_file\n"
"where option is --fromcpm to convert a .cpm disk to .dsk or --tocpm to go the other direction\n"
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
	      "os 2.2\n"
	      "end\n\n");
      return 10;
    }
  
  FILE *in=fopen(argv[2],"r");
  FILE *out=fopen(argv[3],"w");
  int byte=0;
  
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
  if (!strcmp(argv[1],"--tocpm")) byte=tocpm(in,out);
  else if (!strcmp(argv[1],"--fromcpm")) byte=fromcpm(in,out);
  else fprintf(stderr,"Unknown option %s\n",argv[1]);
  printf("Processed %d bytes\n",byte);
  fclose(in);
  fclose(out);
  return 0;
}

  
