# DIYsplay
DIYsplay is a simple LCD screen module that makes it easy to display information on over 70 different screens.

## Basic Usage
DIYsplay has been built to make displaying your information of choise as simple as possible. To build a clock that shows 04:30, for example, the following code is all that is needed.

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