import numpy as np

N = 100
R = 10000
R_range = range(R)
size = (N, 3)
C = np.zeros((N, 3))
k = 1
print ("100")
print ("STEP: ", k)
for i in range(N):
	print ("He ", C[i, 0], " ", C[i, 1], " ", C[i, 2])
k += 1

for j in range(R):
	A = np.random.uniform(-1, 1, size)
	B = np.sum(np.multiply(A, A), axis=1)
	B = np.sqrt(B)
	B = B.reshape(N, 1)
	Norm_A = A / B
	C += Norm_A
	if j % 10 == 0:
		print ("100")
		print ("STEP: ", k)
		for i in range(N):
			print ("He ", C[i, 0], " ", C[i, 1], " ", C[i, 2])
		k += 1