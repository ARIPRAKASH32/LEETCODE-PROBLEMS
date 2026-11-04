class ZeroEvenOdd {
private:
    int n, i;
    mutex m1, m2, m3;

public:
    ZeroEvenOdd(int n) {
        this->n = n;
        this->i = 1;
        m2.lock();  
        m3.lock();
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        for (int j = 1; j <= n; j++) {
            m1.lock();  
            printNumber(0);

            if (j % 2 == 1) {
                m3.unlock();
            } else {
                m2.unlock(); 
            }
        }
    }

    void even(function<void(int)> printNumber) {
        for (int j = 2; j <= n; j += 2) {
            m2.lock(); 
            printNumber(j);
            m1.unlock(); 
        }
    }

    void odd(function<void(int)> printNumber) {
        for (int j = 1; j <= n; j += 2) {
            m3.lock();  
            printNumber(j);
            m1.unlock(); 
        }
    }
};
