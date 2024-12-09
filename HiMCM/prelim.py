import numpy as np
import matplotlib.pyplot as plt
import pandas as pd
import math
import scipy

#consumption is a <string,int> dictionary where the key is the country and the value is the energy consumption
#ci is <string, int> where key is energy type value is carbon intensity
#mixes is <string,<string,int>> where first key is country second key is energy type and value is percentage as a decimal

#unit of consumption is KWh
#unit of carbon intensity is gCO2/KWh

#will convert g of CO2 to kg


#exponential growth do flops 
#plot of fixed energy mix
#Optimistic and Pessimistic graphs of energy mixes 
#do regression of energy efficiency 


#for water use
#proportional to amount of heat
#proportional to amount of power 

def f(mixes, ci, consumption):
    sm = 0
    for country in consumption:
        if(country not in mixes):
            continue
        for source in mixes[country]:
            if(source == "Other"):
                continue
            sm += mixes[country][source] * consumption[country] * ci[source]

    return sm/1000




#stick everything inside a big dataframe and copy specific year into data
def gen_mixes(data):
    res = {}
    for i in data.index:
        country = data['Entity'][i]

        res[country] = {}

        
        res[country]['Coal'] = 0 if math.isnan(data.iloc[:,11][i]) else data.iloc[:,11][i]
        res[country]['Gas'] =  0 if math.isnan(data.iloc[:,10][i]) else data.iloc[:,10][i]
        res[country]['Oil'] =  0 if math.isnan(data.iloc[:,9][i]) else data.iloc[:,9][i]
        res[country]['Nuclear'] =  0 if math.isnan(data.iloc[:,8][i]) else data.iloc[:,8][i]
        res[country]['Hydro'] =  0 if math.isnan(data.iloc[:,7][i]) else data.iloc[:,7][i]
        res[country]['Wind'] =  0 if math.isnan(data.iloc[:,6][i]) else data.iloc[:,6][i]
        res[country]['Solar'] = 0 if math.isnan(data.iloc[:,5][i]) else data.iloc[:,5][i]
        res[country]['Biomass'] = 0 if math.isnan(data.iloc[:,4][i]) else data.iloc[:,4][i]
        res[country]['Other'] = 0 if math.isnan(data.iloc[:,3][i]) else data.iloc[:,3][i]

        tot = 0

        for j in res[country]:
            tot += res[country][j]

        for j in res[country]:
            if(tot != 0):
                res[country][j] = float(res[country][j]/tot)
            else:
                res[country][j] = 0
    
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


def fix_mixes(year):
    data = pd.read_csv("electricity-prod-source-stacked.csv")

    df = data.copy(deep=True)
    df.drop(df.index, inplace=True)

    for i in data.index:
        y = data["Year"][i]

        if(y == year):
            df = df._append(data.iloc[i])

    return df

            



#data is a pd dataframe from top500
def gen_consumption(data):
    res = {}

    #tot is total entries for each country
    tot = {}

    #cnt is valid entries for each country
    cnt = {}

    for i in data.index:
        country = data['Country'][i]

        if(country in tot):
            tot[country]+=1
        else: 
            tot[country] = 1
        if(math.isnan(data['Energy Efficiency'][i])):
            continue

        if(country in cnt):
            cnt[country]+=1
        else: 
            cnt[country] = 1
        

        if(country in res):
            res[country] += data['RMax'][i]  / data['Energy Efficiency'][i]
        else:
            res[country] = data['RMax'][i] / data['Energy Efficiency'][i]

    for country in res:
        
        res[country] = float((res[country] / cnt[country]) * tot[country] / 1000 * 365.25 * 24)
    
    return res
        

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

    for i in df_f.index:
        if(df_f["Country"][i] == 'Korea, South'):
            df_f["Country"][i] = "South Korea"


    
  

    return df_f


graph_x = []
graph_y = []


for y in range(2011, 2024):
    for m in ['06', '11']:
        if(y == 2011 and m == '06'):
            continue
  
        graph_x.append(str(y) + '-' + m)
        data = readTop500(y, m)

        graph_y.append(f(gen_mixes(fix_mixes(y)), gen_ci(y), gen_consumption(data))/1e6)

        if(y == 2023 and m == '11'):
            print(graph_y[-1])

#print(graph_y)
plt.plot(graph_x, graph_y)
plt.xticks(rotation=45, fontsize = 8)
plt.xlabel("Date")
plt.ylabel("Carbon Footprint(ktCO2)")
plt.grid()
plt.show()

"""
x = [i for i in range(len(graph_x))]
res = scipy.optimize.curve_fit(lambda t,a,b: a*np.exp(b*t),  x,  graph_y,  p0=(4, 0.1))
print(res)
a = res[0][0]
b = res[0][1]

y_line = []



proj_x = []

proj_x = graph_x

for i in range(2024, 2031):
    for j in ['06', '11']:
        proj_x.append(str(i) + '-' + j)

for i in range(len(proj_x)):
    y_line.append(a * math.exp(b*i))


plt.plot(proj_x, y_line, label = 'Fit')

"""


