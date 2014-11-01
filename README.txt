 Disk converter for Briel Altair DSK-88 format files
 Currently only converts in one direction (to cpmtool format)

 Public domain by Al Williams al.williams@awce.com
 If you like it, consider donating to St. Jude's 
 Children's Hospital -- even if you don't like it
 perhaps consider it anyway!

 Compile:
    gcc -o diskcvt diskcvt.c

 Typical usage:
   diskcvt input.dsk output.cpm
   cpmls -l -f briel119 output.cpm 
   cpmcp -f briel119 output.cpm 0:somefile.txt somefile.txt

 You do need to add a diskdefs to /etc/cpmtools/diskdefs 
 (see included file)
