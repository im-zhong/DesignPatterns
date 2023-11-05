# Visitor, Traverse

## Intent
Represent an operation to be performed on the elements of an object structure. Visitor lets you define a new operation without changing the classes of the elements on which it operates.

## Motivation
Consider a compiler that represents programs as abstract syntax trees (ASTs). We have many operaions and many classes of AST nodes. It would be better if each new operation could be added separately, and the node classes were independent of the operations that apply to them.

We can have each operation implemented in a separate class called a **visitor**, and passing it to the elements of the AST as it's traversed. When an element **accept** the visitor, it calls the visitor's operation and passes itself as an argument. The visitor will then execute the operation for that element.

With the Visitor pattern, you define two class hierarchies:
- one for the elements being operated on(the Node hierarchy)
- and one for the visitor that define operations on the elements(the NodeVisitor hierarchy)
As long as the grammar doesn't change, we can add new functionality simply by defining new NodeVisitor subclasses.
