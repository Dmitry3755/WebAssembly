#include "variables.h"
#include <iostream>

extern "C"
{
    void getOrientation(char *_orientation)
    {
        if (orientation)
            free((void *)orientation);
        orientation = strdup(_orientation);
    }
}

extern "C"
{
    void getText(char *_text)
    {
        if (text)
            free((void *)text);
        text = strdup(_text);
        textChange = true;
    }
}