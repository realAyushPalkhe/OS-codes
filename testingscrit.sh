#!/bin/bash

# Function to check if a number is a palindrome
is_palindrome() {
    local num=$1
    local rev=$(echo $num | rev)
    if [ "$num" -eq "$rev" ]; then
        echo "$num is a Palindrome."
    else
        echo "$num is not a Palindrome."
    fi
}

# Function to check if a number is prime
is_prime() {
    local num=$1
    if [ $num -le 1 ]; then
        echo "$num is not a Prime number."
        return
    fi
    for ((i=2; i*i<=num; i++)); do
        if [ $((num % i)) -eq 0 ]; then
            echo "$num is not a Prime number."
            return
        fi
    done
    echo "$num is a Prime number."
}

# Function to generate Fibonacci series up to n terms
fibonacci_series() {
    local n=$1
    local a=0
    local b=1
    echo "Fibonacci Series up to $n terms:"
    for ((i=0; i<n; i++)); do
        echo -n "$a "
        fn=$((a + b))
        a=$b
        b=$fn
    done
    echo ""
}

# Function to check if a number is an Armstrong number
is_armstrong() {
    local num=$1
    local sum=0
    local temp=$num
    local digits=${#num}
    
    while [ $temp -gt 0 ]; do
        local digit=$((temp % 10))
        sum=$((sum + digit ** digits))
        temp=$((temp / 10))
    done
    
    if [ $sum -eq $num ]; then
        echo "$num is an Armstrong number."
    else
        echo "$num is not an Armstrong number."
    fi
}

# Main script execution starts here
echo "Enter a number:"
read number

is_palindrome $number
is_prime $number
fibonacci_series 10 # You can change this value to generate more terms.
is_armstrong $number
