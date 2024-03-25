import os
print("Roblox Unban Tool")
username = os.getlogin()
storagepath = f"C:/Users/{username}/AppData/Local/Roblox/LocalStorage"
files = os.listdir(storagepath)
print("Fetching Local Files")
for file in files:
    print("Removing",file)
    try:
        os.remove(storagepath+"/"+file)
    except Exception as e:
        print("Issue in removing file\n", e)
print("Cleared Directory")
print("Finished unban process, you can now play on an alt")
input("\n[ENTER TO QUIT]")