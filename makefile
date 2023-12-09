CC = gcc
CFLAGS = -std=c11 -Wall -g -Iinclude -O2

SFILES = $(wildcard *.c)
OFILES = $(SFILES:.c=.o)
OUT = main

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

$(OUT): $(OFILES)
	$(CC) $^ -o $@

all: $(OUT)

clean:
	@rm -f a.out
	@rm -f $(OFILES) $(OUT)
