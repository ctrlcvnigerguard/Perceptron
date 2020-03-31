#include "Perceptron.hpp"
#include "Training.hpp"

Perceptron brain(3);
Point points[500];

static int trainingIndex = 0;

void setup() {
	int i = 0;
	while (i < (sizeof(points) / sizeof(*points))) {
		Point pot;
		i++;
	}
}

void draw() {
    // Clear display
    window.clear(Color(255, 255, 255));

    // Draw some Line
    Point p1(-1, f(-1)),
          p2(1, f(1));

    Vertex vertices_first[2] = {
            Vertex (sf::Vector2f(p1.pixelX(), p1.pixelY()), sf::Color::Black),
            Vertex (sf::Vector2f(p2.pixelX(), p2.pixelY()), sf::Color::Black),
    };

    window.draw(vertices_first, 2, Lines);

    Point p3(-1, brain.guessY(-1)),
          p4(1, brain.guessY(1));

    Vertex vertices_second[2] = {
            Vertex (sf::Vector2f(p3.pixelX(), p3.pixelY()), sf::Color::Black),
            Vertex (sf::Vector2f(p4.pixelX(), p4.pixelY()), sf::Color::Black),
    };

    window.draw(vertices_second, 2, Lines);

    // Draw some Point
    int i = 0;
    while(i < (sizeof(points) / sizeof(*points))) {
        Point dot = points[i];
        dot.show(i);

        float inputs[] = {dot.x, dot.y, dot.bias};
        int target = dot.label;

        int guess = brain.guess(inputs);
        if(guess == target) {
            el[i].setFillColor(Color(0, 255, 0));
        } else {
            el[i].setFillColor(Color(255, 0, 0));
        }

        el[i].setRadius(8.f);
        el[i].setPosition(dot.pixelX() + 5, dot.pixelY() + 5);

        window.draw(el[i]);
        i++;
    }

    Point training = points[trainingIndex];
    float inputs[] = {training.x, training.y, training.bias};
    int target = training.label;

    brain.train(inputs, target);

    trainingIndex++;
    if(trainingIndex == (sizeof(points) / sizeof(*points))) trainingIndex = 0;

    // Display on screen what has been rendered to the window so far
    window.display();
}

void mousePressed() {
    int i = 0;
    while(i < (sizeof(points) / sizeof(*points))) {
        i++;
    }
}

void Init() {
	setup();
	draw();
}

int main() {
    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed || event.key.code == sf::Keyboard::Escape)
                window.close();
            else if (event.type == sf::Event::MouseButtonPressed) {
                mousePressed();
            }
        }

        Init();
    }

	return 0;
}