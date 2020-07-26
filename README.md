# test_parse_numbers
Quick test to convert numbers in natural to integer representation

# Compiling

cmake .
make

# Running app

$ ./main_app text.txt

# Tests

$ ./test_app

# Comments

Comments about the implementation.

## Corner cases

There are some corner cases that I haven't addressed:

"I have one hundred\nand one apples"

Not clear wheres should go the \n in the output, on option could be:
- "I have 101\napples"
or
- "I have 101 apples" (removeing \n)

Some expression could be valid like:
- hundred
- thousand
- million
- billion

In my implementation is expected to add a number first (one hundred).

In some cases it's possible to add a '-' (thirty-five) but my implementation consider only a space as delimiter in this case.

## Delimiters

I have considered as delimiters:  '\n', '\t', ',', '.', '?', '!', ':' and ';'. There are some corner cases difficult to identy like:
- I tested with one, two and three.
Current implementation returns: "I tested with 1, 5", as it consider 'and' expression as a joint delimiter (like in one hundred and one).

## Architecture

Current implementation parse input string and creates a Vector of tuples (token,delimiter). My initial implementation was designed to process input iterative without an initial parsing, but it was much more complex.


