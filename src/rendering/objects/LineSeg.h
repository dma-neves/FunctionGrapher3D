#ifndef LINE_SEG
#define LINE_SEG

#include <SFML/Graphics.hpp>

template <typename T>
class LineSeg
{
public:
    LineSeg(T pt_a, T pt_b, sf::Color color = sf::Color::White) : pt_a(pt_a), pt_b(pt_b), color(color) {}

    T pt_a;
    T pt_b;
    sf::Color color;
};

#endif