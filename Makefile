# Author: Dominik Harmim <xharmi00@stud.fit.vutbr.cz>

EXECUTABLE := ims-project
BUILD_DIR := cmake-build-release
PACK := 02_xharmi00_xhertl04
DOC_DIR := doc
SRC_DIR := src
DOC := documentation.pdf


.PHONY: build
build: $(EXECUTABLE)

.PHONY: $(EXECUTABLE)
$(EXECUTABLE):
	mkdir -p $(BUILD_DIR)
	cd $(BUILD_DIR) && cmake -D CMAKE_BUILD_TYPE=Release ..
	cmake --build $(BUILD_DIR)


.PHONY: run
run:
	./$(BUILD_DIR)/$(EXECUTABLE) $(ARGS)


.PHONY: pack
pack: $(PACK).tar.gz

$(PACK).tar.gz: doc
	COPYFILE_DISABLE=1 tar -czf \
		$@ CMakeLists.txt Makefile README.md $(DOC) $(SRC_DIR)


.PHONY: doc
doc: $(DOC)

.PHONY: $(DOC)
$(DOC):
	cd $(DOC_DIR) && make
	cp $(DOC_DIR)/$(DOC) .


.PHONY: clean
clean:
	rm -rf $(BUILD_DIR) $(PACK).tar.gz $(DOC)
	cd $(DOC_DIR) && make clean
