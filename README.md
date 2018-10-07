# DbTernaryClock
Little desktop gadget to show time in base 3

[![Build Status](https://travis-ci.org/0xFEEDC0DE64/DbTernaryClock.svg?branch=master)](https://travis-ci.org/0xFEEDC0DE64/DbTernaryClock) [![Codacy Badge](https://api.codacy.com/project/badge/Grade/f9b23e2939824a17921fe7e554b1b219)](https://www.codacy.com/app/0xFEEDC0DE64/DbTernaryClock?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=0xFEEDC0DE64/DbTernaryClock&amp;utm_campaign=Badge_Grade)

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
./bin/ternaryclock
```
