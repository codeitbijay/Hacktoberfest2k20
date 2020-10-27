from matplotlib import pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
import numpy as np

x = np.array([-0.41, 0.57, 0.07, 0.00, -0.29, -0.32,-0.50,-0.23, -0.23])
y = np.array([4.12, 7.71, 2.36, 9.10, 13.35, 8.13, 7.19, 13.25,13.43])
z = [2.06, 0.84, 1.56, 2.07, 2.36, 1.72, 0.66, 1.25,1.38]

z = [i ** 5 for i in z] # More biggers dots
z = np.array(z)

X, Y = np.meshgrid(x, y)

# Set up a figure twice as tall as it is wide
fig = plt.figure(figsize=plt.figaspect(2.))
fig.suptitle('A tale of 2 subplots')

# First subplot
  # 2D Orion constellation with scatter
ax = fig.add_subplot(2,1,1)

ax.scatter(x, y)
#ax.grid(True)
ax.set_ylabel('Y axis')

# Second subplot
  # 3D Orion constellation with scatter
ax = fig.add_subplot(2,1,2, projection= '3d')

plt.scatter(x,y,z, c='steelblue', marker='o', alpha=0.8)

#ax.plot_trisurf(x, y, z, linewidth=0, antialiased=True)
#ax.set_xlim(f'({min(x)}, {max(x)})')
#ax.set_ylim(f'({min(y)}, {max(y)})')
#ax.set_xlabel('X axis')
#ax.set_ylabel('Y axis')
#ax.set_zlabel('Z axis')

# Render and showing up the graph
plt.show()