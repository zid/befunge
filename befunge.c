#include <stdlib.h>
#include "befunge.h"
#include "hashtable.h"

/* Befunge environment */
struct befunge
{
	Hashtable *ht;
	size_t y;
};

/* A befunge instruction */
struct instruction
{
	char c;

	size_t x, y;
};

/* Create a new befunge environment */
struct befunge *befunge_new(void)
{
	struct befunge *b;

	b = malloc(sizeof (struct befunge));
	if(!b)
		return NULL;

	b->ht = NULL;
	b->y = 0;
	return b;
}

/* Create and insert a befunge instruction into the hashtable */
static int befunge_instruction_insert(struct befunge *b, char c, size_t x, size_t y)
{
	struct instruction i;

	i = malloc(sizeof (struct instruction));
	if(!i)
		return 0;
	
	i->c = c;
	i->x = x;
	i->y = y;

	/* hashtable_insert(i, x, y); */
}

/* Add a line of source to the befunge environment */
int befunge_add_line(struct befunge *b, size_t len, const char *buf)
{
	size_t x;

	/* Walk the line inserting found symbols into the hashtable */
	for(x = 0; x<len; x++)
	{
		if(buf[x] != ' ')
		{
			int r;

			r = befunge_instruction_insert(b, buf[i], x, b->y);
			if(!r)
				return 0;
		}
	}

	/* Next befunge_add_line will operate on a new y coordinate */
	b->y++;

	return 1;
}

