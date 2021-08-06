#include <stdio.h>
#include <windows.h>
#include <tlhelp32.h>

int main(void) 
{
	HANDLE hProcessSnap =CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS,0);
	PROCESSENTRY32 pe32 ={0};
	
	if(hProcessSnap == INVALID_HANDLE_VALUE)
	{
		printf("CreateToolhelp32Snapshot (of processes)");
	}
	
	pe32.dwSize = sizeof(PROCESSENTRY32);
	
	if(Process32First(hProcessSnap, &pe32))
	{
		do
		{
			printf("%s \n", pe32.szExeFile);
		} while(Process32Next(hProcessSnap, &pe32));
	}

	return(FALSE);
}
