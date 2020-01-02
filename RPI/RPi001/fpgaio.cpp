#include "fpgaio.h"
#include <wiringPi.h>
#include <stdio.h>
#include <unistd.h>

fpgaio::fpgaio()
{

	try
	{
		if (wiringPiSetupPhys() < 0)
		{
			printf("Error On InitPorts");
			return;
		}
		pinMode(ad, OUTPUT);
		pinMode(di, OUTPUT);
		pinMode(clk, OUTPUT);
		pinMode(doit, OUTPUT);
		pinMode(data, INPUT);
		digitalWrite(ad, 0);
		digitalWrite(di, 0);
		digitalWrite(clk, 0);
		digitalWrite(doit, 0);
	}
	catch (...)
	{
		printf("Error On InitPorts");
		return;
	}
}

fpgaio::~fpgaio()
{
	digitalWrite(ad, 0);
	digitalWrite(di, 0);
	digitalWrite(clk, 0);
	digitalWrite(doit, 0);

}

void fpgaio::sendAddress(unsigned int addr)
{
	digitalWrite(ad, 0);
	digitalWrite(di, 0);
	digitalWrite(clk, 0);

	int mask = 1;
	for (int i = 0; i < 16; i++)
	{
		digitalWrite(di, addr & mask);
		digitalWrite(clk, 1);
		digitalWrite(clk, 0);
		addr >>= 1;
	}
	digitalWrite(di, 0);
	digitalWrite(clk, 0);

}

void fpgaio::send16(unsigned int addr, unsigned int data)
{
	sendAddress(addr);
	digitalWrite(ad, 1);
	digitalWrite(clk, 0);
	unsigned int mask = 1;

	for (int i = 0; i < 16; i++)
	{
		digitalWrite(di, data & mask);
		digitalWrite(clk, 1);
		digitalWrite(clk, 0);
		data >>= 1;
	}
	digitalWrite(di, 0);
	digitalWrite(doit, 1);
	digitalWrite(doit, 0);
	digitalWrite(clk, 0);
}

unsigned int fpgaio::get16(unsigned int addr)
{
	sendAddress(addr);
	digitalWrite(clk, 0);
	digitalWrite(ad, 1);


	unsigned int ret = digitalRead(data);
	for (int i = 0; i < 15; i++)
	{
		digitalWrite(clk, 1);
		digitalWrite(clk, 0);
		ret <<= 1;
		ret += digitalRead(data);
	}

	return ret;
}

void fpgaio::send32(unsigned int addr, unsigned int data)
{
	unsigned int mask = 0xFFFF;

	send16(addr, (data >> 16)& mask);
	send16(addr - 1, data & mask);
}

unsigned int fpgaio::get32(unsigned int addr)
{
	return  get16(addr) + (get16(addr - 1) << 16);

}

void fpgaio::send8(unsigned int addr, unsigned int dL, unsigned int dH)
{
	send16(addr, dL + (dH << 8));
}
