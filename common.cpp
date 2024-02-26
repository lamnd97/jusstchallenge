#include <iostream>
#include "common.h"

static std::string getColorName(const Color &c){
    switch(c)
    {
        case RED:       return "red";
        case YELLOW:    return "yellow";
        case BLUE:      return "blue";
        case WHITE:     return "white";
        case OFF:       return "off";
    }
    return "off";
}
static void ActiveLed(Color c, luminance l){
    std::cout<<getColorName(c)<<"@"<<l<<std::endl;
}

static void FlashingLed(Color c, luminance l, freq_hz f){
    std::cout<<getColorName(c)<<"@"<<l<<" frequency: "<<f<<std::endl;
}

static void VolumeChangedLed(Color c, tm_msec t){
    /**
     * During 3s from VolumeChanged state, 
     * keep checking volume and active led 
     * intensity due to volume
     */
    // ?? This below code is disable for compilation, but it shows the idea @volume
    //int curr = readl(TIMER_REGISTER);
    //while((readl(TIMER_REGISTER)-curr) <= t){
        //int vol = readl(VOLUME_REGISTER);
        //ActiveLed(WHITE,vol);
    //}
}
static void DeactiveLed(){
    std::cout<<"off"<<std::endl;
}

void HandleFunction(State &S){
    switch(S)
    {
        case SystemError:
            ActiveLed(RED, 100);
            break;
        
        case SystemUpdating:
            DeactiveLed();
            FlashingLed(YELLOW, 100, HZ);
            break;
        
        case SystemBooting:
            ActiveLed(RED, 10);
            break;
        
        case PlaybackVolumeChanged:
            VolumeChangedLed(WHITE, 3000);
            break;
        
        case BluetoothPairing:
            DeactiveLed();
            FlashingLed(BLUE, 100, 2*HZ);
            break;
        
        case PlaybackInactive:
            DeactiveLed();
            break;

        case PlaybackPlayingAndBluetoothConnected:
            ActiveLed(BLUE, 10);
            break;

        case PlaybackPlaying:
            ActiveLed(WHITE, 10);
            break;
        
        case PlaybackPaused:
            ActiveLed(WHITE, 50);
            break;

        default: break;
    }
}

