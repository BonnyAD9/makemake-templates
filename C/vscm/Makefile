CC:=${cc}
TARGET:=${name ? name : mname ? mname : 'main'}${ext ? ext : _WINDOWS ? '.exe' : }
CFLAGS:=${dflags}${aflags ? ' ' aflags : }${adflags ? ' ' adflags : }
RFLAGS:=${rflags}${aflags ? ' ' aflags : }${arflags ? ' ' arflags : }
CFILES:=${mname ? mname : 'main'}.c

.PHONY: clean
.PHONY: install

debug: $(CFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(CFILES)

release: $(CFILES)
	$(CC) $(RFLAGS) -o $(TARGET) $(CFILES)

install:
	sudo cp -i $(TARGET) /bin/$(TARGET)

uninstall:
	sudo rm -i /bin/$(TARGET)

clean:
	${_WINDOWS ? 'del' : 'rm'} $(TARGET)
