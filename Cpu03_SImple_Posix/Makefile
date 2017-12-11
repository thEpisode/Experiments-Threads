GCC := g++

OUTPUT := posix
SOURCES := $(wildcard *.cpp)
GCCFLAGS := -std=c++11 -pthread

ALL: $(OUTPUT)

$(OUTPUT):
	$(GCC) -o $(OUTPUT) $(GCCFLAGS) $(SOURCES)

clean:
	rm $(OUTPUT)

.PHONY: all
