// ObjectA.h: interface for the CObjectA class.
//
//////////////////////////////////////////////////////////////////////
#include "bred.h"
class CObjectA  
{
public:
	epoint *Kab;
	void Build_Key_Kab(epoint *Pb);
	epoint *Pa;
	CObjectA(epoint *G, big n);
	CObjectA();
	virtual ~CObjectA();

private:
	big m_bigDa;
};
