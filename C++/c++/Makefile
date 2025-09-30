TARGET=${target}
BUILD_TYPE?=Release
PARALLEL?=-j $(shell nproc)
SOURCES=$(shell find src/ -name '*.cpp')
HEADERS=$(shell find src/ -name '*.hpp')
FILES=$(SOURCES) $(HEADERS)
BUILD_DIR=build

.PHONY: build
build:
	if [ ! -f $(BUILD_DIR)/Makefile ]; then \
		mkdir -p $(BUILD_DIR); \
		cd $(BUILD_DIR) \
			&& cmake .. -DCMAKE_BUILD_TYPE=$(BUILD_TYPE); \
	fi
	cd $(BUILD_DIR) && $(MAKE) $(PARALLEL)

.PHONY: debug
debug:
	$(MAKE) BUILD_TYPE=Debug

.PHONY: release
release:
	$(MAKE) BUILD_TYPE=Release

.PHONY: fmt
fmt:
	clang-format -i $(FILES)

.PHONY: cppcheck
cppcheck:
	cppcheck --check-level=exhaustive $(FILES)

.PHONY: tidy
tidy: debug
	run-clang-tidy $(PARALLEL) -use-color -quiet -p $(BUILD_DIR) \
		-header-filter=src/ 'src/.*\.cpp' 'src/.*\.hpp'

.PHONY: check
check: fmt cppcheck tidy

.PHONY: clean
	-rm -rf target
