![DIYsplay Logo](./DIYsplay_Logo_White.png#gh-dark-mode-only)
![DIYsplay Logo](./DIYsplay_Logo.png#gh-light-mode-only)

# DIYsplay
DIYsplay is a simple LCD screen module that makes it easy to display information on over 70 different screens.

## Getting Started
You'll first need to connect the DIYsplay to your Arduino board, which needs four data pins and two power pins. For a basic connection, we recommend these pins:

|               | Arduino Pin |   | DIYsplay Pin |
|---------------|-------------|---|--------------|
| **5V Power**  | 5V          | → | 5V           |
| **Ground**    | GND         | → | G            |
| **RX Line**   | RX (Pin 0)  | → | SW           |
| **TX Line**   | TX (Pin 1)  | → | RX           |
| **Sig Pin**   | D3 (Pin 3)  | → | SIG          |
| **Reset Pin** | D4 (Pin 4)  | → | RES          |

If you've made sure everything is in the right spot, feel free to turn on your Arduino and ensure that the DIYsplay logo appears on the DIYsplay. Great, let's write some code!

## Basic Usage
DIYsplay has been built to make displaying your information of choice as simple as possible. For example, to build a digital clock that shows 04:30, the following code is all that is needed.

```
#include "DIYsplay.h"

DIYsplay diysplay = DIYsplay();

void setup() {
    diysplay.begin();
    diysplay.setScreen(DIGITAL_CLOCK);
    diysplay.setData(0,4);
    diysplay.setData(1,30);
}
```

The DIYsplay library is a wrapper for the MatesController library, which handles the underlying serial commands. This means that DIYsplay needs the "MatesController" library as a dependency.

## Serial Communication
The most popular Arduino-compatible boards (the Uno and the Nano), along with many others, have one primary hardware Serial line, of which messages can be printed to it with ```Serial.println("Hello world!");``` On the Arduino Uno, this is on Pin 0 (RX) and Pin 1 (TX).

The DIYsplay library, by default, uses this hardware serial line to talk to the DIYsplay. This works absolutely fine, however bear in mind that any serial commands received or sent on that line will be shared with the DIYsplay. You may see some weird characters in the Serial console when a DIYsplay function is called. You may also inadvertently send a valid command to the DIYsplay, causing unexpected behaviour.

*Bottom Line: If you're planning to use the hardware Serial line for anything important, you should use the DIYsplay on a different line.* You can do this if your board has additional HardwareSerial lines like on the Arduino Mega, or use a library like ```AltSoftSerial.h``` or ```SoftwareSerial.h``` as described [below](#custom-pinouts).


## Advanced Usage

### Custom Pinouts
DIYsplay supports customizing all pins used for the hardware interface. We have included multiple constructors for default pinouts, or changing them to a custom configuration. Note that we have not tested using every pin on every Arduino-compatible board, so we cannot guarantee full compatibility with all setups.

#### Hardware Serial
The standard function that is called by default, even if no arguments are passed in (via another overload with no parameters). It assumes you are using Pin 0 and Pin 1 for the hardware Serial configuration.
```
void begin(HardwareSerial serial, uint8_t sigPin = 3, uint8_t resetPin = 4);
```

#### Software Serial
Software Serial is much the same deal, just pass in an instance from your main code.
```
void begin(SoftwareSerial serial, uint8_t sigPin = 3, uint8_t resetPin = 4);
```

#### AltSoftSerial
DIYsplay is fully compatible with the AltSoftSerial library, which if you have multiple Serial lines could make life easier. If you're interested in doing this, you probably already know what you're doing. You'll just need to do the following:

1. Download **AltSoftSerial** from the Arduino Library Manager (or whatever library manager you are using).
2. Open the **DIYsplay.h** header file in the library and **uncomment** this #include line:
```
//Please UNCOMMENT this line if you wish to use AltSoftSerial.
//#include "AltSoftSerial.h"
```
After that, everything should be good to go! Just call the begin() method as usual.
```
void begin(AltSoftSerial serial, uint8_t sigPin = 3, uint8_t resetPin = 4);
```
### Custom Display Firmware
If you want to take DIYsplay one step further, you can program your own firmware onto it. This allows you to choose exactly what screens you want onto it, and even make your own. We did it ourselves to make the pre-loaded DIYsplay firmware that comes with every DIYsplay.

**Please note that once you have programmed your own firmware onto the DIYsplay, the setScreen() and setData() functions may not function as expected.** These functions operate on specific bindings that will break once the order or selection of screens have changed. It's nothing permanent - you can just re-program our default firmware in any case and go back to factory configuration.

### Contributing
This code isn't perfect. There are plenty of bugfixes and optimisations that could be made in this library. If you'd like to contribute, feel free to fork this library and create a pull request with your changes.