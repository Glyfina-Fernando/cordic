from matplotlib import pyplot 
import numpy as np
pyplot.plot([5,10,15,20,25,30],[1896,1898,1898,1900,1900,1900],'r--')

pyplot.plot([5,10,15,20,25,30],[2512,2515,2515,2518,2518,2518],'g--')

pyplot.plot([5,10,15,20,25,30],[212,422,632,842,1052,1262],'b--')

pyplot.ylabel('ff,lut,latency')
pyplot.xlabel('number of iterations')
pyplot.show()

