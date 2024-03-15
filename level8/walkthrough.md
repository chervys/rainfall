# level8

For this level, here are the important informations about this program:  
it waits for commands from the user (auth, login, service, reset) and the login
command will give us a terminal if `auth[32]` is different from 0, the problem
being that `auth` won't let us write more than 30 or 31 chars. The solution is to
give a small parameter to `auth` and then give a long parameter to `service`.
Because they are both stored on the heap and `service` is right next to `auth`,
the line will actually compare a character that belongs to `service` instead
of `auth`.

The exploit:
 - `./level8`
 - `auth AAAA`
 - `service AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA`
 - `login`