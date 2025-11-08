#include <Arduino.h>
#include "qrencode.h"
#include "qrcodeeink.h"

#ifdef USE_GXEPD2
QRcodeEink::QRcodeEink(GxEPD2_GFX *display) {
    this->display = display;
}
#else
QRcodeEink::QRcodeEink(GxGDE0213B72B *display) {
    this->display = display;
}
#endif

void QRcodeEink::init() {
#ifdef USE_GXEPD2
    display->init();
    this->screenwidth = display->width();
    this->screenheight = display->height();
    display->fillScreen(GxEPD_WHITE);
#else
    display->init();
    this->screenwidth = display->width();
    this->screenheight = display->height();
    display->eraseDisplay();
#endif
    int min = screenwidth;
    if (screenheight<screenwidth)
        min = screenheight;
    multiply = min/WD;
    offsetsX = (screenwidth-(WD*multiply))/2;
    offsetsY = (screenheight-(WD*multiply))/2;
}

void QRcodeEink::screenwhite() {
    display->fillScreen(GxEPD_WHITE);
}

void QRcodeEink::screenupdate() {
#ifdef USE_GXEPD2
    display->display();
#else
    display->update();
#endif
}

void QRcodeEink::drawPixel(int x, int y, int color) {
    if(color==1) {
        color = GxEPD_BLACK;
    } else {
        color = GxEPD_WHITE;
    }
    display->fillRect(x,y,multiply,multiply,color);
}