#include "delegate_observer.h"
#include <future>
#include <thread>

static DelegateObserver *g_mainWindow = nullptr;

DelegateObserver::DelegateObserver() {}

DelegateObserver *DelegateObserver::instance() {
    if (!g_mainWindow)
        g_mainWindow = new DelegateObserver();

    return g_mainWindow;
    std::atomic<int> x;
}

void DelegateObserver::push_event() {
    auto fun = [&](std::promise<std::vector<int>> *pro) {
        std::vector<int> element;
        srand((int)time(NULL));
        for (int i = 0; i < 10; ++i) {
            element.push_back(rand());
        }

        sort_element(element);
        pro->set_value(element);
    };

    std::promise<std::vector<int>> pro;
    std::future<std::vector<int>> fut = pro.get_future();

    std::thread thread(fun, &pro);
    thread.join();

    for (auto &e : fut.get()) {
        std::cout << e << std::endl;
    }
}

