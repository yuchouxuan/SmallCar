#include "cur.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>


winsize cur::_getWindowSize()
{
	struct winsize size;
	ioctl(STDIN_FILENO, TIOCGWINSZ, &size);
	return size;
	
}

void cur::tst()
{
	//attrset(COLOR_PAIR(2));
	mvaddnstr(this->size.ws_row/2, this->size.ws_col/2-6, "Hello World.",12);
	refresh();
}

cur::cur()
{
	mw = NULL;
	this->size = _getWindowSize();

	if(!_init())
	{
		clean();
		printf("Error on InitSrc");
	}
}

cur::~cur()
{
	clean();
}

bool cur::_init()
{
	
	try{
	mw = initscr();
	cbreak();
	intrflush(mw, FALSE);
	noecho();
	keypad(mw, TRUE);
	curs_set(0);
	clear();

	start_color();
	init_pair(1, COLOR_WHITE, COLOR_BLACK);
	init_pair(2, COLOR_BLACK, COLOR_WHITE);
	init_pair(3, COLOR_RED, COLOR_WHITE);
	init_pair(4, COLOR_WHITE, COLOR_RED);

	return mw!=NULL;
	}
	catch (...)
	{
		return false;
	}
}

void cur::clean()
{
	try {
		echo();
		nl();
		nocbreak();
		keypad(mw, FALSE);
		intrflush(mw, TRUE);
	}
	catch (...)	{}
	try { endwin(); }
	catch (...) {}
}
