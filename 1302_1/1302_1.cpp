#include "1302_1.h"

int main()
{
	SmartPtr<Point> ad(new Point(1, 2));
	SmartPtr<Point> qw(new Point(3, 4));
	ad->ShowPosition();
	qw->ShowPosition();
}