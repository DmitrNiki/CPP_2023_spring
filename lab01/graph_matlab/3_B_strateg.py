import matplotlib.pyplot as plt

plt.plot([3000, 5000, 8000, 12000, 20000, 30000, 50000, 70000, 90000, 110000, 130000, 140000, 145000, 150000, 160000],
         [5.06, 14.57, 59, 85.54, 226.8, 555.2, 1033.77, 1516.6, 1889, 2309.8, 2657.6, 2886.6, 2986.2, 3079.4, 3232.8], 'bs')
plt.suptitle('T(N), strateg_B', fontsize=14, fontweight='bold')
plt.ylabel('T, ms')
plt.xlabel('N')
plt.show()
