#!/usr/bin/python
def hash_quadratic(key, values):
	h = key % len(values)
	probe = 1
	i = 1
	while(values[h] != None):
		h += (i*i)
		i += 1
		probe += 1
		if h >= len(values):
			h = h - len(values) - 1
	values[h] = key
	return probe

values = [40, 26, 15, 12, 5, 17, None]
probes = hash_quadratic(7, values)
print('Table = ', values)
print('Probes =', probes)

# probes = hash_quadratic(12, values)
# print('Table = ', values)
# print('Probes =', probes)