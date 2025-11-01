#!/bin/bash

set -e

if [ "$#" -lt 2 ]; then
	echo "Usage: $0 <source.cpp> <output_executable> [program_args...]"
	exit 1
fi

SRC="$1"
OUT="$2"
shift 2

CXXFLAGS="-std=c++23 -Wall -Werror -Wextra -Wpedantic -Wshadow"

g++ $CXXFLAGS "$SRC" -o "$OUT"

./"$OUT" "$@"
