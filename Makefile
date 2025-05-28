# DAT Creator Makefile
# A Qt5-based DAT file archive creator/manager

# Qt and compiler configuration
QMAKE = qmake
CXX = g++
CXXFLAGS = -std=c++11
BUILD_DIR = build

# Default target
all: $(BUILD_DIR)/Makefile
	$(MAKE) -C $(BUILD_DIR)

# Configure with qmake
$(BUILD_DIR)/Makefile: DAT.pro | $(BUILD_DIR)
	cd $(BUILD_DIR) && $(QMAKE) ../DAT.pro

# Create build directory
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Clean build artifacts
clean:
	rm -rf $(BUILD_DIR)

# Clean everything including generated files
distclean: clean
	rm -f Makefile.*
	rm -f ui_*.h
	rm -f moc_*.cpp
	rm -f *.o
	rm -f DAT

# Run the application
run: all
	./$(BUILD_DIR)/DAT

# Debug build
debug: QMAKE_ARGS = CONFIG+=debug
debug: clean $(BUILD_DIR)/Makefile
	$(MAKE) -C $(BUILD_DIR)

# Release build
release: QMAKE_ARGS = CONFIG+=release
release: clean $(BUILD_DIR)/Makefile
	$(MAKE) -C $(BUILD_DIR)

# Install dependencies (Ubuntu/Debian)
install-deps:
	@echo "Installing Qt5 development packages..."
	sudo apt-get update
	sudo apt-get install -y qt5-default qtbase5-dev qtbase5-dev-tools

# Help
help:
	@echo "DAT Creator - Build System"
	@echo ""
	@echo "Available targets:"
	@echo "  make           - Build the project (default)"
	@echo "  make run       - Build and run the application"
	@echo "  make debug     - Build with debug symbols"
	@echo "  make release   - Build optimized release version"
	@echo "  make clean     - Remove build artifacts"
	@echo "  make distclean - Remove all generated files"
	@echo "  make install-deps - Install Qt5 dependencies (Ubuntu/Debian)"
	@echo "  make help      - Show this help message"

.PHONY: all clean distclean run debug release install-deps help