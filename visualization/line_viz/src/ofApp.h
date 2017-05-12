/**
 *
 * Joshua Vasquez
 *
 */

#pragma once

#include "ofMain.h"
#include "qpose/src/quaternion.hpp"
#include "node_usb_driver.h"

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

    static const size_t SUBDIVISIONS = 4; // line segments between two adjacent nodes.
    static const size_t NOODLE_LENGTH_PX = 700; // total length of the noodle line (in pixels)
    static const size_t SEGMENT_LENGTH_PX = NOODLE_LENGTH_PX/(SUBDIVISIONS * NodeUsbDriver::NUM_NODES);

    /// The angles of each imu node.
    //Quaternion<float> orientations_[NodeUsbDriver::NUM_NODES];
    // in the NodeUsbDriver now.

    NodeUsbDriver nodeUsbDriver_;

    ofEasyCam cam_;
    //ofVboMesh mesh_;
    //ofxPtf ptf_;
};
