CC := g++
BUILDDIR := build
SRCDIR := src
TARGET := bin/tmachine

SRCEXT := cpp
CFLAGS := -Wall -std=c++11
INC := -I include
LIB :=
SOURCES := $(shell find $(SRCDIR)/*.$(SRCEXT))
OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))

$(TARGET): $(OBJECTS)
	@echo " Linking The Time Machine..."
	@mkdir -p bin
	$(CC) $^ -o $(TARGET) $(LIB)
	@echo " Done!"

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@echo " Building '$@'..."
	@mkdir -p $(BUILDDIR)
	$(CC) $(CFLAGS) $(INC) -c -o $@ $<

clean:
	@echo -n " Cleaning up..."
	@if [ -d "$(BUILDDIR)" ]; then rm -r  "$(BUILDDIR)"; fi
	@if [ -d "bin" ]; then rm -r  "bin"; fi
	@echo " done!"

.PHONY: clean
