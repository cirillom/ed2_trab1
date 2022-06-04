import matplotlib.pyplot as plt
import numpy as np
import pandas as pd


df = pd.read_csv(input("arquivo: "))

df = np.log(df)/np.log(10)
df.plot(x="n", y="t", kind="scatter")

first = int(df.iloc[0,0])
last = int(df.iloc[-1,0])+2

pol = np.polyfit(df["n"], df["t"], 1)
x = np.array([i for i in range(first, last)])
y = (lambda i: pol[0]*i+pol[1])(x)

print(f"{pol[0]:.4f}*x {'+' if pol[1]>0 else '-'} {abs(pol[1]):.4f}")
plt.plot(x, y)


plt.xlabel("log(n)")
plt.ylabel("log(t)")
plt.grid()
plt.show()
