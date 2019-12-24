// ObjectA.cpp: implementation of the CObjectA class.
//
//////////////////////////////////////////////////////////////////////

#include "ObjectA.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////


CObjectA::~CObjectA()
{
	mirkill(m_bigDa);	
	epoint2_free(Pa);
	epoint2_free(Kab);
}

CObjectA::CObjectA(epoint *G, big n)
{
	
	printf("-------------------------------------------------------------------------------\n");
	char ch[255];
	m_bigDa = mirvar(0x0);
	Pa = epoint2_init();
	Kab = epoint2_init();

	for(BYTE bt = 0; bt < 255; bt++)
		ch[bt] = rand()%256;
	time_t t;
	strong_init (strlen(ch), ch, time(&t));
	strong_bigrand(n, m_bigDa);
	printf("Private Key \"da\" (object A) : \n");
	cotnum(m_bigDa, stdout);
	printf("\n");

	ecurve2_mult(m_bigDa, G, Pa);
	
	big tempx, tempy;
	tempx = mirvar(0x0);
	tempy = mirvar(0x0);
	epoint2_get(Pa, tempx, tempy);
	printf("Public Key \"Pa(X,Y)\" (object A) : \n");
	printf("Point X :\t");
	cotnum(tempx, stdout);
	printf("Point Y :\t");
	cotnum(tempy, stdout);
	printf("Press any key to continue.\n");
	printf("-------------------------------------------------------------------------------\n");
	getch();
	printf("\n");
	mirkill(tempx);
	mirkill(tempy);
}

void CObjectA::Build_Key_Kab(epoint *Pb)
{
	printf("-------------------------------------------------------------------------------\n");
	ecurve2_mult(m_bigDa, Pb, Kab);
	big tempx, tempy;
	tempx = mirvar(0x0);
	tempy = mirvar(0x0);
	epoint2_get(Kab, tempx, tempy);
	printf("Common secret \"Kab(X,Y)\" (object A) : \n");
	printf("Point X :\n");
	cotnum(tempx, stdout);
	printf("Point Y :\n");
	cotnum(tempy, stdout);
	printf("Press any key to continue.\n");
	printf("-------------------------------------------------------------------------------\n");
	getch();
	mirkill(tempx);
	mirkill(tempy);
}
