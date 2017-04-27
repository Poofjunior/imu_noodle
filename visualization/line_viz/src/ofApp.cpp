/**
 *
 */

#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofNoFill();
    ofSetFrameRate(30);
    ofBackground(0);

    for (size_t qIndex = 0; qIndex < SUBDIVISIONS; ++qIndex)
    {
        orientations_[qIndex].encodeRotation(0, 1, 0, 0);
    }

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){


    ofPolyline line;
    //translate so that 0,0 is the center of the screen
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2, 0);

    // Hardcode some vertices to start with:
    orientations_[0].encodeRotation(0 * (M_PI/180.0), 0, 0, 1);
    orientations_[1].encodeRotation(90 * (M_PI/180.0), 0, 0, 1);
    //orientations_[2].encodeRotation(0 * (M_PI/180.0), 0, 0, 1);

    Quaternion<float> slerpQuat;
    ofVec3f lastNoodleVertex{1, 0, 0};
    ofVec3f noodleVertex{1, 0, 0};

    for (int nodeIndex = 0; nodeIndex < NUM_NODES - 1; ++nodeIndex)
    {
        for (size_t segmentIndex = 0.0; segmentIndex < SUBDIVISIONS; ++segmentIndex)
        {
            /// Reset the current vector segment to the default orientation.
            noodleVertex.x = 1.0;
            noodleVertex.y = 0.0;
            noodleVertex.z = 0.0;

            /// Compute the next quaternion in the slerp iteration.
            slerpQuat = Quaternion<float>::slerp(orientations_[nodeIndex], orientations_[nodeIndex + 1],
                                                 float(segmentIndex)/SUBDIVISIONS);

            /// Rotate the current vector by the slerp quaternion amount.
            slerpQuat.rotate(noodleVertex.x,
                             noodleVertex.y,
                             noodleVertex.z);
            /// Scale the current vector to the proper segment length
            noodleVertex *= SEGMENT_LENGTH_PX;

            /// Translate to the tip of the previous segment with good ol' vector addition.
            if ((segmentIndex != 0) && (nodeIndex != 0))
                noodleVertex += lastNoodleVertex;

            /// Add it to the current line.
            line.addVertex(noodleVertex);
            lastNoodleVertex = noodleVertex;
        }
    }

/*
    int x, y;
    for (int i = 0; i < 5; ++i)
    {
        x = i * 50;
        y = i * 25;
        line.addVertex(ofVec2f(x,y));
    }
*/


    line.draw();
    ofPopMatrix();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    //store the last mouse point when it's first pressed to prevent popping
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}
