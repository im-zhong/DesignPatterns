// 2023/11/5
// zhangzhong
// behaviour pattern: visitor

class Node;
class AssignmentNode;
class VariableReferenceNode;

class Visitor {
public:
  // we could use function overloading to give these operations the same simple
  // name, Visit
  virtual void Visit(AssignmentNode *node) = 0;
  virtual void Visit(VariableReferenceNode *node) = 0;
};

class TypeCheckingVisitor : public Visitor {
public:
  virtual void Visit(AssignmentNode *node) override {
    // type check assignment node
  }
  virtual void Visit(VariableReferenceNode *node) override {
    // type check variable reference node
  }
};

class CodeGenerator : public Visitor {
public:
  virtual void Visit(AssignmentNode *node) override {
    // generate code for assignment node
  }
  virtual void Visit(VariableReferenceNode *node) override {
    // generate code for variable reference node
  }
};

class Node {
public:
  // double dispatch:
  // simply means the operation that gets executed depends on the kind of
  // request and the type of two receivers.
  // Accept is double dispatch operation. Its meaning depends on two types:
  // - the type of the visitor
  // - the type of the node
  virtual void Accept(Visitor *visitor) = 0;
};

class AssignmentNode : Node {
public:
  virtual void Accept(Visitor *visitor) override { visitor->Visit(this); }
};

class VariableReferenceNode : Node {
public:
  virtual void Accept(Visitor *visitor) override { visitor->Visit(this); }
};

class ProgramAST {
public:
  void Traverse(Visitor *visitor) {
    // ...
    // for (auto &node : nodes_) {
    //     node->Accept(visitor);
    // }
    // ...
  }
};
