#include <iostream>
#include "variables.h"

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
        if (orientationText)
            free((void *)orientationText);
        orientationText = strdup(_text);
        if (originalText)
            free((void *)originalText);

        orientationText = strdup(_text);
        originalText = (char *)malloc(strlen(_text) + 2);

        strcpy(originalText, _text);
        strcat(originalText, ":");

        textChange = true;
    }
}