#include "dependences.h"

class CObjectA
{
public:
	epoint *Kab;
	void Build_Key_Kab(epoint *Pb);
	epoint *Pa;
	CObjectA(epoint *G, big n);
	virtual ~CObjectA();

private:
	big m_bigDa;
};
