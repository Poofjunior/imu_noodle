/**
 *
 * Joshua Vasquez
 *
 */

#pragma once

#include "ofMain.h"
#include "qpose/src/quaternion.hpp"

class ofApp : public ofBaseApp{

 public:
    void setup();
    void update();
    void draw();

    void keyPressed  (int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);

    static const size_t NUM_NODES = 2;  // total number of nodes
    static const size_t SUBDIVISIONS = 5; // line segments between two adjacent nodes.
    static const size_t NOODLE_LENGTH_PX = 1000; // total length of the noodle line (in pixels)
    static const size_t SEGMENT_LENGTH_PX = NOODLE_LENGTH_PX/SUBDIVISIONS;

    /// The angles of each imu node.
    Quaternion<float> orientations_[NUM_NODES];
};
