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

WARNINGS = -Wall	# Add a lot of warning, but not all !
WARNINGS += -Werror  	# Turn warnings into errors
WARNINGS += -Wshadow	# Add a warnings if a variable override another variable

%.o: %.c
	gcc -o $@ ${WARNINGS} -c $<
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
