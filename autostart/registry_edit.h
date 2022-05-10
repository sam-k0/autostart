#pragma once
#include <Windows.h>
#include <conio.h>
#include <string>

int addToAutostart()
{
	char re[MAX_PATH];
	std::string FP = std::string(re, GetModuleFileNameA(NULL, re, MAX_PATH));

	LONG ln = RegGetValueA(HKEY_CURRENT_USER, "SOFTWARE\\Microsoft\\Windows\\Currentversion\\Run", "AmoTekDesktop", RRF_RT_REG_SZ, 0, 0, 0);
	if (ERROR_SUCCESS == ln) // its already in there
	{
		return 0;
	}
	else
	{
		HKEY hkey;
		LONG key = RegOpenKeyExA(HKEY_CURRENT_USER, "SOFTWARE\\Microsoft\\Windows\\Currentversion\\Run", 0, KEY_WRITE, &hkey);
		if (ERROR_SUCCESS == key)
		{
			key = RegSetValueExA(hkey, "AmoTekDesktop", 0, REG_SZ, (BYTE*)FP.c_str(), strlen(FP.c_str()));
			return 1;
		}

	}
	return 0;
}
