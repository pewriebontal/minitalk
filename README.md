# Minitalk

Minitalk is a project that allows two programs to communicate using UNIX signals.

## Structure

The project consists of two main C files: `server.c` and `client.c`, and a library of utility functions located in the `libft` directory.

- `server.c`: This program waits for signals from the client and prints the received message to the console.
- `client.c`: This program takes the server's PID and a string as arguments. It converts the string into binary and sends it to the server using UNIX signals.
- `libft`: This directory contains a library of utility functions used by the server and client programs.

## Usage

1. Compile the project using the Makefile: `make all`
2. Start the server: `./server`
3. In another terminal, send a message to the server: `./client [PID] [message]`

## License

This project is licensed under the GNU General Public License v3.0 - see the [LICENSE](LICENSE) file for details.