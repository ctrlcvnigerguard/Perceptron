#pragma once
#include "header.hpp"

float mnp (float n, int start1, int stop1, int start2, int stop2) {
    return ((n - start1) / (stop1 - start1)) * (stop2 - start2) + start2;
}

float f(float x) {
    // y = mx + b
    return -0.89 * x - 0.6;
}

class Point {
public:
    // Variables
	float x, y, bias = 1.f;
	int label;

    // Constructor
	Point() {
        // Random number from 0.0 till 1.0
        x = -1.f + (rand() * (1.f - -1.f) / RAND_MAX);
		y = -1.f + (rand() * (1.f - -1.f) / RAND_MAX);

		float lineY = f(x);

		y > lineY ? label = 1 : label = -1;
	}

    Point(float _x, float _y) {
        this->x = _x;
        this->y = _y;
        this->bias = 1;
    }

	// Functions

	float pixelX() {
        return mnp(x, -1, 1, 0, widthI);
	}

    float pixelY() {
        return mnp(y, -1, 1, heightI, 0);
    }

	void show(int i) {
        float px = pixelX(), py = pixelY();

	    if(label == 1) {
            shape[i].setRadius(13.f);
            shape[i].setOutlineThickness(2);
            shape[i].setOutlineColor(Color::Black);
            shape[i].setFillColor(Color::White);
            shape[i].setPosition(px, py);
	    } else {
            shape[i].setRadius(16.f);
            shape[i].setFillColor(Color::Black);
            shape[i].setPosition(px, py);
	    }

	    // Draw shape
        window.draw(shape[i]);
	}
};
