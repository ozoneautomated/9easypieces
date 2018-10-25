#include <u.h>
#include <libc.h>

void
main(void)
{
	int fd = create("/tmp/file", ORDWR|OTRUNC, 0644);
	assert(fd >= 0);
	char buffer [20];
	sprint(buffer, "hello world\n");
	long rc = write(fd, buffer, strlen(buffer));
	assert(rc == (strlen(buffer)));
	close(fd);
	exits(0);
}
