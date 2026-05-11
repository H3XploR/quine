.PHONY: all clean fclean re test

all: Colleen

Colleen: Colleen.o
	cc -g3 -no-pie -o Colleen Colleen.o

Colleen.o: Colleen.s
	nasm -f elf64 -g Colleen.s -o Colleen.o

clean:
	rm -f Colleen.o

fclean: clean
	rm -f Colleen

re: fclean all

test:
	./Colleen > tmp_Colleen ; diff tmp_Colleen Colleen.s
