#ifndef OPTIONS_H
#define OPTIONS_H

#define LED2_INDEX_COLOR_RAINBOW_INIT	0x1F
#define LED2_INDEX_COLOR_RAINBOW	0x10
#define LED2_INDEX_COLOR_SET1		0x11
#define LED2_INDEX_COLOR_SET2		0x12
#define LED2_INDEX_COLOR_SET3		0x13
#define LED2_INDEX_MODE				0x20
#define LED2_INDEX_MODE_KEY			0x21
#define LED2_INDEX_MODE_KEY_TYPE	0x22
#define LED2_INDEX_MODE_FADE_TYPE	0x23
#define LED2_INDEX_LED_NUM			0x30
#define LED2_INDEX_LED_BRIGHTNESS	0x40
#define LED2_INDEX_COLOR_KEY_SET	0xA0
#define LED2_INDEX_COLOR_KEY_SET1	0xA1
#define LED2_INDEX_LED_ENABLED		0xE0
#define LED2_INDEX_LED_SAVE         0xF0
#define LED2_INDEX_FULL_LED_MODE    0x80
#define LED2_INDEX_FULL_LED_BRIGHTNESS 0x81
#define LED2_INDEX_ESC_TO_TILDE     0x82
#define LED2_INDEX_FN_LED           0x83
#define LED2_INDEX_TRANSITION_DELAY 0x84

#define LED2_GET_REPORT_LENGTH_RAINBOW			133	//0x85
#define LED2_GET_REPORT_LENGTH_INFO				100
#define LED2_GET_REPORT_LENGTH_KEYMAP			120
#define LED2_GET_REPORT_LENGTH_KEYMAP_LAYER1	121
#define LED2_GET_REPORT_LENGTH_KEYMAP_LAYER2	122
#define LED2_GET_REPORT_LENGTH_KEYMAP_LAYER3	123
#define LED2_GET_REPORT_LENGTH_KEYMAP_LAYER4	124

enum{
	LED2_GET_REPORT_LENGTH_MACRO1 = 168,
	LED2_GET_REPORT_LENGTH_MACRO2,
	LED2_GET_REPORT_LENGTH_MACRO3,
	LED2_GET_REPORT_LENGTH_MACRO4,
	LED2_GET_REPORT_LENGTH_MACRO5,
	LED2_GET_REPORT_LENGTH_MACRO6,
	LED2_GET_REPORT_LENGTH_MACRO7,
	LED2_GET_REPORT_LENGTH_MACRO8,
	LED2_GET_REPORT_LENGTH_MACRO9,
	LED2_GET_REPORT_LENGTH_MACRO10,
	LED2_GET_REPORT_LENGTH_MACRO11,
	LED2_GET_REPORT_LENGTH_MACRO12	//179
};

#define OPTION_INDEX_BOOTLOADER		0x00
#define OPTION_INDEX_BOOTMAPPER		0x01
#define OPTION_INDEX_READY			0x90
#define OPTION_INDEX_ACTION			0x91

#define OPTION_VALUE_BOOTMAPPER_START		0x01
#define OPTION_VALUE_BOOTMAPPER_STOP		0x00

/*
 *  Structure of the LED array
 */
//struct cRGB { uint8_t g; uint8_t r; uint8_t b; };
typedef struct {
	uint8_t g;
	uint8_t r;
	uint8_t b;
} cRGB_t;

typedef struct {
	// num 1byte, mode 1byte, brightness 1byte, color1 3byte, color2 3byte, color3 3byte, rainbow colors 21byte, keymode 1byte, key color1 3byte
    // fade type 1byte,

    // Ver1.1
    //skipFrame 1byte, full led mode 1byte, full led brightness 1byte, esc to tilde 1byte, fn led 1byte

	 uint8_t num;
	 uint8_t mode;
	 uint8_t brightness;
	 cRGB_t color1;
	 cRGB_t color2;
	 cRGB_t color3;
	 cRGB_t rainbow[7];
	 uint8_t keymode;
	 cRGB_t colorkey1;
     uint8_t fadetype;

     //Ver1.1
     uint8_t transitiondelay;

     uint8_t fullledmode;
     uint8_t fullledbrightness;

     uint8_t esctotilde;
     uint8_t fnled;

} led2_info_t;

void setOptions(uint8_t *data);
void getOptions(led2_info_t *buffer);

void stopPwmForUsbReport(bool xIsStop);

#endif
