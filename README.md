# test_parse_numbers
Quick test to convert numbers in natural to integre representation

# Compiling

cmake .
make

# Running app

$ ./main_app text.txt

# Tests

$ ./test_app

# Comments

There are some corner cases that I haven't addressed:

"I have one hundred\nand one apples"

Not clear wheres should go the \n in the output, on option could be:
- "I have 101\napples"
or
- "I have 101 apples" (removeing \n)

