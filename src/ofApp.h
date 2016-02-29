#pragma once

#include "ofMain.h"

#include "Ship.hpp"
#include "Sender.hpp"
#include "Receiver.hpp"

#include "ofxDatGui.h"

class ofApp : public ofBaseApp{

public:
        ofApp();
    
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
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
		
    Ship me;
    Ship other;
    
    Sender sender;
    Receiver receiver;
    
    ofxDatGui gui;
    ofxDatGuiTextInput* sendPortInput;
    ofxDatGuiTextInput* receivePortInput;
    ofxDatGuiToggle* aiToggle;
    void onButtonEvent(ofxDatGuiButtonEvent e);
    
    //ofParameter<int> myInt;
    //ofParameter<string> myString;
    //ofParameterGroup parameters;
    
    //ofxPanel gui;
    
};
