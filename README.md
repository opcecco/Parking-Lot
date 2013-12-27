Parking-Lot
===========

Nintendo DS homebrew game, originally designed by Oliver Ceccopieri.

INSTALLING DEVKITPRO TOOLCHAIN:
Open the "installation" folder and install devkitPro by running "devkitProUpdater-*.*.*.exe".
When selecting components to install, make sure devkitARM is selected.
The default installation directory is "C:\devkitPro", but you can install it anywhere.
On Mac and Linux, visit devkitpro.org to download the appropriate version of the toolchain.

REPLACING LIBRARIES FOR USE WITH PALIB:
Navigate to your devkitPro directory (default "C:\devkitPro").
Delete the folders named "libnds" and "devkitARM" and replace them with the folders in the "replacement libs.7z" archive contained in this repository.
Unzip the contents of the "PAlib 10.7z" folder into a folder named "PAlib" in your devkitPro directory.
The final layout should look something like this:

	C:\devkitPro
	|
	|----libnds
	|
	|----devkitArm
	|
	|----PAlib
	|	|
	|	|----lib
	|	|
	|	|----source
	|	|
	|	|----etc...
	|
	|----etc...

COMPILING PROGRAM:
Once the toolchains have been set up, run "build.bat" in this repository folder.
If no errors occur, you should have compiled a Parking_Lot.nds file to the "release" folder.

Copy the NDS file to a Nintendo DS flashcart, or run it in your favorite emulator.