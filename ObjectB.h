#include "dependences.h"

class CObjectB
{
public:
	epoint *Kba;
	void Build_Key_Kba(epoint *Pa);
	epoint *Pb;
	CObjectB(epoint *G, big n);
	virtual ~CObjectB();

private:
	big m_bigDb;
};
