#pragma once

class fpgaio
{
public:
	int data = 31; // R<-100
	int di = 38; //Br->91
	int clk =36; //Y->89
	int ad = 33; //G->87
	int doit = 35; //B->85
public : 
	fpgaio();
	~fpgaio();
	void send16(unsigned int addr, unsigned int data);
	unsigned int  get16(unsigned int addr);
	void send32(unsigned int addr, unsigned int data);
	unsigned int  get32(unsigned int addr);
	void send8(unsigned int addr, unsigned int dL, unsigned int dH = 0);
private:
	void sendAddress(unsigned int addr);


};