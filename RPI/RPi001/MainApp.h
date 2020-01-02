#pragma once
#include "cur.h"
#include "fpgaio.h"
#include <string>
using namespace std;


class Test;


class MainApp
{
	class Test
	{
	private:
		int addMax = 1023;
		MainApp* mp = NULL;
	public:
		Test(MainApp* imp) {mp = (MainApp*)imp; };
		float Ruler_mm(int add) { return float(this->mp->fpga->get16(add)) * 1.7; };
		void TestSRuler(int add);
		string getAllData(unsigned int istart=0, unsigned int iend=0,bool ptr = true);
		string getAllDataB(unsigned int istart = 0, bool ptr = true);
		string toString(unsigned int address);
	};

public:
	Test* tst = new Test(this);
	cur* scr = new cur();
	fpgaio* fpga = new fpgaio();
	~MainApp();
	MainApp();
	
	
	
};



