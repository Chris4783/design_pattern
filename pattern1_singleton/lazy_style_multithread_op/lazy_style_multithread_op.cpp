#include <iostream>

using namespace std;

// c++11标准下，《Effective C++》static静态局部变量的初始化
class LazyStyle {
private:   
  LazyStyle() {}
  ~LazyStyle() {}
  LazyStyle(const LazyStyle&) = delete;
  LazyStyle& operator=(const LazyStyle&) = delete;
public:
  static LazyStyle* getInstance() {
    static LazyStyle* m_lazy;
    return m_lazy;
  }
};

void test_lazy() {
  LazyStyle* p1 = LazyStyle::getInstance();
  LazyStyle* p2 = LazyStyle::getInstance();
  if (p1 != p2) {
		cout << "不是同一个对象" << endl;
	} else {
		cout << "是同一个对象" << endl;
	}
}

int main() {
  test_lazy();
  
  return 0;
}
