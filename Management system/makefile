CC          =	gcc
# Flags that are sent to the compiler
# Do not change these
CFLAGS      =	-Wall -ansi -pedantic -std=c99 
LDFLAGS     =

#Directories where the compiler can find things
INCLUDES    = -IInclude 
LIBDIRS     = -L/usr/local/mysql/lib -lmysqlclient 
LIBS        = 

# add directory names here if you want to separate files by directories
BINDIR = bin/
SRCDIR = src/

#Put the names of your source code file in the lines below.  

SOURCE = $(SRCDIR)main.c $(SRCDIR)sql.c $(SRCDIR)menu.c $(SRCDIR)inner.c

#The list of object files is below.  The object file names here must match the file names of your source code 
# except with .o instead of .c.   Make changes as appropriate


OBJS    = main.o sql.o menu.o inner.o


#The names of the binary programs that will be produced.  
#
PROGNAME = $(BINDIR)RunMe


default : labLink
	mv *.o $(BINDIR)

labLink: labCompile
	$(CC) $(LIBDIRS) $(LDFLAGS) -o $(PROGNAME) $(OBJS) $(LIBS)

labCompile: 
	$(CC) $(CFLAGS) -c $(SOURCE) $(INCLUDES) 

clean:
	@ rm $(BINDIR)*.o