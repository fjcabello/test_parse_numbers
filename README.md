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

I have considered as delimiters:  '\n', '\t', ',', '.', '?', '!', ':' and ';'
