CXX:=${cxx}
TARGET:=${name ? name : mname ? mname : 'main'}${ext ? ext : _WINDOWS ? '.exe' : }
CFLAGS:=${dflags}${aflags ? ' ' aflags : }${adflags ? ' ' adflags : }
RFLAGS:=${rflags}${aflags ? ' ' aflags : }${arflags ? ' ' arflags : }
${ldflags ? 'LDFLAGS:=' ldflags '\n' : }
SRC:=$(wildcard src/*.cpp)
DOBJ:=$(patsubst src/%.cpp, obj/debug/%.o, $(SRC))
ROBJ:=$(patsubst src/%.cpp, obj/release/%.o, $(SRC))

-include dep.d

.DEFAULT_GOAL:=debug

.PHONY: debug release install clean rel deb


debug:
	mkdir -p obj/debug
	clang -MM $(SRC) | sed -r 's/^.*:.*$$/obj\/debug\/\0/' > dep.d
	$(MAKE) deb

release:
	mkdir -p obj/release
	clang -MM $(SRC) | sed -r 's/^.*:.*$$/obj\/release\/\0/' > dep.d
	$(MAKE) rel

deb: $(DOBJ)
	$(CXX) $(CFLAGS) $^ -o $(TARGET) $(LDFLAGS)

rel: $(ROBJ)
	$(CXX) $(RFLAGS) $^ -o $(TARGET) $(LDFLAGS)

obj/release/%.o: src/%.cpp
	$(CXX) $(RFLAGS) -c -o $@ $<

obj/debug/%.o: src/%.cpp
	$(CXX) $(CFLAGS) -c -o $@ $<

install:
	sudo cp -i $(TARGET) /usr/bin/target

uninstall:
	sudo rm -i /usr/bin/$(TARGET)

clean:
	-rm obj/debug/*.o obj/release/*.o $(TARGET) dep.d
