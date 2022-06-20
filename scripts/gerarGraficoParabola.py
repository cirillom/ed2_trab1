import matplotlib.pyplot as plt
import numpy as np
import pandas as pd


df = pd.read_csv(input("arquivo: "))

df.plot(x="n", y="t", kind="scatter")

first = int(df.iloc[0,0])
last = int(df.iloc[-1,0])+2

pol = np.polyfit(df["n"], df["t"], 2)
x = np.array([i for i in range(first, last)])
y = (lambda i: pol[0]*i**2+pol[1]*i+pol[2])(x)

print(f"{pol[0]:.10f}*x^2 + {pol[1]:.4f}*x + {pol[2]:.4f}")
plt.plot(x, y)

plt.xlabel("Elementos")
plt.ylabel("Tempo (s)")
plt.grid()
plt.show()
