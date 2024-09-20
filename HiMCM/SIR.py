import numpy as np
import matplotlib.pyplot as plt

def sim(t, spreadRate,recoverRate, sz, startInfected, deathRate, birthRate):

    #curS, curI, curR
    cur = [sz-startInfected, startInfected, 0]

    scale = 0.1

    histS = [cur[0]]
    histI = [cur[1]]
    histR = [cur[2]]

    x = [0]

    popSz = sz

    for i in np.arange(0, t, scale):
        print(cur)
        #delta = spreadRate * cur[1] * cur[0] * scale / sz
        delta = spreadRate * cur[1] * cur[0] * scale / popSz
        rec = recoverRate * cur[1] * scale
        death = [cur[j] * deathRate * scale for j in range(3)]
        x.append(i+scale)

        cur[0] += birthRate*scale - delta
        cur[1] += delta - rec
        cur[2] += rec

        for j in range(3):
            cur[j] -= death[j]
            cur[j] = max(cur[j], 0)
        
        popSz = cur[0] + cur[1] + cur[2]
        histS.append(cur[0])
        histI.append(cur[1])
        histR.append(cur[2])

    print(spreadRate/(deathRate+recoverRate))

    plt.plot(x, histS, label = "S")
    plt.plot(x, histI, label = "I")
    plt.plot(x, histR, label = "R")
    plt.legend()

    plt.show()

#for no birth death stuff these numbers work
#10, 5, 1 100, 1, 0, 0 
#10, 5, 1, 100, 1, 1, 5
sim(1000, 0.25, 0.5, 1000, 10, 0.01, 100)


#spreadRate/(deathRate+recoverRate)


    



    
