import numpy as np
import matplotlib.pyplot as plt

N = 100000
R = 100
R_range = range(R)
size = (R, 3)

R_values = [0 for a in range(R)]
for j in range(N):
	A = np.random.uniform(-1, 1, size)
	B = np.sum(np.multiply(A, A), axis=1)
	B = np.sqrt(B)
	B = B.reshape(R, 1)
	Norm_A = A / B
	Final_pos = np.sum(Norm_A, axis=0)
	Magnitude_Final_pos = int(np.sqrt(np.sum(np.multiply(Final_pos, Final_pos))))
	R_values[Magnitude_Final_pos] += 1
fig = plt.figure()
ax = fig.add_subplot(111)
ax.plot(R_range, R_values, color='lightblue', linewidth=3)
#ax.scatter(R_range, R_values, color='red', marker='+', linewidth=3)
plt.xlabel('Radius')
plt.ylabel('No. of Walkers')
plt.show()
