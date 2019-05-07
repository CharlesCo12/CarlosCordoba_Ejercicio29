from mpl_toolkits.mplot3d import Axes3D

import matplotlib.pyplot as plt
from matplotlib import cm
from matplotlib.ticker import LinearLocator
import numpy as np

fig=plt.figure(figsize=(12,5))
ax=fig.add_subplot(1,2,1,projection='3d')
datos=np.loadtxt('datos.dat')
x=np.arange(0,101,1)
y=np.arange(0,601,1)
x1=np.arange(0,101,1)/100
y1=np.arange(0,601,1)/100

def f(x,y):
    return datos[x,y]

X,Y = np.meshgrid(x,y)
X1,Y1 = np.meshgrid(x1,y1)

surf=ax.plot_surface(Y1,X1,f(Y,X),cmap=cm.coolwarm, linewidth = 0, antialiased =True)

ax.set_xlabel("Tiempo[sg]")
ax.set_ylabel("Posicion[m]")

fig.colorbar(surf,shrink=0.5,aspect=10,label="Desplazamiento[m]",ticks=[-0.75,-0.5,-0.25,0,0.25,0.5,0.75])
ax1=fig.add_subplot(1,2,2)
ax1.plot(x1,datos[0],label='Tiempo Inicial')
ax1.plot(x1,datos[-1],label='Tiempo Final')
ax1.legend()
plt.savefig('plot.png')