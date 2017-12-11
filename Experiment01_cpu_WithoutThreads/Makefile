
GCC := g++

OUTPUT := cpu_01
SOURCES := $(wildcard *.cpp)
CCFLAGS := -std=c++11 -pthread

all: $(OUTPUT)
	
$(OUTPUT):
	$(GCC) -o $(OUTPUT) $(CCFLAGS) $(SOURCES)
	
clean:
	rm $(OUTPUT)
	
.PHONY: all
