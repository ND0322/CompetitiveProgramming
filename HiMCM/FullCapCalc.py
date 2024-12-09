import pandas as pd
import math

path = "top500/TOP500_202406.xlsx"


sheet = pd.read_excel(path)



sm = 0
cnt = 0
for i in sheet.index:
    if(math.isnan(sheet['Energy Efficiency [GFlops/Watts]'][i])):
        continue
    cnt += 1
    sm += sheet['Rmax [TFlop/s]'][i] * 1000 / sheet['Energy Efficiency [GFlops/Watts]'][i]

sm /= 1000

Eavg = sm/cnt

print("Avg Full Capacity kW: ", Eavg)
print("Extrapolated Total Full Capacity kW", Eavg * 500)

print("Avg Full Capacity tWh: ", Eavg * 365.25 * 24 / 1e9)
print("Extrapolated Total Full Capacity tWh: ", Eavg * 500 * 365.25 * 24 / 1e9)

