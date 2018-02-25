import matplotlib.pyplot as plt

fig = plt.figure()
ax = fig.add_subplot(111)
datos = [7.874, 13.743, 24.289, 40.064]
dimension = ["200", "300", "400", "500"]
xx = range(len(datos))
ax.barh(xx, datos, width = 0.5, align = "center")
ax.xticks(xx)
ax.xtickslabels(dimension)
ax.setxlabel("Tamaño del problema")
ax.setylabel("Tiempo(s)")
ax.tittle("Tamaños de entrada diferentes")

plt.show()
