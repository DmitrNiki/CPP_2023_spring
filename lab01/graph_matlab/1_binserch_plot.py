import matplotlib.pyplot as plt

plt.plot([100, 500, 1000, 10000, 20000, 50000, 100000, 250000, 400000, 500000],
         [50, 59, 70, 102, 123, 137, 156, 167, 173, 177])
plt.suptitle('T(N), bin_search', fontsize=14, fontweight='bold')
plt.ylabel('T, ms')
plt.xlabel('N')
plt.show()
