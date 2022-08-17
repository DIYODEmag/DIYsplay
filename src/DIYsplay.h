/*
 * DIYsplay.h
 * Author: Liam Davies (l.davies@diyodemag.com)
 * Copyright (c) 2022 DIYODE Magazine
 */

#ifndef _DIYSPLAY_H_
#define _DIYSPLAY_H_


//Ensure includes directory is okay
#include "MatesController.h"
#include "SoftwareSerial.h"

#define DEFAULT_SIG_PIN 3
#define DEFAULT_RESET_PIN 4

//Please UNCOMMENT this line if you wish to use AltSoftSerial.
//#include "AltSoftSerial.h"

//This is an enumerated list that corresponds with the gauges programmed onto the DIYsplay.
//The end-user enters the Enum directory which is implicitly casted to an Page number
//corresponding with the correct Page on the display unit.
//
//The only downside of this method is that the order is completely arbitrary and does not
//hold up to inserting displays in the middle of the array.

typedef enum {
    DIYSPLAY_LOGO,
    _5_GAUGE_EQ,
    BAR_METER_LEDDIGITS,
    LCD_BAR_METER,
    MEDIA_SPECTRUM_L_TO_R,
    MEDIA_SPECTRUM,
    METAL_BAR_METER_SINGLE,
    METAL_BAR_METER_SINGLE_2,
    SOUND_LEVEL_METER,
    DB_METER_LEFT_AND_RIGHT_BLUE,
    DB_METER_LEFT_AND_RIGHT_DUAL,
    DB_METER_LEFT_AND_RIGHT,
    DB_METER_SINGLE_LED_BAR,
    DB_METER_AVG_AND_PEAK_LR,
    DIGITAL_CLOCK_LARGE,
    DIGITAL_CLOCK,
    LIDAR_DISTANCE_METER,
    RULER_GAUGE_SCALE,
    _2_DECIMAL_POINT_LEDDIGITS_X4_RED,
    _2_DECIMAL_POINT_LEDDIGITS_LARGE,
    _2_DIGIT_LEDDIGITS_X3_RED,
    AMMETER_A,
    AMMETER_BLACK,
    BATTERY_LEVEL_GAUGE_BLUE,
    BATTERY_LEVEL_GAUGE,
    DUAL_GAUGE_LEDDIGITS,
    METER_LED_GAUGE,
    VOLTMETER_BLACK,
    CIRCULAR_CROPPED_TO_HALF_MOON_LARGE_TEXT_COLD_HOT,
    TEMPERATURE_HUMIDITY_WITH_TEXT_AREAS,
    FULL_SCOPE,
    GAUGE_LEDDIGITS_X3,
    RGB_GAUGES,
    RULER_GAUGE_WITH_SCALE,
    VARIOUS_GAUGES_BLUE,
    VARIOUS_GAUGES_GREEN,
    VARIOUS_GAUGES_RED,
    _8DIGIT_LEDDIGITS_X2,
    CIRCULAR_CROPPED_TO_HALF_MOON_LARGE_TEXT_LEDDIGITS_RIGHT,
    CIRCULAR_CROPPED_TO_HALF_MOON_LARGE_TEXT,
    CIRCULAR_CROPPED_TO_HALF_MOON_SMALL_TEXT_LEDDIGITS,
    CROPPED_DUAL_0_TO100,
    CROPPED_DUAL_LOW_TO_HIGH,
    DUAL_LED_BAR_GAUGE,
    HALF_MOON_BEZEL_TOP,
    HALF_MOON_DUAL_GAUGES,
    HALF_MOON_DUAL_LEDDIGITS,
    HALF_MOON_LED_LEFT,
    LARGE_LEDDIGITS_RED,
    LEDDIGITS_X3,
    QUARTER_MOON_DUAL_BEZELS_TOP,
    QUARTER_MOON_DUAL_ORANGE,
    QUARTER_MOON_LEDDIGITS_GAUGE_ORANGE,
    QUARTER_MOON_ROUNDED_DUAL,
    QUARTER_MOON_SINGLE_ORANGE_LEDDIGITS_GAUGE_MULTIPANEL,
    VARIOUS_DIGITS,
    ANGLE_DISPLAY,
    MEDIA_PLAYER_RED,
    MULTIMEDIA_INDICATOR_GREEN_GRADIENT,
    ALTIMETER,
    COMPASS_SIMPLE,
    COMPASS_WITH_LONGITUDE_LATITUDE,
    RULER_GAUGE_TAPE_COMPASS,
    SCALE_TAPE_COMPASS,
    _3_X_COLOURED_TEXT_LINES,
    _3_X_PLAIN_TEXT_LINES,
    _3LINE_BLACK_BG_PRINT_AREA,
    _6_X_COLOURED_TEXT_LINES,
    _6_X_PLAIN_TEXT_LINES,
    _6LINE_BLACK_BG_PRINT_AREA,
    _8_X_FLAT_ROUND_LED,
    COLOUR_LED_WITH_GAUGES,
    WAVE_STAT_DISPLAY,
} Screen;



class DIYsplay {
    public:
        DIYsplay();

        //Simple constructor. Assumes we're using the regular hardware serial on the
        //standard pin layout.
        void begin();
        
        //More advanced constructors with additional configurations if needed.
        void begin(HardwareSerial &serial,
             uint8_t sigPin = DEFAULT_SIG_PIN,
             uint8_t resetPin = DEFAULT_RESET_PIN);

        //Only allow this constructor to be used if Software Serial is defined.
        #ifdef SoftwareSerial_h
        void begin(SoftwareSerial &serial, 
             uint8_t sigPin = DEFAULT_SIG_PIN,
             uint8_t resetPin = DEFAULT_RESET_PIN);
        #endif

        //Only allow this constructor to be used if AltSoftSerial is defined.
        //  Note that because it is NOT included by default in the Arduino IDE,
        //  you must install it from the Library Manager and uncomment the define
        //  line at the top of this file.
        #ifdef AltSoftSerial_h
        void begin(AltSoftSerial &serial, 
             uint8_t sigPin = DEFAULT_SIG_PIN, 
             uint8_t resetPin = DEFAULT_RESET_PIN);
        #endif
        
        
        void setScreen(int);

        // We're re-initializing this instance when the DIYsplay::begin() method
        // is called because Mates doesn't have a default constructor.
        // We set the correct parameters there.
        MatesController mates = MatesController(Serial);
        int currentScreen;

        void setData(int, int);
        void setData(int, String);

        void printText(String);
        void clearText();

        uint8_t getNumWidgets(Screen);
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

    private:

        //Initializes interface with MatesController
        void init();


        uint8_t sigPin;
        uint8_t resetPin;
};
#endif
