#pragma once
#include "header.hpp"

//Activation function
#define sign(num) ((num) >= 0 ? (1) : -(1))

class Perceptron {
private:
	// Variables
	int size = 0;
    float lr = 0.01f;
    float *weights;
public:

    // Constructor
    Perceptron(int n) {
        this->size = n;
        this->weights = new float[n];
        // Initialize the weights randomly
        srand(time(NULL));
        int i = 0;
        while (i < n) {
            // Random number from 0.0 till 1.0
            this->weights[i] = 0.0 + (rand() * (1.0 - 0.0) / RAND_MAX);
            i++;
        }
    }

    // Functions
    constexpr int guess(float inputs[]) {
        float sum = 0;
        // Initialize the weights randomly
        int i = 0;
        while (i < this->size) {
            sum += inputs[i] * this->weights[i];
            i++;
        }

        int output = sign(sum);
        return output;
    }

	void train(float inputs[], int target) {
        int guess = this->guess(inputs),
            error = target - guess, i = 0;

        // Tune all the weights
        while (i < this->size) {
            this->weights[i] += error * inputs[i] * lr;
            i++;
        }
    }

    float guessY(float x) {
        float m = this->weights[2] / this->weights[1],
              b = this->weights[0] / this->weights[1];

        return -m - b * x;
    }
};