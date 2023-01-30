import matplotlib.pyplot as plt
import numpy as np
from scipy.interpolate import make_interp_spline

f = open('transfer.txt', 'r')

line1 = f.readline()
line2 = f.readline()

data1 = line1.split(",")
data1.pop()

data2 = line2.split(",")
data2.pop()

data1 = list(map(float, data1))
data2 = list(map(float, data2))

data1 = np.array(data1)
data2 = np.array(data2)

X_Y_Spline = make_interp_spline(data1, data2)
X_ = np.linspace(data1.min(), data1.max(), 500)
Y_ = X_Y_Spline(X_)

plt.plot(X_, Y_)
  
plt.xlabel('x - axis (radius)')
plt.ylabel('y - axis (electric-field)')
  
plt.title('Experimental graph plotting')
  
plt.show()
f.close()