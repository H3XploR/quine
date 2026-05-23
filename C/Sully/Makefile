.PHONY: all clean fclean re test

all: Sully

Sully: Sully.o
	cc -g3 -o Sully Sully.o

Sully.o: Sully.c
	cc -c -g3 Sully.c

clean:
	rm -f Sully.o

fclean: clean
	rm -f Sully

re: fclean all

test:
	./Sully > tmp_Sully ; diff tmp_Sully Sully.c
