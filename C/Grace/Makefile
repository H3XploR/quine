.PHONY: all clean fclean re test

all: Grace

Grace: Grace.o
	cc -g3 -o Grace Grace.o

Grace.o: Grace.c
	cc -c -g3 Grace.c

clean:
	rm -f Grace.o

fclean: clean
	rm -f Grace

re: fclean all

test:
	./Grace > tmp_Grace ; diff tmp_Grace Grace.c
