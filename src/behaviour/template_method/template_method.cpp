// 2023/11/5
// zhangzhong
// behaviour pattern: template method

class TemplateMethod {
public:
  void Do() {
    // ...
    PrimitiveOperation1();
    // ...
    PrimitiveOperation2();
    // ...
  }

  virtual void PrimitiveOperation1() = 0;
  virtual void PrimitiveOperation2() = 0;
};

class ConcreteMethod : public TemplateMethod {
public:
  virtual void PrimitiveOperation1() override {
    // ...
  }

  virtual void PrimitiveOperation2() override {
    // ...
  }
};
