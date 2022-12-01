CC=gcc
CFLAGS=-I.
DEPS = Prehandle.h
OBJ = Preproc.o Prehandle.o

%.o: %.c $(DEPS)
		$(CC) -c -o $@ $< $(CFLAGS)

Preproc: $(OBJ)
		$(CC) -o $@ $^ $(CFLAGS)

# .PHONY: clean

# clean:
# 	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 