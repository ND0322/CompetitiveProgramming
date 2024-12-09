import scipy
import matplotlib.pyplot as plt

"""
Linear Programming

Cost
CO2
Safety 
Time

"""

coeffs = {}
cur = {'Biomass': 0.061453895246881524, 'Coal': 0.2520153393170272, 'Gas': 0.30178834850606095, 'Oil': 0.2217989496154872, 'Nuclear': 0.037743881810364255, 'Hydro': 0.06091804449238565, 'Wind': 0.03340865711813141, 'Solar': 0.023585226244205046, 'Other': 0.00728765764945677}
mp_to_x = {}
cnt = 0

def insert(name, cost, safety, carbon, cap, water):
    coeffs[name] = {"cost" : cost, "safety" : safety, "carbon" : carbon, "cap" : cap, "water" : water}
    global cnt
    mp_to_x[name] = cnt
    cnt+=1
def fixed_budget(budget, energy_total, carbon_weight, safety_weight, renewable_weight, water_weight):

    obj = []
    #death needs to be adjust from TWh to KWh

    #co2 produced, safety, percentage renewable

    for i in coeffs:
        val = coeffs[i]['carbon'] * carbon_weight
        val += safety_weight * coeffs[i]['safety']
        val += water_weight * coeffs[i]['water']

        if(i != 'Coal' and i != 'Gas' and i != 'Oil'):
            val += renewable_weight
        obj.append(val)
        

    lhs = []
    rhs = []

    lhs_eq = []
    rhs_eq = []

    #constraint 1: budget
    #cost * percentage * total energy for each one 
    lhs.append([])
    rhs.append(budget)
    for i in coeffs:
        lhs[-1].append(coeffs[i]["cost"] * energy_total)

    #constraint 2: need to total to 1
    lhs_eq.append([])
    rhs_eq.append(1)
    for i in coeffs:
        lhs_eq[-1].append(1)
    
    #constraint 3: growth cap
    mat = [[0 for i in range(len(coeffs))] for j in range(len(coeffs))]
    cnt = 0
    for source in coeffs:
        mat[cnt][cnt] = 1
        rhs.append(cur[source] + coeffs[source]['cap'])
        cnt+=1

    lhs.extend(mat)

    opt = scipy.optimize.linprog(c=obj, A_ub=lhs, b_ub=rhs, method="revised simplex", A_eq = lhs_eq, b_eq = rhs_eq)

    return opt



def fixed_emissions(budget,energy_total, k, s, r):
    obj = []
    #death needs to be adjust from TWh to KWh

    for i in coeffs:
        val = coeffs[i]['cost'] * k
        val += s * coeffs[i]['safety']

        if(i != 'Coal' and i != 'Gas' and i != 'Oil'):
            val += r
        obj.append(val)
        

    lhs = []
    rhs = []

    lhs_eq = []
    rhs_eq = []

    #constraint 1: CO2 budget
    lhs.append([])
    rhs.append(budget)
    for i in coeffs:
        lhs[-1].append(coeffs[i]["carbon"] * energy_total)

    #constraint 2: need to total to 1
    lhs_eq.append([])
    rhs_eq.append(1)
    for i in coeffs:
        lhs_eq[-1].append(1)
    
    #constraint 3: growth cap
    mat = [[0 for i in range(len(coeffs))] for j in range(len(coeffs))]
    cnt = 0
    for source in coeffs:
        mat[cnt][cnt] = 1
        rhs.append(cur[source] + coeffs[source]['cap'])
        cnt+=1

    lhs.extend(mat)

    opt = scipy.optimize.linprog(c=obj, A_ub=lhs, b_ub=rhs, method="revised simplex", A_eq = lhs_eq, b_eq = rhs_eq)

    return opt
#bar graph for this one
def fixed_percentage(percent, cost_weight, carbon_weight, safety_weight, water_weight):
    obj = []
    #death needs to be adjust from TWh to KWh

    for i in coeffs:
        val = coeffs[i]['cost'] * cost_weight
        val += coeffs[i]['safety'] * safety_weight
        val += coeffs[i]['carbon'] * carbon_weight
        val += coeffs[i]['water'] * water_weight
        obj.append(val)
        

    lhs = []
    rhs = []

    lhs_eq = []
    rhs_eq = []

    #constraint 1: percentage of renewable
    lhs_eq.append([])
    rhs_eq.append(percent)
    for i in coeffs:
        lhs_eq[-1].append(int(i not in {'Coal', 'Gas', 'Oil'}))


    #constraint 2: need to total to 1
    lhs_eq.append([])
    rhs_eq.append(1)
    for i in coeffs:
        lhs_eq[-1].append(1)
    
    #constraint 3: growth cap
    mat = [[0 for i in range(len(coeffs))] for j in range(len(coeffs))]
    cnt = 0
    for source in coeffs:
        mat[cnt][cnt] = 1
        rhs.append(cur[source] + coeffs[source]['cap'])
        cnt+=1

    lhs.extend(mat)

    opt = scipy.optimize.linprog(c=obj, A_ub=lhs, b_ub=rhs, method="revised simplex", A_eq = lhs_eq, b_eq = rhs_eq)
    
    return opt



insert("Coal", 0.0378214826, 24.6, 0.97, .15, 0.6)
insert("Gas", 0.0415, 2.8, 0.44, .15, 0.3)
insert("Oil", 0.21881838074, 18.4, 0.72, .15, 0.1)
insert("Solar",0.0300030003, 0.02, 0.053, .15, 0.05)
insert("Wind", 0.03300330033, 0.04, 0.011, .15, 0.05)
insert("Hydro", 0.05998800239, 1.3, 0.024, .15, 0.2)
insert('Nuclear', 0.24630541871, 0.03, 0.006, .15, 0.2)
insert("Biomass", 0.06199628022, 4.6, .154, .15, 0.3)


def gen_fixed_emissions_graph(energy_total, cost_weight, carbon_weight, safety_weight, water_weight):
    x_graph = []
    y_graph = []
    y_money = []
    y_safety = []
    y_fun = []
    y_water = []

    avg_cost = 0
    avg_carbon = 0
    avg_safety = 0
    avg_water = 0

    for source in coeffs:
        avg_cost += coeffs[source]['cost']
        avg_carbon += coeffs[source]['carbon']
        avg_safety += coeffs[source]['safety']
        avg_water += coeffs[source]['water']

    avg_cost / len(coeffs)
    avg_carbon / len(coeffs)
    avg_safety / len(coeffs)
    avg_water / len(coeffs)

    #put everything on the same order of magnitude
    cost_weight *= avg_cost/avg_safety
    carbon_weight *= avg_carbon/avg_safety
    water_weight *= avg_water/avg_safety


    for i in range(0, 101, 20):
        x_graph.append(str(i) + "%")
        
        res = fixed_percentage(i/100, cost_weight, carbon_weight, safety_weight, water_weight).x
        print(str(i) + "%:", list(map(float, res)))
        sm = 0
        sm_money = 0
        sm_deaths = 0
        sm_water = 0

        for source in coeffs:
            sm += (coeffs[source]['carbon'] * res[mp_to_x[source]] * energy_total) / 1e6
            sm_money += (coeffs[source]['cost'] * res[mp_to_x[source]] * energy_total / 1e8)
            sm_deaths += (coeffs[source]["safety"] * res[mp_to_x[source]] * energy_total / 1e9)
            sm_water += (coeffs[source]['water'] * res[mp_to_x[source]] * energy_total / 1e6)

        y_graph.append(sm)
        y_money.append(sm_money)
        y_safety.append(sm_deaths)
        y_water.append(sm_water)
        y_fun.append(fixed_percentage(i/100, cost_weight, carbon_weight, safety_weight, water_weight).fun)



    plt.subplot(2, 3, 1)
    plt.bar(x_graph, y_graph)
    plt.ylabel("ktCO2")
    plt.xlabel("Percent Green Energy")

    
    plt.subplot(2,3,2)
    plt.bar(x_graph, y_money)
    plt.ylabel("Annual Spending (Tens of Million of Dollars)")
    plt.xlabel("Percent Green Energy")

    plt.subplot(2,3,3)
    plt.bar(x_graph, y_safety)
    plt.ylabel("Annual Deaths")
    plt.xlabel("Percent Green Energy")

    plt.subplot(2,3,4)
    plt.bar(x_graph, y_fun)
    plt.ylabel("Value Function")
    plt.xlabel("Percent Green Energy")

    plt.subplot(2,3,6)
    plt.bar(x_graph, y_water)
    plt.ylabel("Water Consumption")
    plt.xlabel("Percent Green Energy")


    
    


gen_fixed_emissions_graph(4507494849.608232, 0.4, 0.4, 0.05, 0.2)
plt.show()
