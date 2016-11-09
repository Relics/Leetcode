__author__ = 'lichen'

import collections


actual_s = ["null", "null", "null", "null", "8", "null", "-1", "2"]
expect_s = ["null", "null", "null", "null", "8", "null", "8", "-1"]
commands = ["LFUCache", "set", "set", "set", "get", "set", "get", "get"]
params = [[2], [2, 1], [2, 2], [3, 8], [3], [4, 4], [3], [2]]

counter = collections.Counter()
for i in xrange(1, len(commands)):
    cmd = commands[i]
    out = actual_s[i]
    exp = expect_s[i]
    key = params[i][0]
    if cmd == "set":
        counter[key] += 1
        if out != exp:
            print("false")

    elif cmd == "get":
        if out == '-1' and exp == '-1':
            continue

        if out != '-1' and exp != '-1':
            if out == exp:
                counter[key] += 1
                continue
            else:
                print("false1")

        if out == '-1':
            if counter.most_common()[-2][1] != counter[key]:
                print("false3")
            del counter[key]

        if out != '-1':
            if key not in counter:
                print("false4")

print("true")

