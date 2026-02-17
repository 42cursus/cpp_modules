
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


#### Q: How do i pin my task to a pecific core?
#### A: Use `taskset`

```bash
for i in $(seq 1 200); do taskset -c 0-15 ./a.out >/dev/null || break; done
for i in $(seq 1 200); do taskset -c 16-27 ./a.out >/dev/null || break; done
```

#### Q: How do i fix ASan “DEADLYSIGNAL” spam with the loader repeatedly trying to resolve a pthread symbol, and it only reproduces sometimes.
One widely reported root trigger is that the ASLR placing mappings in a way such that ASan’s shadow / reserved ranges
collide or early init takes a bad path, leading to crashes before anything useful exists.

* [Address space layout randomization](https://en.wikipedia.org/wiki/Address_space_layout_randomization)
* https://stackoverflow.com/questions/77894856/possible-bug-in-gcc-sanitizers
* https://stackoverflow.com/questions/78293129/c-programs-fail-with-asan-addresssanitizerdeadlysignal

# workaround: do `setarch $(uname -m) -R` to disable ASLR
```bash
setarch $(uname -m) -R ./a.out

# or in the loop
for i in $(seq 1 200); do setarch $(uname -m) -R taskset -c 0-15 ./a.out >/dev/null || break; done
```
