#
# Minimal makefile
#

# 
# All target
#
all: args

#
# Declare args target
#
args: args.o
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
	rm -f args
