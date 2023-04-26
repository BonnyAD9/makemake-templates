CXX:=${cxx}
TARGET:=${name ? name : mname ? mname : 'main'}${ext ? ext : _WINDOWS ? '.exe' : }
CFLAGS:=${dflags}${aflags ? ' ' aflags : }${adflags ? ' ' adflags : }
RFLAGS:=${rflags}${aflags ? ' ' aflags : }${arflags ? ' ' arflags : }
${ldflags ? 'LDFLAGS:=' ldflags '\n' : }CFILES:=${mname ? mname : 'main'}.cpp

.PHONY: clean install

debug: $(CFILES)
	$(CXX) $(CFLAGS) -o $(TARGET) $(CFILES) $(LDFLAGS)

release: $(CFILES)
	$(CXX) $(RFLAGS) -o $(TARGET) $(CFILES) $(LDFLAGS)
${_WINDOWS ? : '
install:
	sudo cp -i $(TARGET) /bin/$(TARGET)

uninstall:
	sudo rm -i /bin/$(TARGET)
'}
clean:
	-${_WINDOWS ? 'del' : 'rm'} $(TARGET)
