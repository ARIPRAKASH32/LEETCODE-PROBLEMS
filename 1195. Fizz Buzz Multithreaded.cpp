#include <functional>
#include <mutex>
#include <condition_variable>

using namespace std;

class FizzBuzz {
private:
    int n;
    int i;
    mutex m;
    condition_variable cv;

public:
    FizzBuzz(int n) {
        this->n = n;
        this->i = 1;
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        while (true) {
            unique_lock<mutex> lock(m);
            while (i <= n && !(i % 3 == 0 && i % 5 != 0)) {
                cv.wait(lock);
            }
            if (i > n) {
                cv.notify_all(); // Unblock other threads waiting to exit
                break;
            }
            
            printFizz();
            ++i;
            cv.notify_all(); 
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        while (true) {
            unique_lock<mutex> lock(m);
            while (i <= n && !(i % 3 != 0 && i % 5 == 0)) {
                cv.wait(lock);
            }
            if (i > n) {
                cv.notify_all(); // Unblock other threads waiting to exit
                break;
            }

            printBuzz();
            ++i;
            cv.notify_all();
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
    void fizzbuzz(function<void()> printFizzBuzz) {
        while (true) {
            unique_lock<mutex> lock(m);
            while (i <= n && !(i % 3 == 0 && i % 5 == 0)) {
                cv.wait(lock);
            }
            if (i > n) {
                cv.notify_all(); // Unblock other threads waiting to exit
                break;
            }

            printFizzBuzz();
            ++i;
            cv.notify_all();
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        while (true) {
            unique_lock<mutex> lock(m);
            while (i <= n && !(i % 3 != 0 && i % 5 != 0)) {
                cv.wait(lock);
            }
            if (i > n) {
                cv.notify_all(); // Unblock other threads waiting to exit
                break;
            }

            printNumber(i);
            ++i; 
            cv.notify_all();
        }
    }
};
