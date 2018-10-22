#include <u.h>
#include <libc.h>

void
main(void)
{
	print("hello world (pid:%d)\n", getpid());

	int rc = rfork(RFPROC);

	if (rc < 0)
		exits("fork failed\n");
	else if (rc == 0) {
		close(1);
		/* below perm value is most likely wrong. */
		create("./p4.out", ORDWR|OTRUNC, 644);
		print("hello. i am child (pid:%d)\n", getpid());
		execl("/bin/wc", "wc", "p4.c", nil );
		print("you shouldn't see this...");
	}
	else {
		int rcwait = waitpid();
		print("hello. i am parent of %d (rcwait:%d) (pid:%d)\n", rc, rcwait, getpid());
	}

	exits(0);
}
