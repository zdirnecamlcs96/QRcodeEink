# QRcodeEink

Subclass that you can use jointly with https://github.com/yoprogramo/QRcodeDisplay to generate QRcodes in EINK displays like Lilygo TTGO T5

This library supports both GxEPD (classic) and GxEPD2 (newer) libraries.

To use it:

## Using GxEPD (Classic)

### In platform.io 

Add as dependencies:

 * yoprogramo/QRcodeDisplay
 * yoprogramo/QRcodeEink
 * adafruit/Adafruit GFX Library@1.7.5
 * https://github.com/lewisxhe/GxEPD

### In arduino ide 

Open Library Manager (menu Sketch > Include Library > Manage Libraries…) then install the following libraries:

 ** QRcodeDisplay
 ** QRcodeOled
 ** Adafruit GFX Library@1.7.5
 ** https://github.com/lewisxhe/GxEPD

 
Creating a QRcode with GxEPD is just as simple as:

 ```
#define ELINK_SS 5
#define ELINK_BUSY 4
#define ELINK_RESET 16
#define ELINK_DC 17

#include <GxEPD.h>
#include <GxIO/GxIO_SPI/GxIO_SPI.h>
#include <GxIO/GxIO.h>
#include <qrcodeeink.h>

GxIO_Class io(SPI, ELINK_SS, ELINK_DC, ELINK_RESET);
GxEPD_Class display(io, ELINK_RESET, ELINK_BUSY);

QRcodeEink qrcode (&display);

void setup() {

    qrcode.init();
    qrcode.create("Hello world.");

}

 ```

## Using GxEPD2 (Newer)

### In platform.io 

Add as dependencies:

 * yoprogramo/QRcodeDisplay
 * yoprogramo/QRcodeEink
 * adafruit/Adafruit GFX Library
 * zinggjm/GxEPD2

Add `-D USE_GXEPD2` to your build flags in `platformio.ini`:

```ini
build_flags = -D USE_GXEPD2
```

### In arduino ide 

Open Library Manager (menu Sketch > Include Library > Manage Libraries…) then install the following libraries:

 ** QRcodeDisplay
 ** QRcodeEink
 ** Adafruit GFX Library
 ** GxEPD2

Then define `USE_GXEPD2` before including the library in your sketch.

 
Creating a QRcode with GxEPD2:

 ```
// Define USE_GXEPD2 before including qrcodeeink.h
#define USE_GXEPD2

#define ELINK_SS 5
#define ELINK_BUSY 4
#define ELINK_RESET 16
#define ELINK_DC 17

#include <GxEPD2_BW.h>
#include <GxEPD2_3C.h>
#include <qrcodeeink.h>

// Example: Using GxEPD2_213_B72 for 2.13" b/w display
// Replace with your actual display model
GxEPD2_213_B72 display(/*CS=*/ ELINK_SS, /*DC=*/ ELINK_DC, /*RST=*/ ELINK_RESET, /*BUSY=*/ ELINK_BUSY);

QRcodeEink qrcode (&display);

void setup() {

    qrcode.init();
    qrcode.create("Hello world with GxEPD2.");

}

 ```

 For other displays, please refer the main repository: https://github.com/yoprogramo/QRcodeDisplay
