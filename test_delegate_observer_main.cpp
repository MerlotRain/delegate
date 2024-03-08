#include "delegate_observer.h"

int main() {
    DelegateObserver::instance();
    DelegateWatch *watch = new delegate_watch();
    DelegateObserver::instance()->push_event();
    delete watch;
    return 0;
}
