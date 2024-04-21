#include "global.h"

void drawButton(uint8_t x, uint8_t y, char *text, bool selected)
{
    // Need to Test: display.drawButtonUTF8(x, y, selected ? U8G2_BTN_BW1 | U8G2_BTN_INV : U8G2_BTN_BW1, 0, 2, 2, text);
    if (selected)
    {
        display.drawButtonUTF8(x, y, U8G2_BTN_BW1 | U8G2_BTN_INV, 0, 2, 2, text);
    }
    else
    {
        display.drawButtonUTF8(x, y, U8G2_BTN_BW1, 0, 2, 2, text);
    }
}