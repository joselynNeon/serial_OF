#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    mySerial.listDevices();
    vector <ofSerialDeviceInfo> deviceList = mySerial.getDeviceList();
    
    mySerial.setup(0, 115200);
    
    mySerial.flush(); //flush the serial port once before we start
    
    

}

void testApp:: update(){

//--------------------------------------------------------------
if(mySerial.available() >= NUM_MSG_BYTES){
    
    //go through all received bytes - this is where it recieves values from arduino
    for(int i=0; i<NUM_MSG_BYTES; i++){
        
        //read this byte
        int val = mySerial.readByte();
        
        //store it in the array at index i
        bytesReceived[i] = val;
    }
    
    numMsgRecvd++;
    
    
    cout << "bytesReceived[0] = " << bytesReceived[0] << endl;
    cout << "bytesReceived[1] = " << bytesReceived[1] << endl;
    cout << "bytesReceived[2] = " << bytesReceived[2] << endl;
    cout << "------------------------"<<endl;
    
    
    // set desired variables to incoming values
   int  standard =bytesReceived[0];
    //        roll = bytesReceived[1];
    //        pitch = bytesReceived[2];
    
   int   roll = ofMap(bytesReceived[1], 0, 255, -80,80);
   int  pitch =ofMap(bytesReceived[2], 0,255, -180,180);
    
    //this clears the buffer so it doesn't fill up and can be continuously sending values
    mySerial.flush();
    
    
    //this is the flag that initiates the for loop in arduino
    mySerial.writeByte('A'); //request another message!
    
    
    }
}
    //END SERIAL
    
    
    //--------------------------------------------------------------
    void testApp::draw(){
        
    }
    
    //--------------------------------------------------------------
    void testApp::keyPressed(int key){
        
    }
    
    //--------------------------------------------------------------
    void testApp::keyReleased(int key){
        
    }
    
    //--------------------------------------------------------------
    void testApp::mouseMoved(int x, int y ){
        
    }
    
    //--------------------------------------------------------------
    void testApp::mouseDragged(int x, int y, int button){
        
    }
    
    //--------------------------------------------------------------
    void testApp::mousePressed(int x, int y, int button){
        
    }
    
    //--------------------------------------------------------------
    void testApp::mouseReleased(int x, int y, int button){
        
    }
    
    //--------------------------------------------------------------
    void testApp::windowResized(int w, int h){
        
    }
    
    //--------------------------------------------------------------
    void testApp::gotMessage(ofMessage msg){
        
    }
    
    //--------------------------------------------------------------
    void testApp::dragEvent(ofDragInfo dragInfo){ 
        
    }
