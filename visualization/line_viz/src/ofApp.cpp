/**
 *
 */

#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofNoFill();
    ofSetFrameRate(60);
    ofBackground(0);

    mesh_.setMode(OF_PRIMITIVE_LINE_LOOP);

    size_t numVerts = 24;
    float w = 6;
    float h = 6;
    for (unsigned i = 0; i < numVerts; ++i)
    {
        mesh_.addVertex(ofVec3f(0.f,
                               w * cos(TWO_PI * i / (float)numVerts),
                               h * sin(TWO_PI * i / (float)numVerts)));
    }
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    //ofPolyline line;
    ofxPtf ptf;
    cam_.begin();
    cam_.setVFlip(true);

    nodeUsbDriver_.updateNodes();

    ofSetLineWidth(10);

    ofPushMatrix();
    //ofDrawGrid(

    Quaternion<float> slerpQuat;
    float percentRotation;
    ofVec3f lastNoodleVertex{0, 0, 0};
    ofVec3f noodleVertex{1, 0, 0};

    // Start the line at the origin.
    //line.addVertex(lastNoodleVertex);
    ptf.addPoint(lastNoodleVertex);
    for (size_t nodeIndex = 0; nodeIndex < NodeUsbDriver::NUM_NODES - 1; ++nodeIndex)
    {
        for (size_t segmentIndex = 0; segmentIndex < SUBDIVISIONS; ++segmentIndex)
        {
            /// Reset the current vector segment to the default orientation.
            noodleVertex.x = 1.0;
            noodleVertex.y = 0.0;
            noodleVertex.z = 0.0;

            /// Compute the next quaternion in the slerp iteration.
            percentRotation = float(segmentIndex+1)/SUBDIVISIONS;
            slerpQuat = Quaternion<float>::slerp(nodeUsbDriver_.orientations_[nodeIndex],
                                                 nodeUsbDriver_.orientations_[nodeIndex + 1],
                                                 percentRotation);

            /// Rotate the current vector by the slerp quaternion amount.
            slerpQuat.rotate(noodleVertex.x,
                             noodleVertex.y,
                             noodleVertex.z);
            /// Scale the current vector to the proper segment length
            noodleVertex *= SEGMENT_LENGTH_PX;

            /// Translate to the tip of the previous segment with good ol' vector addition
            /// (Exclude the first segment).
             noodleVertex += lastNoodleVertex;

            /// Add it to the current line.
            //line.addVertex(noodleVertex);
            ptf.addPoint(noodleVertex);
            lastNoodleVertex = noodleVertex;
        }
    }

    //line.draw();

    for (int i = 0; i < ptf.framesSize(); ++i)
    {
        ofPushMatrix();

        // multiply current matrix (rotated around x axis)
        // by transform for next frame
        ofMultMatrix(ptf.frameAt(i));

        // draw ellipse
        mesh_.draw();

        ofPopMatrix();
    }


    ofPopMatrix();
    cam_.end();
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
