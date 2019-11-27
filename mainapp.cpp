#include "mainapp.h"
void build_eliptik(big &a, big &b, big &n, epoint *Ppoint);
void main()
{	
	srand(time(NULL));
	miracl *mip = mirsys(2000, 16);
	mip->IOBASE = 16;
	big a, b, n;
	a = mirvar(0x0);
	b = mirvar(0x0);
	n = mirvar(0x0);
	epoint *G;
	G = epoint2_init();
	build_eliptik(a, b, n, G);
	
	CObjectA  A(G, n);
	CObjectB  B(G, n);

	A.Build_Key_Kab(B.Pb);
	B.Build_Key_Kba(A.Pa);
	if(epoint2_comp(A.Kab, B.Kba))
		printf("secret Kab Object A =  secret Kba Object B\n");
	else
		printf("Kab != Kba");
	epoint2_free(G);
	mirkill(a);
	mirkill(b);
	system("pause");
}

void build_eliptik(big &a, big &b, big &n, epoint *Ppoint)
{
	BYTE num = rand()%3;
	big x,y;
	x = mirvar(0x0);
	y = mirvar(0x0);

	switch(num)
	{
	case 0 :
		//173
		convert(0x0,a);
		cinstr(b, "108576C80499DB2FC16EDDF6853BBB278F6B6FB437D9");
		cinstr(n, "800000000000000000000189B4E67606E3825BB2831");
		if (ecurve2_init(173, 10, 2, 1, a, b, FALSE, MR_AFFINE) == false)
		{
			printf("Error init 1\n");
		}
		else 
		{
	//		Ppoint = epoint2_init();
			cinstr(x, "BE6628EC3E67A91A4E470894FBA72B52C515F8AEE9");
			cinstr(y, "D9DEEDF655CF5412313C11CA566CDC71F4DA57DB45C");
			if(!epoint2_set(x, y, 0, Ppoint))
				printf("Error point P\n");
			//printf("Ok 1\n");
		}
		break;
	case 1:
		//283
		convert(0x1,a);
		cinstr(b, "27B680AC8B8596DA5A4AF8A19A0303FCA97FD7645309FA2A581485AF6263E313B79A2F5");
		cinstr(n, "3FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEF90399660FC938A90165B042A7CEFADB307");
		if (ecurve2_init(283, 12, 7, 5, a, b, FALSE, MR_AFFINE) == false)
			printf("Error init 2\n");
		else 
		{
	//		Ppoint = epoint2_init();
			cinstr(x, "4D95820ACE761110824CE425C8089129487389B7F0E0A9D043DDC0BB0A4CC9EB25");
			cinstr(y, "954C9C4029B2C62DE35C2B9C2A164984BF1101951E3A68ED03DF234DDE5BB2013152F2");
			if(!epoint2_set(x, y, 0, Ppoint))
				printf("Error point P\n");
			//printf("Ok 2\n");
		}
		
		break;
	case 2:
		//431
		convert(0x1,a);
		cinstr(b, "3CE10490F6A708FC26DFE8C3D27C4F94E690134D5BFF988D8D28AAEAEDE975936C66BAC536B18AE2DC312CA493117DAA469C640CAF3");
		cinstr(n, "3FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFBA3175458009A8C0A724F02F81AA8A1FCBAF80D90C7A95110504CF");
		if (ecurve2_init(431, 5, 3, 1, a, b, FALSE, MR_AFFINE) == false)
		{
			printf("Error init 3\n");
		}
		else 
		{
	//		Ppoint = epoint2_init();
			cinstr(x, "85478BD4045F95A117FA328F1A64A0B38D694E760619C07ED37A75E2829ECCDB8AFF178BEE0FCB8F734F7C5F427189DF45A7E2649F");
			cinstr(y, "424F02988F6E0AD3C9F70B435B5DD943257A5EE812816FD7FA63A4BCA5F9A5767B0A6748197D0F1CDD321EC2743F1FA20344271D5032");
			if(!epoint2_set(x, y, 0, Ppoint))
				printf("Error point P\n");
			//printf("Ok 3\n");
		}
		break;

	}
	printf("-------------------------------------------------------------------------------\n");
	printf("Base Point \"G\" :\n");
	printf("Point X : \n");
	cotnum(x, stdout);
	printf("Point Y : \n");
	cotnum(y, stdout);
	printf("Order of base point :\n");
	cotnum(n, stdout);
	printf("Press any key to continue.\n");
	printf("-------------------------------------------------------------------------------\n");
	getch();
	mirkill(x);
	mirkill(y);
}
