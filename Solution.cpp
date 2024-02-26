#include <iostream>
#include <string>
#include <stdlib.h>
#include "common.h"

State StateReceiverFromWebSocket(State &S){
    /** 
     * This function keep listening to state changes coming from the WebSocket,
     * Because I don't have the data from infrastructure challenge, I'll use a
     * random function to test my code, it will change state constantly
     */  
    S = static_cast<State>(rand() % 8);
    return S;
}


int main(){
    // The initial state always SystemBooting
    Color ColorOfLed = OFF;
    State PreDeviceState = SystemBooting;
    State CurrDeviceState;
    HandleFunction(PreDeviceState);
    while(true){
        //Always check for changes of device state
        CurrDeviceState = StateReceiverFromWebSocket(CurrDeviceState);
        if(CurrDeviceState != PreDeviceState){
            HandleFunction(CurrDeviceState);
            PreDeviceState = CurrDeviceState;
        } 
    }
    return 0;
}