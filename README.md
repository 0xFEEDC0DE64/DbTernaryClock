# DbTernaryClock
Little desktop gadget to show time in base 3

## Building from source
This project can only be built as part of the project structure [DbSoftware](https://github.com/0xFEEDC0DE64/DbSoftware)

```Shell
git clone https://github.com/0xFEEDC0DE64/DbSoftware.git
cd DbSoftware
git submodule update --init --recursive DbTernaryClock libs/DbGuiLib
cd ..
mkdir build_DbSoftware
cd build_DbSoftware
qmake CONFIG+=ccache ../DbSoftware
make -j$(nproc) sub-DbTernaryClock
make sub-DbTernaryClock-install_subtargets
./bin/serialserver
```
