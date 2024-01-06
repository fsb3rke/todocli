if NOT EXIST build/ (
	mkdir build
)

g++ -Wall -Werror -Wpedantic src/main.cpp src/fs.cpp src/CommandHandlerer.cpp src/cc.cpp -std=c++17 -Ilib -o build/main.exe
