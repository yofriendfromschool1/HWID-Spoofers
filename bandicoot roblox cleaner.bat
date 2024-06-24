@echo off

title Bandicoot Cleaner
@shift /0

@echo
:: BatchGotAdmin
:-------------------------------------

REM --> Check for permissions
IF "%PROCESSOR_ARCHITECTURE%" EQU "amd64" (
>nul 2>&1 "%SYSTEMROOT%\SysWOW64\cacls.exe" "%SYSTEMROOT%\SysWOW64\config\system"
) ELSE (
>nul 2>&1 "%SYSTEMROOT%\system32\cacls.exe" "%SYSTEMROOT%\system32\config\system"
)

title deep cleaner
REM --> If error flag set, we do not have admin.
if '%errorlevel%' NEQ '0' (
echo Requesting Admin...
goto UACPrompt
) else ( goto gotAdmin )

:UACPrompt
echo Set UAC = CreateObject^("Shell.Application"^) > "%temp%\getadmin.vbs"
set params= %*
echo UAC.ShellExecute "cmd.exe", "/c ""%~s0"" %params:"=""%", "", "runas", 1 >> "%temp%\getadmin.vbs"

"%temp%\getadmin.vbs"
del "%temp%\getadmin.vbs"
exit /B

:gotAdmin
pushd "%CD%"
CD /D "%~dp0"

cls

echo Deleting Temporary Files...
del /s /q %temp%\*
echo Temporary Files Deleted.
echo.
echo Btw when it says (would you like to override random characters say NO) or ur WiFi adapter will be FUCKED
echo Well not really u can just troubleshoot
echo Deleting Bloxstrap Logs...
del /s /q %localappdata%\Bloxstrap\logs*
del /s /q %localappdata%\Bloxstrap\LocalStorage*
echo Bloxstrap Logs Deleted.
echo.

echo Deleting Bloxstrap Logs...
del /s /q %localappdata%\Roblox\logs*
del /s /q %localappdata%\Roblox\LocalStorage*
echo Bloxstrap Logs Deleted.
echo.


echo Deleting Prefetch Files...
del /s /q C:\Windows\Prefetch\*
cls
echo Prefetch Files Deleted.
echo.

echo Emptying Recycle Bin...
rd /s /q C:\$Recycle.Bin
cls
echo Recycle Bin Emptied.
echo.

echo Refreshing IP...
ipconfig /flushdns
cls
echo DNS Cache Flushed.
echo.

echo Resetting Network Adapter...
netsh int ip reset
netsh winsock reset
cls
echo Network Adapter Reset.
echo.

echo Clearing DNS Resolver Cache...
ipconfig /displaydns
echo DNS Resolver Cache Cleared.
cls
echo.

setlocal EnableDelayedExpansion
 
netsh interface ipv6 uninstall
netsh advfirewall firewall set rule group="File and Printer Sharing" new enable=no
netsh int tcp set global autotuninglevel=normal
netsh interface set interface "Microsoft Network Adapter Multiplexor Protocol" admin=disabled
sc config lltdsvc start=disabled
netsh advfirewall firewall set rule group="Network Discovery" new enable=no
 
reg add "HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Services\Tcpip6\Parameters" /v DisabledComponents /t REG_DWORD /d 0xFFFFFFFF /f
 
 
netsh advfirewall firewall set rule group="Network Discovery" new enable=no
 
 
sc config lltdsvc start=disabled
 
 
reg add "HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Services\Tcpip6\Parameters" /v DisabledComponents /t REG_DWORD /d 0xFFFFFFFF /f
reg add "HKLM\SYSTEM\CurrentControlSet\Services\Tcpip\Parameters" /v EEE /t REG_DWORD /d 0 /f
reg add "HKLM\SYSTEM\CurrentControlSet\Services\Tcpip\Parameters\Interfaces" /v NetworkAddress /t REG_SZ /d "" /f
reg add "HKLM\SYSTEM\CurrentControlSet\Services\Tcpip\Parameters" /v ArpOffload /t REG_DWORD /d 0 /f
reg add "HKLM\SYSTEM\CurrentControlSet\Services\Tcpip\Parameters" /v TcpAckFrequency /t REG_DWORD /d 1 /f
reg add "HKLM\SYSTEM\CurrentControlSet\Services\Tcpip\Parameters" /v TcpChecksumOffloadIPv4 /t REG_DWORD /d 0 /f
reg add "HKLM\SYSTEM\CurrentControlSet\Services\Tcpip\Parameters" /v LargeSendOffloadv2IPv6 /t REG_DWORD /d 0 /f
reg add "HKLM\SYSTEM\CurrentControlSet\Services\Tcpip\Parameters" /v TcpChecksumOffloadIPv6 /t REG_DWORD /d 0 /f
reg add "HKLM\SYSTEM\CurrentControlSet\Services\Tcpip\Parameters" /v UdpChecksumOffloadIPv6 /t REG_DWORD /d 0 /f
 
echo network properties have been configured.
 
 
set KEY_NAME=HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Services\Tcpip6\Parameters
set VALUE_NAME_DNS=Dhcpv6DNSServers
set VALUE_NAME_SEARCHLIST=Dhcpv6DomainSearchList
set VALUE_NAME_DUID=Dhcpv6DUID
set VALUE_NAME_DISABLED=DisabledComponents
 
set "RANDOM_DNS="
set "RANDOM_SEARCHLIST="
set "RANDOM_DUID="
 
for /l %%i in (1,1,14) do call :generateRandomByte RANDOM_DNS
for /l %%i in (1,1,14) do call :generateRandomByte RANDOM_SEARCHLIST
for /l %%i in (1,1,14) do call :generateRandomByte RANDOM_DUID
 
reg add "%KEY_NAME%" /v "%VALUE_NAME_DNS%" /t REG_BINARY /d !RANDOM_DNS! /f
reg add "%KEY_NAME%" /v "%VALUE_NAME_SEARCHLIST%" /t REG_BINARY /d !RANDOM_SEARCHLIST! /f
reg add "%KEY_NAME%" /v "%VALUE_NAME_DUID%" /t REG_BINARY /d !RANDOM_DUID! /f
 
echo random binary values set
 
ipconfig /flushdns
ipconfig /registerdns
ipconfig /release
ipconfig /renew
netsh winsock reset 

 @ECHO OFF
 SETLOCAL ENABLEDELAYEDEXPANSION
 SETLOCAL ENABLEEXTENSIONS

 ::Generate and implement a random MAC address
 FOR /F "tokens=1" %%a IN ('wmic nic where physicaladapter^=true get deviceid ^| findstr [0-9]') DO (
 CALL :MAC
 FOR %%b IN (0 00 000) DO (
 REG QUERY HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Control\Class\{4D36E972-E325-11CE-BFC1-08002bE10318}\%%b%%a >NUL 2>NUL && REG ADD HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Control\Class\{4D36E972-E325-11CE-BFC1-08002bE10318}\%%b%%a /v NetworkAddress /t REG_SZ /d !MAC!  /f >NUL 2>NUL
 )
 )

 ::Disable power saving mode for network adapters
 FOR /F "tokens=1" %%a IN ('wmic nic where physicaladapter^=true get deviceid ^| findstr [0-9]') DO (
 FOR %%b IN (0 00 000) DO (
 REG QUERY HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Control\Class\{4D36E972-E325-11CE-BFC1-08002bE10318}\%%b%%a >NUL 2>NUL && REG ADD HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Control\Class\{4D36E972-E325-11CE-BFC1-08002bE10318}\%%b%%a /v PnPCapabilities /t REG_DWORD /d 24 /f >NUL 2>NUL
 )
 )

 ::Reset NIC adapters so the new MAC address is implemented and the power saving mode is disabled.
 FOR /F "tokens=2 delims=, skip=2" %%a IN ('"wmic nic where (netconnectionid like '%%') get netconnectionid,netconnectionstatus /format:csv"') DO (
 netsh interface set interface name="%%a" disable >NUL 2>NUL
 netsh interface set interface name="%%a" enable >NUL 2>NUL
 )

 GOTO :EOF
 :MAC
 ::Generates semi-random value of a length according to the "if !COUNT!"  line, minus one, and from the characters in the GEN variable
 SET COUNT=0
 SET GEN=ABCDEF0123456789
 SET GEN2=26AE
 SET MAC=
 :MACLOOP
 SET /a COUNT+=1
 SET RND=%random%
 ::%%n, where the value of n is the number of characters in the GEN variable minus one.  So if you have 15 characters in GEN, set the number as 14
 SET /A RND=RND%%16
 SET RNDGEN=!GEN:~%RND%,1!
 SET /A RND2=RND%%4
 SET RNDGEN2=!GEN2:~%RND2%,1!
 IF "!COUNT!"  EQU "2" (SET MAC=!MAC!!RNDGEN2!) ELSE (SET MAC=!MAC!!RNDGEN!)
 IF !COUNT!  LEQ 11 GOTO MACLOOP 


pause
