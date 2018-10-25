#include <u.h>
#include <libc.h>
#include "common.h"

int
main(int argc, char *argv[])
{
	if (argc != 2) {
		fprint(2, "usage: cpu <string>\n");
		exits(0);
	}

	char *str = argv[1];

	while (1) {
		spin(1);
		print("%s\n", str);
	}
	exits(0);
}
