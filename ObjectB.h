// ObjectB.h: interface for the CObjectB class.
//
//////////////////////////////////////////////////////////////////////

#include "bred.h"
class CObjectB  
{
public:
	epoint *Kba;
	void Build_Key_Kba(epoint *Pa);
	epoint *Pb;
	CObjectB(epoint *G, big n);
	CObjectB();
	virtual ~CObjectB();

private:
	big m_bigDb;
};
