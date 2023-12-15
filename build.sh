BUILD_DIR="./build"
if [ ! -d "$BUILD_DIR" ]; then
	mkdir "$BUILD_DIR"
fi

g++ -Wall -Werror -Wpedantic src/main.cpp src/fs.cpp src/CommandHandlerer.cpp src/cc.cpp -o build/main.obj
