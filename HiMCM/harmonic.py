import numpy as np
import matplotlib.pyplot as plt

def simulate(simTime, springConst, mass, dInit, airConst, fricConst):


    d = dInit
    displacement = []
    v = 0
    scale = 0.01
    f = -springConst * d + pow(-1, v >= 0) * (mass * 9.81 * fricConst + v * v * airConst)

    for i in range(1,int(simTime)+1):


        d += v*scale
        v += (f/mass) * scale

        #print(d,v,f)

        displacement.append(d)

        f = -springConst * d + pow(-1, v >= 0) * (mass * 9.81*fricConst + v*v*airConst)

        

    x = np.array([scale*i for i in range(len(displacement))])

    peak = []

    for i in range(1,len(x)-1):
        if(displacement[i] > displacement[i-1] and displacement[i] > displacement[i+1]):
            peak.append((displacement[i], i))

    trough = []

    for i in range(1,len(x)-1):
        if(displacement[i] < displacement[i-1] and displacement[i] < displacement[i+1]):
            trough.append((displacement[i], i))

    print(peak)
    print(trough)



    displacement = np.array(displacement)

    plt.xlabel("Time (s)")
    plt.ylabel("Displacement (m)")

    #px = [peak[i][1] for i in range(len(peak))]
    #py = [peak[i][0] for i in range(len(peak))]
    plt.plot(x, displacement)
    
    plt.show()

simulate(4000, 10, 1,1, 0.1, 0.01)









