#pragma once
#include <curses.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <termios.h>
class cur
{
private:
	winsize size;
	WINDOW* mw;
	bool _init();

public:
	void tst();
	cur();
	~cur();
	void clean();
	static winsize _getWindowSize();
};