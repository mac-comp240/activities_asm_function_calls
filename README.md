# Activities 13 + 14: Conditionals and Booleans in ASM
## Put your name(s) here

In this activity, you will explore how comparison and jump operations are used
to build conditional statements. You will:
- Experiment with C code containing if statements and examine the generated assembly code
- Examine how C code that stores boolean values is implemented in assembly
- Examine the effect of compiler optimizations in eliminating jumps by handling conditionals differently

## Provided Code

This code has "library" files without `main` functions defined, so that we generate just code for each function to examine.
- `Makefile`
    - a makefile to automate the compilation process
- `basic_condits.c`
    - a C code file for function definitions that implement simple if statements
- `absdiff.c`
    - a C code file to demonstrate variant forms of conditional and their relationship to compiler optimizations
- `boolean_funcs.c`
    - a C code file with functions that return boolean values

### More Makefile complications

The Makefile for this example has a new pattern rules, which allow us
to generate assembly language with no compiler optimizations (our default) and also a 
variation that uses level 1 compiler optimizations. It augments the filenames with an extension to indicate the optimization level.

At the start, the Makefile will only make the basic `.s` files, you will modify it to generate the alternate files later.


## Your Tasks

Before starting the tasks, examine the contents of the C code file and the Makefile. Make sure you understand what both are supposed to do.

### Task 1: Basic conditional statements

- Examine the file `basic_condits.c`. It contains two functions, one implements a simple if statement, and the second implements a "too simple" if statement.

- Run `make` and examine the resulting assembly language. Discuss with your teammates what you see for each example. Why is the second example "too simple"? Put your answers here in the README file.

- Check your work on the by-hand portions of this activity by copying the `equals` and `is_zero` functions to `basic_condit.c`. Fill in specific values for the `DATAT` and `COMP` placeholders, and generate the assembly code. Try all different lengths of integer, plus all the unsigned variants. 

### Task 2: Additional operators

Look at the three variations on the `absdiff` function in the `variant_condits.c` file. It is computing and returning what is called the absolute difference between the inputs x and y. Look at the first function, `absdiff`, and study it to make sure you know what it is doing.

The next two functions in this file are equivalent to `absdiff`. The first one, `absdiff_j`, mimics how the compiler, when set to minimally optimize code, creates the assembly using a jump where you see goto in the C.

The third function `absdiff_cm`, mimics what the compiler does to turn the above versions into conditional move versions when using the -O1 optimization flag.

- First, work through with your teammates what you think the assembly code will look like for `absdiff`.
- Next, generate the assembly code, and examine it. What are the differences between the assembly for `absdiff` and `absdiff_j`?
- Compare the assembly for `absdiff_cm` with the other two. How is it different and why?
- Record here your notes on why the three are different
- Add the filename `variant_condits_opt01.s` to the `variant_files` rule in the Makefile and make the optimizes assembly
- Compare the optimized assembly to the unoptimized version: How and why are they different? Be sure to understand the role of the `cmov` instructions
- Discuss, and record your notes here


### Task 3: Making and using boolean values

Open the `boolean_funcs.c` files and look at the functions defined there. Then generate the basic assembly code and examine it.

- Make a copy of `boolean_funcs.s` called `commented_boolean_funcs.txt`, as we have done before, and add comments in your copy of the file. 
    - Describe how registers correspond to variables and data in the C code
    - Mark each line with which line(s) in the C code it corresponds to
    - Describe what each step is doing
- Add variations on these functions to try out different relational operators (`<`, `>=`, `<=`, `==`, `!=`) and different sizes of integers..
- Try more complex boolean expressions; can you make sense of the results?
- Discuss any unusual results

## References

- x86-64 jump instruction reference
    - [Steve Friedl's Intel x86 JUMP quick reference](http://unixwiz.net/techtips/x86-jumps.html)
- Assembly language resources (x86, 64-bit)
    - [x86 Assembly/X86 Instructions](http://en.wikibooks.org/wiki/X86_Assembly/X86_Instructions)
    - [X86 Opcode and Instruction Reference](http://ref.x86asm.net/coder64.html)
    - [x86 assembly language](http://en.wikipedia.org/wiki/X86_assembly_language)
    - [x86 instruction listings](http://en.wikipedia.org/wiki/X86_instruction_listings)
- gcc compiler flag references
    - [Compiler Option Summary](https://gcc.gnu.org/onlinedocs/gcc/Option-Summary.html)
    - [Index of gcc compiler options](https://gcc.gnu.org/onlinedocs/gcc/Option-Index.html)
- `objdump` resources
    - [Overview of the `objdump` command](https://www.thegeekstuff.com/2012/09/objdump-examples/)
- Makefile guides
  - [An Introduction to Makefiles](https://www.gnu.org/software/make/manual/html_node/Introduction.html), by GNU
  - [Makefile Tutorials and Examples to Build From](https://earthly.dev/blog/make-tutorial/), by Aniket Bhattacharyea
  - [makefile basics - anthony explains](https://www.youtube.com/watch?v=20GC9mYoFGs)
