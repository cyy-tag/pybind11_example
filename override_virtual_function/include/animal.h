#include <string>

class Animal {
public:
  virtual ~Animal() = default;
  virtual std::string go(int n_times) = 0;
};

class Dog : public Animal {
public:
  std::string go(int n_times) override {
    std::string result;
    for(int i = 0; i < n_times; ++i) {
      result += "woof!";
    }
    return result;
  }
};
