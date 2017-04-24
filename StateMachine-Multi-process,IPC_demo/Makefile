############################################################
# Copyright (c) 2017, Gerald Selvino 
# <gerald.selvino@protonmail.com> All rights reserved.
#
# A simple makefile to compile and build the
# cross platform POSIX multiprocess shared memory IPC
# state machine 
############################################################

CC = g++
CFLAGS  = -g -Wall -pthread -lrt

# default target, we name it to statemachine
#
default: statemachine

# To create the executable file statemachine
#
statemachine:  PosixIPC.o main.o
	$(CC) $(CFLAGS) -o statemachine PosixIPC.o main.o

# To create the object file for PosixIPC
#
PosixIPC.o:  PosixIPC.cpp PosixIPC.h 
	$(CC) $(CFLAGS) -c PosixIPC.cpp

# To create the object file for main.cpp
#
main.o:  main.cpp PosixIPC.h
	$(CC) $(CFLAGS) -c main.cpp

# cleans the created object files and backup files
#
clean: 
	$(RM) count *.o *~
