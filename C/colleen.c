#include <stdio.h>
/*	Le commentaire en dehores du programme */

void	the_fonction_needed(void){
	const char* str = "#include <stdio.h>%c/*%cLe commentaire en dehores du programme */%c%cvoid%cthe_fonction_needed(void){%c%cconst char* str = %c%s%c;%c%cprintf(str, 10, 9, 10, 10, 9, 10, 9, 34, str, 34, 10, 9, 10, 9, 10, 10, 10, 9,10, 9, 9, 10, 9, 10, 9, 10, 10);%c%creturn;%c}%c%cint%cmain(void){%c/*%cLA FONCTION PRINCIPALE%c*/%c%cthe_fonction_needed();%c%creturn 0;%c}%c";
	printf(str, 10, 9, 10, 10, 9, 10, 9, 34, str, 34, 10, 9, 10, 9, 10, 10, 10, 9,10, 9, 9, 10, 9, 10, 9, 10, 10);
	return;
}

int	main(void){
/*	LA FONCTION PRINCIPALE	*/
	the_fonction_needed();
	return 0;
}
