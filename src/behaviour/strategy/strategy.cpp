// 2023/11/5
// zhangzhong
// behaviour pattern: strategy

class Context;
class Strategy;
class NecessaryInfomation;

class Strategy {
public:
  virtual ~Strategy() {}
  // Implementation 1. Defining the Strategy and Context interfaces
  // a) Context pass data in parameters to Strategy operations
  // b) Context pass itself as an argument, and the strategy requests data when
  // needed
  virtual void Do(Context *context) = 0;
};

class DefaultStrategy : public Strategy {
public:
  virtual void Do(Context *context) override;
};

class Context {
public:
  // Implementation 3. Making Strategy objects optional
  // Context could carries out default behaviour.
  // the client don't have to deal with strategy unless they don't like the
  // default behaviour
  Context(Strategy *strategy) : strategy_(strategy) {}

  // Context forwards requests from its clients to its strategy.
  void Do() { strategy_->Do(this); }

  // client could configure the context with a strategy object
  void SetStrategy(Strategy *strategy) { strategy_ = strategy; }

  // necessary infomation when perform specific strategy algorithm
  void SetInfomation(NecessaryInfomation *info);
  NecessaryInfomation *GetInfomation();

private:
  Strategy *strategy_;
};

class ConcreteStrategyA : public Strategy {
public:
  virtual void Do(Context *context) override {
    // retrieve necessary information from context
    NecessaryInfomation *info = context->GetInfomation();
    // use the information to do something
    // ...
  }
};
