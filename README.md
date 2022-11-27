Implementation of simple event generator class, that generates events following
Gaussian distribution (https://en.wikipedia.org/wiki/Normal_distribution) using
boost::normal_distribution with mean = 10 and variance 0.5, with dummy
timestamp value for each event that takes current system clock time and adds
index of generated event, in that way creating events with unique timestamp.
These events are saved in boost::bimap and simple analysis is done on these
events. Analyzer class interface is generated, class PeakAnalyzer publicly
inherits Analyzer class, while EventGenerator holds implementation of interface
methods.

CMake is used for project build. For building tests for testAnalyzer.cpp,
Catch2 repo from GitHub (https://github.com/catchorg/Catch2)
is pulled in local project skipList. Doxygen is used for project documentation.

To build project and project documentation, go to root directory:
<pre>
$ cd root
$ mkdir build
$ cd build
$ cmake ..
$ make
$ make doc

To run tests:
$ cd test
$ ./tests

Benchmark results for generating and searching through boost::bimap show cost O(N):

-------------------------------------------------------------------------------
Benchmark - generate events
-------------------------------------------------------------------------------
...............................................................................

benchmark name                       samples       iterations    estimated
                                     mean          low mean      high mean
                                     std dev       low std dev   high std dev
-------------------------------------------------------------------------------
Insert 100 events in bimap                     100             1    23.3027 ms
                                        232.676 us    231.027 us    236.056 us
                                        11.5571 us    7.09731 us    21.2504 us

Insert 1000 events in bimap                    100             1    271.095 ms
                                        2.64506 ms    2.61762 ms    2.69205 ms
                                        178.409 us    118.426 us    274.731 us


-------------------------------------------------------------------------------
Benchmark - find right edge event from 100 generated events
-------------------------------------------------------------------------------
...............................................................................

benchmark name                       samples       iterations    estimated
                                     mean          low mean      high mean
                                     std dev       low std dev   high std dev
-------------------------------------------------------------------------------
Find right edge event from 100                                                 
events                                         100             7    11.7411 ms
                                        17.9059 us    17.4566 us    18.5898 us
                                        2.78366 us    1.99979 us    3.74785 us


-------------------------------------------------------------------------------
Benchmark - find right edge event from 1000 generated events
-------------------------------------------------------------------------------
...............................................................................

benchmark name                       samples       iterations    estimated
                                     mean          low mean      high mean
                                     std dev       low std dev   high std dev
-------------------------------------------------------------------------------
Find right edge event from 1000                                                
events                                         100             1    17.3136 ms
                                        172.068 us    171.035 us    175.144 us
                                        8.02896 us     2.1774 us    17.2201 us


-------------------------------------------------------------------------------
Benchmark - find first event from 100 generated events
-------------------------------------------------------------------------------
...............................................................................

benchmark name                       samples       iterations    estimated
                                     mean          low mean      high mean
                                     std dev       low std dev   high std dev
-------------------------------------------------------------------------------
Find first event from 100 events               100             6    11.6112 ms
                                        17.2994 us    17.0419 us    17.7426 us
                                        1.68547 us     1.0898 us    2.46586 us


-------------------------------------------------------------------------------
Benchmark - find first event from 1000 generated events
-------------------------------------------------------------------------------
...............................................................................

benchmark name                       samples       iterations    estimated
                                     mean          low mean      high mean
                                     std dev       low std dev   high std dev
-------------------------------------------------------------------------------
Find first event from 1000 events              100             1    19.9976 ms
                                        197.804 us    189.715 us    209.091 us
                                        48.6428 us    37.9777 us    65.4806 us


-------------------------------------------------------------------------------
Benchmark - find number of events in one sigma from 100 generated events
-------------------------------------------------------------------------------
...............................................................................

benchmark name                       samples       iterations    estimated
                                     mean          low mean      high mean
                                     std dev       low std dev   high std dev
-------------------------------------------------------------------------------
Find number of events in one sigma                                             
from 100 events                                100             9    12.2679 ms
                                        14.4382 us    13.9496 us    15.1776 us
                                        3.00947 us    2.20033 us     3.9583 us


-------------------------------------------------------------------------------
Benchmark - find number of events in one sigma from 1000 generated events
-------------------------------------------------------------------------------
...............................................................................

benchmark name                       samples       iterations    estimated
                                     mean          low mean      high mean
                                     std dev       low std dev   high std dev
-------------------------------------------------------------------------------
Find number of events in one sigma                                             
from 1000 events                               100             1    11.6987 ms
                                        120.549 us    117.615 us    125.295 us
                                        18.6426 us    12.8985 us    26.7438 us

</pre>
