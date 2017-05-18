## Background
More and more new problems need custom data structures. Previously, we need to write serializer/deserializer code for each structure and also for each language. But in fact, most of these data structures are not very common, and even some structures only appear in a certain problem. Serializer/deserializer is complex for new users to write. It's very time consuming and inconvenient for users to add new problems. So supporting custom data structure without manually write serializer/deserializer code when adding new problems is very meaningful.

This doc will show you how to add new data structure when adding new problems.

## Tutorial
### Applicable situation

The new problem needs a custom data structure, and the data type of each member variable can only be one of the following two.

1.  Basic data type. It already has serializer/deserializer code in the system.
2.  Structure itself. It looks like a pointer(c++) that point to self.

**Attention:**

For now, this feature only supports at most one new data structure in one problem. Actually, it's easy to extend. 

### Applicable language

For now, c++/java/python is available to support custom data structure when adding new problems.

### Step

**Step 1: Define structure in the metadata**

We defined the structure in metadata as json type. If the new problem needs custom structure, we can add a new field named ```structure``` including three properties, ```name```, ```comment```(optional) and ```members```. For each member variable, it including ```name```, ```type``` and ```comment```(optional).

```
"structure": {
  "name":           # Necessary, the name of this structure
  "comment":        # Optional, make comments when the structure be defined
  "members": [      # Necessary, json array, describe each member varaible
    {
      "name":       # Necessary, name for this varaible
      "type":       # Necessary, data type for this varaible
      "comment":    # Optional, make comments for each member varaible
    },
    {
       ...
    },
    ...
  ]
}
```

**Step 2: Generate code definition and driver code**

After generating code definition and driver code, please check the structure definition in the code.

**Step 3: Test cases**

The serialize result should be consistent with the definition order in the metadata. Please find more details in the following example.

**Step 4: Publish**

Generate output format, then publish the new problem.

## Example

In this part, we list an example to describe some details. We copy the same problem as [this one](https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii).

### New structure: TreeLinkNode2

This problem needs a new structure named TreeLinkNode. To avoid naming conflicts, we add a structure named TreeLinkNode2 for testing. 

It includes four fields, an integer value named ```val```, a self-pointer named ```left```, a self-pointer named ```right``` and a self-pointer named ```next```.


### Metadata

As mentioned before, we can add the structure definition using json type in metadata. For this example, the metadata as follows. There are four member variables in ```TreeLinkNode2```. The type of ```val``` is ```integer```, a basic data type which already has serializer/deserializer. The type of ```left```, ```right``` and ```next``` both are structure itself. 

```
{
  "name": "connect",
  "params": [
    {
      "name": "root",
      "type": "TreeLinkNode2"
    }
  ],
  "return": {
    "type": "TreeLinkNode2"
  },
  "structure": {
    "name": "TreeLinkNode2",
    "comment": "TreeLinkNode2",
    "members": [
      {
        "name": "val",
        "type": "integer",
        "comment": "value"
      },
      {
        "name": "left",
        "type": "TreeLinkNode2",
        "comment": "left pointer"
      },
      {
        "name": "right",
        "type": "TreeLinkNode2",
        "comment": "right pointer"
      },
      {
        "name": "next",
        "type": "TreeLinkNode2",
        "comment": "next pointer"
      }
    ]
  }
}
```

### Strcture definition

According to the structure definition in metadata, we can generate the structure in the code. The code displays to users as follows. In addition to the members we defined, there is an extra variable named ```label```, which is the unique id of the node. It can also be regarded as address value which is used to build pointer between different nodes. This extra variable is published to users because it will appear in test cases.
 
```
/*
// TreeLinkNode2
class TreeLinkNode2 {
    // It's the unique id of each node.
    int label;
    // value
    int val;
    // left pointer
    TreeLinkNode2* left;
    // right pointer
    TreeLinkNode2* right;
    // next pointer
    TreeLinkNode2* next;
};
*/
class Solution {
public:
    TreeLinkNode2* connect(TreeLinkNode2* root) {
        
    }
};
```

The real definition in driver code as follows. For each pointer variable, there is a corresponding label value which also represents the pointer's address value. 

```
// TreeLinkNode2
class TreeLinkNode2 {
public:
    int label;
    // value
    int val;
    // left pointer
    TreeLinkNode2* left;int left_label;
    // right pointer
    TreeLinkNode2* right;int right_label;
    // next pointer
    TreeLinkNode2* next;int next_label;

    TreeLinkNode2(int _label,int _val,TreeLinkNode2* _left, int _left_label,TreeLinkNode2* _right, int _right_label,TreeLinkNode2* _next, int _next_label) {
        label = _label;
        val = _val;
        left = _left; left_label = _left_label;
        right = _right; right_label = _right_label;
        next = _next; next_label = _next_label;
    }
};
```

### Serializer/Deserializer

The most valuable thing is that we automatically generated serializer/deserializer. There are two public APIs, ```to${structure.name}``` and ```serialize```. It can be converted between string and structure object.

```
void handleSingleNode(unordered_map<int, TreeLinkNode2*> &nodeMaps, jsmntok_t *tokens, const string &input) {
    int label = __Deserializer__::toInteger(input.substr(tokens[1].start, tokens[1].end - tokens[1].start).c_str());
    int val = __Deserializer__::toInteger(input.substr(tokens[2].start, tokens[2].end - tokens[2].start).c_str());
    int left = __Deserializer__::toInteger(input.substr(tokens[3].start, tokens[3].end - tokens[3].start).c_str());
    int right = __Deserializer__::toInteger(input.substr(tokens[4].start, tokens[4].end - tokens[4].start).c_str());
    int next = __Deserializer__::toInteger(input.substr(tokens[5].start, tokens[5].end - tokens[5].start).c_str());
    TreeLinkNode2* node = new TreeLinkNode2(label, val, NULL, left, NULL, right, NULL, next);
    nodeMaps[label] = node;
}

int getNextNode(jsmntok_t *tokens, int start) {
    int size = tokens[start].size;
    start ++;
    while(size --) {
        start = getNextNode(tokens, start);
    }
    return start;
}
TreeLinkNode2* toTreeLinkNode2(const string &input) {
    char *line = strdup(input.c_str());
    jsmntok_t *tokens = parse_json(line, NULL);
    if(tokens->size == 0) {
        return NULL;
    }
    bool hasPointer = false | true | true | true;
    unordered_map<int, TreeLinkNode2*> nodeMaps;
    int headLabel;
    if(hasPointer) {
        int start = 1;
        int nodeCount = tokens[0].size;
        for(int i = 0; i < nodeCount ; i ++) {
            if(i == 0) {
                headLabel = atoi(line + tokens[start + 1].start);
            }
            handleSingleNode(nodeMaps, tokens + start, input);
            start = getNextNode(tokens, start);
        }
        for(auto const &nodeMap: nodeMaps) {
            int i = nodeMap.first;
            if(nodeMap.second->left_label != -1) {
                nodeMap.second->left = nodeMaps[nodeMap.second->left_label];
            }
            if(nodeMap.second->right_label != -1) {
                nodeMap.second->right = nodeMaps[nodeMap.second->right_label];
            }
            if(nodeMap.second->next_label != -1) {
                nodeMap.second->next = nodeMaps[nodeMap.second->next_label];
            }
        }
    }
    else {
        headLabel = atoi(line + tokens[1].start);
        handleSingleNode(nodeMaps, tokens, input);
    }
    return nodeMaps[headLabel];
}

void collect(TreeLinkNode2* head, map<int, TreeLinkNode2*> &nodeMaps) {
    if (head == NULL) return;
    if (nodeMaps.find(head->label) != nodeMaps.end()) return;
    nodeMaps[head->label] = head;
    head->left_label = head->left == NULL ? -1 : head->left->label;
    collect(head->left, nodeMaps);
    head->right_label = head->right == NULL ? -1 : head->right->label;
    collect(head->right, nodeMaps);
    head->next_label = head->next == NULL ? -1 : head->next->label;
    collect(head->next, nodeMaps);
}

string serialize(TreeLinkNode2* head) {
    if (!head) {
        return "[]";
    }
    map<int, TreeLinkNode2*> nodeMaps;
    collect(head, nodeMaps);
    string buffer = "[";
    bool isFirst = true;
    for (auto const &nodeMap : nodeMaps) {
        if(!isFirst) {
            buffer += ",";
        }
        isFirst = false;
        string label = __Serializer__::serialize(nodeMap.first);
        buffer += "[" + label;
        TreeLinkNode2* node = nodeMap.second;
        string val = __Serializer__::serialize(node->val);
        buffer += "," + val;
        string left = __Serializer__::serialize(node->left_label);
        buffer += "," + left;
        string right = __Serializer__::serialize(node->right_label);
        buffer += "," + right;
        string next = __Serializer__::serialize(node->next_label);
        buffer += "," + next;
        buffer += "]";
    }
    buffer += "]";
    return buffer;
}
```

### Testcases

The structure will be serialized according to the definition order in the metadata. So the test cases should be consistent with the definition order. In this example, the member variable was defined in order of ```val```, ```left```, ```right``` and ```next```. And we add an extra field ```label``` which always in the first place. So the order in test cases should be ```[label, val, left, right, next]```. For the null value of a pointer, the value should be -1.

There are two samples of test cases.  

```
[[1,1,2,3,-1],[2,2,4,-1,-1],[3,3,5,-1,-1],[4,4,-1,-1,-1],[5,5,-1,-1,-1]]

[[1,1,2,3,-1],[2,2,4,5,-1],[3,3,6,7,-1],[4,4,-1,-1,-1],[5,5,-1,-1,-1],[6,6,-1,-1,-1],[7,7,-1,-1,-1]]
```
The first test data represents the following structdure.

```
         1
        / \
       2   3
      /    /
     4    5
```
The second test data represents the following structdure.

```
         1
        / \
       2   3
      / \ / \
     4  5 6  7 
```
