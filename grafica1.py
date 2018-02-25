import matplotlib.pyplot as plt
import numpy as np
fig = plt.figure()
ax = fig.add_subplot(111)
datos = [7.874, 13.743, 24.289, 40.064]
dimension = ["200", "300", "400", "500"]
xx = range(len(datos))
ax.bar(xx, datos, width = 0.5, align = "center")
ax.set_xticks(xx)
ax.set_xticklabels(dimension)
ax.set_xlabel("Tamaño del problema")
ax.set_ylabel("Tiempo(s)")
plt.title("Tamaños de entrada diferentes")

plt.plot(datos, color ='b', label = "Tiempos")
plt.legend(loc="upper left")

plt.show()
