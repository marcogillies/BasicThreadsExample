#include "ofApp.h"

ofApp::ofApp():me(100, 200), other(300, 300), sender(me), receiver(other), gui(10, 10)
{
    sendPortInput = gui.addTextInput("Send Port:", "11999");
    receivePortInput = gui.addTextInput("Receive Port:", "11998");
    aiToggle = gui.addToggle("AI", false);
    gui.addButton("Start!");
    gui.onButtonEvent(this, &ofApp::onButtonEvent);
}

//--------------------------------------------------------------
void ofApp::setup(){
    //parameters.setName("parameters");
    //parameters.add(myInt.set("myInt",10,1,100));
    //parameters.add(myString.set("myString","hello"));
    
    //gui.setup(parameters);

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    //gui.draw();
    me.display();
    other.display();
}

void ofApp::onButtonEvent(ofxDatGuiButtonEvent e)
{
    if (e.target->is("Start!")){
        cout << "Starting" << endl;
        
        int sendPort = stoi(sendPortInput->getText());
        sender.start("127.0.0.1",sendPort);
        
        
        int receievePort = stoi(receivePortInput->getText());
        receiver.start(receievePort);
        
        if(aiToggle->getEnabled()){
            me.startAI();
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == 'w'){
        me.up();
    }
    if(key == 's'){
        me.down();
    }
    
    if(key == 'a'){
        me.left();
    }
    
    if(key == 'd'){
        me.right();
    }

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
