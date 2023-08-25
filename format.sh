find ./src -regex '.*\.\(cpp\|hpp\|cc\|cxx\h\)' -exec clang-format -i {} \;
find ./test -regex '.*\.\(cpp\|hpp\|cc\|cxx\h\)' -exec clang-format -i {} \;