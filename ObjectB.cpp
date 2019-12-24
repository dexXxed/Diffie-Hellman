#include "ObjectB.h"

CObjectB::~CObjectB()
{
	mirkill(m_bigDb);	
	epoint2_free(Pb);
	epoint2_free(Kba);
}

CObjectB::CObjectB(epoint *G, big n)
{
	printf("-------------------------------------------------------------------------------\n");
	char ch[255];
	m_bigDb = mirvar(0x0);
	Pb = epoint2_init();
	Kba = epoint2_init();

	for(BYTE bt = 0; bt < 255; bt++)
		ch[bt] = rand()%256;
	time_t t;
	strong_init (strlen(ch), ch, time(&t));
	strong_bigrand(n, m_bigDb);

	printf("Private Key \"db\" (object B) : \n");
	cotnum(m_bigDb, stdout);
	printf("\n");

	ecurve2_mult(m_bigDb, G, Pb);
	
	big tempx, tempy;
	tempx = mirvar(0x0);
	tempy = mirvar(0x0);
	epoint2_get(Pb, tempx, tempy);
	printf("Public Key \"Pb(X,Y)\" (object B) : \n");
	printf("Point X :\n");
	cotnum(tempx, stdout);
	printf("Point Y :\n");
	cotnum(tempy, stdout);
	printf("Press any key to continue.\n");
	printf("-------------------------------------------------------------------------------\n");
	getch();
	printf("\n");
	mirkill(tempx);
	mirkill(tempy);

}

void CObjectB::Build_Key_Kba(epoint *Pa)
{
	printf("-------------------------------------------------------------------------------\n");
	ecurve2_mult(m_bigDb, Pa, Kba);
	big tempx, tempy;
	tempx = mirvar(0x0);
	tempy = mirvar(0x0);
	epoint2_get(Kba, tempx, tempy);
	printf("Common secret \"Kba(X,Y)\" (object B) : \n");
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
