/* This file */

#define HZ      1

typedef unsigned int tm_msec;
typedef unsigned int freq_hz;
typedef unsigned int luminance;

enum Color{
    RED,
    YELLOW,
    BLUE,
    WHITE,
    OFF
};

enum State{
    SystemError,
    SystemUpdating,
    SystemBooting,
    PlaybackVolumeChanged,
    BluetoothPairing,
    PlaybackInactive,
    PlaybackPlayingAndBluetoothConnected,
    PlaybackPlaying,
    PlaybackPaused,
};

void HandleFunction(State &S);
static std::string getColorName(const Color &c);
static void ActiveLed(Color c, luminance l, tm_msec t, freq_hz f);
static void FlashingLed(Color c, luminance l, freq_hz f);
static void VolumeChangedLed(Color c, tm_msec t);
static void DeactiveLed();