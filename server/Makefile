###############################################################################
# Name        : makefile
# Author      : Justin O'Boyle & Celina Peralta
# Date        : 27 Apr 2021
# Description : chatserver implementation.
# Pledge      : I pledge my honor that I have abided by the Stevens Honor System.
##############################################

CC     = gcc
C_FILE = $(wildcard *.c) $(wildcard *.h)
TARGET = chatserver
TARGET_ZIP_FILE = chatserver.zip
CFLAGS = -O3 -Wall -Werror -pedantic-errors -pthread
ENDFLAGS = -lm

all:
	$(CC) $(CFLAGS) $(C_FILE) -o $(TARGET) $(ENDFLAGS)
clean:
	rm -f $(TARGET)