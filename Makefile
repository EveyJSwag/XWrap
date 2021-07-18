CC := g++
COMPILE_FLAGS := -std=c++17 -g -I./include -I./util -I/usr/X11R6/include
LINK_FLAGS := -g -L/usr/X11R6/lib -lX11
SOURCE_FILES := $(wildcard src/*cpp)
SOURCE_OBJECTS := $(patsubst %.cpp,%.o,$(SOURCE_FILES))

XWrapTestDriver : $(SOURCE_OBJECTS)
	$(CC) -o XWrapTestDriver $(LINK_FLAGS) $(SOURCE_OBJECTS)

%.o : %.cpp
	$(CC) -c  $(COMPILE_FLAGS) $< -o $@

.Phony clean:
	[ -f XWrapTestDriver ] && rm XWrapTestDriver;
	rm src/*.o;

# XWrapTest : 
#gcc -stdc++17 -g main.c -I/usr/X11R6/include -L/usr/X11R6/lib/ -lX11
