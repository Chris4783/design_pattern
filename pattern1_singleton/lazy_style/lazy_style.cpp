#include <iostream>

using namespace std;

class LazyStyle {
private:
	LazyStyle() {}
  ~LazyStyle() {}
  LazyStyle(const LazyStyle&) = delete;
  LazyStyle& operator=(const LazyStyle&) = delete;
	
public:
	static LazyStyle *getInstance() {
		if (m_singer == nullptr ) { //懒汉式：1 每次获取实例都要判断 2 多线程会有问题
			m_singer = new LazyStyle;
		}
		return m_singer;
	}

private:
	static LazyStyle *m_singer;
};

// 类外初始化静态变量
LazyStyle *LazyStyle::m_singer = nullptr;  //懒汉式 并没有创建单例对象

void test_lazy() {
	cout << "演示 懒汉式" << endl;
	LazyStyle *p1 = LazyStyle::getInstance(); //只有在使用的时候，才去创建对象。
	LazyStyle *p2 = LazyStyle::getInstance();
	if (p1 != p2) {
		cout << "不是同一个对象" << endl;
	}
	else {
		cout << "是同一个对象" << endl;
	}

	return;
}

int main(void) {
  test_lazy();

  return 0;
}