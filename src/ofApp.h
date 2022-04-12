#pragma once

#include "ofMain.h"
#include <vector> // std::vector

class Shape {
protected:
	glm::vec2 position;
	ofColor color;

public:
	Shape(const glm::vec2& position, const ofColor& color)
		: position{position}, color{color} {
	}

	virtual ~Shape() = default;
	virtual void render() const = 0; // Pure Virtual Function. This will make Shape an Abstract Class.
};

class Rect : public Shape {
	int width;
	int height;
public:
	Rect(const glm::vec2& position, const ofColor& color, int width, int height)
		: Shape{position, color}, width{width}, height{height} {
	}

	void render() const override {
		ofSetColor(color);
		ofDrawRectangle(position.x, position.y, width, height);
	}
};

class Heart : public Shape {
	int size;
public:
	Heart(const glm::vec2& position, const ofColor& color, int size)
		: Shape{position, color}, size{size} {
	}

	void render() const override {
		// std::cout << "Drawing Heart of s{" << size << "} @ x: " << position.x << " y: " << position.y << "\n";
		ofSetColor(color);

		ofBeginShape();
		float i = 0;
		while (i < TWO_PI) {
			float r = (2 - 2 * sin(i) + sin(i) * sqrt(abs(cos(i))) / (sin(i) + 1.4)) * -(size * 0.25);
			float x = position.x + cos(i) * r;
			float y = position.y + sin(i) * r;
			ofVertex(x, y);
			i += 0.005 * HALF_PI * 0.5;
		}
		ofEndShape(true);
	}
};

class ofApp : public ofBaseApp {

public:
	void setup() override;
	void update() override;
	void draw() override;

	void keyPressed(int key) override;
	void keyReleased(int key) override;
	void mouseMoved(int x, int y) override;
	void mouseDragged(int x, int y, int button) override;
	void mousePressed(int x, int y, int button) override;
	void mouseReleased(int x, int y, int button) override;
	void mouseEntered(int x, int y) override;
	void mouseExited(int x, int y) override;
	void windowResized(int w, int h) override;
	void dragEvent(ofDragInfo dragInfo) override;
	void gotMessage(ofMessage msg) override;

	std::vector<Shape*> shapes;
	bool mouseOnCanvas = false;
};
