#pragma once
enum  { widthI = 800, heightI = 800 };

// Includes
#include <cstdlib>
#include <iterator>
#include <deque>
#include <iostream>
#include <cmath>
#include <ctime>

// SFML
#include <SFML/Graphics.hpp>

// Namespaces
using namespace std;
using namespace sf;

// Constants 
static const float heightF = 800.f, widthF = 800.f;

// Variables
RenderWindow window(VideoMode(widthI, heightI), "Neural Networks");

// Shape
deque<CircleShape> shape(500);
// Ellipse
deque<CircleShape> el(500);