#include "head.h"
#include <DirectXMath.h>

#define new new(__FILE__, __LINE__)
#define GETPTR(x) if((x) == nullptr) {return nullptr;} return (x)

using namespace DirectX;

XMFLOAT3 rr(const XMFLOAT3& xmal)
{
	XMFLOAT3 retfloat;
	retfloat.x = xmal.x;
	retfloat.y = xmal.y;
	retfloat.z = xmal.z;
	return retfloat;
}

class PF
{
public:
	int* getPtr()
	{
		GETPTR(ptr);
	}
private:
	int * ptr = nullptr;
};

int main()
{
	PF pe;
	int * ee = pe.getPtr();

	auto foo = [](int p = 5) {return p + 3;};

	rr({ 1.0f,1.0f,1.0f });

	return 0;
}