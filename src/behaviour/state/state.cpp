// 2023/11/5
// zhangzhong
// behaviour pattern: state

class TCPState;
class TCPConnection;

// TCPState duplicate the state-changing interface of TCPConnection
class TCPState {
public:
  virtual ~TCPState() {}
  // virtual void Transmit(TCPConnection *connection, TCPOctetStream *stream) {}
  virtual void ActiveOpen(TCPConnection *connection) {}
  virtual void PassiveOpen(TCPConnection *connection) {}
  virtual void Close(TCPConnection *connection) {}
  virtual void Synchronize(TCPConnection *connection) {}
  virtual void Acknowledge(TCPConnection *connection) {}
  virtual void Send(TCPConnection *connection) {}

protected:
  // Implementation detail: must define and implement in this class
  // so that our child class can call this function to change the state
  // but other classes cannot call this function
  void ChangeState(TCPConnection *connection, TCPState *state);
};

class TCPEstablished : public TCPState {
public:
  // singleton
  static TCPState *Instance() {
    static TCPEstablished *instance = new TCPEstablished();
    return instance;
  }

  // implement the state-specific behavior
  // ...

private:
  TCPEstablished() {}
};

class TCPListen : public TCPState {
public:
  // singleton
  static TCPState *Instance() {
    static TCPListen *instance = new TCPListen();
    return instance;
  }

  // implement the state-specific behavior
  // ...

private:
  TCPListen() {}
};

class TCPClosed : public TCPState {
public:
  static TCPState *Instance();
  virtual void ActiveOpen(TCPConnection *connection) override;

private:
  TCPClosed() {}
};

class TCPConnection {
public:
  // TCPConnection starts in the TCPClosed state
  TCPConnection() : state_(TCPClosed::Instance()) {}

  // TCPConnection delegates all state-specific requests to its TCPState
  // instance state_
  void ActiveOpen() { state_->ActiveOpen(this); }
  void PassiveOpen() { state_->PassiveOpen(this); }
  void Close() { state_->Close(this); }
  void Send() { state_->Send(this); }
  void Acknowledge() { state_->Acknowledge(this); }
  void Synchronize() { state_->Synchronize(this); }

private:
  // Implementation 1. Who defines the state transitions?
  // It is generally more flexible and appropriate to let the state subclasses
  // themselves specify their successor state and when to make the transition.
  // This requires adding an interface to the TCPConnection that lets State
  // object set the current state explicitly.
  friend class TCPState;
  void ChangeState(TCPState *state) { state_ = state; }
  TCPState *state_;
};

TCPState *TCPClosed::Instance() {
  static TCPClosed *instance = new TCPClosed();
  return instance;
}

void TCPState::ChangeState(TCPConnection *connection, TCPState *state) {
  connection->ChangeState(state);
}

void TCPClosed::ActiveOpen(TCPConnection *connection) {
  // send SYN, receive SYN, ACK, etc.
  // ...
  // After performing state-specific work, these operations call the
  // ChangeState to change the state of the TCPConnection object.
  this->ChangeState(connection, TCPEstablished::Instance());
}
