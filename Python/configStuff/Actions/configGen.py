"""
This will take the contents of a folder defined below and check it for python "modules".
If we make the ending always _mod.py it can skim for just modules

At a few points I considered making use of the status lights but this is more of a config tool
and that would just make the product annoying
"""
import os
import configparser

directory = "Modules"

# Discovered a better way to do this since creation but cant be bothered fixing this
try:
    modules = os.listdir(directory+"/")  # Try to read the folder for modules
except:  # In the event it doesnt exist
    print("Error: '" + directory + "' folder did not exist, it has been created for you")
    os.system("mkdir "+directory)
    exit("1")  # Exit with error code

if not modules:  # If list of directory contents is empty
    print("Error: The folder did not contain anything."
          "Populate the " + directory + " folder with modules \(ending in \.py\) and run again")
    exit("1")

# Now to filter out non-python scripts
pythonScripts = []  # and put them here

for entry in modules:
    # next line looks neater because of this
    length = len(entry)

    # This will check the last 3 chars
    extension = entry[length - 3:]

    if extension == ".py":
        # print("extensions match - "+extension)
        # adds entry as a total compared to without []
        pythonScripts += [entry]
    # else: print(extension + " != .py")

if not pythonScripts:  # If list of python scripts is empty
    print("Error: The folder did not contain modules.\n"
          "Populate the " + directory + " folder with modules \(ending in \.py\) and run again")
    exit("1")


# print(pythonScripts) ##DEBUG
# error checking complete and files have been searched, now to make the config

# start a config file parser
config = configparser.ConfigParser()


def askuser(entry):
    while True:
        status = input("Set " + entry + " to active? (yes/no) - ")
        if status[0] in ("y", "n"):
            return status[0]
        print ("Invalid Input")


# adds subsections for each file that is found
for entry in pythonScripts:
    if askuser(entry) == "y":
        config[entry] = {"Active": "true"}
    else:
        config[entry] = {"Active": "false"}

# Save it all
with open("SkeletonConfig.ini", "w") as configfile:
    config.write(configfile)
exit("0")
