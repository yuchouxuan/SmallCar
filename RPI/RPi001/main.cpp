

#include "MainApp.h"
#include "fpgaio.h"
#include <stdio.h>
#include <math.h>
#include <unistd.h>

int main(int argc,char * argv[])
{
	MainApp *mp = new MainApp();

	//mp->scr->tst();
	mp->scr->clean();

	unsigned int f,z,x;

	while (true)
	{
		
		printf("\r\nAddress and Data16:");
		scanf( "%X %X", &f, &x);
		
		mp->fpga->send16(f, x);
		mp->fpga->get16(f);
		mp->tst->getAllDataB(0x03);

	}
	
	delete mp;
	return 0;
}