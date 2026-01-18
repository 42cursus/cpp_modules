#!/usr/bin/env bash
set -u

BIN="./convert"

if [ ! -x "$BIN" ]; then
  echo "Error: $BIN not found or not executable"
  exit 1
fi

run_case() {
  local arg="$1"
  printf "\n===== input: [%s] =====\n" "$arg"
  "$BIN" "$arg"
  local rc=$?
  printf "exit code: %d\n" "$rc"
}

# Core examples from subject
run_case "0"
run_case "nan"
run_case "42.0f"

# Specials (all variants you should accept)
run_case "+inf"
run_case "-inf"
run_case "inf"
run_case "nanf"
run_case "+inff"
run_case "-inff"
run_case "inff"

# Characters
run_case "a"        # printable char
run_case "Z"
run_case " "        # space (printable, but your parsing might trim or treat oddly)
run_case "\n"       # will be passed as literal backslash-n? depends on shell, so skip if you hate ambiguity

# Non-displayable char via numeric input (0, 7 bell, 31 unit separator, 127 DEL)
run_case "7"
run_case "31"
run_case "127"

# Int boundaries and overflow
run_case "2147483647"
run_case "-2147483648"
run_case "2147483648"      # int overflow
run_case "-2147483649"     # int underflow

# Float/double formatting and suffix rules
run_case "42.0"
run_case "42.0f"
run_case "42f"             # should probably be invalid (subject usually expects digit(s).digit(s)f)
run_case ".5"              # decide if you accept, many implementations reject
run_case "0.5f"
run_case "1."
run_case "1.f"             # usually invalid in strict parsers

# Very large magnitudes (float overflow, double still OK)
run_case "1e39f"            # float overflow (should become inf?)
run_case "1e309"            # double overflow (inf)
run_case "-1e309"

# Tiny magnitudes (underflow)
run_case "1e-400"           # underflow to 0.0 in double on many libs
run_case "1e-50f"           # float underflow-ish

# Whitespace and junk (should be invalid unless you explicitly allow trimming)
run_case " 42"
run_case "42 "
run_case "42.0ff"
run_case "++1"
run_case "--1"
run_case "1.2.3"
run_case "abc"
run_case ""

echo
echo "Done. If anything crashes, congratulations, you found your bug."
