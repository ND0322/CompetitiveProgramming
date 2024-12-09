import numpy as np
import matplotlib.pyplot as plt
import pandas as pd
import math
import scipy

def gen_mix(year):

    sheet = pd.read_csv("global-energy-substitution.csv")

    data = sheet.copy(deep=True)
    data.drop(data.index, inplace=True)

    for i in sheet.index:
        y = sheet["Year"][i]

        if(y == year):
            data = data._append(sheet.iloc[i])
    res = {}
    for i in data.index:
        
        res['Biomass'] = 0 if math.isnan(data.iloc[:,4][i]) else data.iloc[:,12][i]
        res['Coal'] = 0 if math.isnan(data.iloc[:,11][i]) else data.iloc[:,11][i]
        res['Gas'] =  0 if math.isnan(data.iloc[:,10][i]) else data.iloc[:,10][i]
        res['Oil'] =  0 if math.isnan(data.iloc[:,9][i]) else data.iloc[:,9][i]
        res['Nuclear'] =  0 if math.isnan(data.iloc[:,8][i]) else data.iloc[:,8][i]
        res['Hydro'] =  0 if math.isnan(data.iloc[:,7][i]) else data.iloc[:,7][i]
        res['Wind'] =  0 if math.isnan(data.iloc[:,6][i]) else data.iloc[:,6][i]
        res['Solar'] = 0 if math.isnan(data.iloc[:,5][i]) else data.iloc[:,5][i]
        res['Other'] = 0 if math.isnan(data.iloc[:,3][i]) else data.iloc[:,3][i] + 0 if math.isnan(data.iloc[:,4][i]) else data.iloc[:,4][i]

        tot = 0

        for j in res:
            tot += res[j]

        for j in res:
            if(tot != 0):
                res[j] = float(res[j]/tot)
            else:
                res[j] = 0
    
  
    return res
        
def gen_ci(year):
    res = {}
    res['Coal'] = 1000-5*(year-1900)
    res['Oil'] = 950 - 3.5 * (year - 1900)
    res['Gas'] = 600 * math.exp(-.003 * (year - 1950))
    res['Nuclear'] = 15
    res['Hydro'] = 5 + 0.01 * (year - 1900)
    res['Wind'] = 30 * math.exp(-.02 * (year - 1980))
    res['Solar'] = 200 * math.exp(-.04 * (year - 1990))
    res['Biomass'] = 300 - 1.25 * (year - 1950)

    return res

def gen_RMax(year):
    x = (year - 2011) * 2

    #obtained from exponential regression
    #unit is GFlops/s
    a = 117925799.926915
    b = 0.16851734625793385

    return a * math.exp(b * x)


def gen_efficiency(year):
    x = (year - 2011) * 2

    #obtained from exponential regression
    #unit is GFlop/Watt
    a = 0.36204082152511025
    b = 0.14949391746282728

    return a * math.exp(b * x)


def f(RMax, efficiency, ci, mix):
    sm = 0
    tot = RMax/efficiency * 365.25 * 24 / 1000
    #tot is sum of energy in KWh
    for source in mix:
            if(source == "Other"):
                continue
            sm += mix[source] * tot * ci[source]
    
    return sm/1000

#print("ktCO2: ", f(gen_RMax(2023), gen_efficiency(2023), gen_ci(2023), gen_mix(2023)) / 1e6)

#print(gen_RMax(2023) / gen_efficiency(2023) * 365.25 * 24/ 1000)
x_graph = []
y_graph = []
for i in range(2011, 2031):
    x_graph.append(str(i))
    if(i <= 2023):
        y_graph.append(f(gen_RMax(i), gen_efficiency(i), gen_ci(i), gen_mix(i)) / 1e6)
    else:
        y_graph.append(f(gen_RMax(i), gen_efficiency(i), gen_ci(i), gen_mix(2023))/1e6)

x_opt = []
y_opt = []
opt_mix = gen_mix(2023)


for i in range(2011, 2031):
    x_opt.append(str(i))
    if(i <= 2023):
        y_opt.append(f(gen_RMax(i), gen_efficiency(i), gen_ci(i), gen_mix(i)) / 1e6)
    else:
        y_opt.append(f(gen_RMax(i), gen_efficiency(i), gen_ci(i), opt_mix)/1e6)
        opt_mix["Hydro"] += 0.02 * opt_mix['Coal']
        opt_mix["Hydro"] += 0.02 * opt_mix['Oil']
        opt_mix["Hydro"] += 0.02 * opt_mix['Gas']

        opt_mix['Coal'] -= 0.02 * opt_mix['Coal']
        opt_mix['Oil'] -= 0.02 * opt_mix['Oil']
        opt_mix['Gas'] -= 0.02 * opt_mix['Gas']

        
plt.plot(x_opt, y_opt, label = "Optimistic")

plt.plot(x_graph, y_graph, label = "Pessimistic")

plt.xticks(rotation=45, fontsize = 8)
plt.yticks(np.arange(1200, 2200, step=100))
plt.xlabel("Year")
plt.ylabel("ktCO2")
plt.title("Year Vs. Carbon Fooprint")
plt.grid()
plt.legend(loc='upper left')

plt.show()
        
