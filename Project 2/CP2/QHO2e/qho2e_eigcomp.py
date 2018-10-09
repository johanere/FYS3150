import numpy as np


n=1
eig=np.zeros(n);omeg=np.zeros(n)
eig[0]=4.05665
omeg[0]=1
exact=omeg*(3/2.0)

hbar=6.582119514

m=0.5109989461
be2=1.44


a=hbar**2/(m*be2)

eig=eig*hbar**2/(m*a**2)

 
print 3/2.0*m*a**2/hbar**2



#plotting
#===============================================================================
# 
# import matplotlib.pyplot as plt
# plt.plot(r,x,label='no Coloumb interaction')
# plt.xlabel('$|r_1 - r_2|/r_0$ ')
# plt.ylabel('$|\psi_r |$')
# plt.grid('on')
# plt.title('Comparison of ground states for different values of $\omega_r$ ')
# plt.legend(loc=0)
# plt.show()
#===============================================================================
