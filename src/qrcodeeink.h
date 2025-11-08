#ifndef ESPQRCODEEINK_H
#define ESPQRCODEEINK_H

/* ESP_QRcode. e-ink version
 * Import this .h when using some e-ink display
 */

#define EINKDISPLAY

#include <qrcodedisplay.h>
#include <Adafruit_GFX.h>

// Support for both GxEPD and GxEPD2 libraries
#ifdef USE_GXEPD2
    #include <GxEPD2_BW.h>
    #include <GxEPD2_3C.h>
#else
    #include <GxEPD.h>
    #include <GxGDE0213B72B/GxGDE0213B72B.h>
#endif

#ifndef EINK_MODEL
#define EINK_MODEL 128
#endif

class QRcodeEink : public QRcodeDisplay
{
	private:
#ifdef USE_GXEPD2
		GxEPD2_GFX *display;
#else
		GxGDE0213B72B *display;
#endif
        void drawPixel(int x, int y, int color);
	public:
#ifdef USE_GXEPD2
		QRcodeEink(GxEPD2_GFX *display);
#else
		QRcodeEink(GxGDE0213B72B *display);
#endif
		void init();
		void screenwhite();
		void screenupdate();
};
#endif