import matplotlib.pyplot as plt

plt.plot([512,
          1024,
          2048,
          4096,
          6144,
          8192,
          10000,
          12000,
          15000,
          18000,
          20000
          ],
         [2,
          11,
          40,
          171,
          359,
          634,
          939,
          1364,
          2516,
          3639,
          4617
          ])
plt.suptitle('T(N), sum1', fontsize=14, fontweight='bold')
plt.ylabel('T, ms')
plt.xlabel('N')
plt.show()
