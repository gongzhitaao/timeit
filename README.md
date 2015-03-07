Simple C++ Timeit
=================

This is a simple timer for evaluting the execution time of a piece of
code.  Compatible with C++0x and C++11.

## API ##

- **Timer**()

  Constructor.  Initialize the timer.

- void **reset**()

  Reset the timer.

- double **elapsed**()

  Elapsed time since the initilization of the timer or the last reset,
  in seconds.

## Example ##

```c_cpp
#include <iostream>
#include "timeit.h"

int main()
{
    Timer tmr;
    for (int i = 0; i < 10; ++i) /* empty */;
    double t = tmr.elapsed();
    std::cout << t << std::endl;

    tmr.reset();
    for (int i = 0; i < 10; ++i) /* empty */;
    t = tmr.elapsed();
    std::cout << t << std::endl;
	return 0;
}
```
