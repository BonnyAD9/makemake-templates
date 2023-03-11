CC:=${cc}
TARGET:=${name ? name : mname ? mname : 'main'}${ext ? ext : _WINDOWS ? '.exe' : }
CFLAGS:=${dflags}${aflags ? ' ' aflags : }${adflags ? ' ' adflags : }
RFLAGS:=${rflags}${aflags ? ' ' aflags : }${arflags ? ' ' arflags : }
FLAGS:=$(CFLAGS)

SRC:=$(wildcard src/*.c)
OBJ:=$(patsubst src/%.c, obj/%.o, $(SRC))

# call the get-deps script that creates dependency files
DISCARD:=$(shell bash get-deps)

-include $(wildcard deps/*.d)

.DEFAULT_GOAL:=build

build: $(OBJ)
	$(CC) $(FLAGS) $^ -o $(TARGET)

release:
	make build 'FLAGS=$(CFLAGS)'

obj/%.o: src/%.c
	$(CC) $(FLAGS) -c -o $@ $<

install:
	sudo cp $(TARGET) /bin/target

clean:
	rm obj/debug/*.o || true
	rm obj/release/*.o || true
	rm $(TARGET) || true
