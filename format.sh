#!/usr/bin/env bash

# Loops through all code files tracked by Git.
git ls-files -- '*.cc' '*.h' |
while read -r f; do
    clang-format --Wno-error=unknown -i --style=google "$f"
done
