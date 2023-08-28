#!/usr/bin/env bash

# Adapted from https://github.com/godotengine/godot/blob/031f6deefb080d4d7634d8190334a7049f265146/misc/scripts/clang_tidy.sh

# Loops through all code files tracked by Git.
git ls-files -- '*.cc' '*.h' |
while read -r f; do
    clang-tidy --quiet --fix -checks=google-*,modernize-*,clang-analyzer-*,-clang-analyzer-cplusplus*,readability-*,openmp-*,performance-* "$f" &> /dev/null
    clang-format --Wno-error=unknown -i --style=google "$f"
done

diff=$(git diff --color)

# If no diff has been generated all is OK, clean up, and exit.
if [ -z "$diff" ] ; then
    printf "\e[1;32m*** Files in this commit comply with the clang-tidy style rules.\e[0m\n"
    exit 0
fi

# A diff has been created, notify the user, clean up, and exit.
printf "\n\e[1;33m*** The following changes must be made to comply with the formatting rules:\e[0m\n\n"
# Perl commands replace trailing spaces with `·` and tabs with `<TAB>`.
printf "$diff\n" | perl -pe 's/(.*[^ ])( +)(\e\[m)$/my $spaces="·" x length($2); sprintf("$1$spaces$3")/ge' | perl -pe 's/(.*[^\t])(\t+)(\e\[m)$/my $tabs="<TAB>" x length($2); sprintf("$1$tabs$3")/ge'

printf "\n\e[1;91m*** Please fix your commit(s) with 'git commit --amend' or 'git rebase -i <hash>'\e[0m\n"
exit 1
