import numpy as np

import matplotlib.pyplot as plt

outdata=["data1","data2","data3","data4"]

for j in range(len(outdata)):  
    f= open(outdata[j])
    if f.mode == 'r':
        lines = f.readlines()
    n=len(lines)




    n=int(lines[0])
    rmax=float(lines[1])
    omeg=float(lines[2])
    
    
    x=np.zeros(n)
    hold=lines[3].split()
    for i in range(n):
        x[i]=float(hold[i])
    
    r=np.linspace(0,rmax,n)
    x=x*x
    
    x=x/np.linalg.norm(x)    
    plt.plot(r,x,label='%s'%omeg)

#No repulsive:
f= open('ut3k')
if f.mode == 'r':
    lines = f.readlines()
n=len(lines)


#omeg=0
n=int(lines[0])
rmax=float(lines[1])
omeg=float(lines[2])


x=np.zeros(n)
hold=lines[3].split()
for i in range(n):
    x[i]=float(hold[i])

r=np.linspace(0,rmax,n)
x=x*x

x=x/np.linalg.norm(x)    


#plotting

plt.plot(r,x,label='no Coloumb interaction')

    
plt.xlabel('$|r_1 - r_2|/r_0$ ')
plt.ylabel('$|\psi_r |$')
plt.grid('on')
plt.title('Comparison of ground states for different values of $\omega_r$ ')
plt.legend(loc=0)
plt.show()
