#
# Minimal makefile
#

# 
# All target
#
all: try_env

#
# Declare try_env target
#
try_env: try_env.o
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
	rm -f try_env
