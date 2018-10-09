import numpy as np

num=3

rhoval=[3,4,5,6]
rho=np.zeros((4,num))


print rho
rho[0,:]=[3.00864,3.00981,3.0104 ] #rho=3
rho[1,:]=[2.99551,2.99702,2.99777] #rho=4
rho[2,:]=[2.99436,2.99624,2.99718] #rho=5
rho[3,:]=[2.99323,2.99549,2.99662] #rho=6
print rho

n=[2000,3000,4000]
exact=np.ones(num)
exact=3*exact

import matplotlib.pyplot as plt
for i in range(0,4):
    plt.plot(n,rho[i],label ='%s' % rhoval[i] )
plt.plot(n,exact, label="exact")
plt.xlabel('integration points N')
plt.ylabel('$ r $ ')
plt.grid('on')
plt.legend(loc=0)
plt.show()
