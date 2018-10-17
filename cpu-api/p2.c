#include <u.h>
#include <libc.h>

void
main(int argc, char *argv[])
{
	print("hello world (pid:%d)\n", getpid());

	int rc = rfork(RFPROC);

	if (rc < 0)
		exits("fork failed\n");
	else if (rc == 0)
		print("hello. i am child (pid:%d)\n", getpid());
	else {
		int rcwait = waitpid();
		print("hello. i am parent of %d (rcwait:%d) (pid:%d)\n", rc, rcwait, getpid());
	}

	exits(0);
}
