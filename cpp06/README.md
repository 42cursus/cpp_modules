
#### Q: How do i get free standing functions prototypes from a cpp file?
#### A: use clang-query from clang-tools (`sudo apt install clang-tools`):
```bash
TERM=dumb clang-query ScalarConverter.cpp -c \
  'match functionDecl(isDefinition(), isExpansionInMainFile(), unless(cxxMethodDecl()), unless(isStaticStorageClass()))' \
  -- -std=c++98 -Iinclude -I. \
  | awk -F: '/note: "root" binds here/ { print $2 }' \
  | awk '!seen[$0]++' \
  | while read -r l; do
  sed -n "${l},+60p" ScalarConverter.cpp \
    | tr '\n' ' ' \
    | sed 's/[[:space:]]\+/ /g; s/^[[:space:]]*//; s/[[:space:]]*{.*$//; s/[[:space:]]*$//' \
    | sed 's/$/;/' \
    | grep --color=never -E '\) *;'
done  | awk '!seen[$0]++'
```