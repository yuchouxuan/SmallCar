#include "MainApp.h"
#include <unistd.h>

MainApp::MainApp()
{
	tst = new Test(this);
	scr = new cur();
	fpga = new fpgaio();
}



MainApp::~MainApp()
{
	delete scr;
	delete fpga;
}

void MainApp::Test::TestSRuler(int add)
{
	
	float cm = Ruler_mm(add)/10;
	if (cm > 10 && cm < 640)
	{
		printf("-> %.1fcm : %.2fm \r\n",cm, cm / 100);
	}
	else
	{
		printf("<Errdata>  \r\n");
	}
	usleep(20000);
}

string MainApp::Test::getAllData(unsigned int istart, unsigned int iend  ,bool ptr)
{
	string ret = "";
	winsize ws = cur::_getWindowSize();
	if (iend == 0) iend = addMax;

	for (int i = 0; i < ws.ws_col; i++)
	{
		ret.append("-");
	}
	ret[ws.ws_col / 2 - 2] = 'D';
	ret[ws.ws_col / 2 - 1] = 'A';
	ret[ws.ws_col / 2] = 'T';
	ret[ws.ws_col / 2 + 1] = 'A';
	ret[ws.ws_col / 2 + 2] = 'S';
	ret.append("\r\n");



	for (int i = istart; i <= iend; i++)
	{
		unsigned int dat = mp->fpga->get16(i);
		if (dat == 0 || dat == 65535) continue;
		ret.append(toString(i));
		ret.append("\r\n");

	}
	for (int i = 0; i < ws.ws_col; i++)
	{
		ret.append("-");
	}
	ret += "\r\n";
	if(ptr) printf("%s", ret.c_str());
	return ret;
}

string MainApp::Test::getAllDataB(unsigned int block8, bool ptr)
{
	string ret = "";
	winsize ws = cur::_getWindowSize();
	int wid = (ws.ws_col > 116) ? 116: ws.ws_col;
	char row[512] = "";
	sprintf(row, "\r\n DATA:[%02X]:[00-FF]\r\n", block8&0xFF);
	ret.append(row);
	ret.append("|");
	for (int i=  0; i < wid; i++)	ret.append("-");
	ret += "|";
	for(int i =0 ;i <=15;i++)
	{
		sprintf(row, "\r\n| %2X |", i);
		ret.append(row);
		for (int c = 0; c <= 15; c++)
		{ 
			unsigned int address = (block8 << 8) | (i << 4) | c;
			sprintf(row, "%X:%04X|", c,mp->fpga->get16(address));
			ret.append(row);
		}
		ret += "\r\n";
		ret.append("|");
		for (int i = 0; i < wid; i++)	ret.append("-");
		ret.append("|");
	}
	ret += "\r\n";
	
	if (ptr) printf("%s", ret.c_str());
	return string();
}

string MainApp::Test::toString(unsigned int address)
{
	string ret = "";
	unsigned int dat = mp->fpga->get16(address);
	unsigned int l = dat & 0xFF;
	unsigned int h = (dat >> 8) & 0xFF;
	char row[512] = "";
	sprintf(row, "%04u[%04X]=%05u\t\t%03u:%03u\t\t%02X:%02X\t\t<", address, address,dat, h, l, h, l);
	ret.append(row);
	char bin[17] = "0000000000000000";
	for (int x = 15; x >= 0; x--)
	{

		if (dat & 1 == 1)
		{
			bin[x] = '1';
		}
		dat >>= 1;
	}
	ret.append(bin);
	ret.append(">");
	return ret;
}
