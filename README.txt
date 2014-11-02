 Disk converter for Briel Altair DSK-88 format files
 Currently only converts in one direction (to cpmtool format)

 Public domain by Al Williams al.williams@awce.com
 If you like it, consider donating to St. Jude's 
 Children's Hospital -- even if you don't like it
 perhaps consider it anyway!

 Compile:
    gcc -o diskcvt diskcvt.c

 Typical usage:
   diskcvt --tocpm input.dsk output.cpm
   cpmls -l -f briel119 output.cpm 
   cpmcp -f briel119 output.cpm 0:somefile.txt somefile.txt

options are:
	 --tocpm (DSK to CPM format)
	 --fromcpm (CPM to 119 track DSK)
	 --fromcpm77 (CPM to 77 track DSK)

 You do need to add a diskdefs to /etc/cpmtools/diskdefs 
 (see included file)

Note: the --fromcpm options are not well tested and may not correctly
set up the system track, so please backup disk images accordingly!!!
