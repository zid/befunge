#include <stdio.h>
#include <stdlib.h>
#include "befunge.h"

#define BUF_MAX 512

static int read_line(FILE *f, char *buf, size_t maxlen)
{
	size_t len = 0;

	while(1)
	{
		int c;

		c = fgetc(f);

		if(c == EOF || c == '\n') 
			return len;

		buf[len++] = c;
		if(len > maxlen)
			return -1;
	}
}

int main(int argc, char *argv[])
{
	FILE *f;
	char buf[BUF_MAX];
	Befunge *b;

	if(argc != 2)
	{
		printf("befunge [input]\n");
		return EXIT_SUCCESS;
	}

	f = fopen(argv[1], "rb");
	if(!f)
	{
		perror("Unable to open input file '%s'");
		return EXIT_FAILURE;
	}

	b = befunge_new();
	if(!b)

	while(1)
	{
		int len;

		len = read_line(f, buf, BUF_MAX);
		if(len < 0)
		{
			fprintf(stderr, "Line longer than %u, unable to parse.\n", 
				BUF_MAX);
			return EXIT_FAILURE;
		}

		if(len == 0)
			break;

		if(!befunge_add_line(b, len, buf))
		{
			fprintf(stderr, "Out of memory\n");
			return EXIT_FAILURE;
		}
	}

	/* befunge_compile(b); */

	/* befunge_spit_out_dot(b); */

	return EXIT_SUCCESS;
}
