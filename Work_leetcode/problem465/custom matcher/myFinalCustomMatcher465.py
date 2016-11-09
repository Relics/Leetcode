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
        actual_s = json.loads(actual)
        expect_s = json.loads(expect)
        commands = json.loads(kwargs["test_case"][0])
        params = json.loads(kwargs["test_case"][1])

        counter = collections.Counter()
        hmap = {}
        
        for i in xrange(1, len(commands)):
            cmd = commands[i]
            out = actual_s[i]
            exp = expect_s[i]
            key = params[i][0]
            
            if cmd == "set":
                val = params[i][1]
                counter[key] += 1
                hmap[key] = val
                
            elif cmd == "get":
                if str(out) == "-1" and str(exp) == "-1":
                    continue

                if str(out) != "-1" and str(exp) != "-1":
                    if str(out) == str(exp):
                        counter[key] += 1
                        continue
                    else:
                        return False
                    continue
                    
                if str(out) == "-1":
                    del counter[key]
                    continue
                
                if str(out) != "-1":
                    if key not in counter:
                        return False
                    if hmap[key] != out:
                        return False
        return True
    except:
        raise
        return False