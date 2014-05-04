#pragma once

//code written by alex tosti and gabor 2014
//to be used with serial_to_oF code linked with this in GitHub
//notes from Alex : 1. make sure that size of array and number of of thigns being sent match up in arduino and OF
// 2. comment out any println when you want to go into Of or you will get errors
// End Notes
//.....

#include "ofMain.h"

class testApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    
    
#define NUM_MSG_BYTES 3 //how many bytes we are expecting to receive (do this above public class) MAKE SURE THIS MATCHES WITH HOW MANY VALUE ARDUINO IS SENDING
    
    
    //SERIAL PART
    ofSerial mySerial;
    
    //set this array's length to the number of msg
    //bytes we are expecting to receive
    int bytesReceived[NUM_MSG_BYTES];
    
    //we'll use this to count how many msgs have been received so far
    //(for debugging)
    long numMsgRecvd;
    //SERIAL END
    
    
    
};
