// 2023/11/5
// zhangzhong
// memento

class State;
class Memento;

class Memento {
public:
  // narrow public interface
  virtual ~Memento() {}

private:
  // wide private interface
  // private members accessible only to Originator
  friend class Originator;
  Memento(State *state) : state_(state) {}
  void SetState(State *state) { state_ = state; }
  State *GetState() const { return state_; }
  // ...
private:
  State *state_;
};

class Originator {
public:
  Memento *CreateMemento() { return new Memento(state_); }
  void SetMemento(Memento const *memento) { state_ = memento->GetState(); }

private:
  // internal state
  State *state_;
};

class Caretaker {
public:
  Caretaker(Originator *originator) : originator_(originator) {}
  void Save() { memento_ = originator_->CreateMemento(); }
  void Restore() { originator_->SetMemento(memento_); }

private:
  Originator *originator_;
  Memento *memento_;
};
