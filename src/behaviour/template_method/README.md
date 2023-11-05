# Template Method, Framework, Skeleton, Hook

## Intent
Define the skeleton of an algorithm in an operation, deferring some steps to subclasses. Template Method lets subclasses redefine certain steps of an algorithm without changing the algorithm's structure.

## Motivation
A template method defines an algorithm in terms of abstract operations that subclasses override to provide concrete behavior. By defining some of the steps of an algorithm using abstract operations, the template method fixes their ordering, but it lets subclasses vary those steps to suit their needs.

Template Methods use inheritance to vary part of an algorithm. 
Strategies use delegation to vary the entire algorithm.
