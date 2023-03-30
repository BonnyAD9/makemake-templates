CC:=${cxx}
TARGET:=${name ? name : mname ? mname : 'main'}${ext ? ext : _WINDOWS ? '.exe' : }
CFLAGS:=${dflags}${aflags ? ' ' aflags : }${adflags ? ' ' adflags : }
RFLAGS:=${rflags}${aflags ? ' ' aflags : }${arflags ? ' ' arflags : }

SRC:=$(wildcard src/*.cpp)
DOBJ:=$(patsubst src/%.cpp, obj/debug/%.o, $(SRC))
ROBJ:=$(patsubst src/%.cpp, obj/release/%.o, $(SRC))

-include dep.d

.DEFAULT_GOAL:=debug

.PHONY: debug
.PHONY: release
.PHONY: install
.PHONY: clean
.PHONY: rel
.PHONY: deb


debug:
	mkdir -p obj/debug
	clang -MM $(SRC) | sed -r 's/^.*:.*$$/obj\/debug\/\0/' > dep.d
	make deb

release:
	mkdir -p obj/release
	clang -MM $(SRC) | sed -r 's/^.*:.*$$/obj\/release\/\0/' > dep.d
	make rel

deb: $(DOBJ)
	$(CC) $(CFLAGS) $^ -o $(TARGET)

rel: $(ROBJ)
	$(CC) $(RFLAGS) $^ -o $(TARGET)

obj/release/%.o: src/%.cpp
	$(CC) $(RFLAGS) -c -o $@ $<

obj/debug/%.o: src/%.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

install:
	sudo cp -i $(TARGET) /bin/target

clean:
	rm obj/debug/*.o || true
	rm obj/release/*.o || true
	rm $(TARGET) || true
