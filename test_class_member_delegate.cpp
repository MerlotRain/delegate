#include "delegate.h"
#include <assert.h>

class Test
{
public:
    void add(int a, int b, int &c) { c = a + b; }
};

int main(int argc, char **argv)
{
    Delegate<void(int, int, int &)> d;
    d.add(&Test::add);
    int c = 0;
    d(1, 2, c);
    assert(c == 3);
    return 0;
}