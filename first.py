import numpy as np
import matplotlib.pyplot as plt

N_MAX = 500
N_values = [1, 2, 5, 10, 25, 50, 75, 100, 175, 250, 375, N_MAX]
P_values = []
x_axis = np.arange(1, N_MAX + 1)
y_axis = np.zeros((N_MAX + 1, 1))

def nCr (n, r):
	return np.math.factorial(n)/(np.math.factorial(r)*np.math.factorial(n-r))

y_axis = [nCr(2*i, i)/4**i for i in range(1, N_MAX + 1)]

for n in N_values:
	N = n
	M = 100000

	walker1 = np.random.rand(M, N)
	walker2 = np.random.rand(M, N)
	walker1 = walker1 < 0.5
	walker2 = walker2 < 0.5
	X = np.sum(walker1, axis=1)
	Y = np.sum(walker2, axis=1)

	prob = X == Y
	res = np.sum(prob)
	P_values.append(res/M)

	print ("Probability for N = ", n," is approximately: ", res/M)

fig = plt.figure()
ax = fig.add_subplot(111)
ax.plot(N_values, P_values, color='lightblue', linewidth=3, label='Computed Value')
ax.plot(x_axis, y_axis, color='red', linewidth=1, alpha=0.7, label='Expected Probability')
#ax.scatter(N_values, P_values, color='darkred', marker='+', label='Computed Value')
#ax.scatter(x_axis, y_axis, color='lightblue', alpha=0.2, marker='s', label='Expected Probability')
plt.legend(loc='upper right')
plt.xlabel('N')
plt.ylabel('Probability')
plt.show()