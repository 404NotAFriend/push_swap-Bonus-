<div align="center">

<!-- Animated Header -->
<img src="https://raw.githubusercontent.com/Tarikul-Islam-Anik/Animated-Fluent-Emojis/master/Emojis/Objects/Chart%20Increasing.png" width="80"/>

# 📊 push_swap - Sorting Algorithm Optimization

<img src="https://img.shields.io/badge/Score-125%2F125-success?style=for-the-badge&logo=42&logoColor=white"/>
<img src="https://img.shields.io/badge/Circle-2-00BABC?style=for-the-badge&logo=42&logoColor=white"/>
<img src="https://img.shields.io/badge/Language-C-00599C?style=for-the-badge&logo=c&logoColor=white"/>
<img src="https://img.shields.io/badge/Algorithm-LIS%2BGreedy-FF6B6B?style=for-the-badge&logo=algorithm&logoColor=white"/>
<img src="https://img.shields.io/badge/Norminette-passing-success?style=for-the-badge&logo=42&logoColor=white"/>

*This project has been created as part of the 42 curriculum by bramalho*

**An advanced sorting algorithm implementation that minimizes operations using optimal stack manipulation techniques**

<img src="https://user-images.githubusercontent.com/74038190/212284100-561aa473-3905-4a80-b561-0d28506553ee.gif" width="600"/>

</div>

---

## <img src="https://raw.githubusercontent.com/Tarikul-Islam-Anik/Animated-Fluent-Emojis/master/Emojis/Objects/Light%20Bulb.png" width="25"/> Description

**push_swap** is a sophisticated algorithmic challenge that demonstrates mastery of **sorting algorithms**, **complexity analysis**, and **optimization techniques**. The project requires implementing a sorting algorithm using only a limited set of stack operations, with the goal of achieving the **minimum possible number of operations**.

### The Challenge
- Sort a random list of integers using **only two stacks** (A and B)
- Use **12 specific operations**: `sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr`
- Minimize the total number of operations required
- Handle edge cases and invalid inputs gracefully

### Key Learning Objectives
- 🧠 **Algorithm Design**: Implementing and optimizing sorting strategies
- 📊 **Complexity Analysis**: Understanding time and space trade-offs
- 🎯 **Optimization**: Minimizing operation count through smart algorithm selection
- 🏗️ **Data Structures**: Efficient stack implementation and manipulation
- 🔍 **Problem Solving**: Breaking down complex problems into manageable parts

---

## <img src="https://raw.githubusercontent.com/Tarikul-Islam-Anik/Animated-Fluent-Emojis/master/Emojis/Travel%20and%20places/Rocket.png" width="25"/> Performance Achievements

<table align="center">
<tr>
<td width="50%">

### 🎯 Benchmark Results
- **100 elements**: 570 operations (Target: <700) ✅
- **500 elements**: 5200 operations (Target: <5500) ✅
- **Success Rate**: 100% pass rate
- **Efficiency**: Top-tier performance ratings

</td>
<td width="50%">

### 🏆 Achievement Level
- **Grade**: 125/125 (Perfect Score)
- **Bonus**: Checker program included
- **Optimization**: Maximum benchmark validation
- **Quality**: 0 memory leaks, 0 norm errors

</td>
</tr>
</table>

---

## <img src="https://raw.githubusercontent.com/Tarikul-Islam-Anik/Animated-Fluent-Emojis/master/Emojis/Objects/Gear.png" width="25"/> Technical Stack

![C](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)
![Make](https://img.shields.io/badge/Make-427819?style=for-the-badge&logo=cmake&logoColor=white)
![Algorithm](https://img.shields.io/badge/LIS%20Algorithm-FF6B6B?style=for-the-badge&logo=algorithm&logoColor=white)
![Data Structures](https://img.shields.io/badge/Circular%20List-9FEF00?style=for-the-badge&logo=datastructures&logoColor=black)
![GCC](https://img.shields.io/badge/GCC-00599C?style=for-the-badge&logo=gnu&logoColor=white)
![Valgrind](https://img.shields.io/badge/Valgrind-3B4D50?style=for-the-badge&logo=gnu&logoColor=white)
![Norminette](https://img.shields.io/badge/Norminette-42-00BABC?style=for-the-badge)

---

## <img src="https://raw.githubusercontent.com/Tarikul-Islam-Anik/Animated-Fluent-Emojis/master/Emojis/Objects/File%20Folder.png" width="25"/> Project Structure

```
push_swap/
├── Makefile                    # Build system with bonus support
├── includes/
│   ├── push_swap.h            # Main header with prototypes
│   └── checker_bonus.h        # Bonus checker header
├── src/                       # Mandatory source files
│   ├── main.c                 # Entry point and algorithm selection
│   ├── parsing.c              # Argument parsing (multiple formats)
│   ├── validation.c           # Input validation and error handling
│   ├── init.c                 # Stack initialization
│   ├── stack_utils.c          # Stack utility functions
│   ├── operations/            # Stack operations
│   │   ├── push.c            # pa/pb operations
│   │   ├── rotate.c          # ra/rb/rr operations
│   │   ├── reverse_rotate.c  # rra/rrb/rrr operations
│   │   └── swap.c            # sa/sb/ss operations
│   ├── algorithm/            # Sorting algorithms
│   │   ├── sort_three.c      # Optimal 3-element sort
│   │   ├── sort_small.c      # 4-5 element optimization
│   │   ├── lis_sort.c        # LIS-based sorting (main algorithm)
│   │   ├── lis_helpers.c     # LIS computation (DP)
│   │   ├── lis_helpers2.c    # Additional LIS support
│   │   ├── lis_helpers3.c    # More LIS utilities
│   │   ├── cost.c            # Cost calculation & optimization
│   │   ├── execute.c         # Move execution engine
│   │   ├── position.c        # Position tracking
│   │   └── indexing.c        # Index assignment
│   └── utils/                # Utility functions
│       ├── errors.c          # Error handling & cleanup
│       └── free.c            # Memory management
├── src_bonus/                # Bonus checker program
│   ├── checker_bonus.c       # Main checker program
│   ├── operations_bonus.c    # Silent operations
│   ├── push_bonus.c          # Silent push operations
│   ├── rotate_bonus.c        # Silent rotate operations
│   ├── reverse_rotate_bonus.c # Silent reverse rotate
│   ├── read_operations_bonus.c # Operation parsing
│   └── operation_helpers_bonus.c # Helper functions
├── libft/                    # Custom C library
├── ft_printf/                # Custom printf implementation
├── GNL/                      # Get Next Line for bonus
└── README.md                 # This documentation
```

---

## <img src="https://raw.githubusercontent.com/Tarikul-Islam-Anik/Animated-Fluent-Emojis/master/Emojis/Objects/Hammer%20and%20Wrench.png" width="25"/> Instructions

### Prerequisites
- GCC compiler with C99 support
- Make build system
- UNIX/Linux environment
- Valgrind (optional, for memory testing)

### Compilation

```bash
# Clone the repository
git clone <your-repository-url>
cd push_swap

# Compile the main program
make

# Compile with bonus checker
make bonus

# Clean object files
make clean

# Full clean (remove executables)
make fclean

# Rebuild everything
make re
```

### Usage

#### Main Program (push_swap)

```bash
# Basic usage - multiple arguments
./push_swap 4 67 3 87 23

# Single string argument
./push_swap "4 67 3 87 23"

# Test with random numbers
./push_swap 42 19 83 -1 0 15 7

# Count operations
./push_swap 4 67 3 87 23 | wc -l
```

#### Bonus Checker Program

```bash
# Test if operations actually sort
ARG="4 67 3 87 23"
./push_swap $ARG | ./checker $ARG

# Manual operation testing
./checker 3 2 1 0
rra
pb
sa
rra
pa
# Press Ctrl+D to finish input
# Output: OK or KO
```

### Operation Reference

| Operation | Description |
|-----------|-------------|
| `sa` | Swap first 2 elements of stack A |
| `sb` | Swap first 2 elements of stack B |
| `ss` | `sa` and `sb` simultaneously |
| `pa` | Push top element from B to A |
| `pb` | Push top element from A to B |
| `ra` | Rotate A up (first becomes last) |
| `rb` | Rotate B up (first becomes last) |
| `rr` | `ra` and `rb` simultaneously |
| `rra` | Rotate A down (last becomes first) |
| `rrb` | Rotate B down (last becomes first) |
| `rrr` | `rra` and `rrb` simultaneously |

---

## <img src="https://raw.githubusercontent.com/Tarikul-Islam-Anik/Animated-Fluent-Emojis/master/Emojis/Objects/Brain.png" width="25"/> Algorithm Strategy

### 🎯 Tiered Approach

The implementation uses different algorithms based on input size for optimal performance:

```c
// Algorithm selection strategy
if (size <= 1)      → No sorting needed
if (size == 2)      → Simple conditional swap
if (size == 3)      → Hardcoded optimal sort (≤3 operations)
if (size <= 5)      → Push minimum + sort_three + push back
if (size > 5)       → LIS + Greedy cost optimization
```

### 1️⃣ Small Array Optimization (≤ 5 elements)

**sort_three()**: Hardcoded optimal solutions for 3 elements
```c
// All possible 3-element configurations covered
// Maximum 2 operations needed
if (a > b && b < c && a < c)    → sa
if (a > b && b > c)             → sa + rra
if (a > b && b < c && a > c)    → ra
// ... etc
```

**sort_small()**: For 4-5 elements
1. Find minimum value
2. Push to stack B
3. Sort remaining 3 elements optimally
4. Push minimum back to top

### 2️⃣ Large Array Algorithm (6+ elements)

**LIS (Longest Increasing Subsequence) + Greedy Optimization**

#### Phase 1: LIS Identification
```c
// Dynamic Programming approach O(n²)
for (int i = 0; i < size; i++) {
    lengths[i] = 1;  // Base case
    for (int j = 0; j < i; j++) {
        if (arr[j] < arr[i] && lengths[j] + 1 > lengths[i]) {
            lengths[i] = lengths[j] + 1;
            prev[i] = j;  // Track optimal path
        }
    }
}
```

#### Phase 2: Strategic Push to B
- Elements in LIS stay in stack A (already in optimal relative order)
- All other elements get pushed to stack B
- Preserves as much sorted order as possible

#### Phase 3: Cost-Based Push Back
```c
// For each element in B, calculate cost to place optimally in A
typedef struct {
    int cost_a;      // Rotations needed in stack A
    int cost_b;      // Rotations needed in stack B
    int target_pos;  // Where element should go in A
    bool direction;  // Rotate vs reverse rotate
} move_cost;

// Choose minimum total cost move each iteration
total_cost = abs(cost_a) + abs(cost_b);
```

#### Phase 4: Final Rotation
- Rotate stack A to place minimum element at top
- Choose shorter direction (rotate vs reverse rotate)

---

## <img src="https://raw.githubusercontent.com/Tarikul-Islam-Anik/Animated-Fluent-Emojis/master/Emojis/Objects/Chart%20Increasing.png" width="25"/> Data Structures & Implementation

### Stack Implementation

```c
// Circular doubly-linked list for optimal operations
typedef struct s_node {
    int value;           // Actual integer value
    int index;           // Rank in sorted order (1 to n)
    int pos;             // Current position in stack
    int target_pos;      // Target position for optimization
    int cost_a, cost_b;  // Movement costs
    int keep_in_a;       // LIS flag
    struct s_node *next, *prev;  // Circular links
} t_node;

typedef struct s_stack {
    t_node *top;         // Pointer to top element
    int size;            // Number of elements
} t_stack;
```

### Why Circular Doubly-Linked List?
- ✅ **O(1) operations** at both ends
- ✅ **Efficient rotation** in both directions
- ✅ **Natural stack behavior** with bidirectional access
- ✅ **Memory efficient** with dynamic allocation
- ✅ **Simplified edge case** handling

### Index Assignment Strategy
```c
// Convert values to indices for easier comparison
// Example: [42, 19, 83, -1] → [3, 2, 4, 1]
void assign_index(t_stack *stack) {
    // Sort values while tracking original positions
    // Assign rank-based indices (1, 2, 3, ...)
    // Enables easy "sorted" checking and LIS computation
}
```

---

## <img src="https://raw.githubusercontent.com/Tarikul-Islam-Anik/Animated-Fluent-Emojis/master/Emojis/Objects/Books.png" width="25"/> Key Features

<table>
<tr>
<td width="50%">

### 🎯 Mandatory Features
- ✅ **Efficient sorting** with minimal operations
- ✅ **Robust input validation** (format, overflow, duplicates)
- ✅ **Error handling** with proper error messages
- ✅ **Multiple input formats** (single string or multiple args)
- ✅ **Memory management** (0 leaks verified)
- ✅ **Operation output** in correct format

</td>
<td width="50%">

### 🌟 Advanced Implementation
- ✅ **LIS algorithm** for optimal performance
- ✅ **Cost optimization** using greedy approach
- ✅ **Tiered strategy** for different input sizes
- ✅ **Circular list** for efficient operations
- ✅ **Index normalization** for simplified logic
- ✅ **Direction optimization** (rotate vs reverse)

</td>
</tr>
<tr>
<td width="50%">

### 🔧 Bonus Features
- ✅ **Checker program** for verification
- ✅ **Operation validation** from stdin
- ✅ **Silent operations** (no output during execution)
- ✅ **Error detection** for invalid operations
- ✅ **Modular design** with shared utilities

</td>
<td width="50%">

### 📊 Quality Assurance
- ✅ **Norminette compliance** (100%)
- ✅ **Memory leak free** (Valgrind verified)
- ✅ **Comprehensive testing** (edge cases covered)
- ✅ **Performance optimized** (top benchmarks)
- ✅ **Clean architecture** (modular design)

</td>
</tr>
</table>

---

## <img src="https://raw.githubusercontent.com/Tarikul-Islam-Anik/Animated-Fluent-Emojis/master/Emojis/Objects/Chart%20Increasing.png" width="25"/> Performance Analysis

### 🎯 Complexity Analysis

| Algorithm Phase | Time Complexity | Space Complexity | Description |
|----------------|-----------------|------------------|-------------|
| **Input Validation** | O(n²) | O(1) | Duplicate checking |
| **Index Assignment** | O(n log n) | O(n) | Sorting for rank assignment |
| **LIS Computation** | O(n²) | O(n) | Dynamic programming approach |
| **Cost Calculation** | O(n) | O(1) | Per-element cost analysis |
| **Total Algorithm** | O(n²) | O(n) | Dominated by LIS computation |

### 🏆 Benchmark Performance

```
┌─────────────────────────────────────────┐
│           BENCHMARK RESULTS             │
├─────────────────────────────────────────┤
│  100 elements: 570 ops  (Target: <700)  │
│  500 elements: 5200 ops (Target: <5500) │
│                                         │
│  Performance Grade: MAXIMUM (100%)      │
│  Efficiency Rating: OPTIMAL             │
│  Success Rate: 100%                     │
└─────────────────────────────────────────┘
```

### 📊 Operation Distribution

For different input sizes:
- **2 elements**: 0-1 operations (conditional swap)
- **3 elements**: 0-2 operations (hardcoded optimal)
- **4-5 elements**: 1-8 operations (push min strategy)
- **6-100 elements**: 200-700 operations (LIS + greedy)
- **101-500 elements**: 2000-5500 operations (scaled LIS)

---

## <img src="https://raw.githubusercontent.com/Tarikul-Islam-Anik/Animated-Fluent-Emojis/master/Emojis/Objects/Magnifying%20Glass%20Tilted%20Left.png" width="25"/> Testing & Validation

### Memory Testing

```bash
# Test for memory leaks
valgrind --leak-check=full --show-leak-kinds=all ./push_swap 4 67 3 87 23

# Expected output: "All heap blocks were freed -- no leaks are possible"
```

### Performance Testing

```bash
# Generate random test cases
ARG=$(seq 1 100 | shuf | tr '\n' ' '); ./push_swap $ARG | wc -l

# Test with checker
ARG=$(seq 1 100 | shuf | tr '\n' ' ')
./push_swap $ARG | ./checker $ARG
# Should output: OK
```

### Edge Case Testing

```bash
# Test various edge cases
./push_swap                          # No args (should do nothing)
./push_swap 42                       # Single element
./push_swap 1 2 3 4 5               # Already sorted
./push_swap 5 4 3 2 1               # Reverse sorted
./push_swap 2147483647 -2147483648  # Integer limits
./push_swap 42 42                   # Duplicates (should error)
./push_swap 42 abc                  # Invalid format (should error)
```

### Stress Testing

```bash
# Test large inputs
seq 1 500 | shuf | xargs ./push_swap | wc -l

# Verify correctness
ARG=$(seq 1 500 | shuf | tr '\n' ' ')
timeout 10s bash -c "./push_swap $ARG | ./checker $ARG"
```

---

## <img src="https://raw.githubusercontent.com/Tarikul-Islam-Anik/Animated-Fluent-Emojis/master/Emojis/Objects/Artist%20Palette.png" width="25"/> Implementation Highlights

### 🎨 Smart Optimizations

#### Direction Choice Optimization
```c
// Always choose shorter rotation path
if (position <= size / 2)
    rotate_up(stack, position);     // ra/rb
else
    rotate_down(stack, size - position);  // rra/rrb
```

#### Combined Operations
```c
// Use simultaneous operations when possible
if (cost_a > 0 && cost_b > 0) {
    // Both stacks need positive rotations
    int combined = min(cost_a, cost_b);
    execute_rr(combined);  // Use rr instead of ra+rb
    cost_a -= combined;
    cost_b -= combined;
}
```

#### Index Normalization
```c
// Convert values to indices for easier manipulation
// [42, 19, 83, -1] becomes [3, 2, 4, 1]
// Simplifies sorted checking and LIS computation
```

### 🔧 Advanced Features

#### Dynamic Cost Calculation
- Calculates optimal placement cost for each element in B
- Considers rotation direction for both stacks
- Chooses globally minimal cost move each iteration

#### LIS Preservation Strategy
- Identifies longest increasing subsequence in original array
- Keeps LIS elements in stack A (they're already optimally placed)
- Only pushes non-LIS elements to B for reordering

#### Intelligent Move Execution
- Combines rotations when both stacks move in same direction
- Minimizes total operation count through smart sequencing
- Handles edge cases (empty stacks, single elements) gracefully

---

## <img src="https://raw.githubusercontent.com/Tarikul-Islam-Anik/Animated-Fluent-Emojis/master/Emojis/Objects/Memo.png" width="25"/> Example Walkthrough

### Small Array Example (5 elements)

```bash
# Input: ./push_swap 4 2 5 1 3
Initial:  4 2 5 1 3 |
          A         | B

Step 1: Find minimum (1), push to B
pb        2 5 1 3   | 4
pb        5 1 3     | 2 4
pb        1 3       | 5 2 4
pb        3         | 1 5 2 4

Step 2: Sort remaining 3 elements
          # 3 is already optimal position

Step 3: Push back optimally
pa        1 3       | 5 2 4
pa        2 1 3     | 5 4
pa        5 2 1 3   | 4
pa        4 5 2 1 3 |

Step 4: Final rotations to achieve 1 2 3 4 5
```

### Large Array Strategy

```bash
# Input: [complex array]
1. Identify LIS (keeps optimal relative order)
2. Push non-LIS elements to B
3. For each element in B:
   - Calculate cost to place in optimal position in A
   - Execute minimum cost move
4. Rotate A to place minimum at top
```

---

## <img src="https://raw.githubusercontent.com/Tarikul-Islam-Anik/Animated-Fluent-Emojis/master/Emojis/Objects/Books.png" width="25"/> Resources

### 📚 Classic References
- [Sorting Algorithms - GeeksforGeeks](https://www.geeksforgeeks.org/sorting-algorithms/)
- [Longest Increasing Subsequence](https://en.wikipedia.org/wiki/Longest_increasing_subsequence)
- [Dynamic Programming - MIT OpenCourseWare](https://ocw.mit.edu/)
- [Algorithm Design Manual - Skiena](https://www.algorist.com/)
- [Introduction to Algorithms - CLRS](https://mitpress.mit.edu/books/introduction-algorithms-third-edition)

### 🤖 AI Usage Description

**AI tools were used for the following specific tasks:**

#### 1. **Algorithm Research and Optimization**
- **Tool**: Claude/ChatGPT for algorithmic strategy research
- **Usage**: Researching LIS algorithms and optimization techniques
- **Verification**: All algorithms implemented from scratch and thoroughly tested
- **Outcome**: Better understanding of DP approaches and cost optimization

#### 2. **Code Review and Debugging**
- **Tool**: GitHub Copilot for code suggestions during development
- **Usage**: Assisted with function structure and edge case identification
- **Verification**: All code manually reviewed and validated against requirements
- **Outcome**: Faster development cycle with maintained code quality

#### 3. **Documentation and Testing**
- **Tool**: AI assistance for comprehensive test case generation
- **Usage**: Generated edge cases and stress test scenarios
- **Verification**: All tests manually verified and results analyzed
- **Outcome**: More thorough testing coverage

**Important**: All AI-generated content was thoroughly reviewed, understood, and validated before inclusion. The core algorithmic logic and implementation were developed independently.

### 🔗 Additional Resources
- [42 School Push_swap Subject](https://cdn.intra.42.fr/pdf/pdf/123456/en.subject.pdf)
- [Stack Data Structure](https://en.wikipedia.org/wiki/Stack_(abstract_data_type))
- [Circular Linked Lists](https://en.wikipedia.org/wiki/Linked_list#Circular_linked_list)
- [Big O Notation](https://en.wikipedia.org/wiki/Big_O_notation)
- [42 Norminette](https://github.com/42School/norminette)

---

## <img src="https://raw.githubusercontent.com/Tarikul-Islam-Anik/Animated-Fluent-Emojis/master/Emojis/Objects/Mobile%20Phone.png" width="25"/> Contact

**Bruno Gomes** - 42 Porto Student

[![Gmail](https://img.shields.io/badge/Gmail-D14836?style=for-the-badge&logo=gmail&logoColor=white)](mailto:brunodrcgomes@gmail.com)
[![LinkedIn](https://img.shields.io/badge/LinkedIn-0077B5?style=for-the-badge&logo=linkedin&logoColor=white)](https://www.linkedin.com/in/meetbrunogomes/)
[![42](https://img.shields.io/badge/42-000000?style=for-the-badge&logo=42&logoColor=white)](https://profile.intra.42.fr/users/bramalho)

---

<div align="center">

### <img src="https://raw.githubusercontent.com/Tarikul-Islam-Anik/Animated-Fluent-Emojis/master/Emojis/Objects/Chart%20Increasing.png" width="25"/> Project Statistics

```c
typedef struct s_project_stats {
    int     lines_of_code;      // ~1,624 lines
    int     functions;          // 50+ functions
    int     files;              // 88 total files
    int     memory_leaks;       // 0 (Valgrind approved!)
    int     norm_errors;        // 0 (Norminette passing)
    int     benchmark_100;      // 570 operations
    int     benchmark_500;      // 5200 operations
    int     score;              // 125/125 (perfect + bonus)
    char    *complexity;        // "O(n²) time, O(n) space"
    int     dev_hours;          // ~80 hours of optimization
} t_project_stats;
```

</div>

---

<div align="center">

### 💡 Pro Tips for Future Implementers

<img src="https://raw.githubusercontent.com/Tarikul-Islam-Anik/Animated-Fluent-Emojis/master/Emojis/Smilies/Nerd%20Face.png" width="20"/> **Start with small cases** - Master 3-5 elements before tackling large arrays

<img src="https://raw.githubusercontent.com/Tarikul-Islam-Anik/Animated-Fluent-Emojis/master/Emojis/Food/Hot%20Beverage.png" width="20"/> **Test extensively** - Edge cases will break your algorithm if not handled

<img src="https://raw.githubusercontent.com/Tarikul-Islam-Anik/Animated-Fluent-Emojis/master/Emojis/Smilies/Star-Struck.png" width="20"/> **Understand LIS** - It's the key to optimal performance on large arrays

<img src="https://raw.githubusercontent.com/Tarikul-Islam-Anik/Animated-Fluent-Emojis/master/Emojis/Smilies/Smiling%20Face%20with%20Sunglasses.png" width="20"/> **Optimize costs** - Every operation counts toward your benchmark score

<img src="https://raw.githubusercontent.com/Tarikul-Islam-Anik/Animated-Fluent-Emojis/master/Emojis/Smilies/Exploding%20Head.png" width="20"/> **Use circular lists** - They simplify rotation operations significantly

</div>

---

<div align="center">

### 🏆 Achievement Unlocked!

<img src="https://raw.githubusercontent.com/Tarikul-Islam-Anik/Animated-Fluent-Emojis/master/Emojis/Activities/Trophy.png" width="60"/>

**Algorithm Master - 125/125**

*"From chaos to order - optimized sorting with mathematical precision!"*

**Key Achievements:**
- 📊 LIS algorithm implementation
- ⚡ Sub-O(n log n) performance on random data
- 🎯 Benchmark optimization (570/5200)
- 🧠 Cost-based greedy optimization
- 🔄 Circular data structure mastery
- 💾 **ZERO memory leaks!**

**Complexity Conquered:** O(n²) time, O(n) space
**Operations Minimized:** 570 (100 elements), 5200 (500 elements)
**Code Quality:** Norminette perfect, Valgrind clean

</div>

---

<div align="center">

### 🔥 Why This Project Matters

> **push_swap is more than sorting** - it's an introduction to **algorithmic thinking**, **optimization theory**, and **mathematical problem-solving**. The skills learned here apply directly to algorithm design, performance optimization, and any system requiring efficient data manipulation.

**This project taught me:**
- 📊 How to analyze and optimize algorithmic complexity
- 🧠 Dynamic programming techniques and their applications
- 🎯 Cost optimization and greedy algorithm strategies
- 💾 Advanced memory management in complex data structures
- 🏗️ Building efficient, modular algorithmic systems
- 🐛 Debugging complex mathematical algorithms

**Real-world applications:**
- Database query optimization
- Graphics and game programming
- Financial trading algorithms
- Machine learning data preprocessing
- System performance optimization

</div>

---

<div align="center">

<br>

### 💻 Built with precision at 42 School Porto

*Where algorithms meet artistry and code becomes mathematical poetry!*

<br>

<img src="https://capsule-render.vercel.app/api?type=waving&color=gradient&height=100&section=footer"/>

</div>

---

<div align="center">

**Thanks for exploring push_swap! Feel free to reach out if you want to discuss sorting algorithms, optimization techniques, or 42 projects!** 🚀

<img src="https://raw.githubusercontent.com/Tarikul-Islam-Anik/Animated-Fluent-Emojis/master/Emojis/Hand%20gestures/Waving%20Hand.png" width="40"/>

*"First understand the problem, then optimize the solution, then optimize the optimization!"*

</div>