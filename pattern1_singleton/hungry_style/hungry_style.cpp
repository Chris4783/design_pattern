#include <iostream>

using namespace std;

class HungryStyle {
private:
	HungryStyle() {}
  ~HungryStyle() {}
	HungryStyle(const HungryStyle&) = delete;
  HungryStyle& operator=(const HungryStyle&) = delete;
public:
	static HungryStyle *getInstance() {
		return m_hungry;
	}

  static void FreeInstance() {
		if (m_hungry != nullptr) {
			delete m_hungry;
			m_hungry = nullptr;
		}
	}

private:
	static HungryStyle *m_hungry;
};

// 类外初始化静态变量
HungryStyle *HungryStyle::m_hungry = new HungryStyle; //不管你创建不创建实例，均把实例new出来

void test_hungry() {
	cout << "演示 饿汉式" << endl;
	HungryStyle *p1 = HungryStyle::getInstance(); //只有在使用的时候，才去创建对象。
	HungryStyle *p2 = HungryStyle::getInstance();
	if (p1 != p2) {
		cout << "不是同一个对象" << endl;
	}
	else {
		cout << "是同一个对象" << endl;
	}
  HungryStyle::FreeInstance();

	return;
}

int main(void) {
  test_hungry();

  return 0;
}