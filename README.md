# Daemonize
A stupid daemon spawner.

This isn't anything impressive but I wanted to try & implement one.
Obviously this only works through unix.

There are no special arguments, all invocations follow the form
`daemonize subcommand ...`
No more, no less.

## Building
This does not need any special compiler arguments or libraries, just the
POSIX library.
