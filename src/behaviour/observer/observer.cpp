// 2023/11/5
// zhangzhong
// behaviour pattern: observer

#include <list>
#include <unordered_map>

class Subject;
class Observer;
class Interest;

class Observer {
public:
  virtual ~Observer() {}
  // Implementation 2. Observing more than one subject
  // It is necessary to extend the Update interface in such cases to let the
  // observer know which subject is sending the notification.
  // The subject can simply pass itself as an argument to the observer.
  virtual void Update(Subject *subject) = 0;
};

class Subject {
public:
  virtual ~Subject() {}
  // Implementation 7. Specifying modifications of interest explicitly
  // You can improve update efficiency by extending the subject's registration
  // interface to allow the observer to specify specific interests.
  virtual void Attach(Observer *observer, Interest *interest) {
    observers_[interest].push_back(observer);
  }

  virtual void Detach(Observer *observer, Interest *interest) {
    observers_[interest].remove(observer);
  }

  virtual void Notify(Interest *interest) {
    for (auto &observer : observers_[interest]) {
      observer->Update(this);
    }
  }

private:
  std::unordered_map<Interest *, std::list<Observer *>> observers_;
};

// ClockTimer is a concrete subject for storing and maintaining the time of day.
// If notifies its observers every second.
class ClockTimer : public Subject {
public:
  // other methods here

  void Tick(Interest *interest) {
    // update internal time-keeping state
    // ...
    // Implementation 3. Who triggers the update?
    // a) the subject, this
    // b) the client
    Notify(interest);
  }
};

class DigitalClock : public Observer {
public:
  DigitalClock(ClockTimer *subject, Interest *interest)
      : subject_(subject), interest_(interest) {
    subject_->Attach(this, interest_);
  }

  virtual ~DigitalClock() { subject_->Detach(this, interest_); }

  virtual void Update(Subject *subject) {
    // Implementation 6. push model vs. pull model
    // a) push model: the subject sends observers detailed information about the
    // change, whether they want it or not
    // b) pull model: the subject sends nothing but the most minimal
    // notification, and observers ask for details explicitly thereafter
    if (subject == subject_) {
      // pull model
      Draw();
    }
  }

  virtual void Draw() {
    // get the new values from the subject
    // draw the digital clock
  }

private:
  ClockTimer *subject_;
  Interest *interest_;
};
