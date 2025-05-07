# 223-Columbia-River-Project
Modeling the Columbia river as a binary tree.
Joseph Mock, Carson Frost, Charlie Serafin, Jessica Sun


Files and specifications

class_specifications.txt
Describes each class (Dam, Tributary, RiverTree, etc.) in terms of purpose, inputs/outputs, assumptions, state changes, and expected behavior.

Columbia River Project- Updated (PDF)
A project summary including build/run instructions, dependencies, feature list, and usage examples.

main.cpp
The application’s entry point. It builds and initializes the RiverTree, presents a menu to the user, reads input, and invokes core functions (print tree, explore, add node, etc.).

program_specifications.txt
A textual spec listing all program features, use cases, input/output formats, and business rules that the application must satisfy.


RiverTree.hpp
Header file declaring the RiverTree class: data members (like the root pointer), constructors/destructor, and public interfaces for traversal, insertion, printing, and search.

RiverTree.cpp
Implementation of everything declared in RiverTree.hpp, including methods such as print_tree(), explore_tree(), add_node_interactive(), and any helper routines.

unit_test.cpp
The suite of unit tests (using a test framework or assertions) that verify RiverTree, Dam, Tributary, and related classes behave correctly under various scenarios.
