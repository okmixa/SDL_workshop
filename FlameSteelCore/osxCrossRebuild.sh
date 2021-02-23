source ~/Apps/osxcross.sh
mkdir osxCrossBuild
cd osxCrossBuild
ar x ../libFlameSteelCore.a
rm ../libFlameSteelCore.a
x86_64-apple-darwin19-ar rcs ../libFlameSteelCore.a *.o
cd ..
rm -rf osxCrossBuild
