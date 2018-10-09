import numpy as np

num=7

n=[3,7,11,15,19]



rho4=[2.99822,7.00065,11.075,15.5809,21.0566]
rho6=[2.99729,6.99594,10.9949,14.9941,18.9934]
rho8=[2.99639,6.99458,10.9932,14.9921,18.9911]

rooh=[2.99831,6.99746,10.9968,14.9963,18.9959]

rho4=np.asarray(rho4)
rho6=np.asarray(rho6)
rho8=np.asarray(rho8)
rooh=np.asarray(rooh)

n=np.asarray(n)

abserr4=abs(rho4-n)
abserr6=abs(rho6-n)
abserr8=abs(rho8-n)
absroh=abs(rooh-n)

print absroh

print "%g"%abserr4[0]
print "%g"%abserr6[0]
print "%g"%abserr8[0]


import matplotlib.pyplot as plt
plt.plot(n,abserr4, label="r=4")
plt.plot(n,abserr6, label="r=6")
plt.plot(n,abserr8, label="r=8")
plt.xlabel('$\lambda $')
plt.ylabel('$ r $ ')
plt.xticks(n, n)
plt.grid('on')
plt.legend(loc=0)
plt.show()
