#include <u.h>
#include <libc.h>

void
main(void)
{
	print("hello world (pid:%d)\n", getpid());
	int rc = rfork(RFPROC);
	if (rc < 0) {
		fprint(2, "fork failed\n");
		exits(0);
	}
	else if (rc == 0)
		print("hello. i am child (pid:%d)\n", getpid());
	else 
		print("hello. i am parent of %d (pid:%d)\n", rc, getpid());

	exits(0);
}
