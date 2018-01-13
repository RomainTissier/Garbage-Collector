#
# Minimal makefile
#

# 
# All target
#
all: fib even

#
# Declare args target
#
fib: fib.o
	gcc -o $@ $^ 
	
#
# Declare even target
#
even: even.o
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
	rm -f fib even
