// Example using GxEPD2 library
// Define USE_GXEPD2 before including qrcodeeink.h to use GxEPD2
#define USE_GXEPD2

// Pin definitions for e-ink display
#define ELINK_SS 5
#define ELINK_BUSY 4
#define ELINK_RESET 16
#define ELINK_DC 17

#include <GxEPD2_BW.h>
#include <GxEPD2_3C.h>
#include "qrcodeeink.h"

// Example: Using GxEPD2_213_B72 for 2.13" b/w display
// Replace with your actual display model
GxEPD2_213_B72 display(/*CS=*/ ELINK_SS, /*DC=*/ ELINK_DC, /*RST=*/ ELINK_RESET, /*BUSY=*/ ELINK_BUSY);

QRcodeEink qrcode (&display);


void setup() {

    Serial.begin(115200);
    Serial.println("");
    Serial.println("Starting with GxEPD2...");

    // enable debug qrcode
    // qrcode.debug();

    // Initialize QRcode display using library
    qrcode.init();
    // create qrcode
    qrcode.create("Hello world with GxEPD2.");

}

void loop() { }
