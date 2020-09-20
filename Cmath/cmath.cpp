#include <iostream>
#include <cmath>
#include <DirectXMath.h>
#include <DirectXPackedVector.h>

using namespace std;
using namespace DirectX;
using namespace DirectX::PackedVector;

int main()
{
	float cosret = -13 / (sqrtf(14) * sqrtf(26));
	float ddd = acosf(cosret);
	float degree = XMConvertToDegrees(ddd);

	float cosee = cosf(XMConvertToRadians(132.9519f));

	return 0;
}