from ast2000solarsystemviewer_v2  import AST2000SolarSystemViewer
import numpy as np
seed = 78858
system = AST2000SolarSystemViewer(seed)

a=1
def rho(h):
    return p0*np.exp(-h/float(hscale))

def Fdrag(p,v,A):
    speed=np.linalg.norm(v)
    return -v*.5*p*A*speed
    
def grav(r):
    return -G*mp*ml*r/float(np.linalg.norm(r))**3

planetsradius=system.radius #Radiuses of planet, [km]
planetsmass=system.mass #Mass of planets, solar masses]
rho0 = system.rho0 # Atmospheric density at surface [kg/m^3]
G=6.67408*10**(-11) #Gravitational constant [m^3/(s^2 kg)]

rp=planetsradius[0]*10**3 #radius of planet[m]
mp=planetsmass[0]*1.9891*10**30 #mass of planet [kg]
p0=rho0[0] #surface density of planet [kg/m^3]

g=G*mp/float(rp)**2 #gravitational constant for planet at surface
hscale=75200/g 
ml=100 #mass of lander [kg]
h_init=40000*10**3  

A=220 #Area of lander
theta=np.pi/2.51 #entry angle to vertical plane [rad] /kullosning 1635 np.pi/2.5
v_0=1635 #initial speed [m/s] 1635 /kullosning 1635
dt=1 #time step

pos=np.asarray([[0,h_init+rp]])
vel=np.asarray([[v_0*np.sin(theta),-v_0*np.cos(theta)]])


h=np.linalg.norm(pos[-1])-rp
intact=1;iteration=0;breakpoint=0;times=np.asarray([0])
while h>0:
    p=rho(h)
    F=Fdrag(p,vel[-1],A)
    Gr=grav(pos[-1])
    a=(F+Gr)/float(ml)
    vel=np.vstack((vel,vel[-1]+a*dt))
    pos=np.vstack((pos,pos[-1]+vel[-1]*dt))
    times=np.vstack((times,times[-1]+dt))
    iteration+=1
    h=np.linalg.norm(pos[-1])-rp
    if np.linalg.norm(F)>25000:
        intact=0
        breakpoint=iteration
    if h>h_init:
        break
vinkel=np.linspace(0,2*np.pi)
vr=abs(np.dot(pos[-1]/np.linalg.norm(pos[-1]),vel[-1]))

if intact==0:
    intact='$Lander$ $ikke$ $intakt$'
else:
    intact='$Lander$ $intakt$'
    
import matplotlib.pyplot as plt
plt.plot(rp*np.cos(vinkel),rp*np.sin(vinkel))
plt.plot(pos[:,0],pos[:,1])
plt.title(""""$A=%g$, $v_0=%g$, $vinkel =%g$ 
$[rad]$, $v_r=%g$, %s"""%(A,v_0,theta,vr,intact))
plt.axis('equal')
plt.grid(True)
plt.ylabel('$y [m]$')
plt.xlabel('$x [m] $')
if breakpoint>0:
    plt.scatter(pos[breakpoint,0],pos[breakpoint,1])
plt.show()

"""
temrinal>1b8JN.py

"""