#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>


int
main(int argc, char** argv) {
	if (argc == 1) {
		fprintf(stderr, "Must pass extra arguments\n");
		return EXIT_FAILURE;
	}

	// Throws out the first argument
	// This is the only good thing about arrays being the same as pointers
	// in c
	argv++;

	int child_pid = fork();

	if (child_pid == 0) {

		// Clone stderr in the *rare* event exec fails.
		int err_fd = fcntl(2, F_DUPFD_CLOEXEC, 3);

		// cd /
		chdir("/");

		close(0);
		close(1);
		close(2);

		open("/dev/null", O_RDWR);

		dup(0);
		dup(0);

		execvp(argv[0], argv);

		// Exec failed, report this
		FILE* errclone = fdopen(err_fd, "w");
		fprintf(errclone, "Exec failed!\nReason: %s\n", strerror(errno));
		return EXIT_FAILURE;
	} else if (child_pid < 0) {
		fprintf(stderr, "AAAAAAAA\nfork failed!!!!\n");
		return EXIT_FAILURE;
	} else {
		printf("Daemon pid is %d\n", child_pid);
		return EXIT_SUCCESS;
	}
}
