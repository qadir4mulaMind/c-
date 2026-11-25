# C++ Practice and Projects

A collection of C++ learning exercises, algorithm and data-structure implementations, and small projects. The repository is organized by topic so examples can be explored independently.

## Repository guide

| Area | Folders |
| --- | --- |
| Language fundamentals and patterns | `Basic/`, `CONDITIONAL_STATEMENT/`, `TERNARYandSWITCH/`, `PATTERNPRITTING/` |
| Core C++ and object-oriented programming | `OOPS/`, `POINTER/`, `FileHandling.cpp/`, `advance-cpp/` |
| C++ concept and library lessons | `mike_shah/` covers language features, classes and templates, inheritance, pointers and object lifetime, stream I/O, STL containers/iterators/algorithms, and a small custom `MiniSTL/` implementation. |
| Arrays, strings, matrices, and vectors | `ARRAY/`, `STRING/`, `MATRIX/`, `VECTOR/`, `VectorMatrix.cpp/` |
| Bitwise and problem-solving techniques | `BitwiseOperator/`, `bitManipulation/`, `ShortcutBitWiseLogical/`, `Searching/`, `Sorting/`, `PrefixSum/`, `SlidingWindow/` |
| Recursion and algorithm design | `RECURSION/`, `backtracking/`, `dp/` |
| Data structures | `linkedList/`, `doublyLinkedList/`, `stack/`, `queue/`, `heap/`, `tree/`, `graph/`, `segmentTree/`, `setAndMap/` |
| Practice collections and projects | `PRACTICE_BY_PANKAJ/`, `FirstProject/`, `project/` |

The repository root also contains a few individual examples, including `C++ONESHOT.cpp` and `function_pointer.cpp`. Folder and file names are retained as they appear in the source tree.

## Compile and run an example

There is no single application or root-level build target. Many source files are independent programs, often with their own `main()` function. Compile one file at a time with a C++ compiler:

```bash
c++ -std=c++17 ARRAY/Array_basic.cpp -o /tmp/array_basic
/tmp/array_basic
```

Use the language standard supported by the particular example if it differs. Programs that read input accept it through the terminal; you can also redirect a file:

```bash
./program < path/to/input.txt
```

Some folders include their own sample input and output files. Check the source file and its folder for any program-specific instructions.

## Projects

- [Guess Game](project/Guess-Game/) — a console-based number-guessing game.
- [Hospital Management](project/Hospital-Management/) — a separate project with its own README and setup details.

## Acknowledgments

Special thanks to **Mike Shah** for his C++ lessons and tutorials, which have been an important part of my learning journey. The [`mike_shah/`](mike_shah/) directory contains related practice examples.

## License

This repository is licensed under the [MIT License](LICENSE).

## Author

**Abdul Qadir**

- [GitHub](https://github.com/qadir4mulaMind)
- [LinkedIn](https://www.linkedin.com/in/abdul-qadir-4aa642204)

