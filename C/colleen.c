#include <stdio.h>
/*	Le commentaire en dehores du programme	*/

void	the_fonction_needed(void){
	const char* str = "#include <stdio.h>\n/*	Le commentaire en dehores du programme */\n\nvoid	the_fonction_needed(void){\n	const char* str = %c%s%c\n	printf(str, 34, str, 34);\n	return;\n}\n\nint	main(void){\n/*	LA FONCTION PRINCIPALE	*/\n	the_fonction_needed();\n	return 0;\n}\n";
	printf(str, 34, str, 34);
	return;
}

int	main(void){
/*	LA FONCTION PRINCIPALE	*/
	the_fonction_needed();
	return 0;
}
