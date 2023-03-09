import matplotlib.pyplot as plt

plt.plot([512, 4096, 10000, 20000, 30000, 50000, 75000, 100000, 150000, 200000, 250000, 300000, 350000, 400000, 500000],
         [1, 20, 53, 107, 151, 244, 372, 493, 711, 964, 1247, 1480, 1792, 2106, 2443])
plt.suptitle('T(N), lin_search', fontsize=14, fontweight='bold')
plt.ylabel('T, ms')
plt.xlabel('N')
plt.show()