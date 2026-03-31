#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <string.h>

static char *escape_str(const char *str)
{
    if (!str || !str[0])
        return NULL;

    size_t size = strlen(str);
    char *out = malloc(size * 2 + 1);
    if (!out)
        return NULL;

    size_t j = 0;
    for (size_t i = 0; i < size; i++)
    {
        if (str[i] == '\n')      { out[j++] = '\\'; out[j++] = 'n';  }
        else if (str[i] == '\t') { out[j++] = '\\'; out[j++] = 't';  }
        else if (str[i] == '\r') { out[j++] = '\\'; out[j++] = 'r';  }
        else if (str[i] == '\\') { out[j++] = '\\'; out[j++] = '\\'; }
        else if (str[i] == '"')  { out[j++] = '\\'; out[j++] = '"';  }
        else if (!isprint((unsigned char)str[i]))
            out[j++] = '?';
        else
            out[j++] = str[i];
    }
    out[j] = '\0';
    return out;
}

static char *escape_double_quote(const char *str)
{
    if (!str || !str[0])
        return NULL;

    size_t size = strlen(str);
    char *out = malloc(size * 2 + 1);
    if (!out)
        return NULL;

    size_t j = 0;
    for (size_t i = 0; i < size; i++)
    {
        if (str[i] == '"')  { out[j++] = '\\'; out[j++] = '"';  }
        else if (!isprint((unsigned char)str[i]))
            out[j++] = '?';
        else
            out[j++] = str[i];
    }
    out[j] = '\0';
    return out;
}

static int search_landmark(FILE* file){
	fseek(file, 0, SEEK_SET);
	char* line = NULL;
	size_t rded = 0;
	char* found = NULL;
	int line_count = 0;
	while (getline(&line, &rded, file) != -1) {
		printf("%s", line);
		found = strstr(line, "//LANDMARK"); 
		if (found != NULL)
		{
			printf("MOTIF TROUVE: ligne %d\n", line_count);
			free(line);
			return line_count;
		}
		free(line);
		line = NULL;
		line_count++;
	}
	free(line);
	return -1;
}

static int insert_into_section(char* arg, const char* name_out){
    	FILE *file = fopen(arg, "r");
	fseek(file, 0, SEEK_SET);
	int landmark= search_landmark(file);

	FILE* out = fopen(name_out, "a+");
	fseek(file, 0, SEEK_SET);
	int count = 0;
	char* line = NULL;
	size_t rded = 0;
	char* toInsert = NULL;
	int nbLineLandMark = search_landmark(out);
	printf("%s: quining begining\n", __FUNCTION__);

	fclose(out);
	return 0;
}

static char* create_name_out(const char* fileToBeCloned){
	if (strlen(fileToBeCloned) > 48)
		return NULL;
	char *name_concat = malloc(50);
	name_concat[0] = 0;
	for (int i = 0; fileToBeCloned[i] != 0; i++){
		name_concat[i] = fileToBeCloned[i];
		if (fileToBeCloned[i + 1] == 0){
			name_concat[i + 1] = '.';
			name_concat[i + 2] = 'i';
		}
	}
	return name_concat;
}

static void cloning_file(char* fileToBeCloned, char* name_out){
	FILE* in = fopen(fileToBeCloned, "r");
	FILE* out = fopen(name_out, "w");
	char* line = NULL;
	size_t rded = 0;
	int line_count = 0;
	while (getline(&line, &rded, in) != -1) {
		fprintf(out, "%s", line);
		free(line);
		line = NULL;
		line_count++;
	}
	printf("%s: clonage finis\n", __FUNCTION__);
	free(line);
	fclose(out);
}

int main(int argc, char **argv)
{
    if (argc != 2)
        return 1;

    char* name_out = create_name_out(argv[1]);
    cloning_file(argv[1], name_out);
    insert_into_section(argv[1], name_out);
    return 0;
}
