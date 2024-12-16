#ifdef SD_WINDOWS
	#ifndef SD_W_FILE_DIALOG
		#define SD_W_FILE_DIALOG
		#pragma once

		#include <Windows.h>
		#include <commdlg.h>
		#include <iostream>
		#include <string>
		#include <locale> 
		#include <codecvt>
		#include <shobjidl.h>

		namespace SalveDas
		{
			namespace Platform
			{
				namespace Windows
				{
					std::string OpenFileDialog();
					std::string OpenFolderDialog();
				}
			}
		}
	#endif // !SD_W_FILE_DIALOG

#endif // SD_WINDOWS
