inc_dir = include
obj_dir = obj
src_dir = src

CC = gcc
CFLAGS = -I$(inc_dir)

_deps = hashtable.h
deps = $(patsubst %,$(inc_dir)/%,$(_deps))

_obj = hashtable.o main.o
obj = $(patsubst %,$(obj_dir)/%,$(_obj))

$(obj_dir)/%.o: $(src_dir)/%.c $(deps)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(obj)
	$(CC) -o $@ $^

.PHONY: clean
clean:
	rm -f $(obj_dir)/*.o $(inc_dir)/*~ *~ core
