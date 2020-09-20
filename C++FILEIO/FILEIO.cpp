#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <windows.h>
#include <map>
#include <vector>
#include <cstdio>

using namespace std;

map<string, vector<RECT>> Sprite;

int main()
{
	vector<string> temp;
	string buffer;
	ifstream fp("Kaho.txt");
	if (fp.is_open())
	{
	}
	getline(fp, buffer);
	int Total = stoi(buffer);
	temp.resize(Total);
	for (int i = 0; i < Total; i++)
	{
		int k;
		getline(fp, buffer);
		istringstream is(buffer);
		is >> temp[i] >> k;
		vector<RECT> pl;
		pl.resize(k);
		Sprite.insert(make_pair(temp[i], pl));
	}
	while (!fp.eof())
	{
		for (auto it : temp)
		{
			for (int i = 0; i < Sprite[it].size(); ++i)
			{
				int l, t, r, b;
				getline(fp, buffer);
				istringstream is(buffer);
				is >> l >> t >> r >> b;;
				Sprite[it][i] = { l,t,r,b };
			}
		}
	}

	return 0;
}