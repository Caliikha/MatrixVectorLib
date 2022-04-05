from classes import Matrix2x2, Vector3
import numpy as np
import matplotlib
matplotlib.use('TKAgg')
import matplotlib.pyplot as plt
from mpl_toolkits import mplot3d

slerp_data = open("../Simulations/OrbitalSimulation_python.csv", 'r')

fig = plt.figure()
ax3 = plt.axes(projection='3d')

ax3.set_xlim3d(-1.5,1.5)
ax3.set_ylim3d(-1.5,1.5)
ax3.set_zlim3d(-1.5,1.5)

V1 = Vector3(1, 0, 0)#Vector3(1, 0, 0).unitvector() #black line
V1xline = np.linspace(0, V1.x, 10)
V1yline = np.linspace(0, V1.y, 10)
V1zline = np.linspace(0, V1.z, 10)


V2 = Vector3(0, 1, 0).unitvector().scale(V1.magnitude())#Vector3(0, 1, 0).unitvector() #blue line
V2xline = np.linspace(0, V2.x, 10)
V2yline = np.linspace(0, V2.y, 10)
V2zline = np.linspace(0, V2.z, 10)

Axis = Vector3(0, 0, 1)#V1.crossproduct(V2) #green line
Axis = V1.crossproduct(V2)
Axline = np.linspace(0, Axis.x, 10)
Ayline = np.linspace(0, Axis.y, 10)
Azline = np.linspace(0, Axis.z, 10)


theta = np.linspace(0, 10, 50)

ax3.plot3D(V1xline, V1yline, V1zline, 'blue')
ax3.plot3D(V2xline, V2yline, V2zline, 'orange')
ax3.plot3D(Axline, Ayline, Azline, 'green')

i = -2
x1=y1=z1=0

num_planets = 0;
for line in slerp_data:
    i += 1
    if (i == -1):
        num_planets = int(line)

    elif (i % num_planets == 0):
        x = float(line.split(',')[0])
        y = float(line.split(',')[1])
        z = float(line.split(',')[2])
        #ax3.plot3D(np.linspace(0, x, 3), np.linspace(0, y, 3), np.linspace(0, z, 3), 'red')
        ax3.scatter(x, y, z, c='r', marker='.', s=60/2)

    elif (i % num_planets == 1):
        x = float(line.split(',')[0])
        y = float(line.split(',')[1])
        z = float(line.split(',')[2])
        #ax3.plot3D(np.linspace(0, x, 3), np.linspace(0, y, 3), np.linspace(0, z, 3), 'blue')
        ax3.scatter(x, y, z, c='g', marker='.', s=80/2)

    elif (i % num_planets == 2):
        x = float(line.split(',')[0])
        y = float(line.split(',')[1])
        z = float(line.split(',')[2])
        #ax3.plot3D(np.linspace(0, x, 3), np.linspace(0, y, 3), np.linspace(0, z, 3), 'green')
        ax3.scatter(x, y, z, c='b', marker='.', s=120/2)

    elif (i % num_planets == 3):
        x = float(line.split(',')[0])
        y = float(line.split(',')[1])
        z = float(line.split(',')[2])
        #ax3.plot3D(np.linspace(0, x, 3), np.linspace(0, y, 3), np.linspace(0, z, 3), 'red')
        ax3.scatter(x, y, z, c='purple', marker='.', s=180/2)
        
    elif (i % num_planets == 4):
        x = float(line.split(',')[0])
        y = float(line.split(',')[1])
        z = float(line.split(',')[2])
        #ax3.plot3D(np.linspace(0, x, 3), np.linspace(0, y, 3), np.linspace(0, z, 3), 'green')
        ax3.scatter(x, y, z, c='orange', marker='.', s=1000/2)

slerp_data.close()

plt.show()


