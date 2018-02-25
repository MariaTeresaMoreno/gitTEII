import matplotlib.pyplot as plt
import numpy as np

fig = plt.figure()
ax = fig.add_subplot(111)

datos = [24.516, 8.866, 2.355]
dimension = ["1", "2", "3"]
xx = range(len(datos))

ax.bar(xx, datos, width = 0.5, color = "g", align = "center")
ax.set_xticks(xx)
ax.set_xticklabels(dimension)
ax.set_ylabel("Tiempo(s)")
plt.title("Tamaños de entrada iguales")

plt.plot(datos, color ='g', label = "Tiempos")
plt.legend(loc="upper right")

plt.show()
