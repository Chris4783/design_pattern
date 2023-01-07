#include <iostream>
#include <mutex>

using namespace std;

mutex mtx;  //定义全局锁

class LazyStyle {
private:   
  LazyStyle() {}
  ~LazyStyle() {}
  LazyStyle(const LazyStyle&) = delete;
  LazyStyle& operator=(const LazyStyle&) = delete;
public:
  static LazyStyle* getInstance() {
    lock_guard<mutex> lock(mtx);
    //mtx.lock();  普通锁
    if(m_lazy == nullptr) {
      m_lazy = new LazyStyle;
    }
    //mtx.unlock();
    return m_lazy;
  }
  //专门设计一个释放堆区空间的逻辑
  static void destroy() {
  //不要把这个逻辑放在析构函数中，将会出现无限递归
    if(m_lazy != nullptr) {
      delete m_lazy;
    }
  }
private:
  static LazyStyle* m_lazy;
};

LazyStyle* LazyStyle::m_lazy = nullptr;

void test_lazy_multithread() {
  LazyStyle* p1 = LazyStyle::getInstance();
  LazyStyle* p2 = LazyStyle::getInstance();
  if (p1 != p2) {
		cout << "不是同一个对象" << endl;
	} else {
		cout << "是同一个对象" << endl;
	}
  LazyStyle::destroy();
}

int main() {
  test_lazy_multithread();
  
  return 0;
}
