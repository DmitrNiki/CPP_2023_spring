import matplotlib.pyplot as plt

plt.plot([4.60517018598809,
          6.21460809842219,
          6.90775527898214,
          9.21034037197618,
          9.90348755253613,
          10.8197782844103,
          11.5129254649702,
          12.4292161968444,
          12.8992198260901,
          13.1223633774043
          ],
         [50, 59, 70, 102, 123, 137, 156, 167, 173, 177], 'bs')
plt.suptitle('T(ln(N)), bin_search', fontsize=14, fontweight='bold')
plt.ylabel('T, ms')
plt.xlabel('ln(N)')
plt.show()
