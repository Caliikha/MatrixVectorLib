from classes import Matrix2x2, Vector3
import numpy as np
import matplotlib
matplotlib.use('TKAgg')
import matplotlib.pyplot as plt
from mpl_toolkits import mplot3d

slerp_data = open("testgraphing.txt", 'r')

fig = plt.figure()
ax3 = plt.axes(projection='3d')

ax3.set_xlim3d(-1.5,1.5)
ax3.set_ylim3d(-1.5,1.5)
ax3.set_zlim3d(-1.5,1.5)

V1 = Vector3(0, 0, 1)#Vector3(1, 0, 0).unitvector() #black line
V1xline = np.linspace(0, V1.x, 10)
V1yline = np.linspace(0, V1.y, 10)
V1zline = np.linspace(0, V1.z, 10)


V2 = Vector3(0, 1, 0).unitvector().scale(V1.magnitude())#Vector3(0, 1, 0).unitvector() #blue line
V2xline = np.linspace(0, V2.x, 10)
V2yline = np.linspace(0, V2.y, 10)
V2zline = np.linspace(0, V2.z, 10)

Axis = Vector3(1, 0, 0)#V1.crossproduct(V2) #green line
Axis = V1.crossproduct(V2)
Axline = np.linspace(0, Axis.x, 10)
Ayline = np.linspace(0, Axis.y, 10)
Azline = np.linspace(0, Axis.z, 10)

# for computing the formula

theta = np.linspace(0, 10, 50)
#zline = Axis.crossproduct(V1).z*np.cos(theta) - (V1.z + V1.scale(Axis.dotproduct(V1)).z)*np.sin(theta)
#xline = Axis.crossproduct(V1).x*np.cos(theta) - (V1.x + V1.scale(Axis.dotproduct(V1)).x)*np.sin(theta)
#yline = Axis.crossproduct(V1).y*np.cos(theta) - (V1.y + V1.scale(Axis.dotproduct(V1)).y)*np.sin(theta)

#Axis = V1.crossproduct(V2)

#ax3.plot3D(xline, yline, zline, 'red')
ax3.plot3D(V1xline, V1yline, V1zline, 'orange')
ax3.plot3D(V2xline, V2yline, V2zline, 'orange')
ax3.plot3D(Axline, Ayline, Azline, 'orange')
#ax3.plot3D(np.linspace(0,1,10), np.linspace(0,10,100), np.linspace(0,10,100), 'orange')

for line in slerp_data:
    x = np.linspace(0, float(line.split(',')[0]), 5)
    y = np.linspace(0, float(line.split(',')[1]), 5)
    z = np.linspace(0, float(line.split(',')[2]), 5)
    ax3.plot3D(x, y, z, 'r')

#    x = np.linspace(0, float(line.split(',')[0]), 10)
#    y = np.linspace(0, float(line.split(',')[1]), 10)
#    z = np.linspace(0, float(line.split(',')[2]), 10)
#    ax3.plot3D(x, y, z, 'red')
i = 0
#for line in slerp_data:
#    i += 1
#    if (i <= 3):
#        x = np.linspace(0, float(line.split(',')[0]), 5)
#        y = np.linspace(0, float(line.split(',')[1]), 5)
#        z = np.linspace(0, float(line.split(',')[2]), 5)
#        ax3.plot3D(x, y, z, 'r')
#        #ax3.scatter(x, y, z, c='r', marker='.')
#    elif (i > 3):
#        x = np.linspace(0, float(line.split(',')[0]), 5)
#        y = np.linspace(0, float(line.split(',')[1]), 5)
#        z = np.linspace(0, float(line.split(',')[2]), 5)
#        #x = float(line.split(',')[0])
#        #y = float(line.split(',')[1])
#        #z = float(line.split(',')[2])
#        ax3.plot3D(x, y, z, 'b')
#        #ax3.scatter(x, y, z, c='b', marker='.')


#u = np.linspace(0, 2 * np.pi, 13)
#v = np.linspace(0, np.pi, 7)
#
#xuv = 0.97* np.outer(np.cos(u), np.sin(v))
#yuv = 0.97* np.outer(np.sin(u), np.sin(v))
#zuv = 0.97* np.outer(np.ones(np.size(u)), np.cos(v))

#ax3.plot_surface(xuv, yuv, zuv, rstride=1, cstride=1, color='g', shade=0)
#    elif (i > 100):
#        x = float(line.split(',')[0])
#        y = float(line.split(',')[1])
#        z = float(line.split(',')[2])
#        ax3.scatter(x, y, z, c='g', marker='.')
#    elif (i > 50):
#        x = np.linspace(0, float(line.split(',')[0]), 10)
#        y = np.linspace(0, float(line.split(',')[1]), 10)
#        z = np.linspace(0, float(line.split(',')[2]), 10)
#        ax3.plot3D(x, y, z, 'green')


slerp_data.close()

plt.show()


