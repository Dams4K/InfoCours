.PHONY: all run exec debug clean cleanall

SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
GCH = $(SRC:.c=.gch)
EXEC = exe
CFLAGS += -Wall -Wextra -Wvla --std=c17
LINK += 

all: run

run: $(EXEC)
	./$(EXEC)

exec: $(EXEC)

$(EXEC): $(OBJ) $(LINK)
	gcc -o $@ $^ $(CFLAGS)
	@echo "Compilation terminée."

%.o: %.c
	gcc -o $@ -c $< $(CFLAGS)

clean:
	rm -f $(OBJ) $(GCH)

cleanall: clean
	rm -f $(EXEC)