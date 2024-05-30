
compiler = gcc

CFLAGS = -I/opt/homebrew/opt/mysql/include
DFLAGS = -L/opt/homebrew/opt/mysql/lib -lmysqlclient

src = main.c test.c

exe = final

$(exe): $(SRCS) link.h
	$(compiler) $(src) -o $(exe) $(CFLAGS) $(DFLAGS)

clean:
	rm -f $(exe)

.PHONY: clean


