#include "smarterpointer.h"

#include <iostream>

class Font : public RefObject
{
public:
    Font() { std::cout << "Font()" << std::endl; }
    ~Font() { std::cout << "~Font()" << std::endl; }
};
SMARTER_PTR(Font)

class FontWrapper
{
    FontWPtr m_wptrFont;

public:
    FontWrapper() { std::cout << "FontWrapper()" << std::endl; }
    ~FontWrapper() { std::cout << "~FontWrapper()" << std::endl; }

    void setFont(FontPtr font) { m_wptrFont = font; }
    void doSomething()
    {
        if (m_wptrFont.expired())
        {
            std::cout << "m_wptrFont is expired" << std::endl;
        }
        else
        {
            FontPtr ptrFont = m_wptrFont.lock();
            if (ptrFont) { std::cout << "m_wptrFont is valid" << std::endl; }
            else { std::cout << "m_wptrFont is invalid" << std::endl; }
        }
    }
};

int main()
{
    FontWrapper wrapper;
    {
        FontPtr font = new Font();
        wrapper.setFont(font);
        wrapper.doSomething();
    }
    wrapper.doSomething();

    return 0;
}