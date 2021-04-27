/*
 * Name        : mtsieve.c
 * Author      : Justin O'Boyle & Celina Peralta
 * Date        : 27 Apr 2021
 * Description : chatclient implementation.
 * Pledge      : I pledge my honor that I have abided by the Stevens Honor System.
 */

#include <arpa/inet.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include "util.h"

#define ERR_USAGE       "Usage: %s <server IP> <port>\n"
#define ERR_INVALID_IP  "Error: Invalid IP address '%s'.\n"

// int client_socket = -1;
// char username[MAX_NAME_LEN + 1];
// char inbuf[BUFLEN + 1];
// char outbuf[MAX_MSG_LEN + 1];

int handle_stdin() {
    return 1;
}

int handle_client_socket() {
    return 1;
}

char* fixAddress(char* a) {
    if(strcmp(a, "localhost") == 0)  
        return "127.0.0.1";
    return a;
}

int main(int argc, char *argv[]) {
    if(argc != 3) {
        fprintf(stderr, ERR_USAGE, argv[0]);
        return EXIT_FAILURE;
    }

    unsigned char addr[sizeof(struct in6_addr)];

    // if successful, inet_pton() returns 1
    if(inet_pton(AF_INET, fixAddress(argv[1]), addr) != 1) {
        fprintf(stderr, ERR_INVALID_IP, fixAddress(argv[1]));
        return EXIT_FAILURE;
    }

    int* _port = malloc(sizeof(int));

    if(parse_int(argv[2], _port, "port number") == false) {
        return EXIT_FAILURE;
    }

    // dereference
    int port = *_port;
    free(_port);
    printf("Debug: %i | ", port);
    printf("Parse success\n");
}