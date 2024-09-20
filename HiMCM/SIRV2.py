import numpy as np
import matplotlib.pyplot as plt

def sim(t, spreadRate, recoverRate, sz, startInfected, deathRate, birthRate):
    cur = [sz - startInfected, startInfected, 0]
    scale = 0.1

    histS = [cur[0]]
    histI = [cur[1]]
    histR = [cur[2]]

    x = [0]

    for i in np.arange(0, t, scale):
        S, I, R = cur

        # Calculate the changes
        delta_infected = spreadRate * S * I * scale / sz  # New infections
        recovered = recoverRate * I * scale  # Recoveries
        deaths_S = S * deathRate * scale
        deaths_I = I * deathRate * scale
        deaths_R = R * deathRate * scale

        # Update the populations simultaneously
        newS = S + birthRate * scale - delta_infected - deaths_S
        newI = I + delta_infected - recovered - deaths_I
        newR = R + recovered - deaths_R

        # Ensure populations don't go negative
        cur = [max(newS, 0), max(newI, 0), max(newR, 0)]

        # Record population values
        histS.append(cur[0])
        histI.append(cur[1])
        histR.append(cur[2])

        x.append(i + scale)

    # Plot results
    plt.plot(x, histS, label="S")
    plt.plot(x, histI, label="I")
    plt.plot(x, histR, label="R")
    plt.legend()
    plt.xlabel("Time")
    plt.ylabel("Population")
    plt.show()

sim(100, spreadRate=1.5, recoverRate=0.5, sz=1000, startInfected=10, deathRate=0.01, birthRate=0.01)