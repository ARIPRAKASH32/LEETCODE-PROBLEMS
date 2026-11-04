class H2O {
public:
    mutex m;
    condition_variable cv;
    int turn;
    H2O() {
        this->turn=0;
    }

    void hydrogen(function<void()> releaseHydrogen) {
        
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        unique_lock<mutex>lock(m);
        while(turn==2) cv.wait(lock);
        releaseHydrogen();
        turn++;
        cv.notify_all();
    }

    void oxygen(function<void()> releaseOxygen) {
        
        // releaseOxygen() outputs "O". Do not change or remove this line.
        unique_lock<mutex>lock(m);
        while(turn!=2) cv.wait(lock);
        releaseOxygen();
        turn=0;
        cv.notify_all();
    }
};
