import numpy as np

num=4

rhoval=[1,5,10,15,20]
rho=np.zeros((5,num))


print rho
rho[0,:]=[9.76463, 10.0727, 10.1119, 10.1315] #rho=1
rho[1,:]=[2.88724, 2.97743, 2.98872, 2.99436] #rho=5
rho[2,:]=[2.77703, 2.95496, 2.97746, 2.98872 ] #rho=10
rho[3,:]=[2.66949, 2.93259, 2.96622, 2.98309] #rho=15
rho[4,:]=[2.56474, 2.91031, 2.95501, 2.97747] #rho=20
print rho

n=[100,500,1000,2000]
exact=np.ones(num)
exact=3*exact

import matplotlib.pyplot as plt
for i in range(1,5):
    plt.plot(n,rho[i],label ='%s' % rhoval[i] )
plt.plot(n,exact, label="exact")
plt.xlabel('integration points N')
plt.ylabel('$ r $ ')
plt.grid('on')
plt.legend(loc=0)
plt.show()
