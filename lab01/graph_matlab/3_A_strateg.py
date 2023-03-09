import matplotlib.pyplot as plt

plt.plot([3000, 5000, 8000, 12000, 20000, 30000, 50000, 70000, 90000, 110000, 130000, 140000, 145000, 148000, 150000, 160000],
         [5.16, 14.61, 42, 84.93, 223.267, 549.3, 1035.37, 1476, 1891.4, 2357, 2678.8, 2899.6, 2986.2, 3045.8, 3071, 3234.2], 'bs')
plt.suptitle('T(N), strateg_A', fontsize=14, fontweight='bold')
plt.ylabel('T, ms')
plt.xlabel('N')
plt.show()
