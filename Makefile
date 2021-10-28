CMAKE ?= cmake
INSTALL_PATH ?= cmake-build
TARGET_NAME ?= blackjack

.PHONY: build
build:
	mkdir -p $(INSTALL_PATH)
	$(CMAKE) -DCMAKE_BUILD_TYPE=Debug -G "CodeBlocks - Unix Makefiles" -S . -B $(INSTALL_PATH)
	$(CMAKE) --build $(INSTALL_PATH) --target $(TARGET_NAME) -- -j 2

.PHONY: run
run:
	$(INSTALL_PATH)/$(TARGET_NAME)
