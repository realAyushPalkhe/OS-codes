//2.Write a shell script program for different arithmetic functions.
	#!/bin/bash

# Function to perform addition
addition() {
  local num1=$1
  local num2=$2
  echo $((num1 + num2))
}

# Function to perform subtraction
subtraction() {
  local num1=$1
  local num2=$2
  echo $((num1 - num2))
}

# Function to perform multiplication
multiplication() {
  local num1=$1
  local num2=$2
  echo $((num1 * num2))
}

# Function to perform division
division() {
  local num1=$1
  local num2=$2
  if [ $num2 -ne 0 ]; then
    echo $((num1 / num2))
  else
    echo "Error: Division by zero"
  fi
}

# Function to perform modulus
modulus() {
  local num1=$1
  local num2=$2
  echo $((num1 % num2))
}

# Main script
echo "Arithmetic Functions in Shell Script"

# Test numbers
num1=20
num2=5

# Perform addition
result=$(addition $num1 $num2)
echo "$num1 + $num2 = $result"

# Perform subtraction
result=$(subtraction $num1 $num2)
echo "$num1 - $num2 = $result"

# Perform multiplication
result=$(multiplication $num1 $num2)
echo "$num1 * $num2 = $result"

# Perform division
result=$(division $num1 $num2)
echo "$num1 / $num2 = $result"

# Perform modulus
result=$(modulus $num1 $num2)
echo "$num1 % $num2 = $result"
