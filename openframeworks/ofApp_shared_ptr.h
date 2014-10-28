#pragma once

#include "ofMain.h"

#include <tr1/memory>  // it looks like osx version of openframeworks (0.8.4) is still using tr1
using namespace tr1;   // we do this so we avoid having to type tr1:: all over the place


class Diagonals {
    int x, y, speed, thick, gray;
public:
    Diagonals(int xpos, int ypos, int s, int t, int g) {
        x = xpos;
        y = ypos;
        speed = s;
        thick = t;
        gray = g;
    }
    void update() {
        //! strokeWeight(thick);
        //! stroke(gray);
        ofLine(x, y, x+20, y-40);
        ofLine(x+10, y, x+30, y-40);
        ofLine(x+20, y, x+40, y-40);
        x = x + speed;
        if (x > 100) {
            x = -100;
        }
    }
};


class ofApp : public ofBaseApp {
    shared_ptr<Diagonals> da, db;
public:
    void setup() {
        // size(100, 100);    // becomes ofSetupOpenGL(100,100, OF_WINDOW); in main.cpp
        //! smooth();
        // Inputs: x, y, speed, thick, gray
        da = shared_ptr<Diagonals>(new Diagonals(0, 80, 1, 2, 0));
        db = shared_ptr<Diagonals>(new Diagonals(0, 55, 2, 6, 255));
        // in a c++11 compatible build, the above line can be written as
        // db = make_shared<Diagonals>(0, 55, 2, 6, 255));
    }
    
    void draw() {
        ofBackground(204);
        da->update();
        db->update();
    }
};





#if 0

// here's the processing code

Diagonals da, db;

void setup() {
    size(100, 100);
    smooth();
    // Inputs: x, y, speed, thick, gray
    da = new Diagonals(0, 80, 1, 2, 0);
    db = new Diagonals(0, 55, 2, 6, 255);
}

void draw() {
    background(204);
    da.update();
    db.update();
}

class Diagonals {
    int x, y, speed, thick, gray;
    
    Diagonals(int xpos, int ypos, int s, int t, int g) {
        x = xpos;
        y = ypos;
        speed = s;
        thick = t;
        gray = g;
    }
    void update() {
        strokeWeight(thick);
        stroke(gray);
        line(x, y, x+20, y-40);
        line(x+10, y, x+30, y-40);
        line(x+20, y, x+40, y-40);
        x = x + speed;
        if (x > 100) {
            x = -100;
        }
    }
}

#endif

