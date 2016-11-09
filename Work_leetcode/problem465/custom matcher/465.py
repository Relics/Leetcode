import collections
import json

# add custom matcher here
def custom_matcher(actual, expect, **kwargs):
    """
    actual is the user input string
    expect is the test data string
    example of implementation of matchExact:
    return actual == expect
    """
    try:
        #actual_s = json.loads(actual)
        #expect_s = json.loads(expect)
        #commands = json.loads(kwargs["test_case"][0])
        #params = json.loads(kwargs["test_case"][1])

        actual_s = ["null","null","null","null","8","null","-1","2"]
        expect_s = ["null","null","null","null","8","null","8","-1"]
        commands = ["LFUCache","set","set","set","get","set","get","get"]
        params = [[2],[2,1],[2,2],[3,8],[3],[4,4],[3],[2]]

        counter = collections.Counter()
        for i in xrange(1, len(commands)):
            cmd = commands[i]
            out = actual_s[i]
            exp = expect_s[i]
            key = params[i][0]
            if cmd == "set":
                counter[key] += 1
                if out != exp:
                    return False

            elif cmd == "get":
                # Both -1
                if out == '-1' and exp == '-1':
                    continue

                # Both not -1
                if out != '-1' and exp != '-1':
                    if out == exp:
                        counter[key] += 1
                        continue
                    else:
                        return False

                # When out is not -1
                if out != '-1':
                    if counter.most_common()[-1][1] != counter[key]:
                        return False
                    counter[key] += 1
                    continue

                # When out is -1
                if not out == '-1':
                    if counter.most_common()[-1][1] != counter[key]:
                        return False
                    del counter[key]

        return True
    except:
        raise
        return False

custom_matcher("", "")