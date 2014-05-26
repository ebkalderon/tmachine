#ifndef CORE_HPP
#define CORE_HPP

#include <iostream>
#include <string>

typedef int Year;

static struct AnsiColors
{
    char normal[5] = { 0x1b, '[', '0', 'm', 0 };
    char bold[5] = { 0x1b, '[', '1', 'm', 0 };
    char italic[5] = { 0x1b, '[', '3', 'm', 0 };
    char unbold[6] = { 0x1b, '[', '2', '1', 'm', 0 };
    char unitalic[6] = { 0x1b, '[', '2', '3', 'm', 0 };
    char lightBlack[8] = { 0x1b, '[', '1', ';', '3', '0', 'm', 0 };
    char lightBlue[8] = { 0x1b, '[', '1', ';', '3', '4', 'm', 0 };
    char lightGreen[8] = { 0x1b, '[', '1', ';', '3', '2', 'm', 0 };
    char lightMagenta[8] = { 0x1b, '[', '1', ';', '3', '5', 'm', 0 };
    char lightRed[8] = { 0x1b, '[', '1', ';', '3', '1', 'm', 0 };
    char lightYellow[8] = { 0x1b, '[', '1', ';', '3', '3', 'm', 0 };
    char black[8] = { 0x1b, '[', '0', ';', '3', '0', 'm', 0 };
    char blue[8] = { 0x1b, '[', '0', ';', '3', '4', 'm', 0 };
    char green[8] = { 0x1b, '[', '0', ';', '3', '2', 'm', 0 };
    char magenta[8] = { 0x1b, '[', '0', ';', '3', '5', 'm', 0 };
    char red[8] = { 0x1b, '[', '0', ';', '3', '1', 'm', 0 };
    char yellow[8] = { 0x1b, '[', '0', ';', '3', '3', 'm', 0 };
} AnsiColors;

#endif // CORE_HPP
