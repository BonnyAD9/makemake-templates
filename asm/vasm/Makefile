LD:=${cc}
AC:=${ac}
TARGET:=${name ? name : mname ? mname : 'main'}${ext ? ext : _WINDOWS ? '.exe' : }
CFLAGS:=${dflags}${aflags ? ' ' aflags : }${adflags ? ' ' adflags : }
CFILES:=${mname ? mname : 'main'}.asm
OBJ:=${mname ? mname : 'main'}.o

.PHONY: clean
.PHONY: debug

debug: $(CFILES)
	$(AC) -felf32 -F dwarf -g $(CFILES) -o $(OBJ)
	$(LD) -m32 $(CFLAGS) -o $(TARGET) $(OBJ)

clean:
	-rm $(TARGET) $(OBJ)
