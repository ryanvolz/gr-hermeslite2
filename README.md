# gr-hermeslite2

GNU Radio modules for Hermes Lite 2.

The main branch supports GNU Radio 3.10. The maint-3.8 branch supports GNU Radio
3.8. The maint-3.7 branch supports GNU Radio 3.7.

* hermesNB  sources decimated downconverted 48K-to-384K receiver complex stream(s), and sinks one 48k sample rate transmit complex stream.
* hermesWB  sources raw ADC samples as a vector of floats, with vlen=16384. Each individual vector contains time contiguous samples. However there are large time gaps between between vectors. This is how HPSDR produces raw samples, it is due to Ethernet interface rate limitations between HPSDR and the host computer.

## Installation

gr-hermeslite2 can be built and installed from source as follows:

```
mkdir build 
cd build 
cmake ..
make -j$(nproc)
sudo make install 
sudo ldconfig
```
