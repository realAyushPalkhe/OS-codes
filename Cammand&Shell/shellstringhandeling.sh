//1.Write a shell script program for different string handling functions.
#!/bin/bash

# Function to find the length of a string
string_length() {
  local str="$1"
  echo "${#str}"
}

# Function to extract a substring
substring() {
  local str="$1"
  local start="$2"
  local length="$3"
  echo "${str:$start:$length}"
}

# Function to replace a substring with another substring
replace_substring() {
  local str="$1"
  local search="$2"
  local replace="$3"
  echo "${str//$search/$replace}"
}

# Function to convert a string to uppercase
to_uppercase() {
  local str="$1"
  echo "${str^^}"
}

# Function to convert a string to lowercase
to_lowercase() {
  local str="$1"
  echo "${str,,}"
}

# Function to reverse a string
reverse_string() {
  local str="$1"
  echo "$str" | rev
}

# Main script
echo "String Handling Functions in Shell Script"

# Test strings
test_string="Hello, Shell Scripting World!"
search_string="Shell"
replace_string="Bash"

# Find the length of the test string
length=$(string_length "$test_string")
echo "Length of '$test_string': $length"

# Extract a substring from the test string
start=7
length=5
substring=$(substring "$test_string" $start $length)
echo "Substring of '$test_string' from index $start with length $length: '$substring'"

# Replace a substring in the test string
replaced_string=$(replace_substring "$test_string" "$search_string" "$replace_string")
echo "String after replacing '$search_string' with '$replace_string': '$replaced_string'"

# Convert the test string to uppercase
uppercase_string=$(to_uppercase "$test_string")
echo "Uppercase of '$test_string': '$uppercase_string'"

# Convert the test string to lowercase
lowercase_string=$(to_lowercase "$test_string")
echo "Lowercase of '$test_string': '$lowercase_string'"

# Reverse the test string
reversed_string=$(reverse_string "$test_string")
echo "Reversed string of '$test_string': '$reversed_string'"
