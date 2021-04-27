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
#define ERR_PORT_RANGE  "Error: Port must be in range [1024, 65535].\n"
#define ERR_UNAME_LONG  "Sorry, limit your username to %d characters.\n"

#define STR_USER_PROMPT "Enter your username: "

#define PORT_RANGE_MIN  1024
#define PORT_RANGE_MAX  65535

// int client_socket = -1;
// char username[MAX_NAME_LEN + 1];
// char inbuf[BUFLEN + 1];
// char outbuf[MAX_MSG_LEN + 1];

int readUsername(char* uname);

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

    if(port < PORT_RANGE_MIN || port > PORT_RANGE_MAX) {
        fprintf(stderr, ERR_PORT_RANGE);
        return EXIT_FAILURE;
    }

    char* uname = malloc((MAX_NAME_LEN + 2) * sizeof(char));

    readUsername(uname);

    printf("Hello, %s. Let's try to connect to the server.\n", uname);

    free(uname);

    printf("Debug: %i | ", port);
    printf("Parse success\n");
}

int readUsername(char* uname) {

    int ACTIVE = 1;
    int BYTES_READ = -1;

    while(ACTIVE) {
        char tmp[BUFLEN];
        fflush(stdin);
        printf(STR_USER_PROMPT);
        fflush(stdout);

        if((BYTES_READ = read(STDIN_FILENO, tmp, BUFLEN)) == -1) {
            fprintf(stderr, "%i Error: Could not read username.\n", BYTES_READ);
            continue;
        }

        tmp[strcspn(tmp, "\n")] = 0;

        if(BYTES_READ < 2) {
            // EOF, flush line
            if(BYTES_READ == 0)
                printf("\n");
            // re prompt
            continue;
        } else {
            if((BYTES_READ-1) > MAX_NAME_LEN || strlen(tmp) > MAX_NAME_LEN) {
                fprintf(stderr, ERR_UNAME_LONG, MAX_NAME_LEN);
                ACTIVE = 1;
                continue;
            } else {
                strcpy(uname, tmp);
                ACTIVE = 0;
            }
        }
    }
    return 0;
}