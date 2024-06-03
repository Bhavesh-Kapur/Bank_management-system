
compiler = gcc

CFLAGS = -I/opt/homebrew/opt/mysql/include
DFLAGS = -L/opt/homebrew/opt/mysql/lib -lmysqlclient

src = main.c backend.c

exe = final

$(exe): $(src) link.h
	$(compiler) $(src) -o $(exe) $(CFLAGS) $(DFLAGS)

clean:
	rm -f $(exe)

.PHONY: clean


