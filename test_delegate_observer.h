#pragma once

#include <iostream>
#include <algorithm>
#include "delegate.h"

class DelegateObserver {
  public:
    DelegateObserver();
    static DelegateObserver *instance();

    void push_event();

  public:
    Delegate<void(std::vector<int> &)> sort_element;
};


class DelegateWatch {
  public:
    DelegateWatch() {
        int p = 0;
        DelegateObserver::instance()->sort_element.add(this, &delegate_watch::sortElement);
    }

    void sortElement(std::vector<int> &element) {
        int p = 0;
        std::sort(element.begin(), element.end());
    }
};
