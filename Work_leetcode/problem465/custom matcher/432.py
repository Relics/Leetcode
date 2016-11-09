import collections
import json

def custom_matcher(actual, expect, **kwargs):
    """
    actual is the user input string
    expect is the test data string
    example of implementation of matchExact:
    return actual == expect
    """
    try:
        actual_s = json.loads(actual)
        expect_s = json.loads(expect)
        commands = json.loads(kwargs["test_case"][0])
        params = json.loads(kwargs["test_case"][1])
        counter = collections.Counter()
        for i in xrange(1, len(commands)):
            cmd = commands[i]
            out = actual_s[i]
            exp = expect_s[i]
            if cmd == "inc":
                key = params[i][0]
                counter[key] += 1
            elif cmd == "dec":
                key = params[i][0]
                if key in counter:
                    counter[key] -= 1
            elif cmd == "getMaxKey":
                if out == "" and exp == "":
                    continue
                if out not in counter:
                    return False
                # Assumes expected output is in counter.
                if counter[out] != counter[exp]:
                    return False
            elif cmd == "getMinKey":
                if out == "" and exp == "":
                    continue
                if out not in counter:
                    return False
                # Assumes expected output is in counter.
                if counter[out] != counter[exp]:
                    return False
        return True
    except:
        #raise
        return False