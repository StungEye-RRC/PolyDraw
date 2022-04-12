#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {
	for (const auto shape : shapes) {
		shape->render();
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	if (!mouseOnCanvas) { return; }

	int x = ofGetMouseX();
	int y = ofGetMouseY();

	switch (key) {
	case 'r': // Add a rectangle. 
		shapes.push_back(new Rect({x, y}, ofColor::cadetBlue, 100, 200));
		break;
	case 'h': // Add a heart.
		shapes.push_back(new Heart({x, y}, ofColor::darkRed, 100));
		break;
	case 'd': // Remove the last added shape. 
		if (!shapes.empty()) {
			delete shapes.back(); // Without this line we will leak memory!
			shapes.pop_back();
		}
		break;
	default:
		std::cout << "Unknown key: " << static_cast<char>(key) << "\n";
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {
	mouseOnCanvas = true;
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {
	mouseOnCanvas = false;
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}
