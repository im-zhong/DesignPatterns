# Ovesrver, Dependents, Publish-Subscribe

## Intent
Define a one-to-many dependency between objects so that when one object changes state, all its dependents are notified and updated automatically.

## Motivation
A common side-effect of partitioning a system into a collection of cooperating classes is the need to maintain consistency between related objects. The Observer pattern describes how to establish these relationships. The key objects in this pattern are **subject** and **observer**. A subject may have any number of dependent observers. All observers are notified whenever the subject undergoes a change in state. In response, each observer will query the subject to synchronize its state with the subject's state.

This kind of interaction is also known as **publish-subscribe**. The subject is the **publisher** of notifications. It sends out these notifications without having to know who its observers are. Any number of observers can **subscribe** to receive notifications.

