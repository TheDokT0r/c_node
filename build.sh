#!/bin/bash

# I know it's not something super cool like CMake or Meson, or a godforsaken Makefile, but it works and it's simple so who cares

gcc src/*.c -o c_node
echo "Build complete. Run with ./c_node"
