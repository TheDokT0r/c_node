build:
    gcc -o c_node src/*.c

build-static:
    gcc -O2 -static -o c_node src/*.c
