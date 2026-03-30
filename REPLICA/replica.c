#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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

static into_insert_section(void)

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
	printf("%s", line);
	free(line);
	line = NULL;
    }
    free(line);
    fclose(in);
    return 0;
}
