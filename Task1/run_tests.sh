#!/bin/bash

gcc -o task1 insertion_sort.c

if [ ! -f task1 ]; then
    echo "Compilation failed!"
    exit 1
fi

run_test() {
    local test_in=$1
    local test_out=$2

    local input_array=($(cat "$test_in"))
    local length=${#input_array[@]}

    program_output=$(./task1 "${input_array[@]}")

    if echo "$program_output" | diff -q - "$test_out"; then
        echo "Test case $(basename "$test_in" .in) passed!"
    else
        echo "Test case $(basename "$test_in" .in) failed!"
        echo "Expected output:"
        cat "$test_out"
        echo "Actual output:"
        echo "$program_output"
    fi
}

# Run all test cases in the current directory
for test_in in ./*.in; do
    test_out="${test_in%.in}.out"
    if [ ! -f "$test_in" ] || [ ! -f "$test_out" ]; then
        echo "Test files $test_in or $test_out do not exist."
        continue
    fi
    run_test "$test_in" "$test_out"
done

