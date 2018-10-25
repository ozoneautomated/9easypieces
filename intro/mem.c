#include <u.h>
#include <libc.h>
#include "common.h"

void
main(int argc, char *argv[])
{
	if(argc != 2) {
		fprint(2, "usage: mem <value>\n");
		exits(0);
	}

	int *p;
	p = malloc(sizeof(int));
	assert(p != nil);
	print("(%d) addr pointed to by p: %p\n", getpid(), p);
	*p = atoi(argv[1]);
	while (1) {
		spin(1);
		*p = *p + 1;
		print("(%d) value of p: %d\n", getpid(), *p);
	}
	exits(0);
}
