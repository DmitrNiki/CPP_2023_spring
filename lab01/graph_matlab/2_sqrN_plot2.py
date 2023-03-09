import matplotlib.pyplot as plt

plt.plot([512,
          1024,
          2048,
          4096,
          10000,
          30000,
          50000,
          100000,
          150000,
          200000,
          250000,
          300000,
          400000,
          500000
          ],
         [1,
          2,
          5,
          9,
          23,
          73,
          138,
          277,
          412,
          566,
          704,
          860,
          1122,
          1422
          ])
plt.suptitle('T(N), sum1', fontsize=14, fontweight='bold')
plt.ylabel('T, ms')
plt.xlabel('N')
plt.show()
