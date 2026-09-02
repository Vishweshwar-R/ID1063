import numpy as np
v1=np.loadtxt('str1.dat',delimiter=' ')
v2=np.loadtxt('str2.dat',delimiter=' ')
dot=v1@v2.T
print("V1:",v1)
print("V2:",v2)
print(dot)
