#pragma once

#include "ofMain.h"

#include <vector>                       // we use the vector template for growable arrays
using namespace std;                    // we do this so we avoid having to type std:: all over the place

class ofApp : public ofBaseApp {
    int num = 20;
    vector<int> dx;                     // we use the vector template for growable arrays
    vector<int> dy;
public:
    void setup() {
        // size(100, 100);              // becomes ofSetupOpenGL(100,100, OF_WINDOW); in main.cpp
        for (int i=0; i<num; i++) {
            dx.push_back(i*5);
            dy.push_back(12 + (i*6));
        }
    }
    void update() {
    
    }
    void draw() {
        ofBackground(204);
        for (int i=0; i<num; i++) {
            dx[i] = dx[i] + 1;
            if (dx[i] > 100) {
                dx[i] = -100;
            }
            diagonals(dx[i], dy[i]);
        }
    }
    
    void diagonals(int x, int y) {
        ofLine(x, y, x+20, y-40);
        ofLine(x+10, y, x+30, y-40);
        ofLine(x+20, y, x+40, y-40);
    }
};



#if 0

// here's the processing code

int num = 20;
int[] dx = new int[num]; // Declare and create an array
int[] dy = new int[num]; // Declare and create an array

void setup() {
    size(100, 100);
    for (int i=0; i<num; i++) {
        dx[i] = i*5;
        dy[i] = 12 + (i*6);
    }
}

void draw() {
    background(204);
    for (int i=0; i<num; i++) {
        dx[i] = dx[i] + 1;
        if (dx[i] > 100) {
            dx[i] = -100;
        }
        diagonals(dx[i], dy[i]);
    }
}

void diagonals(int x, int y) {
    line(x, y, x+20, y-40);
    line(x+10, y, x+30, y-40);
    line(x+20, y, x+40, y-40);
}

#endif

