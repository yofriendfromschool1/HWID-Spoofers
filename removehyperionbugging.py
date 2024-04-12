import os
print("Roblox remove hyperion bugging? Tool")
username = os.getlogin()
storagepath = f"C:/Users/{username}/AppData/Local/Roblox/logs"
files = os.listdir(storagepath)
print("Fetching Local Files")
for file in files:
    print("Removing",file)
    try:
        os.remove(storagepath+"/"+file)
    except Exception as e:
        print("Issue in removing file\n", e)
print("Cleared Directory")
input("\n[ENTER TO QUIT]")