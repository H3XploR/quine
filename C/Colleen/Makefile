.PHONY: all clean fclean re

all: Colleen

Colleen: Colleen.o
	cc -g3 -o Colleen Colleen.o

Colleen.o: Colleen.c
	cc -c -g3 Colleen.c

clean:
	rm -f Colleen.o

fclean: clean
	rm -f Colleen

re: fclean all
