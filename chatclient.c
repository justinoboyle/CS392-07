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
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include "util.h"

int client_socket = -1;
char username[MAX_NAME_LEN + 1];
char inbuf[BUFLEN + 1];
char outbuf[MAX_MSG_LEN + 1];

int handle_stdin() {

}

int handle_client_socket() {

}

int main(int argc, char *argv[]) {
    
}