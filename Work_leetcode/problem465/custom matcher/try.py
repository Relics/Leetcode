__author__ = 'lichen'

import collections


counter = collections.Counter()


counter[1] += 1

counter[2] += 1

counter[1] += 1

counter[2] += 1

counter[1] += 1

counter[123] += 1

counter[-123] += 1

print(counter)
print(counter.most_common()[-1][0])