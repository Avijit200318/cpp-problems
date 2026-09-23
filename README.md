> 📌 **Note:** This is not my original document. I found this sheet on LeetCode, created and shared by [Alien_me](https://leetcode.com/u/vishalbhagat185/). I am sharing this here purely for educational and learning purposes.

# 🚀 DSA All Pattern-Wise Master Sheet

Comprehensive pattern recognition sheet designed for LeetCode and technical interview preparation. Covers key triggers, boilerplate templates, time complexities, and curated practice problems.

---

## 📌 Table of Contents
1. [Two Pointers](#1-two-pointers-)
2. [Sliding Window (Variable Size)](#2-sliding-window-variable-size-)
3. [Sliding Window (Fixed Size)](#3-sliding-window-fixed-size-)
4. [HashMap / HashSet](#4-hashmap--hashset-)
5. [Prefix Sum](#5-prefix-sum-)
6. [Binary Search](#6-binary-search-)
7. [Two Heap / Heap / Priority Queue](#7-two-heap--heap--priority-queue-)
8. [Monotonic Stack / Stack](#8-monotonic-stack--stack-)
9. [Greedy Algorithm](#9-greedy-algorithm-)
10. [Backtracking](#10-backtracking-)
11. [Dynamic Programming (1D / 2D)](#11-dynamic-programming-1d--2d-)
12. [Matrix / Grid Traversals](#12-matrix--grid-traversals-)
13. [Graph BFS](#13-graph-bfs-)
14. [Graph DFS](#14-graph-dfs-)
15. [Topological Sort (Kahn's Algorithm)](#15-topological-sort-kahns-algorithm-)
16. [Union Find (Disjoint Set Union - DSU)](#16-union-find-disjoint-set-union---dsu-)
17. [Fast & Slow Pointers (Floyd's Cycle Detection)](#17-fast--slow-pointers-floyds-cycle-detection-)
18. [Linked List In-Place Reversal](#18-linked-list-in-place-reversal-)
19. [Tree DFS (Preorder / Inorder / Postorder)](#19-tree-dfs-preorder--inorder--postorder-)
20. [Tree BFS (Level Order Traversal)](#20-tree-bfs-level-order-traversal-)

---

## 1. TWO POINTERS 🟢
- **Core Idea:** Maintain two index pointers (`left` starting at 0, `right` starting at `n - 1`, or both moving forward) to traverse an array or string based on conditions.
- **Recognition Triggers:** Sorted array, searching pairs/triplets with a target sum, reversing/partitioning, comparing from ends.
- **Complexity:** Time: $O(N)$ or $O(N \log N)$ if sorting is needed | Space: $O(1)$

### Boilerplate Template
```cpp
int left = 0, right = nums.size() - 1;
while (left < right) {
    int current_sum = nums[left] + nums[right];
    if (current_sum == target) {
        // Record pair or move both
        left++; right--;
    } else if (current_sum < target) {
        left++;
    } else {
        right--;
    }
}
```

### Key Problems
* [LC 11 — Container With Most Water](https://leetcode.com/problems/container-with-most-water/)
* [LC 15 — 3Sum](https://leetcode.com/problems/3sum/)
* [LC 16 — 3Sum Closest](https://leetcode.com/problems/3sum-closest/)
* [LC 18 — 4Sum](https://leetcode.com/problems/4sum/)
* [LC 167 — Two Sum II - Input Array Is Sorted](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/)
* [LC 881 — Boats to Save People](https://leetcode.com/problems/boats-to-save-people/)
* [LC 2491 — Divide Players Into Teams of Equal Skill](https://leetcode.com/problems/divide-players-into-teams-of-equal-skill/)

---

## 2. SLIDING WINDOW (VARIABLE SIZE) 🟢
- **Core Idea:** Maintain a dynamic window `[left ... right]` that expands to find valid states and shrinks from the left when constraints are violated.
- **Recognition Triggers:** "Longest/Shortest subarray or substring", "At most K distinct elements", contiguous subsegment search.
- **Complexity:** Time: $O(N)$ | Space: $O(K)$ or $O(1)$

### Boilerplate Template
```cpp
int left = 0, max_len = 0;
for (int right = 0; right < nums.size(); right++) {
    // 1. Expand window with right pointer
    add_to_window(nums[right]);
    
    // 2. Shrink window while constraint is violated
    while (is_invalid()) {
        remove_from_window(nums[left]);
        left++;
    }
    
    // 3. Update result
    max_len = max(max_len, right - left + 1);
}
```

### Key Problems
* [LC 3 — Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/)
* [LC 76 — Minimum Window Substring](https://leetcode.com/problems/minimum-window-substring/)
* [LC 209 — Minimum Size Subarray Sum](https://leetcode.com/problems/minimum-size-subarray-sum/)
* [LC 424 — Longest Repeating Character Replacement](https://leetcode.com/problems/longest-repeating-character-replacement/)
* [LC 1004 — Max Consecutive Ones III](https://leetcode.com/problems/max-consecutive-ones-iii/)
* [LC 2958 — Longest Subarray With at Most K Frequency](https://leetcode.com/problems/longest-subarray-with-at-most-k-frequency/)

---

## 3. SLIDING WINDOW (FIXED SIZE) 🟢
- **Core Idea:** Maintain a window of constant length `K`. Move both pointers simultaneously to process sub-ranges of exact length `K`.
- **Recognition Triggers:** Subarray of fixed size `K`, maximum/minimum sum of sub-segment with size `K`.
- **Complexity:** Time: $O(N)$ | Space: $O(1)$

### Boilerplate Template
```cpp
int current_val = 0;
for (int i = 0; i < nums.size(); i++) {
    current_val += nums[i];
    if (i >= k - 1) {
        // Window reached size K
        update_result(current_val);
        current_val -= nums[i - (k - 1)]; // Remove outgoing element
    }
}
```

### Key Problems
* [LC 438 — Find All Anagrams in a String](https://leetcode.com/problems/find-all-anagrams-in-a-string/)
* [LC 567 — Permutation in String](https://leetcode.com/problems/permutation-in-string/)
* [LC 1343 — Number of Sub-arrays of Size K and Average Greater than or Equal to Threshold](https://leetcode.com/problems/number-of-sub-arrays-of-size-k-and-average-greater-than-or-equal-to-threshold/)
* [LC 1456 — Maximum Number of Vowels in a Substring of Given Length](https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/)
* [LC 2461 — Maximum Sum of Distinct Subarrays With Length K](https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k/)

---

## 4. HASHMAP / HASHSET 🟢
- **Core Idea:** Store frequency counts, complements, or seen positions to achieve $O(1)$ search and lookup time.
- **Recognition Triggers:** "Find duplicates", "Frequency count", "Check existence/complement", $O(N)$ time requirement.
- **Complexity:** Time: $O(N)$ | Space: $O(N)$

### Key Problems
* [LC 1 — Two Sum](https://leetcode.com/problems/two-sum/)
* [LC 49 — Group Anagrams](https://leetcode.com/problems/group-anagrams/)
* [LC 128 — Longest Consecutive Sequence](https://leetcode.com/problems/longest-consecutive-sequence/)
* [LC 217 — Contains Duplicate](https://leetcode.com/problems/contains-duplicate/)
* [LC 347 — Top K Frequent Elements](https://leetcode.com/problems/top-k-frequent-elements/)
* [LC 451 — Sort Characters By Frequency](https://leetcode.com/problems/sort-characters-by-frequency/)

---

## 5. PREFIX SUM 🟢
- **Core Idea:** Precompute cumulative sums where `prefix[i] = nums[0] + ... + nums[i]`. Calculate any range sum $[L, R]$ in $O(1)$ time via `prefix[R] - prefix[L - 1]`.
- **Recognition Triggers:** "Subarray sum equals K", range sum queries, divisible subarray sums.
- **Complexity:** Time: $O(N)$ build, $O(1)$ query | Space: $O(N)$

### Boilerplate Template
```cpp
unordered_map<int, int> prefixCount;
prefixCount[0] = 1;
int current_sum = 0, count = 0;

for (int num : nums) {
    current_sum += num;
    if (prefixCount.count(current_sum - k)) {
        count += prefixCount[current_sum - k];
    }
    prefixCount[current_sum]++;
}
```

### Key Problems
* [LC 303 — Range Sum Query - Immutable](https://leetcode.com/problems/range-sum-query-immutable/)
* [LC 523 — Continuous Subarray Sum](https://leetcode.com/problems/continuous-subarray-sum/)
* [LC 525 — Contiguous Array](https://leetcode.com/problems/contiguous-array/)
* [LC 560 — Subarray Sum Equals K](https://leetcode.com/problems/subarray-sum-equals-k/)
* [LC 2270 — Number of Ways to Split Array](https://leetcode.com/problems/number-of-ways-to-split-array/)

---

## 6. BINARY SEARCH 🟢
- **Core Idea:** Halve the search space repeatedly on sorted arrays or monotonic answer spaces.
- **Recognition Triggers:** "Sorted array", "Find min/max value satisfying condition", $O(\log N)$ requirement.
- **Complexity:** Time: $O(\log N)$ or $O(N \log(\text{range}))$ | Space: $O(1)$

### Boilerplate Template
```cpp
int low = min_val, high = max_val, ans = -1;
while (low <= high) {
    int mid = low + (high - low) / 2;
    if (isValid(mid)) {
        ans = mid;
        high = mid - 1; // Try finding smaller valid answer
    } else {
        low = mid + 1;
    }
}
```

### Key Problems
* [LC 33 — Search in Rotated Sorted Array](https://leetcode.com/problems/search-in-rotated-sorted-array/)
* [LC 34 — Find First and Last Position of Element in Sorted Array](https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/)
* [LC 153 — Find Minimum in Rotated Sorted Array](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/)
* [LC 875 — Koko Eating Bananas](https://leetcode.com/problems/koko-eating-bananas/)
* [LC 1011 — Capacity To Ship Packages Within D Days](https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/)

---

## 7. TWO HEAP / HEAP / PRIORITY QUEUE 🟡
- **Core Idea:** Use Max-Heap and Min-Heap structures to track Top-K elements or dynamically find medians.
- **Recognition Triggers:** "Find Median in stream", "Kth largest/smallest element", continuous ordering tracking.
- **Complexity:** Insertion/Deletion: $O(\log N)$ | Peek: $O(1)$

### Key Problems
* [LC 215 — Kth Largest Element in an Array](https://leetcode.com/problems/kth-largest-element-in-an-array/)
* [LC 295 — Find Median from Data Stream](https://leetcode.com/problems/find-median-from-data-stream/)
* [LC 373 — Find K Pairs with Smallest Sums](https://leetcode.com/problems/find-k-pairs-with-smallest-sums/)
* [LC 621 — Task Scheduler](https://leetcode.com/problems/task-scheduler/)
* [LC 973 — K Closest Points to Origin](https://leetcode.com/problems/k-closest-points-to-origin/)

---

## 8. MONOTONIC STACK / STACK 🟡
- **Core Idea:** Maintain a stack with strictly increasing or decreasing elements to find nearest greater/smaller boundaries in $O(N)$.
- **Recognition Triggers:** "Next Greater Element", "Next Smaller Element", balanced parentheses, histogram areas.
- **Complexity:** Time: $O(N)$ | Space: $O(N)$

### Boilerplate Template
```cpp
stack<int> st;
vector<int> nge(n, -1);
for (int i = 0; i < n; i++) {
    while (!st.empty() && nums[st.top()] < nums[i]) {
        nge[st.top()] = nums[i];
        st.pop();
    }
    st.push(i);
}
```

### Key Problems
* [LC 84 — Largest Rectangle in Histogram](https://leetcode.com/problems/largest-rectangle-in-histogram/)
* [LC 150 — Evaluate Reverse Polish Notation](https://leetcode.com/problems/evaluate-reverse-polish-notation/)
* [LC 394 — Decode String](https://leetcode.com/problems/decode-string/)
* [LC 402 — Remove K Digits](https://leetcode.com/problems/remove-k-digits/)
* [LC 739 — Daily Temperatures](https://leetcode.com/problems/daily-temperatures/)
* [LC 901 — Online Stock Span](https://leetcode.com/problems/online-stock-span/)

---

## 9. GREEDY ALGORITHM 🟡
- **Core Idea:** Make locally optimal choices at each step to reach a global optimum without backtracking.
- **Recognition Triggers:** Interval scheduling, activity selection, minimum/maximum operations to reach target.
- **Complexity:** Time: $O(N)$ or $O(N \log N)$ | Space: $O(1)$ or $O(N)$

### Key Problems
* [LC 45 — Jump Game II](https://leetcode.com/problems/jump-game-ii/)
* [LC 55 — Jump Game](https://leetcode.com/problems/jump-game/)
* [LC 134 — Gas Station](https://leetcode.com/problems/gas-station/)
* [LC 435 — Non-overlapping Intervals](https://leetcode.com/problems/non-overlapping-intervals/)
* [LC 605 — Can Place Flowers](https://leetcode.com/problems/can-place-flowers/)
* [LC 763 — Partition Labels](https://leetcode.com/problems/partition-labels/)

---

## 10. BACKTRACKING 🔴
- **Core Idea:** Incrementally build candidate solutions and discard (backtrack) as soon as a candidate cannot lead to a valid final solution.
- **Recognition Triggers:** "Generate all combinations/permutations", "Find all valid configurations/paths", N-Queens.
- **Complexity:** Time: $O(2^N)$ or $O(N!)$ | Space: $O(N)$ call stack

### Boilerplate Template
```cpp
void backtrack(int index, vector<int>& path, vector<vector<int>>& res) {
    if (index == nums.size()) {
        res.push_back(path);
        return;
    }
    // Decision 1: Include
    path.push_back(nums[index]);
    backtrack(index + 1, path, res);
    path.pop_back(); // Undo (Backtrack)

    // Decision 2: Exclude
    backtrack(index + 1, path, res);
}
```

### Key Problems
* [LC 17 — Letter Combinations of a Phone Number](https://leetcode.com/problems/letter-combinations-of-a-phone-number/)
* [LC 22 — Generate Parentheses](https://leetcode.com/problems/generate-parentheses/)
* [LC 39 — Combination Sum](https://leetcode.com/problems/combination-sum/)
* [LC 46 — Permutations](https://leetcode.com/problems/permutations/)
* [LC 78 — Subsets](https://leetcode.com/problems/subsets/)
* [LC 79 — Word Search](https://leetcode.com/problems/word-search/)
* [LC 131 — Palindrome Partitioning](https://leetcode.com/problems/palindrome-partitioning/)

---

## 11. DYNAMIC PROGRAMMING (1D / 2D) 🔴
- **Core Idea:** Break down optimization problems into overlapping subproblems, solving each once and storing results in a DP table (Memoization / Tabulation).
- **Recognition Triggers:** "Count number of ways", "Minimum/Maximum cost to reach state", optimal substructure.
- **Complexity:** Time: $O(\text{States})$ | Space: $O(\text{States})$

### Key Problems
* [LC 62 — Unique Paths](https://leetcode.com/problems/unique-paths/)
* [LC 70 — Climbing Stairs](https://leetcode.com/problems/climbing-stairs/)
* [LC 198 — House Robber](https://leetcode.com/problems/house-robber/)
* [LC 300 — Longest Increasing Subsequence](https://leetcode.com/problems/longest-increasing-subsequence/)
* [LC 322 — Coin Change](https://leetcode.com/problems/coin-change/)
* [LC 1143 — Longest Common Subsequence](https://leetcode.com/problems/longest-common-subsequence/)

---

## 12. MATRIX / GRID TRAVERSALS 🟡
- **Core Idea:** Traverse 2D grids using 4-directional or 8-directional offsets with DFS or BFS.
- **Recognition Triggers:** "Number of islands", "Shortest path in grid", flood fill algorithm.
- **Complexity:** Time: $O(M \times N)$ | Space: $O(M \times N)$

### Boilerplate Directions
```cpp
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool isValid(int r, int c, int rows, int cols) {
    return r >= 0 && r < rows && c >= 0 && c < cols;
}
```

### Key Problems
* [LC 73 — Set Matrix Zeroes](https://leetcode.com/problems/set-matrix-zeroes/)
* [LC 130 — Surrounded Regions](https://leetcode.com/problems/surrounded-regions/)
* [LC 200 — Number of Islands](https://leetcode.com/problems/number-of-islands/)
* [LC 695 — Max Area of Island](https://leetcode.com/problems/max-area-of-island/)
* [LC 994 — Rotting Oranges](https://leetcode.com/problems/rotting-oranges/)

---

## 13. GRAPH BFS 🟡
- **Core Idea:** Level-by-level traversal using a Queue FIFO structure. Computes the unweighted shortest path.
- **Recognition Triggers:** "Shortest path in unweighted graph", level-order traversal, nearest target node.
- **Complexity:** Time: $O(V + E)$ | Space: $O(V)$

### Key Problems
* [LC 127 — Word Ladder](https://leetcode.com/problems/word-ladder/)
* [LC 752 — Open the Lock](https://leetcode.com/problems/open-the-lock/)
* [LC 863 — All Nodes Distance K in Binary Tree](https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/)
* [LC 1091 — Shortest Path in Binary Matrix](https://leetcode.com/problems/shortest-path-in-binary-matrix/)

---

## 14. GRAPH DFS 🟡
- **Core Idea:** Deep traversal along edges before backtracking using Recursion or an explicit Stack.
- **Recognition Triggers:** "Detect cycle", "Find all paths", connected components, topological dependencies.
- **Complexity:** Time: $O(V + E)$ | Space: $O(V)$ call stack

### Key Problems
* [LC 332 — Reconstruct Itinerary](https://leetcode.com/problems/reconstruct-itinerary/)
* [LC 399 — Evaluate Division](https://leetcode.com/problems/evaluate-division/)
* [LC 547 — Number of Provinces](https://leetcode.com/problems/number-of-provinces/)
* [LC 797 — All Paths From Source to Target](https://leetcode.com/problems/all-paths-from-source-to-target/)

---

## 15. TOPOLOGICAL SORT (KAHN'S ALGORITHM) 🔴
- **Core Idea:** Order vertices in a Directed Acyclic Graph (DAG) using In-Degree counts and a Queue.
- **Recognition Triggers:** "Prerequisites", "Task scheduling dependencies", "Detect directed cycle".
- **Complexity:** Time: $O(V + E)$ | Space: $O(V + E)$

### Boilerplate Template
```cpp
vector<int> inDegree(V, 0);
for (auto& edge : edges) inDegree[edge[1]]++;

queue<int> q;
for (int i = 0; i < V; i++) {
    if (inDegree[i] == 0) q.push(i);
}

while (!q.empty()) {
    int node = q.front(); q.pop();
    topoOrder.push_back(node);
    for (int neighbor : adj[node]) {
        inDegree[neighbor]--;
        if (inDegree[neighbor] == 0) q.push(neighbor);
    }
}
```

### Key Problems
* [LC 207 — Course Schedule](https://leetcode.com/problems/course-schedule/)
* [LC 210 — Course Schedule II](https://leetcode.com/problems/course-schedule-ii/)
* [LC 310 — Minimum Height Trees](https://leetcode.com/problems/minimum-height-trees/)
* [LC 1203 — Sort Items by Groups Respecting Dependencies](https://leetcode.com/problems/sort-items-by-groups-respecting-dependencies/)

---

## 16. UNION FIND (DISJOINT SET UNION - DSU) 🔴
- **Core Idea:** Track partitioned non-overlapping sets. Optimized via Path Compression and Rank/Size merging.
- **Recognition Triggers:** Dynamic connectivity, cycle detection in undirected graphs, minimum spanning trees.
- **Complexity:** Time: $O(\alpha(N)) \approx O(1)$ per query | Space: $O(N)$

### Boilerplate Template
```cpp
class DSU {
    vector<int> parent, rank;
public:
    DSU(int n) : parent(n), rank(n, 0) {
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int i) {
        if (parent[i] == i) return i;
        return parent[i] = find(parent[i]); // Path compression
    }
    bool unite(int i, int j) {
        int root_i = find(i), root_j = find(j);
        if (root_i != root_j) {
            if (rank[root_i] < rank[root_j]) swap(root_i, root_j);
            parent[root_j] = root_i;
            if (rank[root_i] == rank[root_j]) rank[root_i]++;
            return true;
        }
        return false; // Cycle detected
    }
};
```

### Key Problems
* [LC 684 — Redundant Connection](https://leetcode.com/problems/redundant-connection/)
* [LC 721 — Accounts Merge](https://leetcode.com/problems/accounts-merge/)
* [LC 990 — Satisfiability of Equality Equations](https://leetcode.com/problems/satisfiability-of-equality-equations/)
* [LC 1319 — Number of Operations to Make Network Connected](https://leetcode.com/problems/number-of-operations-to-make-network-connected/)

---

## 17. FAST & SLOW POINTERS (FLOYD'S CYCLE DETECTION) 🟢
- **Core Idea:** Use two pointers (`slow` moving 1 step, `fast` moving 2 steps) to detect loops or locate midpoints.
- **Recognition Triggers:** "Detect cycle in Linked List", "Find middle of Linked List", "Happy number".
- **Complexity:** Time: $O(N)$ | Space: $O(1)$

### Key Problems
* [LC 141 — Linked List Cycle](https://leetcode.com/problems/linked-list-cycle/)
* [LC 142 — Linked List Cycle II](https://leetcode.com/problems/linked-list-cycle-ii/)
* [LC 202 — Happy Number](https://leetcode.com/problems/happy-number/)
* [LC 234 — Palindrome Linked List](https://leetcode.com/problems/palindrome-linked-list/)
* [LC 876 — Middle of the Linked List](https://leetcode.com/problems/middle-of-the-linked-list/)

---

## 18. LINKED LIST IN-PLACE REVERSAL 🟢
- **Core Idea:** Modify pointers in-place using three pointers (`prev`, `curr`, `next`) without extra heap memory.
- **Recognition Triggers:** "Reverse list", "Reverse sub-list from position L to R", "Reverse in K-groups".
- **Complexity:** Time: $O(N)$ | Space: $O(1)$

### Boilerplate Template
```cpp
ListNode* prev = nullptr;
ListNode* curr = head;
while (curr != nullptr) {
    ListNode* nextTemp = curr->next;
    curr->next = prev;
    prev = curr;
    curr = nextTemp;
}
return prev; // New head
```

### Key Problems
* [LC 25 — Reverse Nodes in k-Group](https://leetcode.com/problems/reverse-nodes-in-k-group/)
* [LC 92 — Reverse Linked List II](https://leetcode.com/problems/reverse-linked-list-ii/)
* [LC 206 — Reverse Linked List](https://leetcode.com/problems/reverse-linked-list/)
* [LC 61 — Rotate List](https://leetcode.com/problems/rotate-list/)

---

## 19. TREE DFS (PREORDER / INORDER / POSTORDER) 🟢
- **Core Idea:** Recursively traverse tree branches top-down or bottom-up to calculate path properties, depths, or search conditions.
- **Recognition Triggers:** Maximum depth, path sum, validate BST, lowest common ancestor.
- **Complexity:** Time: $O(N)$ | Space: $O(H)$ recursion stack height

### Key Problems
* [LC 98 — Validate Binary Search Tree](https://leetcode.com/problems/validate-binary-search-tree/)
* [LC 104 — Maximum Depth of Binary Tree](https://leetcode.com/problems/maximum-depth-of-binary-tree/)
* [LC 112 — Path Sum](https://leetcode.com/problems/path-sum/)
* [LC 124 — Binary Tree Maximum Path Sum](https://leetcode.com/problems/binary-tree-maximum-path-sum/)
* [LC 236 — Lowest Common Ancestor of a Binary Tree](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/)
* [LC 543 — Diameter of Binary Tree](https://leetcode.com/problems/diameter-of-binary-tree/)

---

## 20. TREE BFS (LEVEL ORDER TRAVERSAL) ⭐⭐⭐⭐⭐ 🟢
- **Core Idea:** Traverse binary tree level by level using a FIFO Queue to collect node values horizontal layer by layer.
- **Recognition Triggers:** "Level order traversal", "Zigzag level order", "Populate next right pointers", "Right side view of tree", "Minimum depth".
- **Complexity:** Time: $O(N)$ | Space: $O(W)$ maximum width of tree

### Boilerplate Template
```cpp
vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> result;
    if (!root) return result;
    
    queue<TreeNode*> q;
    q.push(root);
    
    while (!q.empty()) {
        int levelSize = q.size();
        vector<int> currentLevel;
        
        for (int i = 0; i < levelSize; i++) {
            TreeNode* node = q.front();
            q.pop();
            currentLevel.push_back(node->val);
            
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        result.push_back(currentLevel);
    }
    return result;
}
```

### Key Problems
* [LC 102 — Binary Tree Level Order Traversal](https://leetcode.com/problems/binary-tree-level-order-traversal/)
* [LC 103 — Binary Tree Zigzag Level Order Traversal](https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/)
* [LC 107 — Binary Tree Level Order Traversal II](https://leetcode.com/problems/binary-tree-level-order-traversal-ii/)
* [LC 111 — Minimum Depth of Binary Tree](https://leetcode.com/problems/minimum-depth-of-binary-tree/)
* [LC 199 — Binary Tree Right Side View](https://leetcode.com/problems/binary-tree-right-side-view/)
* [LC 637 — Average of Levels in Binary Tree](https://leetcode.com/problems/average-of-levels-in-binary-tree/)
* [LC 116 — Populating Next Right Pointers in Each Node](https://leetcode.com/problems/populating-next-right-pointers-in-each-node/)