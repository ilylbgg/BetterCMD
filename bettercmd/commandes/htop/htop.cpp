#include "htop.h"
#include <iostream>
#include <windows.h>
#include <psapi.h>
#include <thread>
#include <chrono>

void htopCmd() {
    while (true) {
        // Get the handle to the current process
        HANDLE hProcess = GetCurrentProcess();

        // Get memory usage information
        PROCESS_MEMORY_COUNTERS pmc;
        if (GetProcessMemoryInfo(hProcess, &pmc, sizeof(pmc))) {
            std::cout << "Memory Usage: " << pmc.WorkingSetSize / 1024 << " KB" << std::endl;
        }

        // Get CPU usage information
        FILETIME ftSysIdle, ftSysKernel, ftSysUser;
        FILETIME ftProcCreation, ftProcExit, ftProcKernel, ftProcUser;

        if (GetSystemTimes(&ftSysIdle, &ftSysKernel, &ftSysUser) &&
            GetProcessTimes(hProcess, &ftProcCreation, &ftProcExit, &ftProcKernel, &ftProcUser)) {
            ULARGE_INTEGER sysKernel, sysUser;
            sysKernel.LowPart = ftSysKernel.dwLowDateTime;
            sysKernel.HighPart = ftSysKernel.dwHighDateTime;
            sysUser.LowPart = ftSysUser.dwLowDateTime;
            sysUser.HighPart = ftSysUser.dwHighDateTime;

            ULARGE_INTEGER procKernel, procUser;
            procKernel.LowPart = ftProcKernel.dwLowDateTime;
            procKernel.HighPart = ftProcKernel.dwHighDateTime;
            procUser.LowPart = ftProcUser.dwLowDateTime;
            procUser.HighPart = ftProcUser.dwHighDateTime;

            std::cout << "CPU Usage: " << (procKernel.QuadPart + procUser.QuadPart) * 100 / (sysKernel.QuadPart + sysUser.QuadPart) << "%" << std::endl;
        }

        CloseHandle(hProcess);

        // Sleep for 1 second before updating again
        std::this_thread::sleep_for(std::chrono::seconds(1));

        // Clear the console
        system("cls");
    }
}