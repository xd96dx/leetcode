/*
1115. 交替打印 FooBar
给你一个类：

class FooBar {
  public void foo() {
    for (int i = 0; i < n; i++) {
      print("foo");
    }
  }

  public void bar() {
    for (int i = 0; i < n; i++) {
      print("bar");
    }
  }
}
两个不同的线程将会共用一个 FooBar 实例：

线程 A 将会调用 foo() 方法，而
线程 B 将会调用 bar() 方法
请设计修改程序，以确保 "foobar" 被输出 n 次。
*/

#include <iostream>
#include <mutex>
#include <thread>
#include <condition_variable>

// 这个题用atomic, 做也可以, 先用了普通的condition 做了一版, 没啥难度吧感觉...
class test {
public:
    std::condition_variable cv;
    std::mutex m;
    bool res = false;
    int n = 5;

    void foo() {
        for (int i = 0; i < n; i++) {
            std::unique_lock<std::mutex> lock(m);
            std::cout << "foo";
            res = true;
            cv.notify_one();
            cv.wait(lock, [&]() {return !res;});
        }
    }

    void bar() {
        for (int i = 0; i < n; i++) {
            std::unique_lock<std::mutex> lock(m);
            cv.wait(lock, [&]() {return res;});
            std::cout << "bar" << std::endl;
            res = false;
            cv.notify_one();
        }
   }

   void run() {
        auto t1 = std::thread(&test::bar, this);
        auto t2 = std::thread(&test::foo, this);
        t1.join();
        t2.join();
    }
};
