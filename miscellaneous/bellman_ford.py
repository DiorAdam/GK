from collections import defaultdict


def bellman_ford(graph_edges: list[tuple], src: int) -> list[int]:
    m = len(graph_edges)
    nodes = set([edge[0] for edge in graph_edges] + [edge[1] for edge in graph_edges])
    n = len(nodes)
    mem = [[float("inf") for _ in range(n)] for _ in range(m+1)]
    mem[0][src] = 0
    parents = parent_graph(graph_edges)
    for k in range(1, m+1):
        for node in range(n):
            mem[k][node] = mem[k-1][node]
            for parent, edge_dist in parents[node]:
                mem[k][node] = min(mem[k][node], mem[k-1][parent] + edge_dist)
    return mem[m]


def parent_graph(edges):
    ans = defaultdict(list)
    for edge in edges:
        ans[edge[1]].append((edge[0], edge[2]))
    return ans



if __name__ == "__main__":
    edges = [(0, 1, 100), (0, 2, 1), (2, 3, 4), (1, 3, -99), (2, 4, 5), (3, 4, 3)]
    print(bellman_ford(edges, 0))
