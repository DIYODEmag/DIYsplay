#include "DIYsplay.h"

DIYsplay::DIYsplay() {

}

void DIYsplay::init() {
    //Init for communication with the display
    pinMode(DIYsplay::sigPin, OUTPUT);
    digitalWrite(DIYsplay::sigPin, HIGH);
    mates.begin();
}

void DIYsplay::begin() {
    //Init for communication with the display
    //Since the Mates constructor must be called on initialization (in the header file),
    //we need to re-initialize it here unfortunately. There is no processing code
    //called directly from the begin() method so it's not a huge deal.
    DIYsplay::sigPin = DEFAULT_SIG_PIN;
    DIYsplay::resetPin = DEFAULT_RESET_PIN;
    mates = MatesController(Serial, resetPin);
    DIYsplay::init();
}

void DIYsplay::begin(HardwareSerial &serial, uint8_t sigPin, uint8_t resetPin) {
    DIYsplay::sigPin = sigPin;
    DIYsplay::resetPin = resetPin;
    mates = MatesController(serial, resetPin);
    DIYsplay::init();
}

#ifdef SoftwareSerial_h
void DIYsplay::begin(SoftwareSerial &serial, uint8_t sigPin, uint8_t resetPin) {
    DIYsplay::sigPin = sigPin;
    DIYsplay::resetPin = resetPin;
    mates = MatesController(serial, resetPin);
    DIYsplay::init();
}
#endif

#ifdef AltSoftSerial_h
void DIYsplay::begin(AltSoftSerial &serial, uint8_t sigPin, uint8_t resetPin) {
    DIYsplay::sigPin = sigPin;
    DIYsplay::resetPin = resetPin;
    mates = MatesController(serial, resetPin);
    DIYsplay::begin();
}
#endif

void DIYsplay::setScreen(int page) {
    mates.setPage(page);
    currentScreen = page;
}

uint8_t DIYsplay::getNumWidgets(Screen page) {
    return widgetLengths[page];
}

uint8_t widgetLengths[73] = {
	0, 10, 20, 10, 12, 12, 4, 
	10, 2, 4, 12, 8, 6, 8, 
	4, 7, 4, 2, 8, 2, 6, 
	6, 4, 4, 4, 8, 6, 4, 
	2, 10, 2, 12, 12, 2, 6, 
	6, 6, 4, 4, 2, 4, 4, 
	4, 4, 2, 8, 8, 4, 2, 
	6, 4, 4, 6, 4, 8, 6, 
	4, 29, 10, 5, 2, 4, 4, 
	6, 3, 3, 0, 6, 6, 0, 
	16, 14, 4};

//Use this command to set data to any widget on the DIYsplay screen.
//The 'index' parameter determines which widget to set, starting at 0.
void DIYsplay::setData(int index, int data) {
    // This is auto-generated mapping code that ensures each MATES widget is
    // mapped to a data index. This prevents the user having to remember the
    // individual indexes for each widget.
    // 
    // This code should not be modified or unpredictable behaviour may result.
    switch(currentScreen) {
        case(1):
            switch(index) {
                case(0): mates.setSpectrumValue(LedSpectrum0, 0, data); break;
                case(1): mates.setSpectrumValue(LedSpectrum0, 1, data); break;
                case(2): mates.setSpectrumValue(LedSpectrum0, 2, data); break;
                case(3): mates.setSpectrumValue(LedSpectrum0, 3, data); break;
                case(4): mates.setSpectrumValue(LedSpectrum0, 4, data); break;
            } break;
        case(2):
            switch(index) {
                case(0): mates.setWidgetValue(LedDigits0, data); break;
                case(1): mates.setWidgetValue(LedDigits1, data); break;
                case(2): mates.setWidgetValue(LedDigits2, data); break;
                case(3): mates.setWidgetValue(LedDigits3, data); break;
                case(4): mates.setWidgetValue(LedDigits4, data); break;
                case(5): mates.setSpectrumValue(LedSpectrum1, 0, data); break;
                case(6): mates.setSpectrumValue(LedSpectrum1, 1, data); break;
                case(7): mates.setSpectrumValue(LedSpectrum1, 2, data); break;
                case(8): mates.setSpectrumValue(LedSpectrum1, 3, data); break;
                case(9): mates.setSpectrumValue(LedSpectrum1, 4, data); break;
            } break;
        case(3):
            switch(index) {
                case(0): mates.setSpectrumValue(LedSpectrum2, 0, data); break;
                case(1): mates.setSpectrumValue(LedSpectrum2, 1, data); break;
                case(2): mates.setSpectrumValue(LedSpectrum2, 2, data); break;
                case(3): mates.setSpectrumValue(LedSpectrum2, 3, data); break;
                case(4): mates.setSpectrumValue(LedSpectrum2, 4, data); break;
            } break;
        case(4):
            switch(index) {
                case(0): mates.setSpectrumValue(MediaSpectrum0, 0, data); break;
                case(1): mates.setSpectrumValue(MediaSpectrum0, 1, data); break;
                case(2): mates.setSpectrumValue(MediaSpectrum0, 2, data); break;
                case(3): mates.setSpectrumValue(MediaSpectrum0, 3, data); break;
                case(4): mates.setSpectrumValue(MediaSpectrum0, 4, data); break;
                case(5): mates.setSpectrumValue(MediaSpectrum0, 5, data); break;
            } break;
        case(5):
            switch(index) {
                case(0): mates.setSpectrumValue(MediaSpectrum1, 0, data); break;
                case(1): mates.setSpectrumValue(MediaSpectrum1, 1, data); break;
                case(2): mates.setSpectrumValue(MediaSpectrum1, 2, data); break;
                case(3): mates.setSpectrumValue(MediaSpectrum1, 3, data); break;
                case(4): mates.setSpectrumValue(MediaSpectrum1, 4, data); break;
                case(5): mates.setSpectrumValue(MediaSpectrum1, 5, data); break;
            } break;
        case(6):
            switch(index) {
                case(0): mates.setWidgetValue(LedDigits5, data); break;
                case(1): mates.setWidgetValue(GaugeA0, data); break;
            } break;
        case(7):
            switch(index) {
                case(0): mates.setWidgetValue(GaugeA1, data); break;
                case(1): mates.setWidgetValue(GaugeA2, data); break;
                case(2): mates.setWidgetValue(GaugeA3, data); break;
                case(3): mates.setWidgetValue(GaugeA4, data); break;
                case(4): mates.setWidgetValue(GaugeA5, data); break;
            } break;
        case(8):
            switch(index) {
                case(0): mates.setWidgetValue(MediaGaugeB0, data); break;
            } break;
        case(9):
            switch(index) {
                case(0): mates.setWidgetValue(GaugeA6, data); break;
                case(1): mates.setWidgetValue(GaugeA7, data); break;
            } break;
        case(10):
            switch(index) {
                case(0): mates.setWidgetValue(GaugeA8, data); break;
                case(1): mates.setWidgetValue(GaugeA9, data); break;
                case(2): mates.setWidgetValue(LedDigits6, data); break;
                case(3): mates.setWidgetValue(LedDigits7, data); break;
                case(4): mates.setWidgetValue(GaugeA10, data); break;
                case(5): mates.setWidgetValue(GaugeA11, data); break;
            } break;
        case(11):
            switch(index) {
                case(0): mates.setWidgetValue(LedDigits8, data); break;
                case(1): mates.setWidgetValue(LedDigits9, data); break;
                case(2): mates.setWidgetValue(GaugeA12, data); break;
                case(3): mates.setWidgetValue(GaugeA13, data); break;
            } break;
        case(12):
            switch(index) {
                case(0): mates.setWidgetValue(MediaGaugeB1, data); break;
                case(1): mates.setWidgetValue(LedDigits10, data); break;
                case(2): mates.setWidgetValue(GaugeA14, data); break;
            } break;
        case(13):
            switch(index) {
                case(0): mates.setWidgetValue(GaugeA15, data); break;
                case(1): mates.setWidgetValue(GaugeA16, data); break;
                case(2): mates.setWidgetValue(GaugeA17, data); break;
                case(3): mates.setWidgetValue(GaugeA18, data); break;
            } break;
        case(14):
            switch(index) {
                case(0): mates.setWidgetValue(LedDigits11, data); break;
                case(1): mates.setWidgetValue(LedDigits12, data); break;
            } break;
        case(15):
            switch(index) {
                case(0): mates.setWidgetValue(LedDigits13, data); break;
                case(1): mates.setWidgetValue(LedDigits14, data); break;
                case(2): mates.setWidgetValue(LedDigits15, data); break;
            } break;
        case(16):
            switch(index) {
                case(0): mates.setWidgetValue(LedDigits16, data); break;
                case(1): mates.setWidgetValue(GaugeA19, data); break;
            } break;
        case(17):
            switch(index) {
                case(0): mates.setWidgetValue(RulerGauge0, data); break;
            } break;
        case(18):
            switch(index) {
                case(0): mates.setWidgetValue(LedDigits17, data); break;
                case(1): mates.setWidgetValue(LedDigits18, data); break;
                case(2): mates.setWidgetValue(LedDigits19, data); break;
                case(3): mates.setWidgetValue(LedDigits20, data); break;
            } break;
        case(19):
            switch(index) {
                case(0): mates.setWidgetValue(LedDigits21, data); break;
            } break;
        case(20):
            switch(index) {
                case(0): mates.setWidgetValue(LedDigits22, data); break;
                case(1): mates.setWidgetValue(LedDigits23, data); break;
                case(2): mates.setWidgetValue(LedDigits24, data); break;
            } break;
        case(21):
            switch(index) {
                case(0): mates.setWidgetValue(MediaGaugeB2, data); break;
                case(1): mates.setWidgetValue(LedDigits25, data); break;
                case(2): mates.setWidgetValue(LedDigits26, data); break;
            } break;
        case(22):
            switch(index) {
                case(0): mates.setWidgetValue(MediaGaugeB3, data); break;
                case(1): mates.setWidgetValue(LedDigits27, data); break;
            } break;
        case(23):
            switch(index) {
                case(0): mates.setWidgetValue(GaugeA20, data); break;
                case(1): mates.setWidgetValue(LedDigits28, data); break;
            } break;
        case(24):
            switch(index) {
                case(0): mates.setWidgetValue(GaugeA21, data); break;
                case(1): mates.setWidgetValue(LedDigits29, data); break;
            } break;
        case(25):
            switch(index) {
                case(0): mates.setWidgetValue(LedDigits30, data); break;
                case(1): mates.setWidgetValue(LedDigits31, data); break;
                case(2): mates.setWidgetValue(GaugeE0, data); break;
                case(3): mates.setWidgetValue(GaugeE1, data); break;
            } break;
        case(26):
            switch(index) {
                case(0): mates.setWidgetValue(MediaGaugeB4, data); break;
                case(1): mates.setWidgetValue(MediaLed0, data); break;
                case(2): mates.setWidgetValue(GaugeA22, data); break;
            } break;
        case(27):
            switch(index) {
                case(0): mates.setWidgetValue(MediaGaugeB5, data); break;
                case(1): mates.setWidgetValue(LedDigits32, data); break;
            } break;
        case(28):
            switch(index) {
                case(0): mates.setWidgetValue(MediaGaugeB6, data); break;
            } break;
        case(29):
            switch(index) {
                case(0): mates.setWidgetValue(MediaGaugeC0, data); break;
                case(1): mates.setWidgetValue(LedDigits33, data); break;
                case(2): mates.setWidgetValue(MediaGaugeC1, data); break;
                case(3): mates.setWidgetValue(LedDigits34, data); break;
            } break;
        case(30):
            switch(index) {
                case(0): mates.setWidgetValue(Scope0, data); break;
            } break;
        case(31):
            switch(index) {
                case(0): mates.setWidgetValue(GaugeA23, data); break;
                case(1): mates.setWidgetValue(LedDigits35, data); break;
                case(2): mates.setWidgetValue(GaugeA24, data); break;
                case(3): mates.setWidgetValue(GaugeA25, data); break;
                case(4): mates.setWidgetValue(LedDigits36, data); break;
                case(5): mates.setWidgetValue(LedDigits37, data); break;
            } break;
        case(32):
            switch(index) {
                case(0): mates.setWidgetValue(MediaGaugeA0, data); break;
                case(1): mates.setWidgetValue(MediaGaugeA1, data); break;
                case(2): mates.setWidgetValue(MediaGaugeA2, data); break;
                case(3): mates.setWidgetValue(LedDigits38, data); break;
                case(4): mates.setWidgetValue(LedDigits39, data); break;
                case(5): mates.setWidgetValue(LedDigits40, data); break;
            } break;
        case(33):
            switch(index) {
                case(0): mates.setWidgetValue(RulerGauge1, data); break;
            } break;
        case(34):
            switch(index) {
                case(0): mates.setWidgetValue(GaugeA26, data); break;
                case(1): mates.setWidgetValue(LedDigits41, data); break;
                case(2): mates.setWidgetValue(MediaGaugeB7, data); break;
            } break;
        case(35):
            switch(index) {
                case(0): mates.setWidgetValue(GaugeA27, data); break;
                case(1): mates.setWidgetValue(LedDigits42, data); break;
                case(2): mates.setWidgetValue(MediaGaugeB8, data); break;
            } break;
        case(36):
            switch(index) {
                case(0): mates.setWidgetValue(GaugeA28, data); break;
                case(1): mates.setWidgetValue(LedDigits43, data); break;
                case(2): mates.setWidgetValue(MediaGaugeB9, data); break;
            } break;
        case(37):
            switch(index) {
                case(0): mates.setWidgetValue(LedDigits44, data); break;
                case(1): mates.setWidgetValue(LedDigits45, data); break;
            } break;
        case(38):
            switch(index) {
                case(0): mates.setWidgetValue(MediaGaugeB10, data); break;
                case(1): mates.setWidgetValue(LedDigits46, data); break;
            } break;
        case(39):
            switch(index) {
                case(0): mates.setWidgetValue(MediaGaugeB11, data); break;
            } break;
        case(40):
            switch(index) {
                case(0): mates.setWidgetValue(MediaGaugeB12, data); break;
                case(1): mates.setWidgetValue(LedDigits47, data); break;
            } break;
        case(41):
            switch(index) {
                case(0): mates.setWidgetValue(MediaGaugeB13, data); break;
                case(1): mates.setWidgetValue(MediaGaugeB14, data); break;
            } break;
        case(42):
            switch(index) {
                case(0): mates.setWidgetValue(MediaGaugeB15, data); break;
                case(1): mates.setWidgetValue(MediaGaugeB16, data); break;
            } break;
        case(43):
            switch(index) {
                case(0): mates.setWidgetValue(MediaGaugeD0, data); break;
                case(1): mates.setWidgetValue(MediaGaugeD1, data); break;
            } break;
        case(44):
            switch(index) {
                case(0): mates.setWidgetValue(MediaGaugeB17, data); break;
            } break;
        case(45):
            switch(index) {
                case(0): mates.setWidgetValue(MediaGaugeB18, data); break;
                case(1): mates.setWidgetValue(MediaGaugeB19, data); break;
                case(2): mates.setWidgetValue(GaugeA29, data); break;
                case(3): mates.setWidgetValue(GaugeA30, data); break;
            } break;
        case(46):
            switch(index) {
                case(0): mates.setWidgetValue(MediaGaugeB20, data); break;
                case(1): mates.setWidgetValue(MediaGaugeB21, data); break;
                case(2): mates.setWidgetValue(LedDigits48, data); break;
                case(3): mates.setWidgetValue(LedDigits49, data); break;
            } break;
        case(47):
            switch(index) {
                case(0): mates.setWidgetValue(MediaGaugeB22, data); break;
                case(1): mates.setWidgetValue(LedDigits50, data); break;
            } break;
        case(48):
            switch(index) {
                case(0): mates.setWidgetValue(LedDigits51, data); break;
            } break;
        case(49):
            switch(index) {
                case(0): mates.setWidgetValue(LedDigits52, data); break;
                case(1): mates.setWidgetValue(LedDigits53, data); break;
                case(2): mates.setWidgetValue(LedDigits54, data); break;
            } break;
        case(50):
            switch(index) {
                case(0): mates.setWidgetValue(MediaGaugeB23, data); break;
                case(1): mates.setWidgetValue(MediaGaugeB24, data); break;
            } break;
        case(51):
            switch(index) {
                case(0): mates.setWidgetValue(MediaGaugeB25, data); break;
                case(1): mates.setWidgetValue(MediaGaugeB26, data); break;
            } break;
        case(52):
            switch(index) {
                case(0): mates.setWidgetValue(MediaGaugeB27, data); break;
                case(1): mates.setWidgetValue(LedDigits55, data); break;
                case(2): mates.setWidgetValue(GaugeA31, data); break;
            } break;
        case(53):
            switch(index) {
                case(0): mates.setWidgetValue(MediaGaugeB28, data); break;
                case(1): mates.setWidgetValue(MediaGaugeB29, data); break;
            } break;
        case(54):
            switch(index) {
                case(0): mates.setWidgetValue(MediaGaugeB30, data); break;
                case(1): mates.setWidgetValue(GaugeA32, data); break;
                case(2): mates.setWidgetValue(LedDigits56, data); break;
                case(3): mates.setWidgetValue(MediaLed1, data); break;
            } break;
        case(55):
            switch(index) {
                case(0): mates.setWidgetValue(LedDigits57, data); break;
                case(1): mates.setWidgetValue(LedDigits58, data); break;
                case(2): mates.setWidgetValue(LedDigits59, data); break;
            } break;
        case(56):
            switch(index) {
                case(0): mates.setWidgetValue(MediaGaugeB31, data); break;
                case(1): mates.setWidgetValue(LedDigits60, data); break;
            } break;
        case(57):
            switch(index) {
                case(0): mates.setWidgetValue(MediaLed2, data); break;
                case(1): mates.setWidgetValue(MediaLed3, data); break;
                case(2): mates.setWidgetValue(MediaLed4, data); break;
                case(3): mates.setWidgetValue(MediaLed5, data); break;
                case(4): mates.setWidgetValue(MediaLed6, data); break;
                case(5): mates.setWidgetValue(MediaLed7, data); break;
                case(6): mates.setWidgetValue(MediaLed8, data); break;
                case(7): mates.setWidgetValue(MediaLed9, data); break;
                case(8): mates.setSpectrumValue(LedSpectrum3, 0, data); break;
                case(9): mates.setSpectrumValue(LedSpectrum3, 1, data); break;
                case(10): mates.setSpectrumValue(LedSpectrum3, 2, data); break;
                case(11): mates.setSpectrumValue(LedSpectrum3, 3, data); break;
                case(12): mates.setSpectrumValue(LedSpectrum3, 4, data); break;
                case(13): mates.setSpectrumValue(LedSpectrum3, 5, data); break;
            } break;
        case(58):
            switch(index) {
                case(0): mates.setWidgetValue(MediaGaugeD2, data); break;
                case(1): mates.setWidgetValue(MediaLed10, data); break;
                case(2): mates.setWidgetValue(MediaLed11, data); break;
                case(3): mates.setWidgetValue(MediaLed12, data); break;
                case(4): mates.setWidgetValue(MediaLed13, data); break;
            } break;
        case(59):
            switch(index) {
                case(0): mates.setWidgetValue(MediaGaugeB32, data); break;
            } break;
        case(60):
            switch(index) {
                case(0): mates.setWidgetValue(MediaGaugeB33, data); break;
            } break;
        case(61):
            switch(index) {
                case(0): mates.setWidgetValue(MediaGaugeB34, data); break;
            } break;
        case(62):
            switch(index) {
                case(0): mates.setWidgetValue(LedDigits61, data); break;
                case(1): mates.setWidgetValue(RulerGauge2, data); break;
            } break;
        case(63):
            switch(index) {
                case(0): mates.setWidgetValue(LedDigits62, data); break;
                case(1): mates.setWidgetValue(RulerGauge3, data); break;
                case(2): mates.setWidgetValue(RulerGauge4, data); break;
            } break;
        case(70):
            switch(index) {
                case(0): mates.setWidgetValue(MediaLed14, data); break;
                case(1): mates.setWidgetValue(MediaLed15, data); break;
                case(2): mates.setWidgetValue(MediaLed16, data); break;
                case(3): mates.setWidgetValue(MediaLed17, data); break;
                case(4): mates.setWidgetValue(MediaLed18, data); break;
                case(5): mates.setWidgetValue(MediaLed19, data); break;
                case(6): mates.setWidgetValue(MediaLed20, data); break;
                case(7): mates.setWidgetValue(MediaLed21, data); break;
            } break;
        case(71):
            switch(index) {
                case(0): mates.setWidgetValue(MediaColorLed0, data); break;
                case(1): mates.setWidgetValue(LedDigits63, data); break;
                case(2): mates.setWidgetValue(LedDigits64, data); break;
                case(3): mates.setWidgetValue(LedDigits65, data); break;
                case(4): mates.setWidgetValue(GaugeA33, data); break;
                case(5): mates.setWidgetValue(GaugeA34, data); break;
                case(6): mates.setWidgetValue(GaugeA35, data); break;
            } break;
        case(72):
            switch(index) {
                case(0): mates.setWidgetValue(LedDigits66, data); break;
                case(1): mates.setWidgetValue(LedDigits67, data); break;
            } break;
    }
}

//Use this command to set data to any widget on the DIYsplay screen.
//The 'index' parameter determines which widget to set, starting at 0.
void DIYsplay::setData(int index, String data) {
    // This is auto-generated mapping code that ensures each MATES widget is
    // mapped to a data index. This prevents the user having to remember the
    // individual indexes for each widget.
    // 
    // This code should not be modified or unpredictable behaviour may result.
    switch(currentScreen) {
        case(15):
            switch(index) {
                case(3): mates.updateTextArea(0, data); break;
            } break;
        case(29):
            switch(index) {
                case(4): mates.updateTextArea(1, data); break;
                case(5): mates.updateTextArea(2, data); break;
            } break;
        case(57):
            switch(index) {
                case(14): mates.updateTextArea(3, data); break;
            } break;
        case(59):
            switch(index) {
                case(1): mates.updateTextArea(4, data); break;
                case(2): mates.updateTextArea(5, data); break;
                case(3): mates.updateTextArea(6, data); break;
            } break;
        case(61):
            switch(index) {
                case(1): mates.updateTextArea(7, data); break;
                case(2): mates.updateTextArea(8, data); break;
            } break;
        case(64):
            switch(index) {
                case(0): mates.updateTextArea(9, data); break;
                case(1): mates.updateTextArea(10, data); break;
                case(2): mates.updateTextArea(11, data); break;
            } break;
        case(65):
            switch(index) {
                case(0): mates.updateTextArea(12, data); break;
                case(1): mates.updateTextArea(13, data); break;
                case(2): mates.updateTextArea(14, data); break;
            } break;
        case(67):
            switch(index) {
                case(0): mates.updateTextArea(15, data); break;
                case(1): mates.updateTextArea(16, data); break;
                case(2): mates.updateTextArea(17, data); break;
                case(3): mates.updateTextArea(18, data); break;
                case(4): mates.updateTextArea(19, data); break;
                case(5): mates.updateTextArea(20, data); break;
            } break;
        case(68):
            switch(index) {
                case(0): mates.updateTextArea(21, data); break;
                case(1): mates.updateTextArea(22, data); break;
                case(2): mates.updateTextArea(23, data); break;
                case(3): mates.updateTextArea(24, data); break;
                case(4): mates.updateTextArea(25, data); break;
                case(5): mates.updateTextArea(26, data); break;
            } break;
    }
}

// Prints automatically wrapped and formatted text onto a PrintArea.
// Note that this will NOT work with TextArea screens. Please use the setData()
// command instead.
void DIYsplay::printText(String text) {
    switch(currentScreen) {
        case(66): mates.appendToPrintArea(0,text); break; 
        case(69): mates.appendToPrintArea(1,text); break; 
    }
}

// Clears the text of a PrintArea to revert it back to a black screen.
// Note that this will NOT work with TextArea screens. Please use the setData()
// command instead.
void DIYsplay::clearText() {
    switch(currentScreen) {
        case(66): mates.clearPrintArea(0); break; 
        case(69): mates.clearPrintArea(1); break; 
    }
}

