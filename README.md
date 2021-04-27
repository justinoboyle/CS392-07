# CS 392 Assignment 7 TCP/IP Chat Client

This assignment requires you to work with the sockets API in the C programming language. You will create a chat client that is able to communicate with a server. The client will send messages to the server, which is then able to broadcast the message to all the other clients on the system. Similarly, the client will be able to receive messages directly from the server, thus enabling the user to read messages sent by all other clients on the system.

## Specifications

Your program should be written in a source file called `chatclient.c`. The makefile should produce a binary called chatclient.

### Requirements

- [x] [Command line arguments](https://github.com/justinoboyle/CS392-07/issues/1)
- [x] [Prompting for a username](https://github.com/justinoboyle/CS392-07/issues/2)
- [ ] [Establishing connection](https://github.com/justinoboyle/CS392-07/issues/3)
- [ ] [Handling activity on file descriptors (sockets)](https://github.com/justinoboyle/CS392-07/issues/4)

## Submission Requirements

Submit a zip containing called `chatclient.zip` that contains `chatclient.c`, `util.`h, and your `makefile`. Do not make any modifications to the server code, and do not supply the server code or binary. We will compile the server code as-is and test your client against it.

The client binary is available for you to compare against your solution.