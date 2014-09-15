#ifndef BEFUNGE_H
#define BEFUNGE_H

struct befunge;

typedef struct befunge Befunge;

Befunge *befunge_new(void);
int befunge_add_line(Befunge *, size_t, const char *);

#endif
