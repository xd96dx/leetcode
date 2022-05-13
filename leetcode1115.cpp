//
// Created by xd on 5/13/22.
//

#include <iostream>
#include <mutex>
#include <thread>
#include <condition_variable>

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
