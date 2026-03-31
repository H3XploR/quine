#include <stdio.h>
/*	Le commentaire en dehores du programme	*/

void	the_fonction_needed(void){
	const char* str = "#include <stdio.h>\n/*\tLe commentaire en dehores du programme */\n\nvoid\tthe_fonction_needed(void){\n\tconst char* str = %c%s%c\n\tprintf(str, 34, str, 34);\n\treturn;\n}\n\nint\tmain(void){\n/*	LA FONCTION PRINCIPALE	*/\n\tthe_fonction_needed();\n\treturn 0;\n}\n";
	printf(str, 34, str, 34);
	return;
}

int	main(void){
/*	LA FONCTION PRINCIPALE	*/
	the_fonction_needed();
	return 0;
}
