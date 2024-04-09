#include "delegate.h"
#include <iostream>

class Local
{
public:
    Local() = default;

    static Delegate<void(int, int)> s_d;

    void do_something() { s_d(1, 2); }
};

Delegate<void(int, int)> Local::s_d;

static void s_lb(int a, int b) { std::cout << (a + b) << std::endl; }

class Library_Bind
{
public:
    Library_Bind() { Local::s_d.add(s_lb); }
};

int main(int argc, char **argv)
{
    Local *l = new Local;
    Library_Bind *lb = new Library_Bind;

    l->do_something();

    Local::s_d.remove(s_lb);

    return 0;
}
