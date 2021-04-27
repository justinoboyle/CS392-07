###############################################################################
# Name        : makefile
# Author      : Justin O'Boyle & Celina Peralta
# Date        : 27 Apr 2021
# Description : chatclient implementation.
# Pledge      : I pledge my honor that I have abided by the Stevens Honor System.
##############################################

CC     = gcc
C_FILE = $(wildcard *.c) $(wildcard *.h)
TARGET = chatclient
TARGET_ZIP_FILE = chatclient.zip
CFLAGS = -O3 -Wall -Werror -pedantic-errors -pthread
ENDFLAGS = -lm

all:
	$(CC) $(CFLAGS) $(C_FILE) -o $(TARGET) $(ENDFLAGS)
sort:
	$(CC) $(CFLAGS) $(C_FILE) -o $(TARGET)
clean:
	rm -f $(TARGET)
test:
	rm -f $(TARGET)
	./test.sh
zip:
	rm -rf $(target)
	zip -r $(TARGET_ZIP_FILE) $(wildcard *.c) $(wildcard *.h) Makefile