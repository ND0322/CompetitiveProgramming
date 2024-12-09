import numpy as np
import matplotlib.pyplot as plt
import pandas as pd
import math
import scipy

def readTop500(y, m):
    file_path = f"top500/TOP500_{y}{m}.xls{'x'*min(1, max(0, y-2019))}"
    df_f = pd.read_excel(file_path, header=1 - min(1, max(0, y - 2007)))

    df_f = df_f.iloc[:500]
    
 
    df_f['Cores'] = df_f['Total Cores']
    if y >= 2017:
        df_f['RMax'] = df_f['Rmax [TFlop/s]'] * 1000 
        df_f['RPeak'] = df_f['Rpeak [TFlop/s]'] * 1000
        df_f['Energy Efficiency'] = df_f.iloc[:,20]

    else:
        df_f['RMax'] = df_f['Rmax'] * (1000 - 999 * min(1, max(0, 2017 - y)))
        df_f['RPeak'] = df_f['Rpeak'] * (1000 - 999 * min(1, max(0, 2017 - y)))
        df_f["Energy Efficiency"] = df_f['Mflops/Watt'] / 1000


    
    return df_f

def gen_consumption(data):
    res = 0
    cnt = 0
    for i in data.index:
        if(math.isnan(data['Energy Efficiency'][i])):
            continue

        cnt += 1

        res += data['Energy Efficiency'][i]

    return res/cnt
        


graph_x = []
graph_y = []


for y in range(2011, 2024):
    for m in ['06', '11']:
        if(y == 2011 and m == '06'):
            continue
  
        graph_x.append(str(y) + '-' + m)
        data = readTop500(y, m)
        graph_y.append(gen_consumption(data))

    



plt.plot(graph_x, graph_y)
plt.xticks(rotation=45, fontsize = 8)

x = [i for i in range(len(graph_x))]

res = scipy.optimize.curve_fit(lambda t,a,b: a*np.exp(b*t),  x,  graph_y,  p0=(4, 0.1))

a = res[0][0]
b = res[0][1]

print(a,b)

proj_x = []
proj_y = []


for i in range(2011, 2031):
    for j in ['06', '11']:
        if(i == 2011 and j == '06'):
            continue

        proj_x.append(str(i) + '-' + j)


for i in range(len(proj_x)):
    proj_y.append(a * math.exp(b * i))


plt.plot(proj_x, proj_y)
plt.xlabel("Date")
plt.ylabel("GFlops/Watt")
plt.show()



