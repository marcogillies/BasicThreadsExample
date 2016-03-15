#include "ofApp.h"

// set up the two ships
// associated the sender with me and the
// receiver with other (though it is also
// fum to link them both to the same ship)
ofApp::ofApp():me(100, 200), other(300, 300), sender(me), receiver(me), gui(10, 10)
{
    // GUI input for the ports
    sendPortInput = gui.addTextInput("Send Port:", "11999");
    receivePortInput = gui.addTextInput("Receive Port:", "11998");
    // set "me" to be autnomously controlled
    // (doesn't do anything intersting
    // just moves in one direction
    aiToggle = gui.addToggle("AI", false);
    
    // start the network code
    gui.addButton("Start!");
    gui.onButtonEvent(this, &ofApp::onButtonEvent);
}

//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    // draw the two ships
    me.display();
    other.display();
}

// if we press start then we
// read the ports from the GUI
// and start the sender and receiver
void ofApp::onButtonEvent(ofxDatGuiButtonEvent e)
{
    
    if (e.target->is("Start!")){
        cout << "Starting" << endl;
        
        try{
            int sendPort = stoi(sendPortInput->getText());
            sender.start("127.0.0.1",sendPort);
            
            
            int receievePort = stoi(receivePortInput->getText());
            receiver.start(receievePort);
            
            
            // if we have enabled AI
            // we also start the AI
            if(aiToggle->getEnabled()){
                me.startAI();
            }
            
        } catch (std::invalid_argument){
            ofSystemAlertDialog("please Enter a valid port number");
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
