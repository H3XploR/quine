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

static int search_end(FILE* file){
	fseek(file, 0, SEEK_SET);
	char* line = NULL;
	size_t rded = 0;
	char* found = NULL;
	int line_count = 0;
	while (getline(&line, &rded, file) != -1) {
		printf("%s", line);
		found = strstr(line, "//END"); 
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

static int insert_into_section(FILE* file, const char* name_out, const char* toInsert, int nbLine){
	if (strlen(name_out) > 48)
		return -1;
	int end = search_end(file);
	char name_concat[50] = {0};
	for (int i = 0; name_out[i] != 0; i++){
		name_concat[i] = name_out[i];
		if (name_out[i + 1] == 0){
			name_concat[i + 1] = '.';
			name_concat[i + 2] = 'i';
		}
	}
	printf("%s: name_concat for the moment: %s\n", __FUNCTION__, name_out);
	FILE* out = fopen(name_out, "w");
	if (end != -1){
		printf("%s: end recupere\n", __FUNCTION__);
	}
	else{
		printf("%s: end non trouve\n", __FUNCTION__);
	}
	fclose(out);
	return 0;
}

int main(int argc, char **argv)
{
    if (argc != 2)
        return 1;

    FILE *in = fopen(argv[1], "r+");
    char* line = NULL;
    size_t rded = 0;
    if (!in)
        return 1;
    while (1){
	if (getline(&line, &rded, in) == -1)
		break;
	//printf("%s", line);
	free(line);
	line = NULL;
    }
    int end_line_count = search_end(in);
    insert_into_section(in, argv[1], "INSERTED", end_line_count);
    free(line);
    fclose(in);
    return 0;
}
