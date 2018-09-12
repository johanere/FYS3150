import numpy as np

#variables
n=10**3
h=1/float(n)
hh=h*h
a=np.ones(n+1)
c=np.ones(n+1)
d=np.ones(n+1)
v=np.zeros(n+1)
x=np.zeros(n+1)

a=a*-1.0
c=c*-1.0
d=d*2.0



for i in range(0,n+1):
    x[i]=i*h
    

def f(x):   
    return hh*100*(np.exp(-10.0*x))    
b=f(x)

#correct values
v[0]=v[n]=0.0
a[0]=a[1]=c[0]=d[0]=a[n]=c[n]=c[n-1]=0.0
b[0]=b[n]=0



#fwd subst.
for i in range(2,n):
    m=a[i]/d[i-1]
    d[i]-=m*c[i-1]
    b[i]-=m*b[i-1]
    
print d,b
#bckw subst
v[n-1]=b[n-1]/d[n-1]
for i in range(n-2,0,-1):
    v[i]=(b[i]-c[i-1]*v[i+1])/d[i]
    
#plott the shit
import matplotlib.pyplot as plt
plt.plot(x,v,'b',label="exact")
plt.xlabel('x')
plt.ylabel('$v$')
plt.grid('on')
plt.legend(loc=0)
plt.show()

