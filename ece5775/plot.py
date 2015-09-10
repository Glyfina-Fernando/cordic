from matplotlib import pyplot 
import numpy as np
pyplot.plot([5,10,15,20,25,30],[16.200,0.711,0.0058,0.00059,3.9262e-5,1.2949e-6],'r--')

pyplot.plot([5,10,15,20,25,30],[16.200,0.711,0.0058,0.00059,3.926e-5,1.294e-6],'g--')
pyplot.ylabel('error')
pyplot.xlabel('number of iterations')
pyplot.show()

