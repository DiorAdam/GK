from copy import copy
from collections import defaultdict


def dag_shortest_path(dag: dict[int, list], node: int) -> dict[int, int]:
    mem: dict[int, dict] = dict()
    def rec(node):
        if node in mem: return mem[node]
        ans = {}
        for child in dag[node]:
            sp = rec(child)
            sp[child] = 0
            sp = increment_distances(sp)
            ans = min_dict(ans, sp)
        mem[node] = ans
        return ans
    return rec(node)

def min_dict(dico1, dico2):
    ans = copy(dico1)
    for key in dico2:
        if key in dico1:
            ans[key] = min(dico1[key], dico2[key])
        else:
            ans[key] = dico2[key]
    return ans

def increment_distances(distances):
    return {node: dist+1 for node, dist in distances.items()}


def dejkstra(graph: dict[int, list[list[int]]], root: int) -> dict[int, int]:
    fifo = [root]
    dist = {root:0}
    while fifo: 
        node = fifo.pop(0)
        for neighbor, edge_dist in graph[node]:
            if neighbor in dist:
                dist[neighbor] = min(dist[neighbor], dist[node] + edge_dist)
            else:
                dist[neighbor] = dist[node] + edge_dist
                fifo.append(neighbor)
    return dist


if __name__ == "__main__":
    dag = defaultdict(list, {0: [1, 2], 1: [2, 6], 2: [3, 4, 5], 5: [6]})
    print(dag_shortest_path(dag, 0))

    graph = defaultdict(list, {0: [(1, 1), (2, 1)], 1: [(2, 1), (6, 1)], 2: [(3, 1), (4, 1), (5, 1)], 5: [(6, 1)]})
    graph = {0: [(1, 1), (2, 6)], 1: [(2, 2)], 2: [(0, 1)]}
    print(dejkstra(graph, 0))
