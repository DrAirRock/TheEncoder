#pragma once

// DISTRIBUTION 1.2.2
// LAST RELEASE 6/6/2014
// LAST EDITED 6/6/2014

// This is released under the Free Software definition with all freedoms ensured. I ask to keep my name on it. Enjoy
// Created by Don Virginia
// Member functions:
        // curs(on, 15) or curs(off)    turns the console cursor on or off. Number changes size, and is optional.
        // color(foreground, background, text)  prints the text in the colors, background optional, which defaults to black
        // color(foreground, background) sets the colors to the parameters. Typing reset changes to (black, white)
        // cent(text)   centers the text on the screen.
        // cls()                double void function that clears the screen.
        // randomInt(short,short) and randomDouble(short,short) return a value in between its parameters.
        // wait(long) waits long amount of time in milliseconds before program continues.

//https://docs.google.com/file/d/0B-veyAcclrE8b3h3b3RURkpZNm8/edit?pli=1

#include <windows.h>
#include <iostream>
#include <string>
#include <random>
#include <time.h>
#define CWIDTH 80

enum state_t{on,off};
std::mt19937 mt(time(0));
enum spectrum: WORD {black = 0,
blue,
green,
aqua,
red,
purple,                 // 5
yellow,
white,
gray,
lightblue,
lightgreen,     // 10
lightaqua,
lightred,
lightpurple,
lightyellow,
brightwhite,  // 15
reset};



class Cursor
{
        HANDLE console;
        CONSOLE_CURSOR_INFO lpCursor;
public:
        Cursor          ();
        void    on      ();
        void    on      (DWORD size);
        void    off     ();
};
Cursor::Cursor()
{
        console = GetStdHandle(STD_OUTPUT_HANDLE);
};
void Cursor::on()
{
        lpCursor.bVisible = true;
        lpCursor.dwSize = 10;
        SetConsoleCursorInfo(console,&lpCursor);
};
void Cursor::on(DWORD size)
{
        size = 20 - size;
        lpCursor.bVisible = true;
        lpCursor.dwSize = size;
        SetConsoleCursorInfo(console,&lpCursor);
};
void Cursor::off()
{
        lpCursor.bVisible = false;
        lpCursor.dwSize = 20;
        SetConsoleCursorInfo(console,&lpCursor);
};

void curs(state_t y)
        {
                Cursor *p = new Cursor;
                if (y == on)
                        p->on();
                else if (y == off)
                        p->off();
                else
                        std::cerr<<"\nERROR: FUNCTION DATA RANGE INVALID.";
                delete p;
        }
void curs(state_t y, DWORD size)
{
        Cursor *p = new Cursor;
        if (y == on)
                p->on(size);
        else if (y == off)
                p->off();
        else
                std::cerr<<"\nERROR: FUNCTION DATA RANGE INVALID.";
        delete p;
}



void cent(std::string input)
{
        int * sLength           = new int;
        int * spaces            = new int;
        int * dum                       = new int;
        *sLength = input.length();
        if (*sLength % 2 == 1)
                *sLength = *sLength + 1;
        *spaces = 40 - *sLength/2;
        *dum = *spaces;
        for ((*spaces); (*spaces) > 0; (*spaces)--)
                std::cout<<' ';
        std::cout<<input;
        for ((*dum); (*dum) > 0; (*dum)--)
                std::cout<<' ';
        delete sLength;
        delete spaces;
        delete dum;
}



/*      FIRST CHARACTER BACKGROUND, SECOND IS FOREGROUND
        0 = Black
        1 = Blue
        2 = Green
        3 = Aqua
        4 = Red
        5 = Purple
        6 = Yellow
        7 = White
        8 = Gray
        9 = Light Blue
        A = Light Green
        B = Light Aqua
        C = Light Red
        D = Light Purple
        E = Light Yellow
        F = Bright White
*/

class Color
{
public:
        Color();
        ~Color();
        void colorSet   (bool reset1);
        void toHex              (spectrum x);
        void toHex              (spectrum x, spectrum y);
        void flush              ();
private:
HANDLE hstdin;
HANDLE hstdout;
CONSOLE_SCREEN_BUFFER_INFO csbi;
WORD    fore,
                back,
                both;
bool reset;
};
void Color::colorSet(bool reset1)
{
        reset = reset1;
        both = fore + back;
        SetConsoleTextAttribute( hstdout, both );
}
void Color::toHex(spectrum x)
{
        switch (x)
        {
                case 0:
                        fore = 0x00;
                        break;
                case 1:
                        fore = 0x01;
                        break;
                case 2:
                        fore = 0x02;
                        break;
                case 3:
                        fore = 0x03;
                        break;
                case 4:
                        fore = 0x04;
                        break;
                case 5:
                        fore = 0x05;
                        break;
                case 6:
                        fore = 0x06;
                        break;
                case 7:
                        fore = 0x07;
                        break;
                case 8:
                        fore = 0x08;
                        break;
                case 9:
                        fore = 0x09;
                        break;
                case 10:
                        fore = 0x0A;
                        break;
                case 11:
                        fore = 0x0B;
                        break;
                case 12:
                        fore = 0x0C;
                        break;
                case 13:
                        fore = 0x0D;
                        break;
                case 14:
                        fore = 0x0E;
                        break;
                case 15:
                        fore = 0x0F;
                        break;
                default:
                        fore = 0x07;
        }
        back = 0x00;
}
void Color::toHex(spectrum x, spectrum y)
{
        switch (x)
        {
                case 0:
                        fore = 0x00;
                        break;
                case 1:
                        fore = 0x01;
                        break;
                case 2:
                        fore = 0x02;
                        break;
                case 3:
                        fore = 0x03;
                        break;
                case 4:
                        fore = 0x04;
                        break;
                case 5:
                        fore = 0x05;
                        break;
                case 6:
                        fore = 0x06;
                        break;
                case 7:
                        fore = 0x07;
                        break;
                case 8:
                        fore = 0x08;
                        break;
                case 9:
                        fore = 0x09;
                        break;
                case 10:
                        fore = 0x0A;
                        break;
                case 11:
                        fore = 0x0B;
                        break;
                case 12:
                        fore = 0x0C;
                        break;
                case 13:
                        fore = 0x0D;
                        break;
                case 14:
                        fore = 0x0E;
                        break;
                case 15:
                        fore = 0x0F;
                        break;
                default:
                        fore = 0x07;
        }
        switch (y)
        {
                case 0:
                        back = 0x00;
                        break;
                case 1:
                        back = 0x10;
                        break;
                case 2:
                        back = 0x20;
                        break;
                case 3:
                        back = 0x30;
                        break;
                case 4:
                        back = 0x40;
                        break;
                case 5:
                        back = 0x50;
                        break;
                case 6:
                        back = 0x60;
                        break;
                case 7:
                        back = 0x70;
                        break;
                case 8:
                        back = 0x80;
                        break;
                case 9:
                        back = 0x90;
                        break;
                case 10:
                        back = 0xA0;
                        break;
                case 11:
                        back = 0xB0;
                        break;
                case 12:
                        back = 0xC0;
                        break;
                case 13:
                        back = 0xD0;
                        break;
                case 14:
                        back = 0xE0;
                        break;
                case 15:
                        back = 0xF0;
                        break;
                default:
                        back = 0x00;
        }
}
Color::Color()
{
GetConsoleScreenBufferInfo( hstdout, &csbi );   // get stats for deconstructor
hstdin = GetStdHandle( STD_INPUT_HANDLE  );
hstdout = GetStdHandle( STD_OUTPUT_HANDLE );
}
Color::~Color()
{
        if (reset)
                SetConsoleTextAttribute( hstdout, 0x07 );       // Set text to white on black
}
void Color::flush()
{
        FlushConsoleInputBuffer( hstdin );
}


void color(spectrum x, std::string input)
{
        Color *foo = new Color;
        foo->toHex(x);
        foo->colorSet(false);
        std::cout<<input;
        foo->flush();
        delete foo;
}

void color(spectrum x, char input)
{
        Color *foo = new Color;
        foo->toHex(x);
        foo->colorSet(false);
        std::cout<<input;
        foo->flush();
        delete foo;
}

void color(spectrum x, spectrum y, std::string input)
{
        Color *foo = new Color;
        foo->toHex(x,y);
        foo->colorSet(true);
        std::cout<<input;
        foo->flush();
        delete foo;
}

void color(spectrum x, spectrum y, char input)
{
        Color *foo = new Color;
        foo->toHex(x,y);
        foo->colorSet(false);
        std::cout<<input<<" 1";
        foo->flush();
        delete foo;
}

void color(spectrum x)
{

        Color *foo = new Color;
        foo->toHex(x);
        if (x == reset)
                foo->colorSet(true);
        else
                foo->colorSet(false);
        foo->flush();
        delete foo;
}

void color(spectrum x, spectrum y)
{
        Color *foo = new Color;
        foo->toHex(x,y);
        foo->colorSet(false);
        foo->flush();
        delete foo;
}


int randomInt(short lower, short upper)
{
        std::uniform_int_distribution<int> dist(lower,upper);
        if (lower > upper)
                std::uniform_int_distribution<int> dist(upper,lower);
        return dist(mt);
}
double randomDouble(short lower, short upper)
{
        std::uniform_real_distribution<double> dist(lower,upper);
        if (lower > upper)
                std::uniform_real_distribution<double> dist(upper,lower);
        return dist(mt);
}



class Wait
{
public:
        Wait();
        void setTime(clock_t sec);
private:
        clock_t time1;
        clock_t time2;
        clock_t time;
};
Wait::Wait()
{
        time1 = clock();
}
void Wait::setTime(clock_t sec)
{
        time = sec;
        time2 = time1+time;
        while (time1 < time2)
                time1 = clock();
}

void wait(clock_t time)
{
        Wait *wait = new Wait;
        wait->setTime(time);
        delete wait;
}

void cls()
{
        COORD topLeft  = { 0, 0 };
        HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_SCREEN_BUFFER_INFO screen;
        DWORD written;

        GetConsoleScreenBufferInfo(console, &screen);
        FillConsoleOutputCharacterA(console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written);
        FillConsoleOutputAttribute(
                console, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE,
                screen.dwSize.X * screen.dwSize.Y, topLeft, &written
        );
        SetConsoleCursorPosition(console, topLeft);
}
