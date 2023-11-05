# State, TCP State Machine

## Intent
Allow an object to alter its behaviour when its internal state changes. The object will appear to change its class.

## Motivation
A TCPConnection object can be in one of several different states: Listenning, Established, Closed. When a TCPConnection object receives requests from other objects, it responds differently depending on its **state**.

