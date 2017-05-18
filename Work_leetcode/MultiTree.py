import json


class TreeNode(object):
    # TreeNode val is an integer

    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

    @staticmethod
    def _array_to_tree_node(tokens):
        if not tokens:
            return None
        n = len(tokens)
        root = TreeNode(tokens[0])
        que = [root]
        head = 0
        for i in range(1, n, 2):
            if tokens[i] is not None:
                node = TreeNode(tokens[i])
                que[head].left = node
                que.append(node)
            if i + 1 < n and tokens[i + 1] is not None:
                node = TreeNode(tokens[i + 1])
                que[head].right = node
                que.append(node)
            head += 1
        return root

    @staticmethod
    def deserialize(s):
        tokens = json.loads(s)
        return TreeNode._array_to_tree_node(tokens)

    @staticmethod
    def serialize(root):
        que = [root]
        head = 0
        s = ""
        comma = ""
        while (head < len(que)):
            if que[head] is None:
                s += comma + "null"
            else:
                s += comma + str(que[head].val)
                que.append(que[head].left)
                que.append(que[head].right)
            comma = ","
            head += 1
        # Delete trailing ",null" suffix.
        while s[-1] == "l":
            s = s[:-5]
        return "[%s]" % s