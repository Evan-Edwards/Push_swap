# push_swap

## Description
A sorting algorithm project that sorts data on a stack, with a limited set of instructions, using the lowest possible number of actions. This project involves implementing an efficient sorting algorithm while working with two stacks and a specific set of allowed operations. Developed as part of the 42 curriculum.

## Features

### Available Operations
- `sa` - Swap the first 2 elements at the top of stack A
- `sb` - Swap the first 2 elements at the top of stack B
- `ss` - Execute sa and sb simultaneously
- `pa` - Push the first element of stack B onto stack A
- `pb` - Push the first element of stack A onto stack B
- `ra` - Rotate stack A (first element becomes last)
- `rb` - Rotate stack B (first element becomes last)
- `rr` - Execute ra and rb simultaneously
- `rra` - Reverse rotate stack A (last element becomes first)
- `rrb` - Reverse rotate stack B (last element becomes first)
- `rrr` - Execute rra and rrb simultaneously

## Getting Started

### Installation
Clone and compile the project:
```bash
git clone https://github.com/Evan-Edwards/push_swap.git
cd push_swap
make
```

### Usage
```bash
./push_swap 2 1 3 6 5 8
```
This will output the sequence of operations needed to sort the numbers.

## Technical Details

### Input Handling
- Accepts positive and negative integers
- Handles non-numeric input with error message
- Detects and reports duplicate numbers
- Manages integer overflow cases

### Algorithm
- Implements an efficient sorting strategy
- Optimized for different input sizes:
  - 3 numbers: Maximum 2-3 operations
  - 5 numbers: Maximum 12 operations
  - 100 numbers: Maximum 700 operations
  - 500 numbers: Maximum 5500 operations

### Project Structure
```
push_swap/
├── src/          # Source files
│   ├── push.c
│   ├── swap.c
│   ├── rotate.c
│   ├── reverse_rotate.c
│   └── main.c
├── include/      # Header files
├── obj/          # Object files (created during compilation)
├── Makefile      # Build configuration
└── README.md     # Project documentation
```

### Return Values
- Returns 0 on successful execution
- Returns appropriate error codes for invalid inputs

## Error Handling
- Invalid arguments (non-numeric input)
- Duplicate numbers
- Integer overflow
- Memory allocation failures

## Performance
The algorithm is optimized to use the minimum number of operations possible:
- 3 numbers: ≤ 3 operations
- 5 numbers: ≤ 12 operations
- 100 numbers: ≤ 700 operations
- 500 numbers: ≤ 5500 operations

---
This project is part of the 42 School curriculum.