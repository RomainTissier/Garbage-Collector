#
# Minimal makefile
#

# 
# All target
#
all: types

#
# Declare types target
#
types: types.o
	gcc -o $@ $^ 

#
# Generic .o compilation rule
#
%.o: %.c
	gcc -o $@ -c $<
#
# Classic clean target
#
clean: 
	rm -f *.o

#
# Classic mrproper target
#
mrproper: clean
	rm -f types
