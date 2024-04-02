#include "test_delegate_observer.h"

int main() {
    DelegateObserver::instance();
    DelegateWatch *watch = new DelegateWatch();
    DelegateObserver::instance()->push_event();
    delete watch;
    return 0;
}
