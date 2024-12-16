#include "FileDialog.h"

std::string WStringToString(const std::wstring& wstr) 
{ 
    std::wstring_convert<std::codecvt_utf8<wchar_t>> converter; 
    return converter.to_bytes(wstr); 
}

namespace SalveDas
{
	namespace Platform
	{
		namespace Windows
		{
			std::string OpenFileDialog()
			{
                // Initialize the OPENFILENAME structure
                OPENFILENAME ofn;
                wchar_t szFile[260] = { 0 };  // Buffer to store the selected file path

                // Zero out the OPENFILENAME structure
                ZeroMemory(&ofn, sizeof(ofn));
                ofn.lStructSize = sizeof(ofn);
                ofn.hwndOwner = NULL;  // Parent window handle (NULL if no parent)
                ofn.lpstrFile = szFile;
                ofn.nMaxFile = sizeof(szFile);
                ofn.lpstrFilter = TEXT("All files\0*.*\0Png files\0*.png*");  // Filter for file types
                ofn.nFilterIndex = 1;  // Default filter type
                ofn.lpstrFileTitle = NULL;
                ofn.nMaxFileTitle = 0;
                ofn.lpstrInitialDir = NULL;  // Default directory
                ofn.lpstrTitle = TEXT("Select a File");  // Title of the dialog
                ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;  // Only allow valid files

                // Show the Open File Dialog
                if (GetOpenFileName(&ofn) == TRUE)
                {
                    return WStringToString(ofn.lpstrFile);
                }

                return NULL;
			}
            std::string OpenFolderDialog()
            {
                HRESULT hr = CoInitializeEx(NULL, COINIT_APARTMENTTHREADED | COINIT_DISABLE_OLE1DDE);
                if (SUCCEEDED(hr)) {
                    IFileDialog* pfd = NULL;
                    hr = CoCreateInstance(CLSID_FileOpenDialog, NULL, CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&pfd));
                    if (SUCCEEDED(hr)) {
                        DWORD dwOptions;
                        hr = pfd->GetOptions(&dwOptions);
                        if (SUCCEEDED(hr)) {
                            pfd->SetOptions(dwOptions | FOS_PICKFOLDERS);
                            hr = pfd->Show(NULL);
                            if (SUCCEEDED(hr)) {
                                IShellItem* psiResult;
                                hr = pfd->GetResult(&psiResult);
                                if (SUCCEEDED(hr)) {
                                    PWSTR pszFilePath = NULL;
                                    hr = psiResult->GetDisplayName(SIGDN_FILESYSPATH, &pszFilePath);
                                    if (SUCCEEDED(hr)) {
                                        std::wstring ws(pszFilePath);
                                        std::string folderPath(ws.begin(), ws.end());
                                        CoTaskMemFree(pszFilePath);
                                        psiResult->Release();
                                        pfd->Release();
                                        CoUninitialize();
                                        return folderPath;
                                    }
                                    psiResult->Release();
                                }
                            }
                        }
                        pfd->Release();
                    }
                    CoUninitialize();
                }
            }
		}
	}
}