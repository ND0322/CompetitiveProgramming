import matplotlib.pyplot as plt

# Parameters
springConst = 10.0    # spring constant (N/m)
airConst = 0.1        # air resistance coefficient
fricConst = 0.01      # friction coefficient
mass = 1.0            # mass (kg)
time_steps = 5000     # number of time steps
dt = 0.01             # time step size in seconds

# Initial conditions
d = 1.0               # initial displacement (m)
v = 0.0               # initial velocity (m/s)
displacement = []     # list to store displacement values

# Initial force calculation
f = -springConst * d + pow(-1, v >= 0) * (v * v * airConst + mass * 9.81 * fricConst)

# Simulation loop
for _ in range(time_steps):
    # Update displacement based on current velocity
    d += v * dt
    
    # Update velocity based on current force
    v += (f / mass) * dt
    
    # Print the current state for debugging
    print(f"Displacement: {d:.2f}, Velocity: {v:.2f}, Force: {f:.2f}")
    
    # Store the current displacement
    displacement.append(d)
    
    # Recalculate the force for the next time step
    f = -springConst * d + pow(-1, v >= 0) * (v * v * airConst + mass * 9.81 * fricConst)

# Plotting the displacement over time
time = [dt * i for i in range(time_steps)]
plt.plot(time, displacement)
plt.xlabel('Time (s)')
plt.ylabel('Displacement (m)')
plt.title('Displacement of a Damped Harmonic Oscillator Over Time')
plt.grid(True)
plt.show()