${cc ? 'CC:=' cc '\n' : }TARGET:=${name ? name : mname ? mname : 'main'}${ext ? ext : _WINDOWS ? '.exe' : }
CFLAGS:=${dflags}${aflags ? ' ' aflags : }${adflags ? ' ' adflags : }
RFLAGS:=${rflags}${aflags ? ' ' aflags : }${arflags ? ' ' arflags : }
${ldflags ? 'LDFLAGS:=' ldflags '\n' : }CFILES:=${mname ? mname : 'main'}.c

.PHONY: clean install


debug: $(CFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(CFILES) $(LDFLAGS)

release: $(CFILES)
	$(CC) $(RFLAGS) -o $(TARGET) $(CFILES) $(LDFLAGS)
${_WINDOWS ? : '
install:
	sudo cp -i $(TARGET) /usr/bin/$(TARGET)

uninstall:
	sudo rm -i /usr/bin/$(TARGET)
'}
clean:
	-${_WINDOWS ? 'del' : 'rm'} $(TARGET)
