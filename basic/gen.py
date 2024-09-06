import random, string,itertools
n = random.randint(1, 100)
m = random.randint(1, 10**6)#開區間
# print(' '.join(map(str,random.sample(range(1, 10**6+1), m))))#m個不重複數字
# 生成 n 個不重複的隨機字串，每個字串長度為 5
result = [''.join(random.sample(string.ascii_lowercase, 5)) for _ in range(n)]
# 生成範圍內的隨機浮點數
f = random.uniform(0, 10)
#隨機字串生成
random_string = ''.join(random.choices(string.ascii_lowercase, k=n))
# 生成所有排列
permutations = list(itertools.permutations([1, 2, 3]))
# 生成所有組合
combinations = list(itertools.combinations([1, 2, 3], 2))
# 隨機生成 n 個節點和 m 條邊的無向圖
n, m = 5, 7
edges = set()
while len(edges) < m:
    u, v = random.randint(1, n), random.randint(1, n)
    if u != v:
        edges.add((min(u, v), max(u, v)))
# 隨機生成 n 個節點和 m 條邊的DAG
def generate_dag(n, m):
    nodes = list(range(1, n+1))
    random.shuffle(nodes)
    edges = set()
    while len(edges) < m:
        u, v = random.sample(nodes, 2)
        u_index, v_index = nodes.index(u), nodes.index(v)
        if u_index < v_index:
            edges.add((u, v))
    return nodes, list(edges)

