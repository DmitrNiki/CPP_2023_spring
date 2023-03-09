import matplotlib.pyplot as plt

plt.plot([3000, 5000, 8000, 12000, 20000, 30000, 50000, 70000, 90000, 110000, 130000, 140000, 145000, 150000, 160000],
         [23.92, 64.93, 180, 369.36, 947.7, 2366.8, 3888.53, 5019, 5974.5, 6952.2, 7523.2, 7875.2, 8094.8, 8252.2, 8460.4], 'bs')
plt.suptitle('T(N), strateg_C', fontsize=14, fontweight='bold')
plt.ylabel('T, ms')
plt.xlabel('N')
plt.show()