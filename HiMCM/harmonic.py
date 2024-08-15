import numpy as np
import matplotlib.pyplot as plt

def simulate(simTime, springConst, mass, dInit, airConst, fricConst):


    d = dInit
    displacement = []
    v = 0
    scale = 0.01
    f = -springConst * d + pow(-1, v >= 0) * (v * v * airConst + mass * 9.81 * fricConst)

    for i in range(1,int(simTime)+1):


        d += v*scale
        v += (f/mass) * scale

        #print(d,v,f)

        displacement.append(d)

        f = -springConst * d + pow(-1, v >= 0) * (v*v*airConst + mass * 9.81*fricConst)

    x = np.array([scale*i for i in range(len(displacement))])
    displacement = np.array(displacement)

    plt.xlabel("Time (s)")
    plt.ylabel("Displacement (m)")
    plt.plot(x, displacement)
    
    plt.show()

simulate(4000, 10, 1,1, 0.1, 0.01)









