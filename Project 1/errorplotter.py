import numpy as np


print "running"
data=["outdata1","outdata2","outdata3","outdata4","outdata5","outdata6","outdata7"]
maxerror=np.zeros(7)
m=np.linspace(1,7,7)
for j in range(0,7):
    f= open("%s"%(data[j]),"r")
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
    maxerror[j]=max(error)

print "plotting"
import matplotlib.pyplot as plt
h=1.0/(10**m)
plt.plot(np.log(h),maxerror,'r')
plt.xlabel('$log_{10}(h)$')
plt.ylabel('$\epsilon$')
plt.grid('on')
plt.title('Comparison of relative error as a function of $log_{10}(h)$ for general alg.')
plt.show()
print 'done'