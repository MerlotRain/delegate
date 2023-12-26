#include "delegate.h"
#include <assert.h>

void add_fun(int a, int b, int &c) { c = a + b; }

int main(int argc, char **argv)
{
    Delegate<void(int, int, int &)> d;
    d.add(add_fun);
    int c = 0;
    d(1, 2, c);
    assert(c == 3);
    return 0;
}