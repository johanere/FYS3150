import numpy as np
f= open("outdata2","r")
if f.mode == 'r':
    lines = f.readlines()
n=len(lines)
x=np.zeros(n)
solution=np.zeros(n)
exact=np.zeros(n)
error=np.zeros(n)

for i in range(len(lines)):
    line=lines[i]
    hold=line.split()
    newx,newsolution,newexact,newerror=hold
    x[i]=float(newx)
    solution[i]=float(newsolution)
    exact[i]=float(newexact)
    error[i]=float(newerror)


n=1000 #set n for plotting
import matplotlib.pyplot as plt
plt.plot(x,solution,'r',label="Numerical solution")
plt.plot(x,exact,'b',label="Analytical solution")
plt.xlabel('x')
plt.ylabel('$u(x)$')
plt.grid('on')
plt.legend(loc=0)
plt.title('Matrix size: $%g x %g$ '%(n,n))
plt.show()

