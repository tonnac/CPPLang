#include <string>
#include <iostream>
#include <filesystem>
#include <algorithm>
#include <array>
#include <vector>
#include <fstream>

using namespace std;
using namespace filesystem;

//#define CLEAN

static const array<wstring, 2> bracket = { L"[]", L"()" };
static const vector<wstring> labels = {
L"300mium",
L"jux",
L"juy",
L"pred",
L"miad",
L"pppd",
L"meyd",
L"rbd",
L"cjod",
L"jufd",
L"prtd",
L"gbg",
L"bban",
L"rbd",
L"gvg",
L"miae",
L"sprd",
L"tamo",
L"ssr",
L"nsps",
L"sdmu",
L"nhdtb",
L"rctd",
L"ndra",
L"ksbj",
L"ssr",
L"nacx",
L"hhkl",
L"adn",
L"ebod",
L"ngod",
L"shkd",
L"atid",
L"ipx",
L"sdsi",
L"sspd",
L"gexp",
L"momj",
L"aoz",
L"jag",
L"fset",
L"mdb",
L"hsrm",
L"sdmt",
L"mimu",
L"sgv",
L"armg",
L"mkbd",
L"smbd",
L"bdsr",
L"adz",
L"pgd",
L"upsm",
L"ysn",
L"nhdta",
L"iene",
L"ezc",
L"juc",
L"fajs",
L"nfdm",
L"sero",
L"ezd",
L"dvdes",
L"psd",
L"okad",
L"hyaz",
L"zuko",
L"dasd",
L"crpd",
L"hunta",
L"dvdms",
L"hbad",
L"finh",
L"pkpd",
L"zmen",
L"jufe",
L"meko",
L"juvr",
L"xrw",
L"nkkd" };

int wmain(int argc, wchar_t* argv[])
{
	wcout.imbue(locale("kor"));
	vector<wstring> conditionString;

	if (argc > 2)
	{
		for (int i = 2; i < argc; i++)
		{
			wstring finding = argv[i];
			std::transform(finding.begin(), finding.end(), finding.begin(), ::tolower);
			conditionString.push_back(finding);
		}
	}
	else
	{
		conditionString = labels;

		//wifstream list;
		//list.open(L"D:\\repos\\output\\C++Lang\\check.txt");
		//wstring line;
		//if (list.is_open())
		//{
		//	wofstream newc;
		//	newc.open(L"D:\\repos\\output\\C++Lang\\newcheck.txt");
		//	while (getline(list, line))
		//	{
		//		if (!line.empty())
		//		{
		//			std::transform(line.begin(), line.end(), line.begin(), ::tolower);
		//			conditionString.push_back(line);
		//			wstring nn = L"L\"" + line + L"\",\n";
		//			newc.write(nn.c_str(), nn.size());
		//		}
		//	}
		//	newc.close();
		//	list.close();
		//}
	}

	if (conditionString.empty())
	{
		return 0;
	}

	vector<array<wstring, 2>> p;

	for (const auto& entry : filesystem::directory_iterator(path(argv[1])))
	{
		wstring dir = entry.path().parent_path().c_str();
		wstring fullName = entry.path().filename().c_str();
		wstring name = wstring(fullName, 0, fullName.find_last_of(L'.'));
		wstring lowerName = name;
		transform(lowerName.begin(), lowerName.end(), lowerName.begin(), ::tolower);
		wstring ext = wstring(fullName, fullName.find_last_of(L"."), fullName.length());
		wstring findingName;

		bool isLowercase = false;
		size_t start = wstring::npos;
		for (const auto& fName : conditionString)
		{
			size_t length = lowerName.find(fName);
			if (length != wstring::npos)
			{
				start = length;
				findingName = fName;
				break;
			}
		}

		if (start == wstring::npos)
		{
			continue;
		}

		wstring label;
		size_t length;
		bool ishyphen;

		if (name.at(start + findingName.length()) == '-')
		{
			length = findingName.length() + 4;
			label = wstring(name, start, length);
			ishyphen = true;
		}
		else
		{
			ishyphen = false;
			length = findingName.length() + 3;
			label = wstring(name, start, findingName.length()) + L"-" + wstring(name, start + findingName.length(), 3);
		}

		if (start == 0 && ishyphen && wstring(name, start, findingName.length()) != findingName)
		{
			continue;
		}

		std::transform(label.begin(), label.end(), label.begin(), ::toupper);
		name.replace(start, length, L"");

		bool isDirty = true;

		do
		{
			isDirty = false;
			size_t l;
			if ((l = name.find(L"  ")) != wstring::npos)
			{
				isDirty = true;
				name.replace(l, 2, L" ");
			}
			for (const auto& b : bracket)
			{
				if ((l = name.find(b)) != wstring::npos)
				{
					isDirty = true;
					name.replace(l, 2, L"");
				}
			}
		} while (isDirty);

		if (name.empty())
		{
			name = ext;
		}
		else
		{
			if (name[name.length() - 1] == L' ')
			{
				name = wstring(name, 0, name.length() - 1);
			}
			if (name[0] != L' ')
			{
				name = wstring(L" " + name);
			}
			name += ext;
		}

		wstring newName = label + name;

		array<wstring, 2> names = { entry.path(), dir + L"\\" + newName };
		p.push_back(names);
	}

#ifdef CLEAN
	p.clear();
	for (const auto& entry : filesystem::directory_iterator(path(argv[1])))
	{
		wstring dir = entry.path().parent_path().c_str();
		wstring fullName = entry.path().filename().c_str();
		wstring name = wstring(fullName, 0, fullName.find_last_of(L'.'));
		wstring lowerName = name;
		transform(lowerName.begin(), lowerName.end(), lowerName.begin(), ::tolower);
		wstring ext = wstring(fullName, fullName.find_last_of(L"."), fullName.length());
		wstring findingName;

		bool isDirty = true;
		bool nosearch = true;
		array<wstring, 2> bracket = { L"[]", L"()" };
		do
		{
			isDirty = false;
			size_t l;
			if ((l = name.find(L"  ")) != wstring::npos)
			{
				isDirty = true;
				nosearch = false;
				name.replace(l, 2, L" ");
			}
			for (const auto& b : bracket)
			{
				if ((l = name.find(b)) != wstring::npos)
				{
					nosearch = false;
					isDirty = true;
					name.replace(l, 2, L"");
				}
			}
		} while (isDirty);

		if (!nosearch)
		{
			wstring newName = name + ext;

			array<wstring, 2> names = { entry.path(), dir + L"\\" + newName };
			p.push_back(names);
		}
	}
#endif
	if (!p.empty())
	{
		for (const auto& e : p)
		{
			wcout << L"전: " << e[0] << endl;
			wcout << L"후: " << e[1] << endl << endl;
		}

		string a = {};
		wcout << L"계속하시겠습니까(y/n)?";
		cin >> a;

		if (a == "y" || a == "Y")
		{
			for (const auto& e : p)
			{
				filesystem::rename(e[0], e[1]);
			}
		}
	}
}