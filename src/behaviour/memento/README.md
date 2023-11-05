# Memento, Token, Snapshot, Checkpoint, Undo

## Intent
without violating encapsulation, capture and externalize an objects's internal state so that the object can be restored to this state later.

## Motivation
Sometime it's necessary to record the internal state of an object. This is required when implementing checkpoints and undo mechanisms that let users back out of tentative operations or recover from errors. You must save state infomation somewhere so that you can restore objects to their previous states.

A **memento** is an object that stores a snapshot of the internal state of another object(the memento's **originator**). Only the originator can sotre and retrieve infomation from the memento, the memento is opaque to other objects.

## Applicability
  - a snapshot of (some portion of) an object's state must be saved so that it can be restored to that state later, and
  - a direct interface to obtaining the state would expose implementation details and break the object's encapsulation.
