SH = nu
CC = g++ # or clang++, but that doesn't seem to work for debugging so use g++ for now
# ASM = -S # dump into main.s asm file
DEBUG = -g # emit debug sybols
# OPT = -O3 # optimize with level 3 optimization
# you can add flags like this, to enable them just uncomment them
FLAGS = ${DEBUG}${ASM}${OPT}
# target name of output executable, "a" and "out" are most common names
TARGET_NAME = a

SRCS = main.cpp $(wildcard src/*.cpp) # add every ".cpp" file in "cpp/" to the source list, also add the main.cpp file
OBJS = $(patsubst main.cpp,build/main.o,$(patsubst src/%.cpp,build/%.o,$(SRCS))) # parse so the ".o" files are emitted in build.o for incremental compilation

build: ${OBJS}
	${CC} ${FLAGS} $^ -o ${TARGET_NAME}.exe

b: build

run: build
	${SH} -c "./${TARGET_NAME}"

r: run

build/main.o: main.cpp
	${SH} -c "mkdir build"
	${CC} ${FLAGS} -c $^ -o $@

build/%.o: src/%.cpp
	${CC} ${FLAGS} -c $^ -o $@

clean:
	${SH} -c "rm -rf build/"
	${SH} -c "rm -f ${TARGET_NAME}.exe"
