SH = "C:\Program Files\nu\bin\nu.exe"
CC = g++
# ASM = -S
DEBUG = -g
# OPT = -O3
FLAGS = ${DEBUG} ${ASM} ${OPT}
CPP_OBJECT_LIST = build/main.o build/square.o build/board.o
TARGET_NAME = a

build: ${CPP_OBJECT_LIST}
	${CC} ${FLAGS} $^ -o ${TARGET_NAME}.exe

r: build
	${SH} -c "./${TARGET_NAME}"

build/main.o: main.cpp
	${CC} ${FLAGS} -c $^ -o $@

build/%.o: cpp/%.cpp
	${CC} ${FLAGS} -c $< -o $@

clean:
	${SH} -c "rm -v -f build/*"
	${SH} -c "rm -v -f ${TARGET_NAME}.exe"