import matplotlib.pyplot as plt
import numpy as np

f = open('transfer.txt', 'r')

line1 = f.readline()
line2 = f.readline()

data1 = line1.split(",")
data1.pop()

data2 = line2.split(",")
data2.pop()

data1 = np.array(data1)
data2 = np.array(data2)

plt.plot(data1, data2)
  
plt.xlabel('x - axis')
plt.ylabel('y - axis')
  
plt.title('Experimental plotting')
  
plt.show()
f.close()